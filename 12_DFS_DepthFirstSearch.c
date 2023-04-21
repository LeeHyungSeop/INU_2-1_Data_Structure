#include <stdio.h>

#define NV 5

int visited[NV] = { 0 };
int stack[NV];
int top = -1;

void push(int _data)
{
	if (top == NV - 1)
		return;

	top++;
	stack[top] = _data;
}

int pop()
{
	if (top == -1)
		return -999;

	top--;
	return stack[top + 1];
}

int isin_stack(int _data)
{
	for (int i = 0; i <= top; i++)
	{
		if (stack[i] == _data)
			return 1;
	}
	return 0;
}

void addEdge(int graph[][NV], int a, int b)
{
	graph[a][b] = 1;
	graph[b][a] = 1;
}

void processAdjacentVertices(int graph[][NV], int v, void *addFunc(int), int *checkin(int))
{
	// stack에 vertex 번호를 오름차순으로 push하는 방법
	// for(int i=NV;i>=0;i--)
	// for (int i = NV; i < NV; i++)

	for(int i=NV;i>=0;i--)
	{
		if (graph[i][v] != 0)
		{
			if (visited[i] == 0 && checkin(i)==0)
				addFunc(i);
		}
	}
}

void DFS(int graph[][NV], int startv)
{
	visited[startv] = 1;
	push(startv);

	while (1)
	{
		int v = pop();

		if (v == -999)
			return;

		printf("%d ", v);
		visited[v] = 1;

		processAdjacentVertices(graph, v, &push, &isin_stack);
	}
}

int main(void)
{
	int graph[NV][NV] = { 0 };

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1,2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	int startv;
	scanf("%d", &startv);

	DFS(graph,startv);

	return 0;
}