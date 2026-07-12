// 11. Binary Watch

#include <stdio.h>

int countBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    int turnedOn;

    printf("Enter number of LEDs ON: ");
    scanf("%d", &turnedOn);

    printf("Possible Times:\n");

    for (int h = 0; h < 12; h++)
    {
        for (int m = 0; m < 60; m++)
        {
            if (countBits(h) + countBits(m) == turnedOn)
                printf("%d:%02d\n", h, m);
        }
    }

    return 0;
}