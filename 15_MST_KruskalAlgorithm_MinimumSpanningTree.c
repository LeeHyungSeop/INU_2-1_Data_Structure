#include <stdio.h>
#define NV 5

void addEdge(int graph[][NV], int a, int b, int weight)
{
	graph[a][b] = weight;
	graph[b][a] = weight;
}

void MST_Kruskal(int graph[][NV])
{
	int family[NV] = { 0,1,2,3,4 };

	for (int i = 0; i < NV - 1; i++)
	{
		int min = 9999;
		int v1, v2;

		for (int j = 0; j < NV; j++)
		{
			for (int k = j+1; k < NV; k++)
			{
				if (graph[j][k] != 0 && min > graph[j][k] && family[j] != family[k])
				{
					v1 = j;
					v2 = k;
					min = graph[j][k];
				}
			}
		}
		printf("%d -> %d\n", v1, v2);

		int old_family = family[v2];
		int new_family = family[v1];
		for (int cnt = 0; cnt < NV; cnt++)
		{
			if (family[cnt] == old_family)
			{
				family[cnt] = new_family;
			}
		}
	}
}

int main(void)
{
	int graph[NV][NV] = { 0 };

	addEdge(graph, 0, 1, 100);
	addEdge(graph, 0, 2, 10);
	addEdge(graph, 1, 2, 1);
	addEdge(graph, 1, 3, 1);
	addEdge(graph, 1, 4, 15);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 4, 1);

	MST_Kruskal(graph);

	return 0;
}