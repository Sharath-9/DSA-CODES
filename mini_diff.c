#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int memo[MAX][MAX];

int kp(int wt[], int n, int W) {
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    if (wt[n - 1] <= W) {
        memo[n][W] = max(wt[n - 1] + kp(wt, n - 1, W - wt[n - 1]), kp(wt, n - 1, W));
    } else {
        memo[n][W] = kp(wt, n - 1, W);
    }

    return memo[n][W];
}

int mindiff(int wt[], int n) {
    int range = 0;
    for (int i = 0; i < n; i++) {
        range += wt[i];
    }

    int W = range / 2;

    memset(memo, -1, sizeof(memo));

    int s1 = kp(wt, n, W);
    return (range - 2 * s1);
}

int main() {
    int wt[] = {7, 6, 11, 5};
    int n = sizeof(wt) / sizeof(wt[0]);

    int min_diff = mindiff(wt, n);
    printf("%d\n", min_diff);

    return 0;
}

