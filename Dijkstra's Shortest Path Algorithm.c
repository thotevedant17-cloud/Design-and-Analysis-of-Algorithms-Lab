#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	  int distance[MAX];
    int visited[MAX];
    int parent[MAX];

    int i, j, count;
    int nextnode;
    int min;

    /* Initialize */
    for (i = 1; i <= n; i++) {
        distance[i] = INFINITY;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[startnode] = 0;

    /* Find shortest paths */
    for (count = 1; count <= n - 1; count++) {

        min = INFINITY;
        nextnode = -1;

        /* Find unvisited node with minimum distance */
        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                nextnode = i;
            }
        }

        /* No more reachable vertices */
        if (nextnode == -1)
            break;

        visited[nextnode] = 1;

        /* Update distances */
        for (j = 1; j <= n; j++) {
            if (G[nextnode][j] != 0 &&
                !visited[j] &&
                distance[nextnode] != INFINITY &&
                distance[nextnode] + G[nextnode][j] < distance[j]) {

                distance[j] = distance[nextnode] + G[nextnode][j];
                parent[j] = nextnode;
            }
        }
    }

    printf("Node\tDistance\tPath\n");

    /* Print result */
    for (i = 1; i <= n; i++) {

        if (i == startnode)
            continue;

        if (distance[i] == INFINITY) {

            /* 3 spaces before node and aligned distance column */
            printf("%4d\t%8s\tNO PATH\n", i, "INF");

        } else {

            /* Print node and distance */
            printf("%4d\t%8d\t", i, distance[i]);

            /* Print path from destination to source */
            printf("%d", i);

            j = i;

            while (parent[j] != -1) {
                printf("<-%d", parent[j]);
                j = parent[j];
            }

            printf("\n");
        }
	}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
