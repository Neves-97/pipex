#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <unistd.h>
#include <errno.h>

int main(int ac, char *av[], char *envp[])
{
	char *arr[] = {"ping", "googewle.com", NULL};
	
	char *env[] = {"TEST=environment variable", NULL};
	
	execvpe("ping", arr, env);

	int err = errno;
	
	printf("Ping finished executing\n");
	return 0;
}