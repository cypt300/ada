// 12. Permutations

#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void permute(int arr[], int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i <= r; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = l; i <= r; i++)
    {
        swap(&arr[l], &arr[i]);
        permute(arr, l + 1, r);
        swap(&arr[l], &arr[i]);
    }
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    permute(arr, 0, n - 1);

    return 0;
}