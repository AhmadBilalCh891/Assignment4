#include<stdio.h>
#include<pthread.h>
#define max 1000
#define max_thread 10
int arry[1000];
int count_threads=0;
void *sum_array(void *arg)
{
	int i,thread_part =count_threads++;
	int sum=0;
	for(i=thread_part*(max/10);i<(thread_part+1)*(max/10);i++)
	{
		sum +=arry[i];
	}
	return sum;
}
int main()
{
	int i,*p;
	for(i=0;i<1000;i++)
	{
		arry[i]=i;
	}
	pthread_t threads[max_thread];
	
	for(i=0;i<max_thread;i++)
	{
		pthread_create(&threads[i],NULL,sum_array,NULL);
	}
	int total_sum=0;
	for(i=0;i<max_thread;i++)
	{
		pthread_join(threads[i],(void*)p);
		total_sum+=(*p);
	}
	printf("Sum is %d",total_sum);
}
