// 9. Coin Change

#include <stdio.h>

#define INF 100000

int main()
{

    int n, amount;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coin[n];

    printf("Enter coins:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = INF;

    for (int i = 1; i <= amount; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (coin[j] <= i && dp[i - coin[j]] + 1 < dp[i])
                dp[i] = dp[i - coin[j]] + 1;
        }
    }

    if (dp[amount] == INF)
        printf("-1");
    else
        printf("Minimum Coins = %d", dp[amount]);

    return 0;
}