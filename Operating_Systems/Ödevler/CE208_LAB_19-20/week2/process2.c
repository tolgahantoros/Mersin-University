#include<stdio.h>
#include<unistd.h>

int main(){
	char *env[] = {"/usr/home", NULL};
	execle("/bin/ls", "ls", "-l", NULL, env);
	
}

/*

int execle(const char *path, const char *arg0, ... ,(char *)0, char *const envp[]);

The following example is similar to Using execl(). In addition, it specifies the environment for the new process image using the env argument.

#include <unistd.h>


int ret;
char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
...
ret = execle ("/bin/ls", "ls", "-l", (char *)0, env);
*/
