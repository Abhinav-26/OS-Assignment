#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	system("clear");
	char str[100];
	system("tput setaf 2");
	int n;    		 
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Please enter length of Characters of Your String :");
	scanf("%d", &n);
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 4");
	printf("Enter your String :");
	int i=0;

	while(i<n)
	{
	scanf("%c",&str[i]);
	i++;
	}
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");	

	int fd[2];	
	write(fd[1],str,strlen(str));
	
	
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 3");
	printf("PID for Writing in Pipe is %d- \n",getpid());
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	int y=strlen(str);
	
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 5");
	printf("We have Written in pipe :%s",str);	
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	for(i=0;i<strlen(str);i++)
		{
		if((int)str[i]>=65 && (int)str[i]<=90)
			{
				str[i]=(int)str[i]+32;
			
			}
		else if((int)str[i]>=97 && (int)str[i]<=122)
			{
				str[i]=(int)str[i]-32;
			
			}
		}
	close(fd[0]);
	read(fd[0],str,strlen(str));

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	system("tput setaf 6");
	printf("\nPid for reading from Pipe is %d \n",getpid());
	system("tput setaf 6");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	system("tput setaf 3");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Reading from the file  :%s",str);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 7");
	
}
