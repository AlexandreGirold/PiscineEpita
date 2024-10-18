#include "libstream.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

struct stream *lbs_fopen(const char *path, const char *mode) {
    int fd;
    int flags;

    if (strcmp(mode, "r") == 0) {
        flags = O_RDONLY;
    } else if (strcmp(mode, "r+") == 0) {
        flags = O_RDWR;
    } else if (strcmp(mode, "w") == 0) {
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    } else if (strcmp(mode, "w+") == 0) {
        flags = O_RDWR | O_CREAT | O_TRUNC;
    } else {
        return NULL;
    }

    fd = open(path, flags, 0644);
    if (fd == -1) {
        return NULL;
    }

    return lbs_fdopen(fd, mode);
}

struct stream *lbs_fdopen(int fd, const char *mode) {
    struct stream *s = malloc(sizeof(struct stream));
    if (!s) {
        return NULL;
    }

    s->fd = fd;
    s->error = 0;
    s->buffered_size = 0;
    s->already_read = 0;
    s->io_operation = STREAM_READING;

    if (strcmp(mode, "r") == 0 || strcmp(mode, "r+") == 0) {
        s->flags = O_RDONLY;
    } else if (strcmp(mode, "w") == 0 || strcmp(mode, "w+") == 0) {
        s->flags = O_WRONLY;
    } else {
        free(s);
        return NULL;
    }

    if (isatty(fd)) {
        s->buffering_mode = STREAM_LINE_BUFFERED;
    } else {
        s->buffering_mode = STREAM_BUFFERED;
    }

    return s;
}

int lbs_fflush(struct stream *stream) {
    if (stream->io_operation == STREAM_WRITING) {
        ssize_t written = write(stream->fd, stream->buffer, stream->buffered_size);
        if (written == -1) {
            stream->error = 1;
            return LBS_EOF;
        }
        stream->buffered_size = 0;
    } else if (stream->io_operation == STREAM_READING) {
        if (lseek(stream->fd, -stream->buffered_size + stream->already_read, SEEK_CUR) == -1) {
            stream->error = 1;
            return LBS_EOF;
        }
        stream->buffered_size = 0;
        stream->already_read = 0;
    }
    return 0;
}

int lbs_fclose(struct stream *stream) {
    if (lbs_fflush(stream) == LBS_EOF) {
        return LBS_EOF;
    }
    if (close(stream->fd) == -1) {
        stream->error = 1;
        return LBS_EOF;
    }
    free(stream);
    return 0;
}

int lbs_fputc(int c, struct stream *stream) {
    if (stream->buffered_size == LBS_BUFFER_SIZE || 
        stream->buffering_mode == STREAM_UNBUFFERED || 
        (stream->buffering_mode == STREAM_LINE_BUFFERED && c == '\n')) {
        if (lbs_fflush(stream) == LBS_EOF) {
            return LBS_EOF;
        }
    }
    if (stream->io_operation != STREAM_WRITING) {
        if (lbs_fflush(stream) == LBS_EOF) {
            return LBS_EOF;
        }
        stream->io_operation = STREAM_WRITING;
    }
    stream->buffer[stream->buffered_size++] = c;
    return c;
}

int lbs_fgetc(struct stream *stream) {
    if (stream->io_operation != STREAM_READING) {
        if (lbs_fflush(stream) == LBS_EOF) {
            return LBS_EOF;
        }
        stream->io_operation = STREAM_READING;
        stream->buffered_size = 0;
        stream->already_read = 0;
    }
    if (stream->already_read == stream->buffered_size) {
        ssize_t bytes_read = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        if (bytes_read == -1) {
            stream->error = 1;
            return LBS_EOF;
        }
        if (bytes_read == 0) {
            return LBS_EOF;
        }
        stream->buffered_size = bytes_read;
        stream->already_read = 0;
    }
    return stream->buffer[stream->already_read++];
}
