#include <stdio.h>

int my_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') 
        return 0;
    if (*haystack == '\0')
        return -1;
    const char h_start;
    const char *h = haystack;
    const char *aie;
    
    while (h) {
        const char *h_start = h;
        const char *aie = needle;
        

        while (*aie != '\0' && *h != '\0' && *h == *aie) 
        {
            h++;
            aie++;
        }
        if (*aie == '\0') 
            return h_start - haystack; 
        h++;
    }

    return -1;
}

int main() {
    const char *haystack = "Hello, world";
    const char *needle = "world";
    
    int index = my_strstr(haystack, needle);
    if (index != -1) 
    {
        printf("Found '%s' at index %d\n", needle, index);
    } 
    else 
    {
        printf("'%s' not found\n", needle);
    }

    return 0;
}
