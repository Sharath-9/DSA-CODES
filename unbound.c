#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int unboundedKnapsack(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W)
        return max(val[n - 1] + unboundedKnapsack(wt, val, n, W - wt[n - 1]), unboundedKnapsack(wt, val, n - 1, W));
    else
        return unboundedKnapsack(wt, val, n - 1, W);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int wt[n], val[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }
    
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);
    
    int maxValue = unboundedKnapsack(wt, val, n, W);
    
    printf("The maximum value that can be achieved is: %d\n", maxValue);
    
    return 0;
}

