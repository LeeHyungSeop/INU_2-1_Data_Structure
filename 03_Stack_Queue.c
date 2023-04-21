#include <stdio.h>
#define SIZE 5

// stack -----------------------------

int stack[SIZE];
int top=-1;
void push(int _data)
{
	if(top==SIZE-1)
	return;

	top++;
	stack[top]=_data;
}

int pop()
{
	if(top==-1)
	return -999;

	top--;
	return stack[top+1];
}

// queue -----------------------------

int queue[SIZE];
int front=0;
int rear=0;
void enqueue(int _data)
{
	if(front==(rear+1)%SIZE)
	{
		return;
	}
	queue[rear]=_data;
	rear=(rear+1)%SIZE;
}
int dequeue()
{
	if(front==rear)
	{
		return -999;
	}
	int ret=queue[front];
	front=(front+1)%SIZE;
	return ret;
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", pop()); // 5 4 3 2 1
	}
	printf("\n");

	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", dequeue()); // 1 2 3 4 -999
	}

	return 0;
}