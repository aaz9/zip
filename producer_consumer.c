#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int buffer[10],size=10,index1=0;
sem_t full,empty;
pthread_t tidp[10],tidc[10];
pthread_mutex_t lock;
void insertin(int a);
void removefrom();

void *producer(){
	int item=rand()%100;
	sem_wait(&full);
	pthread_mutex_lock(&lock);
	insertin(item);
	pthread_mutex_unlock(&lock);
	sem_post(&empty);
}

void *consumer(){
	sem_wait(&empty);
	pthread_mutex_lock(&lock);
	removefrom();
	pthread_mutex_unlock(&lock);
	sem_post(&full);
}
void insertin(int a){
	int item=a;
	if(index1<size){
		buffer[index1]=item;
		index1++;
		printf("Producer produced number :: %d\n",item);
	}
	else{
		printf("BUFFER FULL!!!");
	}	
}

void removefrom(){
	if(index1>0){
		index1--;
		printf("Item consumed by consumer is :: %d\n",buffer[index1]);
	}
	else{
		printf("BUFFER EMPTY!!!");
	}
}

void main(){
	int i;
	sem_init(&full,1,size);
	sem_init(&empty,1,0);
	pthread_mutex_init(&lock,NULL);
	
	for(i=0;i<size;i++){
		pthread_create(&tidc[i],NULL,consumer,NULL);
		pthread_create(&tidp[i],NULL,producer,NULL);
	}
	for(i=0;i<size;i++){
		pthread_join(tidc[i],NULL);
		pthread_join(tidp[i],NULL);
	}
}
/*
info-51@info51-ThinkCentre-M72e:~/Desktop$ gcc ass4.c -l pthread
ass4.c: In function ‘producer’:
ass4.c:13:11: warning: implicit declaration of function ‘rand’ [-Wimplicit-function-declaration]
  int item=rand()%100;
           ^
info-51@info51-ThinkCentre-M72e:~/Desktop$ ./a.out
Producer produced number :: 83
Producer produced number :: 86
Item consumed by consumer is :: 86
Item consumed by consumer is :: 83
Producer produced number :: 77
Item consumed by consumer is :: 77
Producer produced number :: 15
Item consumed by consumer is :: 15
Producer produced number :: 93
Item consumed by consumer is :: 93
Producer produced number :: 35
Item consumed by consumer is :: 35
Producer produced number :: 86
Item consumed by consumer is :: 86
Producer produced number :: 92
Producer produced number :: 49
Item consumed by consumer is :: 49
Item consumed by consumer is :: 92
Producer produced number :: 21
Item consumed by consumer is :: 21
*/
