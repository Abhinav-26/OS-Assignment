#include<stdio.h>
#include<pthread.h>
int arr[50],n,i;

void *th()
{
	int sum=0;
	float average;
	printf("Please Enter Count of Numbers :");
	scanf("%d",&n);
	printf("Enter your Numbers :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
		{
			sum=sum+arr[i];
		}
	average=sum/n;
	printf("The average value is:%f",average);
}
void *th1()
{


	int temp=arr[0];
	for(int i=1;i<n;i++)
		{
			if(temp>arr[i])
			{
			temp=arr[i];
			}
		}
	printf("\nThe Minimum  value is:=%d",temp);

}
void *th2()
{

	int temp=arr[0];
	for(int i=1;i<n;i++)
		{
			if(temp<arr[i])
			{
			temp=arr[i];
			}
		}
	printf("\nThe Maximum  value is:=%d",temp);
	}
int main()
{
int n,i;
pthread_t t1;
pthread_t t2;
pthread_t t3;
	n=pthread_create(&t1,NULL,&th,NULL);
	pthread_join(t1,NULL);
	//printf("\n done and my value is %d",n);
	n=pthread_create(&t2,NULL,&th1,NULL);
        pthread_join(t2,NULL);
	//printf("\n done and my value is %d",n);
	n=pthread_create(&t3,NULL,&th2,NULL);
        pthread_join(t3,NULL);
	//printf("\n done and my value is %d",n);

}
