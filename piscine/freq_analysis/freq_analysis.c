#include <stdio.h>
#include <string.h>

void freq_analysis(const char text[], const char table[]) 
{
    int freq[26] = {0}; // Frequency array for letters A-Z
    int length = strlen(text);

    // Count the frequency of each character in the text
    for (int i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            freq[text[i] - 'A']++;
        }
    }

    // Create an array to hold letters and their frequencies
    char letters[26];
    int counts[26];
    int uniqueCount = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            letters[uniqueCount] = 'A' + i;
            counts[uniqueCount] = freq[i];
            uniqueCount++;
        }
    }

    // Sort the letters based on their frequencies (most common to least common)
    for (int i = 0; i < uniqueCount - 1; i++) {
        for (int j = i + 1; j < uniqueCount; j++) {
            if (counts[i] < counts[j]) {
                // Swap counts
                int tempCount = counts[i];
                counts[i] = counts[j];
                counts[j] = tempCount;

                // Swap corresponding letters
                char tempLetter = letters[i];
                letters[i] = letters[j];
                letters[j] = tempLetter;
            }
        }
    }

    // Prepare output mapping based on sorted frequency
    char mapping[26] = {0};
    for (int i = 0; i < uniqueCount; i++) {
        mapping[letters[i] - 'A'] = table[i];
    }

    // Print the mapping in alphabetical order
    for (char c = 'A'; c <= 'Z'; c++) {
        if (mapping[c - 'A'] != 0) {
            printf("%c %c$\n", mapping[c - 'A'], c); // Added '$' for expected output
        }
    }
}

