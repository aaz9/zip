#include<stdio.h>
#include<unistd.h>

int main( int argc, char* argv[])
{
	int arr[10],i,j, flag=0,first=0,last=argc, mid, find;
	
	printf("argc %d\n", argc);
	printf("The received array is\n");
	for(i=0;i<argc;i++)
	{
		arr[i] = atoi(argv[i]);
	}

	for(i=0;i<argc;i++)
		printf("Element %d: %d \n", (i+1), arr[i]);

	printf("Enter the number to be searched\n");
	scanf("%d", &find);

	//Binary Search
	
	while(first<=last)
	{
		mid = (int)((first+last))/2;
		if(arr[mid] == find)
		{
			flag = 1;
			printf("Element found\n");
			break;
		}
		else if(arr[mid] > find)
		{
			last = mid-1;
		}
		else
		{
			first = mid+1;
		}
	}
	
	if(flag == 0)
		printf("Element not found\n");
		
	return 0;
}

