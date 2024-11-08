#include <stddef.h>
#include <stdio.h>
void freq_analysis(const char text[], const char table[])
{
    int freq[26] = { 0 };
    int len = 0;

    while (text[len] != '\0')
    {
        if (text[len] >= 'A' && text[len] <= 'Z')
            freq[text[len] - 'A']++;
        len++;
    }

    char letters[26];
    int counts[26]; // fonctionne avec letters (compte la freq de lettre dans
                    // letters)
    int uniqueCount = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            letters[uniqueCount] = 'A' + i;
            counts[uniqueCount] = freq[i];
            uniqueCount++;
        }
    }

    for (int i = 0; i < uniqueCount - 1; i++)
    {
        for (int j = i + 1; j < uniqueCount; j++)
        {
            if (counts[i] < counts[j])
            {
                int tempCount = counts[i];
                counts[i] = counts[j];
                counts[j] = tempCount;

                char tempLetter = letters[i];
                letters[i] = letters[j];
                letters[j] = tempLetter;
            }
        }
    }

    char mapping[26] = { 0 };
    for (int i = 0; i < uniqueCount; i++)
        mapping[letters[i] - 'A'] = table[i];

    for (int i = 0; i < uniqueCount; i++)
        printf("%c %c\n", mapping[letters[i] - 'A'], letters[i]);
}
