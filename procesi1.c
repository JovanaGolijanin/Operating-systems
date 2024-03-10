#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid;
	pid = fork();
	if (pid !=0)
	{
		printf("parent \n");
		printf("child pid = %d \n",pid);
	}
	else
	{
		sleep(4);
		printf("child\n");
		printf("parent id %d\n",getppid());
	}
	printf("exit %d\n",getpid());
	return 0;
}