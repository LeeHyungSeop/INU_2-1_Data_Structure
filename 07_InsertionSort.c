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
	for(i=1;i<size;i++)
	{
		int me=arr[i];
		for (j = i-1; j>=0; j--)
		{
			if(me<arr[j])
			{
				arr[j+1]=arr[j];
			}
			else
				break;
		}
		arr[j+1]=me;
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