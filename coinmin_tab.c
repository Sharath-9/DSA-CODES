#include <stdio.h>
#include <limits.h>

#define max 9999
#define SIZE 1000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coin_min(int coin[], int n, int num) {
    int dp[n + 1][num + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= num; j++) {
            if (j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                dp[i][j] = max;
            } else if (coin[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    // Print the table
    printf("\nTabulation Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= num; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    
    return dp[n][num];
}

int main() {
    int n, num;
    printf("\nEnter the number of coins: ");
    scanf("%d", &n);
    
    int coin[n];
    printf("Enter the value of coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    
    printf("Enter the target sum value: ");
    scanf("%d", &num);
    
    int result = coin_min(coin, n, num);
    if (result == max) {
        printf("No valid combination found.\n");
    } else {
        printf("%d is the minimum number of coins required.\n", result);
    }
    
    return 0;
}
