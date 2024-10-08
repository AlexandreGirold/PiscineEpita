#include <stddef.h>
#include <stdio.h>

int my_strstr(const char *haystack, const char *needle)
{
    if (needle[0] == '\0')
        return 0;
    if (!haystack)
        return -1;
    if (!needle)
        return 0;
    // if (len(haystack) < len(needle))
    // return -1;
    const char *h = haystack;
    int count = 0;
    while (h[count] != '\0')
    {
        int i = 0;
        int oldpos = count;
        // const char *h_start = h;
        // const char *aie = needle;

        while (needle[i] != '\0' && h[count] != '\0' && h[count] == needle[i])
        {
            i++;
            count++;
        }
        if (needle[i] == '\0')
            return count - i;
        if (h[i] == '\0')
            return -1;
        if (h[count] != needle[i])
        {
            count = oldpos + 1;
        }
    }

    return -1;
}
