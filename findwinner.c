#include <stdio.h>

int findTheWinner(int n, int k) {
    int winner = 0;  // Starting from the 0th position (since we use 0-based index)
    
    // Iteratively calculate the position of the winner
    for (int i = 2; i <= n; i++) {
        winner = (winner + k) % i;
    }
    
    return winner + 1;  // Convert to 1-based index
}

int main() {
    int n1 = 5, k1 = 2;
    int n2 = 6, k2 = 5;

    printf("Winner for n = %d, k = %d: %d\n", n1, k1, findTheWinner(n1, k1));  // Output: 3
    printf("Winner for n = %d, k = %d: %d\n", n2, k2, findTheWinner(n2, k2));  // Output: 1
    
    return 0;
}
