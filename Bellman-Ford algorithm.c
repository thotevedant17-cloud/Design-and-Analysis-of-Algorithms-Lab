#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

typedef struct {
	int u, v, w;
} Edge;

void printPath(int parent[], int source, int vertex) {
	int path[MAX];
	int count = 0;
	int current = vertex;

	while (current != -1) {
		path[count++] = current;
		if (current == source)
			break;
		current = parent[current];
	}

	for (int i = count - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i > 0)
			printf("->");
	}
}

int main() {
	int V, E;
	Edge edges[MAX];
	int dist[MAX], parent[MAX];
	int source;

	scanf("%d", &V);
	scanf("%d", &E);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	}

	scanf("%d", &source);

	// Initialize distances and parents
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
		parent[i] = -1;
	}

	dist[source] = 0;

	// Relax all edges V-1 times
	for (int i = 1; i <= V - 1; i++) {
		int updated = 0;

		for (int j = 0; j < E; j++) {
			int u = edges[j].u;
			int v = edges[j].v;
			int w = edges[j].w;

			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				parent[v] = u;
				updated = 1;
			}
		}

		// Optimization: stop if no distance changed
		if (!updated)
			break;
	}

	// Check for a negative weight cycle
	for (int i = 0; i < E; i++) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;

		if (dist[u] != INF && dist[u] + w < dist[v]) {
			printf("Negative cycle detected\n");
			return 0;
		}
	}

	// Print shortest distance and path for every vertex except source
	for (int i = 1; i <= V; i++) {
		if (i == source)
			continue;

		if (dist[i] == INF) {
			printf("%d INF None\n", i);
		} else {
			printf("%d %d ", i, dist[i]);
			printPath(parent, source, i);
			printf("\n");
		}
	}

	return 0;
}
