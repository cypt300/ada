// 10. Letter Combinations of Phone Number

#include <stdio.h>

char *map[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"};

char result[20];

void solve(char digits[], int index)
{

    if (digits[index] == '\0')
    {
        result[index] = '\0';
        printf("%s\n", result);
        return;
    }

    char *letters = map[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++)
    {
        result[index] = letters[i];
        solve(digits, index + 1);
    }
}

int main()
{

    char digits[10];

    printf("Enter digits: ");
    scanf("%s", digits);

    solve(digits, 0);

    return 0;
}