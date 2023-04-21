#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#define GSZ 100
#define MAP_SIZE 10
#define STK_SZ 100


int graph[GSZ][GSZ] = { 0 };

// 갈 수 없는 길 1, 뚫긴 길 0
int map[MAP_SIZE][MAP_SIZE] =
{
	{0,1,0,0,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,0,0,1},
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,1,1,0},
	{0,0,0,1,0,0,0,1,0,0}
};

typedef struct {
	int prev;
	int dist;
	int done;
}Dijkstra;

Dijkstra dtable[GSZ];

int stack[STK_SZ];
int top = -1;
void push(int _data)
{
	if (top == STK_SZ - 1)
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

void ini_dtable(Dijkstra dtable[])
{
	for (int i = 0; i < GSZ; i++) 
	{
		dtable[i].prev = -1;
		dtable[i].dist = 9999;
		dtable[i].done = 0;
	}
}

void addEdge(int graph[][GSZ],int a,int b, int weight)
{
	graph[a][b] = weight;
	graph[b][a] = weight;
}

void ini_graph(int graph[][GSZ])
{
	for (int i = 0; i < GSZ; i++)
	{
		for (int j = 0; j < GSZ; j++)
		{
			graph[i][j] = -1;
		}
	}
}

int find_shortest_path_vertex(Dijkstra dtable[])
{
	int min = 9999;
	int res = -1;

	for (int i = 0; i < GSZ; i++)
	{
		if (dtable[i].done == 0 && min > dtable[i].dist)
		{
			min = dtable[i].dist;
			res = i;
		}
	}
	return res;
}

void show_map(int map[][MAP_SIZE], int start, int end)
{
	// vertex화 시켰던 좌표들을 다시 좌표화 시킨다.
	int mx = start / 10; 
	int my = start % 10;

	int cx = end / 10;
	int cy = end % 10;

	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (i == mx && j == my)
			{
				printf("m ");
				continue;
			}
			if (i == cx && j == cy)
			{
				printf("c ");
				continue;
			}
			if (map[i][j] == 0)
			{
				printf("  ");
				continue;
			}
			if (map[i][j] == 1)
			{
				printf("X");
				continue;
			}
		}
		printf("\n");
	}
	printf("\n");
}

void show_shortest_path(Dijkstra dtable[], int start, int end)
{
	int current = end;

	// stack에 지나온 vertex들을 push (나중에 pop하면서 거꾸로된 경로가 아닌 제대로된 경로를 출력할 것이기 때문)
	while (current != start)
	{
		push(current);
		current = dtable[current].prev;
	}
	push(start);

	// stack에 먼저 들어온 vertex들을 pop하며 map을 update 시킨다.
	while (!(top == -1))
	{
		// system("cls");
		system("clear");
		int pop_data = pop();
		printf("(%d,%d)\n", pop_data / 10, pop_data % 10);
		show_map(map,pop_data,end);
	}
	printf("쥐가 치즈를 찾았습니다!\n");
	printf("총 %d의 weight가 발생하였습니다.\n", dtable[end].dist);
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		addEdge(graph,10*i,10*(i+1), 1); // 0열
		addEdge(graph,10*i+2,10*(i+1)+2, 1); // 2열
		addEdge(graph, 10 * i + 4, 10 * (i + 1) + 4, 1); // 4열
		addEdge(graph, 10 * i + 6, 10 * (i + 1) + 6, 1); // 6열
		if (i <= 6)
		{
			addEdge(graph, 10 * i + 8, 10 * (i + 1) + 8, 1); // 8열은 7행까지만 연결
		}
	}
	addEdge(graph, 90, 91, 1); // 나머지 길은 수기로 작성
	addEdge(graph, 91, 92, 1);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 4, 1);
	addEdge(graph, 94, 95, 1);
	addEdge(graph, 95, 96, 1);
	addEdge(graph, 16, 17, 1);
	addEdge(graph, 17, 18, 1);
	addEdge(graph, 38, 39, 1);
	addEdge(graph, 78, 79, 1);
	addEdge(graph, 79, 89, 1);
	addEdge(graph, 89, 99, 1);
	addEdge(graph, 99, 98, 1);

	int mouse_startv;
	int cheese_endv;
	// 좌표를 입력받고 그 좌표를 숫자화 시킨다  (2,3) --> 23
	//  (Dijkstra) ---------------------------------------------------------------------
		int mx, my;
		printf("쥐의 처음 위치를 입력하세요 : (x,y) : ");
		scanf("%d %d", &mx, &my);
		mouse_startv = mx * 10 + my; // 쥐의 좌표를 vertex화(숫자화)

		int cx, cy;
		printf("치즈의 위치를 입력하세요 : (x,y) : ");
		scanf("%d %d", &cx, &cy);
		cheese_endv = 10 * cx + cy; // 치즈의 좌표를 vertex화

		if (map[mx][my] == 1)
		{
			printf("그곳은 쥐가 있을 수 없는 곳입니다.\n");
			return 0;
		}
		
		if (map[cx][cy] == 1)
		{
			printf("그곳은 치즈가 있을 수 없는 곳입니다.\n");
			return 0;
		}

		ini_dtable(dtable);
		dtable[mouse_startv].done=1; 

		for (int i = 0; i < GSZ; i++)
		{
			if (graph[mouse_startv][i] > 0)
			{
				dtable[i].prev = mouse_startv;
				dtable[i].dist = graph[mouse_startv][i];
			}
		}
		while (1)
		{
			int v= find_shortest_path_vertex(dtable);

			if (v == -1)
			{
				break;
			}
			dtable[v].done = 1;

			for (int i = 0; i < GSZ; i++)
			{
				if (dtable[i].done == 0 && graph[v][i] > 0 && dtable[i].dist > dtable[v].dist + graph[v][i]) 
				{
					dtable[i].dist = dtable[v].dist + graph[i][v];
					dtable[i].prev = v;
				}
			}
		}
	show_shortest_path(dtable, mouse_startv, cheese_endv);

	return 0;
}