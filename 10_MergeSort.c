#include <stdio.h>
#include <stdlib.h>

void show(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void merge(int arr[], int copy[], int start, int mid, int end)
{
	int lidx=start;
	int lstart=start;
	int lend=mid;
	int ridx=mid+1;
	int rstart=mid+1;
	int rend=end;
	int c=start;

	while(1)
	{
		if(lidx>lend && ridx>rend)
		{
			break;
		}
		if(lidx>lend)
		{
			copy[c++]=arr[ridx++];
		}
		else if(ridx>rend)
		{
			copy[c++]=arr[lidx++];
		}
		else{
			if(arr[lidx]<arr[ridx])
			{
				copy[c++]=arr[lidx++];
			}
			else
			
			copy[c++]=arr[ridx++];
		}
	}
	for (int i = start; i <= end; i++)
	{
		arr[i]=copy[i];
	}
	
}

void sort(int arr[], int copy[], int start, int end)
{
	if (start == end)
		return;

	sort(arr, copy, start, (start + end) / 2);
	sort(arr, copy, (start + end) / 2 +1 , end);

	merge(arr, copy, start, (start + end) / 2, end);
}

int main(void)
{
	int arr[] = { 5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int* copy = (int*)malloc(sizeof(int) * size);

	sort(arr, copy, 0, size - 1);
	show(arr, size);

	return 0;
}