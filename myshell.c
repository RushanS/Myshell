#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	pid_t pid;

	while(1) {
		char command[100];
		//printf("> ");
		scanf("%s", command);
		if (strcmp(command, "exit") == 0)
			exit(0);
		pid = fork();
		switch(pid)
		{
			case -1:
				perror("fork failed");
				exit(1);
			case 0:
				execlp(command, command, 0);
			default:
				continue;
		}
	}
}
