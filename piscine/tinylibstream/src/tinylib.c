#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libstream.h"

struct stream *lbs_fopen(const char *path, const char *mode)
{
    int flags;
    if (strcmp(mode, "r") == 0)
        flags = O_RDONLY;
    else if (strcmp(mode, "r+") == 0)
        flags = O_RDWR;
    else if (strcmp(mode, "w") == 0)
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    else if (strcmp(mode, "w+") == 0)
        flags = O_RDWR | O_CREAT | O_TRUNC;
    else
        return NULL;

    int fd = open(path, flags, 0666);
    if (fd < 0)
        return NULL;

    return lbs_fdopen(fd, mode);
}

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd < 0)
        return NULL;

    struct stream *strm = malloc(sizeof(struct stream));
    if (!strm)
        return NULL;

    strm->fd = fd;
    strm->flags = fcntl(fd, F_GETFL);
    strm->error = 0;
    strm->buffered_size = 0;
    strm->already_read = 0;
    strm->io_operation = STREAM_READING;
    strm->buffering_mode = isatty(fd) ? STREAM_LINE_BUFFERED : STREAM_BUFFERED;

    return strm;
}

int lbs_fflush(struct stream *stream)
{
    if (!stream)
        return LBS_EOF;

    if (stream->io_operation == STREAM_WRITING)
    {
        ssize_t written =
            write(stream->fd, stream->buffer, stream->buffered_size);
        if (written < 0)
        {
            stream->error = 1;
            return LBS_EOF;
        }
    }
    else if (stream->io_operation == STREAM_READING)
    {
        if (lseek(stream->fd, -stream->buffered_size + stream->already_read,
                  SEEK_CUR)
            < 0)
        {
            stream->error = 1;
            return LBS_EOF;
        }
    }

    stream->buffered_size = 0;
    stream->already_read = 0;
    return 0;
}

int lbs_fclose(struct stream *stream)
{
    if (!stream)
        return LBS_EOF;

    if (lbs_fflush(stream) == LBS_EOF)
        return LBS_EOF;

    if (close(stream->fd) < 0)
    {
        stream->error = 1;
        return LBS_EOF;
    }

    free(stream);
    return 0;
}

int lbs_fputc(int c, struct stream *stream)
{
    if (!stream)
        return LBS_EOF;

    if (stream->io_operation != STREAM_WRITING)
    {
        if (lbs_fflush(stream) == LBS_EOF)
            return LBS_EOF;
        stream->io_operation = STREAM_WRITING;
    }

    stream->buffer[stream->buffered_size++] = c;

    if (stream->buffering_mode == STREAM_UNBUFFERED
        || stream->buffering_mode == STREAM_LINE_BUFFERED && c == '\n'
        || stream->buffered_size == LBS_BUFFER_SIZE)
    {
        if (lbs_fflush(stream) == LBS_EOF)
            return LBS_EOF;
    }

    return c;
}

int lbs_fgetc(struct stream *stream)
{
    if (!stream)
        return LBS_EOF;

    if (stream->io_operation != STREAM_READING)
    {
        if (lbs_fflush(stream) == LBS_EOF)
            return LBS_EOF;
        stream->io_operation = STREAM_READING;
    }

    if (stream->already_read < stream->buffered_size)
        return stream->buffer[stream->already_read++];

    ssize_t nread = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
    if (nread <= 0)
    {
        stream->error = 1;
        return LBS_EOF;
    }

    stream->buffered_size = nread;
    stream->already_read = 1;
    return stream->buffer[0];
}
