# include <stdio.h>
# include <pthread.h>
#define num 1000

void * thread_sum(void*);
void *Create(void*);
int TotalSum=0;
int part=0;

pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{
    pthread_t parent;
    pthread_create (&parent,NULL,Create,NULL);
    pthread_join(parent,NULL);
    printf("Sum is %d ",TotalSum);
}
void *thread_sum(void * no)
{
    int p=part++;
    int  *iNumber=(int*)no;
    for(int i=p*(num/10);i<(p+1)*(num/10);i++)
    {
        pthread_mutex_lock(&mVar);
        TotalSum=TotalSum + i;
        pthread_mutex_unlock(&mVar);
    }
      pthread_exit(NULL);
}
void *Create(void *n)
{
     int Num;
    pthread_t childTreads[10];
    for(int i=0;i<10;i++)
    {
        Num=i*100;
        pthread_create(&childTreads[i],NULL,thread_sum,(void *)&Num);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(childTreads[i],NULL);
    }
}
