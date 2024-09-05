#include<stdio.h>
#include<unistd.h>

int main(){
	execl("/bin/ls", "ls", "-l", NULL);
	
}

/*

int execl(const char *path, const char *arg0, ... , (char *)0 );


Using execl()
The following example executes the ls command, specifying the pathname of the executable ( /bin/ls) and using arguments supplied directly to the command to produce single-column output.

#include <unistd.h>


int ret;
...
ret = execl ("/bin/ls", "ls", "-1", (char *)0);
*/
