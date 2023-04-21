#include <stdio.h>

void show(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void sort(int arr[], int size)
{
	int i,j;

	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
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