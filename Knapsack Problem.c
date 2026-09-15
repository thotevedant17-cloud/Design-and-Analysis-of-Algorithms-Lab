#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int value[n], weight[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    int capacity;
    scanf("%d", &capacity);

    int dp[n + 1][capacity + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = 0;
        }
    }

    // 0/1 Knapsack DP
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {

            if (weight[i - 1] <= w) {
                int include = value[i - 1] +
                              dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("%d\n", dp[n][capacity]);

    return 0;
}
