#include<stdio.h>

int coin_total(int coin[], int n, int num) {
    int dp[n + 1][num + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= num; j++) {
            if (j == 0) {
                dp[i][j] = 1;
            } else if (i == 0) {
                dp[i][j] = 0;
            } else if (coin[i - 1] <= j) {
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    // Print the memoization table
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
    
    int result = coin_total(coin, n, num);
    printf("%d are total number of ways\n", result);
    
    return 0;
}
