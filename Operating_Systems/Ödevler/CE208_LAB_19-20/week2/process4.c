#include<stdio.h>
#include<unistd.h>

int main(){
	char *cmd[] = {"ls", "-l", NULL};
	execv("/bin/ls", cmd);
	
}

/*
int execv(const char *path, char *const argv[]);

The following example passes arguments to the ls command in the cmd array.

#include <unistd.h>


int ret;
char *cmd[] = { "ls", "-l", (char *)0 };
...
ret = execv ("/bin/ls", cmd);

*/
