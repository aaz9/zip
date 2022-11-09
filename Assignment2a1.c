/*Assignment No. 2: Process control system calls: The demonstration of FORK, EXECVE and WAIT system calls
along with zombie and orphan states.
a. Implement the C program in which main program accepts the integers to be sorted. Main
program uses the FORK system call to create a new process called a child process. Parent process
sorts the integers using sorting algorithm and waits for child process using WAIT system call to
sort the integers using any sorting algorithm. Also demonstrate zombie and orphan states.*/
#include<stdio.h>
void quicksort_rec(int a[],int left ,int right );
int partition(int a[], int left ,int right);
void bubblesort(int a[],int n);
int main()
{	
	int ans;
	
		int a[20],ch,n,i,left,right;
		printf("Enter the number of elements in the array:");
		scanf("%d",&n);
		printf("\nEnter the array elements:");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		do
		{
		printf("ENTER YOUR CHOICE:\n1.QUICK SORT(ASCENDING ORDER) \n2.BUBBLE SORT(DESCENDING ORDER)\n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:left=0;
				right=n-1;
				quicksort_rec(a,left,right); 
				for(i=0;i<n;i++)
				{
					printf("%d\t",a[i]);
				}
				break;
			case 2:bubblesort(a,n);
				for(i=0;i<n;i++)
				{
					printf("%d\t",a[i]);
				}
				break;
			default: printf("INVALID CHOICE!");
		}
		printf("\nENTER 1 TO CONTINUE:");
		scanf("%d",&ans);
	}while(ans==1);
}
void quicksort_rec(int a[],int left ,int right)
{
	int j;
 	if(left >right)
        	return;
   	j=partition(a, left ,right);
 	quicksort_rec(a, left,j-1);   
 	quicksort_rec(a, j+1,right);
}
int partition(int a[], int left ,int right)
{
 	int i,j,temp,v,pivot;
 	 pivot=a[left];  
	i=left;   
	j=right+1;
 	do
        {
       		do
      		{
        		i++;
       	       	}while(a[i]<pivot);
       		do 
       		{  
			j--; 
        	}while(a[j]>pivot);
       		if(i<j)
		{
		    	temp=a[i];
		    	a[i]=a[j];
		    	a[j]=temp;
		}
     }while(i<j);
 	a[left]=a[j];
 	a[j]=pivot;
	printf("Partition position is %d\n", j);
  	return(j);
}

void bubblesort(int a[],int n)
{	
	int i,j;
	int temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		
	}
}
