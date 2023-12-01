#include <stdio.h>
#include <unistd.h>

int main()
{
	int i=0;
	for(;;)
	{
		fprintf(stderr,"Demo service running %d\n",i);
		i++;
		sleep(10);	
	}
}

