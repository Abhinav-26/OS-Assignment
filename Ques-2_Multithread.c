/************************** Important header files **************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int arr[50],n,i;  /**Declaring Global Variables**/

/** Thread1 Function for Average Computation **/
void *Avg_thread()
{
	int sum=0;
	float average;
	system("tput setaf 6");
	/** For taking the size of array **/
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Please Enter Count of Numbers :");
	scanf("%d",&n);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	/** Taking user inputs as for size given **/
	
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Enter %d Numbers of Your Choice :\n",n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	/** Adding all the numbers present in array **/
	for(i=0;i<n;i++)
		{
			sum=sum+arr[i];
		}
	/** Finding the avg of the numbers **/
	average=sum/n;

	system("tput setaf 4");
	printf("============\n");
	printf(" OUTPUT IS :\n");
	printf("============\n");
	
	system("tput setaf 3");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("-> THE AVERAGE VALUE IS %f",average);
}

/** Thread2 for Finding Minimum Value **/
void *Min_thread()
{
	int temp=arr[0];
	for(int i=1;i<n;i++)
	/** Logic for min. value **/
		{
			/** Checking for every value in array and storing in Temp variable. If value of temp > arr[index] then	  
			replacing the value of temp var. by the smaller value present in array index ie, arr[i] **/

			if(temp>arr[i])
			{
			temp=arr[i];
			}
		}

	printf("\n-> THE MINIMUM VALUE IS %d",temp);

}

/** Thread3 for Finding Maximum Value **/
void *Max_thread()
{

	int temp=arr[0];
	for(int i=1;i<n;i++)
		{
			/** The logic is same as that for min. value. Just we modified ie, now we are checing for max. values 
			and if value in arr[i] > temp, assigning that value to variable temp **/

			if(temp<arr[i])
			{
			temp=arr[i];
			}
		}
	printf("\n-> THE MAXIMUM  VALUE IS %d \n",temp);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	system("tput setaf 7");
}

/******************************** Main Function ******************************/

int main()
{
int n,i;

pthread_t t1;
pthread_t t2;
pthread_t t3;
	system("clear");
	n=pthread_create(&t1,NULL,&Avg_thread,NULL);
	pthread_join(t1,NULL);
	
	n=pthread_create(&t2,NULL,&Min_thread,NULL);
        pthread_join(t2,NULL);

	n=pthread_create(&t3,NULL,&Max_thread,NULL);
        pthread_join(t3,NULL);


}
