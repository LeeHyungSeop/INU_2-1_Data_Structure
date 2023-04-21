#include <stdio.h>

void show(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}

void sort(int arr[],int size)
{
	int i,j;

	for(i=0;i<size-1;i++)
	{
		int least=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[j]<arr[least])
			{
				least=j;
			}
		}
		int temp=arr[least];
		arr[least]=arr[i];
		arr[i]=temp;
	}
}

int main(void)
{
	int arr[] = { 5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	sort(arr, size);
	show(arr, size);

	return 0;
}