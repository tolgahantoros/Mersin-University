#include<stdio.h>
#include<unistd.h>

int main(){

	execlp("ls", "ls", "-l", NULL);
}

/*

int execlp(const char *file, const char *arg0, ... , (char *)0 );

The following example searches for the location of the ls command among the directories 
specified by the PATH environment variable.

#include <unistd.h>


int ret;
...
ret = execlp ("ls", "ls", "-l", (char *)0);
*/
