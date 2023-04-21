#include <stdio.h>
#define SIZE 5

int heap[SIZE];
int hsz=0;

void enheap(int _data)
{
	if(hsz==SIZE-1)
		return;

	hsz++;
	heap[hsz]=_data;

	int me=hsz;
	int parent=me/2;

	while(1)
	{
		if(me==1)
		return;

		if(heap[parent]>=heap[me])
		return;

		else{
			int temp=heap[parent];
			heap[parent]=heap[me];
			heap[me]=temp;

			me=parent;
			parent=me/2;
		}
	}
}

int findReplacer(int me)
{
	int lc=2*me;
	int rc=lc+1;

	if(hsz<lc)
		return -1;
	
	if(hsz<rc)
	{
		return lc;
	}
	else{
		if(heap[lc]>heap[rc])
			return lc;
		else
			return rc;
	}
}

int deheap()
{
	if(hsz==0)
		return -999;

	int ret=heap[1];
	heap[1]=heap[hsz];
	hsz--;

	int me=1;

	while(1)
	{
		int replacer=findReplacer(me);

		if(replacer==-1)
			return ret;

		if(heap[me]>=heap[replacer])
		{
			return ret;
		}
		else{
			int temp=heap[replacer];
			heap[replacer]=heap[me];
			heap[me]=temp;

			me=replacer;
		}
	}
}

int main(void)
{
	enheap(1);
	enheap(2);
	enheap(3);
	enheap(4);
	enheap(5);

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", deheap());
	}

	return 0;
}