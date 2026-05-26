

#include <stdio.h>

int b[8][8] = {0}, n = 8;

int safe(int r, int c)
{
    for (int i = 0; i < c; i++)
        if (b[r][i])
            return 0;

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return 0;

    for (int i = r, j = c; i < n && j >= 0; i++, j--)
        if (b[i][j])
            return 0;

    return 1;
}

int solve(int c)
{
    if (c == n)
        return 1;

    for (int r = 0; r < n; r++)
    {
        if (safe(r, c))
        {
            b[r][c] = 1;

            if (solve(c + 1))
                return 1;

            b[r][c] = 0;
        }
    }
    return 0;
}

int main()
{
    solve(0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c ", b[i][j] ? 'Q' : '.');
        printf("\n");
    }
}