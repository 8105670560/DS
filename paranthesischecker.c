#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to check if the brackets are valid
bool isValid(char *s) {
    char stack[MAX_SIZE];
    int top = -1;

    // Loop through each character in the string
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            stack[++top] = ch;
        } else {
            // If stack is empty, return false
            if (top == -1) return false;

            // Check if the current closing bracket matches the top of the stack
            char topChar = stack[top];
            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                // If matched, pop the top of the stack
                top--;
            } else {
                // Mismatch found
                return false;
            }
        }
    }

    // If stack is empty, the string is valid
    return top == -1;
}

int main() {
    char s1[] = "()";
    char s2[] = "()[]{}";
    char s3[] = "(]";

    printf("Input: \"%s\" Output: %s\n", s1, isValid(s1) ? "true" : "false");
    printf("Input: \"%s\" Output: %s\n", s2, isValid(s2) ? "true" : "false");
    printf("Input: \"%s\" Output: %s\n", s3, isValid(s3) ? "true" : "false");

    return 0;
}
