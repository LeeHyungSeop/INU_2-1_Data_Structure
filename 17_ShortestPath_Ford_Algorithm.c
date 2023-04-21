#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy 

// Dijkstra 알고리즘과 달리, 모든 vertex로 가는 weight를 알 수 있다.
// 하지만 어디를 거쳐가는지에 대한 경로는 알 수 없다.

#define NV 7

int main(void)
{
	int graph[NV][NV] = {
		{9999,4,1,9999,9999,9999,9999},
		{4,9999,3,9999,15,9999,9999},
		{1,3,9999,30,2,9999,9999},
		{9999,9999,30,9999,9999,3,4},
		{9999,15,2,9999,9999,1,9999},
		{9999,9999,9999,3,1,9999,20},
		{9999,9999,9999,4,9999,20,9999}
	};

	int dtable[NV][NV] = { 0 };

	memcpy(dtable, graph, sizeof(int) * NV * NV);

	for (int i = 0; i < NV; i++)
	{
		dtable[i][i] = 0;
	}

	for (int k = 0; k < NV; k++)
	{
		for (int i = 0; i < NV; i++)
		{
			for (int j = 0; j < NV; j++)
			{
				if (dtable[i][j] > dtable[i][k] + dtable[k][j])
				{
					dtable[i][j] = dtable[i][k] + dtable[k][j];
				}
			}
		}
	}

	for (int i = 0; i < NV; i++)
	{
		for (int j = 0; j < NV; j++)
		{
			printf("%2d ", dtable[i][j]);
		}
		printf("\n");
	}

	return 0;
}