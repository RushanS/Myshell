#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	pid_t pid;
	char *words[100];
	char str[100];
	char sep[] = " ";
	
	while(1) {
		printf("> ");		
		gets(str);
		
		int mode = 1;
		int i = 0;
		char *ptr = strtok(str, sep);

   		while (ptr != NULL)
		{
			words[i++] = ptr;
			ptr = strtok (NULL, sep);
		}
		
		if (i > 1 && strcmp(words[i-1], "$") == 0) {
			mode = 0;
			words[i-1] = NULL;
		} else words[i] = NULL;
		
		if (strcmp(words[0], "exit") == 0)
			exit(0);
		
		pid = fork();
		switch(pid)
		{
			case -1:
				perror("fork failed");
				exit(1);
			case 0:
				execvp(words[0], words);
			default:
				if (mode)
					wait();
		}
	}
}
