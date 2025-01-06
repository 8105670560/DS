#include <stdio.h>
#include <string.h>

// Function to compute the minimum number of letters to insert
int addMinimum(char *word) {
    char pattern[] = "abc"; // The valid pattern
    int patternIndex = 0;   // Pointer for the "abc" pattern
    int insertions = 0;     // Count of insertions

    // Traverse the input string
    for (int i = 0; i < strlen(word); i++) {
        while (word[i] != pattern[patternIndex]) {
            // Increment the insertion count for mismatched characters
            insertions++;
            patternIndex = (patternIndex + 1) % 3; // Move to the next character in "abc"
        }
        // Move to the next character in the pattern when there's a match
        patternIndex = (patternIndex + 1) % 3;
    }

    // Add remaining characters from the pattern to complete the sequence
    while (patternIndex != 0) {
        insertions++;
        patternIndex = (patternIndex + 1) % 3;
    }

    return insertions;
}

int main() {
    char word1[] = "b";
    char word2[] = "aaa";
    char word3[] = "abc";

    printf("Input: \"%s\" Output: %d\n", word1, addMinimum(word1)); // Expected: 2
    printf("Input: \"%s\" Output: %d\n", word2, addMinimum(word2)); // Expected: 6
    printf("Input: \"%s\" Output: %d\n", word3, addMinimum(word3)); // Expected: 0

    return 0;
}
