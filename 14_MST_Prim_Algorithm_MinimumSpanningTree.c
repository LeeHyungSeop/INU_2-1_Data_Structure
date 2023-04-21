#include <stdio.h>
#define NV 5

void addEdge(int graph[][NV], int a, int b, int weight)
{
	graph[a][b] = weight;
	graph[b][a] = weight;
}

void MST_Prim(int graph[][NV], int startv)
{
	int visited[NV] = { 0 };
	visited[startv] = 1;

	for (int i = 0; i < NV - 1; i++)
	{
		int min = 9999;
		int visited_vertex, nonvisited_vertex;
		for (int j = 0; j < NV; j++)
		{
			if (visited[j] == 1)
			{
				for (int k = 0; k < NV; k++)
				{
					if (visited[k] == 0)
					{
						if (graph[j][k] != 0 && min > graph[j][k])
						{
							min = graph[j][k];
							visited_vertex = j;
							nonvisited_vertex = k;
						}
					}
				}
			}
		}
		printf("%d -> %d\n", visited_vertex, nonvisited_vertex);
		visited[nonvisited_vertex] = 1;
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

	int startv;
	scanf("%d", &startv);

	MST_Prim(graph, startv); // 0 2 1 3 4

	return 0;
}