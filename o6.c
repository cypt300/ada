// Jump game
#include <stdio.h>

int canJump(int nums[], int n)
{
    int reach = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > reach)
            return 0;

        if (i + nums[i] > reach)
            reach = i + nums[i];
    }
    return 1;
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    if (canJump(nums, n))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}