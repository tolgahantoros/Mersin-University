
/* Program to check identifiers of  processes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main ()
{  
int i = 0;   
pid_t pid, parent, child, myparent;
pid = fork(); /* Parent creates a child process */

if (pid == 0) {/* Statements for the child process only */
               child = getpid(); i = 2;
               printf("Child: my ID = %d, i = %d\n", child, i);
               myparent = getppid();
               printf("Child: my parent ID = %d\n", myparent);
               sleep(10); /* Child sleeps for 10 seconds */
               child = getpid();
               printf("\nChild after sleeping: my ID = %d\n", child);
               myparent = getppid();
               printf ("Child after sleeping: my parent ID = %d\n",
               myparent); 
               execl("simple", "simple",0);} /* Swith to simple */

/* All the statements below are for the parent process only */
/* Depending on the argument of sleep(), the parent process
   can terminate BEFORE or AFTER its child process */

else {     
     sleep(3); 
     parent = getpid(); 
     printf ("Parent: my ID = %d, i = %d\n",  parent, i);
     printf ("Parent: terminating...\n");
     }
} 
