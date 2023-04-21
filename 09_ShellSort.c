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
	int i,j,k,gap;

	for(gap=size/2;gap>0;gap/=2)
	{
		for(i=0;i<gap;i++)
		{
			for(j=i+gap;j<size;j+=gap)	// 여기서부터 for문은 Insertion Sort와 똑같다. gap에 해당하는 인덱스만 
			{
				int me=arr[j];
				for(k=j-gap;k>=0;k-=gap)
				{
					if(me<arr[k])
					{
						arr[k+gap]=arr[k];
					}
					else
						break;
				}
				arr[k+gap]=me;
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