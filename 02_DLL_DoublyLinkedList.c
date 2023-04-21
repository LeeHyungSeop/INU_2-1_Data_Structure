#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int data;
	struct node* next;
	struct node* prev;
}D;

D* head=0;

void addNode(int _data)
{
	D* new_node=(D*)malloc(sizeof(D));
	new_node->next=new_node->prev=0;
	new_node->data=_data;

	D* temp=head;

	if(head==0)
	{
		head=new_node;
		return;
	}
	while(temp->next!=0)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->prev=temp;
}


void showDLL()
{
	D* temp=head;
	if(temp==0)
	{
		printf("-999\n");
		return;
	}
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void clearDLL(){
	D* temp=head;
	while(head!=0)
	{
		head=head->next;
		free(temp);
		temp=head;
	}
}

D* findNode(int _data)
{
	D* temp=head;
	while(temp!=0)
	{
		if(temp->data==_data)
		return temp;

		temp=temp->next;
	}
	return temp;
}

void deleteFromDLL(int _data)
{
	D* temp=findNode(_data);
	if(temp==0)
	return;

	if(temp==head)
	{
		if(temp->next==0)
		{
			free(temp);
			head=0;
			return;
		}
		head=head->next;
		head->prev=0;
		free(temp);
		return;
	}
	if(temp->next==0)
	{
		temp->prev->next=0;
		free(temp);
		return;
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		return;
	}
}

void insertFrontFromDLL(int _where,int _what)
{
	D* temp=findNode(_where);
	D* new_node=(D*)malloc(sizeof(D));
	new_node->next=new_node->prev=0;
	new_node->data=_what;

	if(temp==0)
	return;

	if(temp==head)
	{
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
		return;
	}
	new_node->next=temp;
	new_node->prev=temp->prev;

	temp->prev->next=new_node;
	temp->prev=new_node;
}

void insertRearFromDLL(int _where,int _what)
{
	D* temp=findNode(_where);
	D* new_node=(D*)malloc(sizeof(D));
	new_node->next=new_node->prev=0;
	new_node->data=_what;

	if(temp==0)
	return;

	if(temp->next==0)
	{
		new_node->prev=temp;
		temp->next=new_node;
		return;
	}
	new_node->prev=temp;
	new_node->next=temp->next;

	temp->next->prev=new_node;
	temp->next=new_node;
	
}

int main(void)
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);

	showDLL(); // 1 2 3 4 5 

	deleteFromDLL(1);
	deleteFromDLL(3);
	deleteFromDLL(5);
	deleteFromDLL(100);// 100은 DLL에 없습니다

	showDLL(); // 2 4

	insertFrontFromDLL(2, 1); 
	insertFrontFromDLL(4, 3);
	insertRearFromDLL(4, 5); 
	insertRearFromDLL(4, 3);
	insertFrontFromDLL(100, 3); // 100은 DLL에 없습니다
	insertRearFromDLL(100, 3); // ..

	showDLL(); // 1 2 3 4 3 5 

	clearDLL();

	showDLL(); // -999

	return 0;
}