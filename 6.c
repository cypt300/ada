#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int g[MAX][MAX], dist[MAX], vis[MAX], n;

void dijkstra(int s)
{
    for(int i=0;i<n;i++)
        dist[i]=INF, vis[i]=0;

    dist[s]=0;

    for(int i=0;i<n-1;i++)
    {
        int min=INF, u=-1;

        for(int j=0;j<n;j++)
            if(!vis[j] && dist[j]<min)
                min=dist[j], u=j;

        if(u==-1) break;

        vis[u]=1;

        for(int v=0;v<n;v++)
            if(!vis[v] && g[u][v] &&
               dist[u]!=INF &&
               dist[u]+g[u][v] < dist[v])

                dist[v]=dist[u]+g[u][v];
    }
}

int main()
{
    int e,s,u,v,w;

    printf("Enter vertices and edges: ");
    scanf("%d%d",&n,&e);

    printf("Enter edges (u v w):\n");

    for(int i=0;i<e;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        g[u][v]=g[v][u]=w;
    }

    printf("Enter source: ");
    scanf("%d",&s);

    dijkstra(s);

    printf("\nShortest distances:\n");

    for(int i=0;i<n;i++)
        printf("%d -> %d\n",i,dist[i]);

    return 0;
}
