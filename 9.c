

#include <stdio.h>

int f = 0;

void subset(int a[], int n, int d, int s[], int k, int sum)
{
    if (sum == d)
    {
        printf("{ ");
        for (int i = 0; i < k; i++)
            printf("%d ", s[i]);
        printf("}\n");
        f = 1;
        return;
    }

    if (sum > d || n == 0)
        return;

    s[k] = a[0];

    subset(a + 1, n - 1, d, s, k + 1, sum + a[0]); // include
    subset(a + 1, n - 1, d, s, k, sum);            // exclude
}

int main()
{
    int a[] = {1, 2, 5, 6, 8}, d = 9;
    int s[5];

    subset(a, 5, d, s, 0, 0);

    if (!f)
        printf("No subset found");

    return 0;
}