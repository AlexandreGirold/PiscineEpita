#include <assert.h>
#include <stdio.h>

void freq_analysis(const char text[], const char table[])
{
    int freq[26] = { 0 };
    int len = 0;

    while (text[len] != '\0')
    {
        freq[text[len] - 'A']++;
        len++;
    }

    char sorted_chars[26];
    for (int i = 0; i < 26; i++)
    {
        sorted_chars[i] = 'A' + i;
    }

    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (freq[sorted_chars[i] - 'A'] < freq[sorted_chars[j] - 'A'])
            {
                char temp = sorted_chars[i];
                sorted_chars[i] = sorted_chars[j];
                sorted_chars[j] = temp;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            // Find the position of 'A' + i in sorted_chars
            int pos = 0;
            while (sorted_chars[pos] != 'A' + i)
            {
                pos++;
            }
            printf("%c %c\n", 'A' + i, table[pos]);
        }
    }
}

/*int main() {
    freq_analysis("ABBCCCDDDDD", "ABCD");
    printf("\n");
    freq_analysis("AAB", "XY");
    return 0;
}
*/
