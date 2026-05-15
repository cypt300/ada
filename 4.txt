4

#include <stdio.h>

struct Edge {
    int u, v, w;
} e[20], temp;

int parent[20];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, m, i, j, cost = 0, count = 0;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    // Initialize parent
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Enter u v weight:\n");
    for (i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    // Sort edges by weight
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    printf("Edges in MST:\n");

    for (i = 0; i < m; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);

        if (uni(a, b)) {
            printf("%d -- %d = %d\n", e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            count++;
        }

        if (count == n - 1)
            break;
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}