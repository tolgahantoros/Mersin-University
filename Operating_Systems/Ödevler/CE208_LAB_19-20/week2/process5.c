#include<stdio.h>
#include<unistd.h>

int main(){
	char *env[] = {"/usr/home/", NULL};
	char *cmd[] = {"mkdir", "newDir", NULL};
	execve("/bin/mkdir", cmd, env);
	
}

/*
parametre dizisini ortam de�i�ken� kullanarak arar

int execve(const char *path, char *const argv[], char *const envp[]);

The following example passes arguments to the ls command in the cmd array, and specifies the environment for the new process image using the env argument.

#include <unistd.h>


int ret;
char *cmd[] = { "ls", "-l", (char *)0 };
char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
...
ret = execve ("/bin/ls", cmd, env);


*/
