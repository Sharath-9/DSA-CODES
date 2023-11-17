#include<stdio.h>

int dp[100][100];

int coin_total(int coin[], int n, int num) {
    if (n == 0 && num != 0)
        return dp[n][num] = 0;
    else if (num == 0)
        return dp[n][num] = 1;
    else if (dp[n][num] != -1)
        return dp[n][num];
    else if (coin[n - 1] <= num) {
        return dp[n][num] = (coin_total(coin, n, num - coin[n - 1]) + coin_total(coin, n - 1, num));
    } else {
        return dp[n][num] = coin_total(coin, n - 1, num);
    }
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
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= num; j++) {
            dp[i][j] = -1;
        }
    }
    
    int result = coin_total(coin, n, num);
    printf("%d are maximum no.of ways\n", result);
    
    // Print the memoization table
    printf("\nMemoization Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= num; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
