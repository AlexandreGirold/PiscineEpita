#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int is_in(char c, const char *s)
{
    int found = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            found = 1;
            return found;
        }
        i++;
    }
    return found;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t count = 0;
    int i = 0;
    int j = 0;
    // int is_in = 0;
    if (!s || !accept)
        return 0;
    while (s[i] != '\0')
    {
        j = 0;
        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
            {
                count++;
                j++;
                // is_in = 1;
            }
            else if (!is_in(s[i], accept))
                return count;

            else
            {
                j++;
            }
        }
        i++;
    }
    return count;
}
/*
int main(void)
{
    printf("%lu\n", my_strspn("acab", "ab"));
    printf("%lu\n", strspn("123123", "bcbcb1"));
    printf("%lu\n", my_strspn("123123", "bcbcb1"));
    assert(my_strspn("heyyheyy", "hey") == strspn("heyyheyy", "hey"));
    assert(my_strspn("heyyheyy", "") == strspn("heyyheyy", ""));
    assert(my_strspn("", "hey") == strspn("", "hey"));
    assert(my_strspn("abcdef", "abcdef") == strspn("abcdef", "abcdef"));
    assert(my_strspn("1u2ue", "bcbcb1") == strspn("1u2ue", "bcbcb1"));

    assert(my_strspn("123123", "bcbcb1") == strspn("123123", "bcbcb1"));
}
*/
