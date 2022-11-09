#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
 
#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N
  
 
sem_t room;
sem_t chopst[N];
 
void * philospher(void *num);
void take_chopst(int);
void put_chopst(int);
void test(int);
//int try;
int state[N];
int phil_num[N]={0,1,2,3,4};
 
int main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&room,0,1);
    for(i=0;i<N;i++)
        sem_init(&chopst[i],0,0);


    for(i=0;i<N;i++)
    {
        pthread_create(&thread_id[i],NULL,philospher,&phil_num[i]);
        printf("Philosopher %d is thinking\n",i+1);
    }
    for(i=0;i<N;i++)
        pthread_join(thread_id[i],NULL);


//for(try=0;try<N;try++)
sem_destroy(&chopst[N]);
sem_destroy(&room);
pthread_exit(0);
}
 
void *philospher(void *num)
{int x=1;
    while(x<5)
    {
        int *i = num;
        usleep(1);
        take_chopst(*i);
        usleep(1);
        put_chopst(*i);
x++;
    }
}
 
void take_chopst(int ph_num)
{
    sem_wait(&room);
    state[ph_num] = HUNGRY;
    printf("Philosopher %d is Hungry\n",ph_num+1);
    test(ph_num);
    sem_post(&room);
    sem_wait(&chopst[ph_num]);
    usleep(1);
}
 
void test(int ph_num)
{
    if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[ph_num] = EATING;
        usleep(1);
        printf("Philosopher %d takes left chopst  %d and right chopstick %d\n",ph_num+1,LEFT+1,ph_num+1);
        printf("Philosopher %d is Eating\n",ph_num+1);
        sem_post(&chopst[ph_num]);
    }
}
 
void put_chopst(int ph_num)
{
    sem_wait(&room);
    state[ph_num] = THINKING;
    printf("Philosopher %d putting chopst %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);
    printf("Philosopher %d is thinking\n",ph_num+1);
    test(LEFT);
    test(RIGHT);
    sem_post(&room);
}






/*info41@info41:~/Desktop$ gcc diningphilo.c -lpthread
info41@info41:~/Desktop$ ./a.out
Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 3 is thinking
Philosopher 4 is thinking
Philosopher 5 is thinking
Philosopher 1 is Hungry
Philosopher 1 takes left chopst  5 and right chopstick 1
Philosopher 1 is Eating
Philosopher 5 is Hungry
Philosopher 4 is Hungry
Philosopher 4 takes left chopst  3 and right chopstick 4
Philosopher 4 is Eating
Philosopher 3 is Hungry
Philosopher 2 is Hungry
Philosopher 1 putting chopst 5 and 1 down
Philosopher 1 is thinking
Philosopher 2 takes left chopst  1 and right chopstick 2
Philosopher 2 is Eating
Philosopher 4 putting chopst 3 and 4 down
Philosopher 4 is thinking
Philosopher 5 takes left chopst  4 and right chopstick 5
Philosopher 5 is Eating
Philosopher 1 is Hungry
Philosopher 4 is Hungry
Philosopher 2 putting chopst 1 and 2 down
Philosopher 2 is thinking
Philosopher 3 takes left chopst  2 and right chopstick 3
Philosopher 3 is Eating
Philosopher 5 putting chopst 4 and 5 down
Philosopher 5 is thinking
Philosopher 1 takes left chopst  5 and right chopstick 1
Philosopher 1 is Eating
Philosopher 2 is Hungry
Philosopher 5 is Hungry
Philosopher 3 putting chopst 2 and 3 down
Philosopher 3 is thinking
Philosopher 4 takes left chopst  3 and right chopstick 4
Philosopher 4 is Eating
Philosopher 1 putting chopst 5 and 1 down
Philosopher 1 is thinking
Philosopher 2 takes left chopst  1 and right chopstick 2
Philosopher 2 is Eating
Philosopher 4 putting chopst 3 and 4 down
Philosopher 4 is thinking
Philosopher 5 takes left chopst  4 and right chopstick 5
Philosopher 5 is Eating
Philosopher 3 is Hungry
Philosopher 4 is Hungry
Philosopher 1 is Hungry
Philosopher 2 putting chopst 1 and 2 down
Philosopher 2 is thinking
Philosopher 3 takes left chopst  2 and right chopstick 3
Philosopher 3 is Eating
Philosopher 5 putting chopst 4 and 5 down
Philosopher 5 is thinking
Philosopher 1 takes left chopst  5 and right chopstick 1
Philosopher 1 is Eating
Philosopher 2 is Hungry
Philosopher 5 is Hungry
Philosopher 3 putting chopst 2 and 3 down
Philosopher 3 is thinking
Philosopher 4 takes left chopst  3 and right chopstick 4
Philosopher 4 is Eating
Philosopher 1 putting chopst 5 and 1 down
Philosopher 1 is thinking
Philosopher 2 takes left chopst  1 and right chopstick 2
Philosopher 2 is Eating
Philosopher 4 putting chopst 3 and 4 down
Philosopher 4 is thinking
Philosopher 5 takes left chopst  4 and right chopstick 5
Philosopher 5 is Eating
Philosopher 2 putting chopst 1 and 2 down
Philosopher 2 is thinking
Philosopher 1 is Hungry
Philosopher 3 is Hungry
Philosopher 3 takes left chopst  2 and right chopstick 3
Philosopher 3 is Eating
Philosopher 4 is Hungry
Philosopher 5 putting chopst 4 and 5 down
Philosopher 5 is thinking
Philosopher 1 takes left chopst  5 and right chopstick 1
Philosopher 1 is Eating
Philosopher 2 is Hungry
Philosopher 5 is Hungry
Philosopher 3 putting chopst 2 and 3 down
Philosopher 3 is thinking
Philosopher 4 takes left chopst  3 and right chopstick 4
Philosopher 4 is Eating
Philosopher 1 putting chopst 5 and 1 down
Philosopher 1 is thinking
Philosopher 2 takes left chopst  1 and right chopstick 2
Philosopher 2 is Eating
Philosopher 4 putting chopst 3 and 4 down
Philosopher 4 is thinking
Philosopher 5 takes left chopst  4 and right chopstick 5
Philosopher 5 is Eating
Philosopher 2 putting chopst 1 and 2 down
Philosopher 2 is thinking
Philosopher 3 is Hungry
Philosopher 3 takes left chopst  2 and right chopstick 3
Philosopher 3 is Eating
Philosopher 5 putting chopst 4 and 5 down
Philosopher 5 is thinking
Philosopher 3 putting chopst 2 and 3 down
Philosopher 3 is thinking
info41@info41:~/Desktop$ 
*/

