#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// zadaci od 4-7

int main (int argc, char* argv[])
{
	int i=0;
	for(i;i<argc;i++)
	{
		printf("argumenti su %s\n",argv[i]);
	}
	return 0;
}