#include <stdio.h>
#define NV 5

int visited[NV] = { 0 };
int queue[NV];
int front = 0;
int rear = 0;

void enqueue(int _data)
{
	if (front == (rear + 1) % NV)
		return;

	queue[rear] = _data;
	rear = (rear + 1) % NV;
}

int dequeue()
{
	if (front == rear)
	{
		return -999;
	}
	int ret = queue[front];
	front = (front + 1) % NV;
	return ret;
}

int isin_queue(int _data)
{
	int i = front;

	while (i != rear)
	{
		if (queue[i] == _data)
			return 1;

		i = (i + 1) % NV;
	}
	return 0;
}

void addEdge(int graph[][NV], int a, int b)
{
	graph[a][b] = 1;
	graph[b][a] = 1;
}

void processAdjacentVertices(int graph[][NV], int v, void* addFunc(int), int* checkin(int))
{
	for (int i = 0; i < NV; i++)
	{
		if (graph[i][v] != 0)
		{
			if (visited[i] == 0 && checkin(i) == 0)
			{
				addFunc(i);
			}
		}
	}
}

void BFS(int graph[][NV],int startv)
{
	visited[startv] = 1;
	enqueue(startv);

	while (1)
	{
		int v = dequeue();
		if (v == -999)
			return;

		printf("%d ", v);
		visited[v] = 1;

		processAdjacentVertices(graph, v, &enqueue, &isin_queue);
	}
}

int main(void)
{
	int graph[NV][NV] = { 0 };

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	int startv;
	scanf("%d", &startv);

	BFS(graph,startv);

	return 0;
}