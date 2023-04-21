#include <stdio.h>
#include <stdlib.h>
#define SZ 10

typedef struct node{
    struct node* next;
    int data;
}NODE;

typedef struct bucket{
    struct node* head;
    int cnt;
}BUCKET;

void ini_hash_table(BUCKET* NODE){
    for (int i = 0; i < SZ; i++)
    {
        NODE[i].head=NULL;
        NODE[i].cnt=0;
    }
    
}

int hash_function(_data){
    return _data%10;
}

void addNode(BUCKET _hash_table[],int _data){
    int index=hash_function(_data);

    NODE* new_node=(NODE*)malloc(sizeof(NODE));
    new_node->data=_data;
    
    if(_hash_table[index].head==NULL){
        _hash_table[index].head=new_node;
        _hash_table[index].cnt++;
        return;
    }

    NODE* temp=_hash_table[index].head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    _hash_table[index].cnt++;
    return;
}

void show_hash_table(BUCKET _hash_table[]){
    for (int i = 0; i < SZ; i++)
    {
        NODE* temp=_hash_table[i].head;
        printf("BUCKET[%d] (%d개) : ",i,_hash_table[i].cnt);
        while(temp!=NULL){
            printf("%3d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    
}

int main(void){

    BUCKET* hash_table=(BUCKET*)malloc(sizeof(BUCKET)*SZ);

    ini_hash_table(hash_table);

    addNode(hash_table,10);
	addNode(hash_table,20);
	addNode(hash_table,30);
	addNode(hash_table,12);
	addNode(hash_table,55);
	addNode(hash_table,99);
	addNode(hash_table,101);
	addNode(hash_table,202);
	addNode(hash_table,303);

    show_hash_table(hash_table);

    return 0;
}