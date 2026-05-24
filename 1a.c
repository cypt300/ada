1*A*

#include <stdio.h>
#include <string.h>

void bruteForcePatternMatch(char T[], char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    int found = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && T[i + j] == P[j]) {
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found\n");
}

int main() {
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    bruteForcePatternMatch(text, pattern);

    return 0;
}


















1*B

#include <stdio.h>
#include <time.h>

int checkUnique(int arr[], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                return 0; // Duplicate found
            }
        }
    }

    return 1; // All elements are unique
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double time_taken;

    start = clock();

    int result = checkUnique(arr, n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(result)
        printf("All elements are unique\n");
    else
        printf("Duplicate elements found\n");

    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}