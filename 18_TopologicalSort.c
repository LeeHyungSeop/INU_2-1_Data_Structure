#include <stdio.h>
#define NV 6

void ini_indegree_table(int graph[][NV],int indegree_table[])
{
	for (int i = 0; i < NV; i++)
	{
		for (int j = 0; j < NV; j++)
		{
			if (graph[j][i] != 0)
			{
				indegree_table[i]++;
			}
		}
	}
}

int find_zero(int indegree_table[])
{
	for (int i = 0; i < NV; i++)
	{
		if (indegree_table[i] == 0)
			return i;
	}
	return -1;
}

void update(int v, int graph[][NV], int indegree_table[])
{
	for (int i = 0; i < NV; i++)
	{
		if (graph[v][i] != 0)
		{
			indegree_table[i]--;
		}
	}
}

int main(void)
{

	int graph[NV][NV] = {

		{0,0,1,1,0,0},   
		{0,0,0,1,1,0},	  
		{0,0,0,0,0,1},
		{0,0,0,0,0,1},
		{0,0,0,0,0,1},	  
		{0,0,0,0,0,0}	 

	};
	int indegree_table[NV] = { 0 };

	ini_indegree_table(graph,indegree_table);

	while (1)
	{
		int v = find_zero(indegree_table);
		if (v == -1)
			break;

		printf("%d ", v);
        
		indegree_table[v] = -1;

		update(v, graph, indegree_table);
	}

	return 0;
}