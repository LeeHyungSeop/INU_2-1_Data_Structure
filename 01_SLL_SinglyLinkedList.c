#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}S;
S* head=0;

void addNode(int _data)
{
	S* new_node=(S*)malloc(sizeof(S));
	new_node->data=_data;
	new_node->next=0;

	S* temp=head;

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
}

void showSLL()
{
	S* temp=head;
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

void clearSLL(){
	S* temp=head;
	while(head!=0)
	{
		head=head->next;
		free(temp);
		temp=head;
	}
}

S* findNode(int _data)
{
	S* temp=head;

	while(temp!=0)
	{
		if(temp->data==_data)
		return temp;
		temp=temp->next;
	}
	return temp;
}

S* findPrev(S* me){
	S* temp=head;

	while(temp!=0)
	{
		if(temp->next==me)
		return temp;

		temp=temp->next;
	}
	return temp;
}

void deleteFromSLL(int _data)
{
	S* temp=findNode(_data);

	if(temp==0)
	return;

	if(temp==head)
	{
		head=head->next;
		free(temp);
		return;
	}
	if(temp->next==0)
	{
		S* prev=findPrev(temp);
		prev->next=0;
		free(temp);
		return;
	}
	else
	{
		S* prev=findPrev(temp);
		prev->next=temp->next;
		free(temp);
		return;
	}
}

void insertFrontFromSLL(int _where,int _what){
	S* temp=findNode(_where);
	S* new_node=(S*)malloc(sizeof(S));
	new_node->data=_what;
	new_node->next=0;

	if(temp==0)
		return;

	if(temp==head)
	{
		new_node->next=head;
		head=new_node;
		return;
	}
	S* prev=findPrev(temp);
	new_node->next=temp;
	prev->next=new_node;
}
void insertRearFromSLL(int _where,int _what){
	S* temp=findNode(_where);
	S* new_node=(S*)malloc(sizeof(S));
	new_node->data=_what;
	new_node->next=0;

	if(temp==0)
		return;

	if(temp->next==0)
	{
		temp->next=new_node;
		return;
	}
	new_node->next=temp->next;
	temp->next=new_node;
}

int main(void)
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);

	showSLL(); // 1 2 3 4 5;    

	deleteFromSLL(1);
	deleteFromSLL(3);
	deleteFromSLL(5);
	deleteFromSLL(100); 

	showSLL(); // 2 4;    

	insertFrontFromSLL(2, 1); // 1 2 4
	insertFrontFromSLL(4, 3); // 1 2 3 4
	insertRearFromSLL(4, 5); // 1 2 3 4 5
	insertRearFromSLL(4, 3); // 1 2 3 4 3 5
	insertFrontFromSLL(100, 3); 
	insertRearFromSLL(100, 3);

	showSLL(); // 1 2 3 4 3 5;    

	clearSLL(); 

	showSLL(); // -999    

	return 0;
}