// 13. Combinations

#include <stdio.h>

int temp[20];

void combine(int start, int n, int k, int index)
{

    if (index == k)
    {
        for (int i = 0; i < k; i++)
            printf("%d ", temp[i]);
        printf("\n");
        return;
    }

    for (int i = start; i <= n; i++)
    {
        temp[index] = i;
        combine(i + 1, n, k, index + 1);
    }
}

int main()
{

    int n, k;

    printf("Enter n and k: ");
    scanf("%d%d", &n, &k);

    combine(1, n, k, 0);

    return 0;
}