#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 9999

int memo[MAX][MAX];

int coin_min(int coin[], int n, int num) {
    if (n == 0)
        return 0;
    else if (num == 0)
        return 1;
    else if (memo[n][num] != -1)
        return memo[n][num];
    else if (coin[n - 1] <= num)
        memo[n][num] = coin_min(coin, n, num - coin[n - 1]) + coin_min(coin, n - 1, num);
    else
        memo[n][num] = coin_min(coin, n - 1, num);
    return memo[n][num];
}

int main() {
    int n, num;
    printf("\nEnter the number of coins: ");
    scanf("%d", &n);
    int coin[n];
    printf("\nEnter the values of coins: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    printf("\nEnter the sum value: ");
    scanf("%d", &num);

    memset(memo, -1, sizeof(memo));

    int result = coin_min(coin, n, num);
    printf("\n%d are the maximum number of ways\n", result);

    return 0;
}

