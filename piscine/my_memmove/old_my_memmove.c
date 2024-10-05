#include <stddef.h>
#include <errno.h>
#include <assert.h>

void *my_memmove(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    char *d = dest;
    const char *s = src;
    if (d < s) {
        for (size_t i = 0; i < n; ++i) {
            d[i] = s[i];
        }
    } else {
        for (size_t i = n; i > 0; --i) {
            d[i - 1] = s[i - 1];
        }
    }
    return dest;
}
