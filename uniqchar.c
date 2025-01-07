#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

int firstUniqChar(char* s) {
    int freq[ALPHABET_SIZE] = {0};  // Array to store frequency of each character

    // First pass: Count the frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Second pass: Find the first character with frequency 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;  // Return the index of the first unique character
        }
    }

    return -1;  // Return -1 if no unique character is found
}

int main() {
    char s1[] = "leetcode";
    char s2[] = "loveleetcode";
    char s3[] = "aabb";

    printf("First unique character index in '%s': %d\n", s1, firstUniqChar(s1));  // Output: 0
    printf("First unique character index in '%s': %d\n", s2, firstUniqChar(s2));  // Output: 2
    printf("First unique character index in '%s': %d\n", s3, firstUniqChar(s3));  // Output: -1

    return 0;
}
