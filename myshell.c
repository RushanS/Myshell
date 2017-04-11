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
		printf("> ");
		scanf("%s", command);
		if (strcmp(command, "exit") == 0)
			break;
		pid = fork();
		switch(pid)
		{
			case -1:
				perror("fork failed");
				exit(1);
			case 0:
				execlp(command, command, 0);
			default:
				;
		}
		if (command[strlen(command) - 1] == '$' && pid != 0) {
			int stat_val;
			pid_t child_pid;
			
			child_pid = wait(&stat_val);
		}
	}
}
