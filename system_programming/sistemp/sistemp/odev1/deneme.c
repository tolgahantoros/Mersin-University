/*
 * Kullanim: program_adi kaynak_dosya_adi hedef_dosya_adi
 * ornegin: paralel_yazma dosya1.txt dosya2.txt dosya3.txt:wq
 */
  
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main (argc,argv)
int argc;
char  *argv[];

{
int fdrd,fdwt2,fdwt3;
char *c[10];
char *cc[20];

char parent = 'P';
char child ='C'; 
int pid;
unsigned long i;

if (argc != 4) exit (1);

if ((fdrd = open(argv[1], O_RDONLY)) == -1) {exit (1); }

printf("Parent: creating a child process\n");

   for(;;)
          {
          
          if (read (fdrd, &c, 1) != 1) break;
            printf(read (&c);     
         
          //write(1,&child,1);
          //write (fdwt3, *c, 10);
         
          
          } 
 
          
  
}


