// 15. Word Search

#include <stdio.h>
#include <string.h>

int dfs(char board[10][10], char word[], int i, int j, int k, int r, int c)
{

    if (word[k] == '\0')
        return 1;

    if (i < 0 || i >= r || j < 0 || j >= c)
        return 0;

    if (board[i][j] != word[k])
        return 0;

    char temp = board[i][j];
    board[i][j] = '*';

    int found =
        dfs(board, word, i + 1, j, k + 1, r, c) ||
        dfs(board, word, i - 1, j, k + 1, r, c) ||
        dfs(board, word, i, j + 1, k + 1, r, c) ||
        dfs(board, word, i, j - 1, k + 1, r, c);

    board[i][j] = temp;

    return found;
}

int main()
{

    int r, c;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    char board[10][10];

    printf("Enter board:\n");

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf(" %c", &board[i][j]);

    char word[20];

    printf("Enter word: ");
    scanf("%s", word);

    int found = 0;

    for (int i = 0; i < r && !found; i++)
        for (int j = 0; j < c && !found; j++)
            if (dfs(board, word, i, j, 0, r, c))
                found = 1;

    if (found)
        printf("Word Found\n");
    else
        printf("Word Not Found\n");

    return 0;
}