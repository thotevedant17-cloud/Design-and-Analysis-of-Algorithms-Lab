#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	 int parent[V];
    int i, j, min, a, b, u, v;
    int edge = 0, mincost = 0;

    // Initialize parent array
    for(i = 0; i < V; i++)
        parent[i] = i;

    while(edge < V - 1)
    {
        min = INT_MAX;

        // Find the minimum edge
        for(i = 0; i < V; i++)
        {
            for(j = i + 1; j < V; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find parent of u
        while(parent[u] != u)
            u = parent[u];

        // Find parent of v
        while(parent[v] != v)
            v = parent[v];

        // If no cycle is formed
        if(u != v)
        {
            printf("Edge %d:(%d, %d) cost:%d\n", edge, a, b, min);
            mincost += min;
            parent[u] = v;
            edge++;
        }

        // Remove the selected edge
        cost[a][b] = cost[b][a] = INT_MAX;
    }

    printf("Minimum cost= %d\n", mincost);
}

int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
