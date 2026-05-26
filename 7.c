#include <stdio.h>

#define MAX 100

int a[MAX][MAX], vis[MAX], order[MAX];
int n, idx;

void dfs(int v)
{
    vis[v]=1;

    for(int i=0;i<n;i++)
        if(a[v][i] && !vis[i])
            dfs(i);

    order[--idx]=v;
}

void topo()
{
    idx=n;

    for(int i=0;i<n;i++)
        vis[i]=0;

    for(int i=0;i<n;i++)
        if(!vis[i])
            dfs(i);
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    topo();

    printf("Topological order:\n");

    for(int i=0;i<n;i++)
        printf("%d ",order[i]);

    return 0;
}
