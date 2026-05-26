
#include <stdio.h>
#include <string.h>

void bruteForcePatternMatch(char T[], char P[])
{
    int n = strlen(T);
    int m = strlen(P);
    int found = 0;

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        while (j < m && T[i + j] == P[j])
        {
            j++;
        }

        if (j == m)
        {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found\n");
}

int main()
{
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    bruteForcePatternMatch(text, pattern);

    return 0;
}
