/************************** Important header files **************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

/******************************** Main Function ******************************/

int main()
{
	system("clear"); 
	char str[100];
	system("tput setaf 2");
	int n;    		
	/** Asking user for entering count of characters of his string **/ 
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Please enter length of Characters of Your String :");
	scanf("%d", &n);
 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 4");
	printf("Enter your String :");
	int i=0;

	/** Logic behind the taking only specific count of no. that user 		    entered **/
	while(i<n)
	{
	scanf("%c",&str[i]);
	i++;
	}
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");	

	/** Writing the string using system call **/
	int fd[2];	
	write(fd[1],str,strlen(str));
	
	
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 3");

	/** Getting process id for writing into PIPE **/
	printf("PID for Writing in Pipe is %d- \n",getpid());
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	int y=strlen(str); /** strlen() for finding count of string **/
	
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 5");
	printf("We have Written in pipe :%s",str);	
	system("tput setaf 7");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");


	/** Logic for converting lowercase into uppercase and vice verssa **/

	for(i=0;i<strlen(str);i++)
		{

		/** Converting into ASCII value and checking if it is lower 			    case than add 32 and covert it into uppercase or if it is 			    uppercase substract 32 and make it into lower case **/
		
		if((int)str[i]>=65 && (int)str[i]<=90)
			{
				str[i]=(int)str[i]+32;
			
  			}
		else if((int)str[i]>=97 && (int)str[i]<=122)
			{
				str[i]=(int)str[i]-32;
			
			}
		}
	
	close(fd[0]); /** Closing filedescripter **/
	read(fd[0],str,strlen(str));

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	system("tput setaf 6");
	
	/** Showing process used for reading **/
	printf("\nPid for reading from Pipe is %d \n",getpid());
	system("tput setaf 6");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	
	/** Converting the LowerCase into UpperCase and vice versa and 		    printing **/

	system("tput setaf 3");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Reading from the file  :%s",str);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("tput setaf 7");
	
}
