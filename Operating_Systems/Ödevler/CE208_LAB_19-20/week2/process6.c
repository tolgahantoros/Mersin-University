#include<stdio.h>
#include<unistd.h>

int main(){

	char *cmd[] = {"ls", "-l", NULL};
	execvp("ls", cmd);
}

/*

int execvp(const char *file, char *const argv[]);

The following example searches for the location of the ls command among the directories specified by the PATH environment variable, and passes arguments to the ls command in the cmd array.

#include <unistd.h>


int ret;
char *cmd[] = { "ls", "-l", (char *)0 };
...
ret = execvp ("ls", cmd);

*/
