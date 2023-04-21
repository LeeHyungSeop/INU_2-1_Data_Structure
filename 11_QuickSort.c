#include <stdio.h>

void show(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void sort(int arr[], int start, int end, int size)
{
	int pivot = start;
	int low = start + 1;
	int high = end;

	if (start >= end)
		return;

	while (low <= high)
	{
		while (arr[pivot] >= arr[low] && low <= end)
		{
			low++;
		}
		while (arr[pivot] <= arr[high] && high >= start + 1)
		{
			high--;
		}
		if (low <= high)
		{
			swap(arr, low, high);
		}
	}
	swap(arr, pivot, high);

	printf("pivot %d : ",arr[high]);
	show(arr, size);

	sort(arr, start, high - 1, size);
	sort(arr, high + 1, end, size);
}

int main(void)
{
	int arr[] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

	int size = sizeof(arr) / sizeof(arr[0]);

	printf("unsorted : ");
	show(arr, size);

	sort(arr, 0, size - 1,size);
	printf("sorted : ");
	show(arr, size);

	return 0;
}