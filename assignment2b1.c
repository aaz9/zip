#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
 
int main()
{
	int array[10], n, c, d, swap,pid;
	char str[5], *arg[10];
	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter %d integers\n", n);

	for (c = 0; c < n; c++)
	{
		scanf("%d", &array[c]);
	}
	for (c = 0 ; c < ( n - 1 ); c++)
		{
			for (d = 0 ; d < n - c - 1; d++)
			{
				  if (array[d] > array[d+1]) 
				  {
						swap       = array[d];
						array[d]   = array[d+1];
						array[d+1] = swap;
				  }
			}
		}
		printf("Sorted list in ascending order:\n");

	for ( c = 0 ; c < n ; c++ )
		printf("%d\n", array[c]);
	pid = fork();
	if(pid == 0)
	{
		for(c=0;c<n;c++)
		{
			sprintf(str,"%d",array[c]);
			arg[c] = (char*)malloc(sizeof(str));
			strcpy(arg[c],str);
		}
		arg[c] = NULL;
		printf("The sorted array is\n");
		for(c=0;c<n;c++)
		{
			printf("%s\n", arg[c]);
		}
		execve("./child", arg, NULL);
		printf("Sending the sorted list to child process\n");
	}
	else
	{
		wait();
	}
	return 0;
}
