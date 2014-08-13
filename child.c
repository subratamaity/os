#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void)
{
	int i,pid[11],p=0;
	for(i=0;i<=10;i++)
	{
		pid[i]=fork();
		if(pid[i]<0)
		{
			printf("Error\n");
			return 0;
		}
		else if(pid[i]==0)
		{
			printf("Child process no.%d\n",i);
			printf("pid is %d\n",getpid());
			printf("ppid is %d\n",getppid());
			return 0;
		}
		wait(&p);
	}
	printf("Parent process\n");
	printf("pid is %d\n",getpid());
	return 0;
}
