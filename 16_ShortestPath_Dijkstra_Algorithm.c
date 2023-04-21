#include <stdio.h>
#include <stdlib.h>
#define NV 7

typedef struct node{
    int prev;
    int dist;
    int done;
}Dijkstra;

void ini_dtable(Dijkstra dtable[]){

    for (int i = 0; i < NV; i++)
    {
        dtable[i].prev=-1;
        dtable[i].dist=9999;
        dtable[i].done=0;
    }
    
}

int findShortestPathVertex(Dijkstra dtable[]){

    int ret=-1;
    int min=9999;
    for (int i = 0; i < NV; i++)
    {
        if(dtable[i].done==0 && dtable[i].dist<min){
            min=dtable[i].dist;
            ret=i;
        }
    }
    return ret;
}

void show_path(Dijkstra dtable[],int startv,int endv){


    int current=endv;
    
    int stack[NV]={0};
    int i=0;

    while(current!=startv){
        stack[i++]=current;
        current=dtable[current].prev;
    }
    stack[i]=current;
    
    for (int j = i; j >= 0; j--)
    {
        printf("%d -> ",stack[j]);
    }
    
}

int main(void){

    int graph[NV][NV] = {
		//   0   1  2  3  4  5  6
			{-1,-1,-1,-1,-1,-1,-1}, // 0
			{-1,-1,3,-1,15,-1,-1}, // 1
			{-1,3,-1,30,2,-1,-1}, // 2
			{-1,-1,30,-1,-1,3,4}, // 3
			{-1,15,2,-1,-1,1,-1}, // 4 
			{-1,-1,-1,3,1,-1,20}, // 5
			{-1,-1,-1,4,-1,20,-1}, // 6
	};

    Dijkstra dtable[NV];
    ini_dtable(dtable);

    int startv;
    printf("startv 입력 : ");
    scanf("%d",&startv);

    dtable[startv].done=1;

    for (int i = 0; i < NV; i++)
    {
        if(graph[i][startv]!=-1){
            dtable[i].prev=startv;
            dtable[i].dist=graph[i][startv];
        }
    }

    while(1){

        int v = findShortestPathVertex(dtable);
        if(v==-1)
            break;

        dtable[v].done=1;

        for (int i = 0; i < NV; i++)
        {
            if(graph[i][v]!=-1 && dtable[i].done==0 && dtable[i].dist > dtable[v].dist + graph[v][i]){
                dtable[i].dist=dtable[v].dist + graph[v][i];
                dtable[i].prev=v;
            }
        }
    }
    int endv;
    printf("endv 입력 : ");
    scanf("%d",&endv);

    show_path(dtable,startv,endv);
    
    return 0;
}