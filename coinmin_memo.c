#include <stdio.h>
#include <limits.h>

#define max 9999
#define SIZE 1000

int memo[SIZE][SIZE];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coin_min(int coin[], int n, int num) {
    if (n == 0 && num != 0) {
        return max;
    } else if (num == 0) {
        return 0;
    }
    
    if (memo[n][num] != -1) {
        return memo[n][num];
    }
    
    int result;
    if (coin[n - 1] <= num) {
        result = min((1 + coin_min(coin, n, num - coin[n - 1])), coin_min(coin, n - 1, num));
    } else {
        result = coin_min(coin, n - 1, num);
    }
    
    memo[n][num] = result;
    
    
    
    return result;
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
            memo[i][j] = -1;
        }
    }
    
    int result = coin_min(coin, n, num);
    if (result == max) {
        printf("No valid combination found.\n");
    } else {
        printf("%d is the minimum number of coins required.\n", result);
    }
     printf("\nMemoization Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= num; j++) {
            printf("%d\t", memo[i][j]);
        }
        printf("\n");
    }
    //printTable(n, num); // Print the memoization table
    
    return 0;
}
