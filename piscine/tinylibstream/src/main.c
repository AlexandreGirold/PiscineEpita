#include <assert.h>
#include <stdio.h>

#include "libstream.h"

void test_lbs_fopen()
{
    struct stream *stream = lbs_fopen("testfile.txt", "w");
    assert(stream != NULL);
    assert(stream->fd >= 0);
    lbs_fclose(stream);
    printf("test_lbs_fopen passed\n");
}

int main()
{
    test_lbs_fopen();
    return 0;
}
