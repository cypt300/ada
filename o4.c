// 4. Assign Cookies

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int content(int g[], int gs, int s[], int ss)
{

    qsort(g, gs, sizeof(int), cmp);
    qsort(s, ss, sizeof(int), cmp);

    int i = 0, j = 0;

    while (i < gs && j < ss)
    {
        if (s[j] >= g[i])
            i++;
        j++;
    }

    return i;
}

int main()
{

    int g[] = {1, 2, 3};
    int s[] = {1, 1};

    printf("%d", content(g, 3, s, 2));

    return 0;
}