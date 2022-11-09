#include<stdio.h>
#include<math.h>
int a[20][20],b[20][20],p[20][20],flag=0;;
int r1=0,c1=0,r2=0,c2=0;
void mult(int i);
void print();
void main(){	
	int i,j;	
	printf("Enter no of rows and columns for matrix A\n");
	scanf("%d%d",&r1,&c1);
	printf("Enter the matrix A\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter no of rows and columns for matrix B\n");
	scanf("%d%d",&r2,&c2);
	printf("Enter the matrix B\n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	printf("\n");
	if(c1==r2){
		for(i=0;i<r1;i++){
			mult(i);
		}
	}
	else
		printf("Error!!");
	print();
}
void mult(int i){
	int j,k;
	printf("\n*************\n");
	printf("Row calculated is :: %d \n",i+1);	
	for(j=0;j<c1;j++){
		p[i][j]=0;
		for(k=0;k<c1;k++){
			p[i][j]=p[i][j]+a[i][k]*b[k][j];
		}
	}
	for(j=0;j<c1;j++){
		printf("%d\t",p[i][j]);
	}
	printf("\n*************\n");
}
void print(){
	int i,j;
		printf("The final matrix is ::\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
}
