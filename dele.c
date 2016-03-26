#include <stdio.h>
#include <stdlib.h> 

#define N 100 

void quick_sort(int array[],int first,int last); 
void del_same(int n,int array_1[]);
int count=0;

int main(void)
{
	int arr[N];
	int num,i,j;
	int first=0;
	int last;
	scanf("%d",&num);
	last=num-1;
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,first,last);		
	del_same(num,arr);
	
	for(j=num-count-1;j>=0;j--)
	{
		printf("%d ",arr[j]);	
	}
	
	return 0;
}
void quick_sort(int array[],int first,int last)
{
	int key=array[first];
	int temp_last=last;
	int temp_first=first;
	if( first >= last)
		return ;
	while(first < last)
	{
		while(first < last && array[last] <= key)
		{
			--last;
		}
		array[first]=array[last];
		while(first < last && array[first] >=key)
		{
			++first;
		}
		array[last]=array[first];
		
	}	
	array[first]=key;
	quick_sort(array,temp_first,first-1);
	quick_sort(array,first+1,temp_last); 
}
void del_same(int n,int a[])
{
	int i,j;
	int n_temp=n;
	for(i=0;i<n_temp-1;i++)
	{
		if(a[i]==a[i+1])
		{
			for(j=i+1;j<n_temp-1;j++)
			{
				a[j]=a[j+1];
			}	
			n_temp--;
			i--;
			count++;
		}
	} 
}