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
char ch1[10];
char ch2[5];


char parent = 'P';
char child ='C'; 
int pid;
unsigned long i;

if (argc != 4) exit (1);


printf("Parent: creating a child process\n");
pid = fork ();
if ((fdrd = open(argv[1], O_RDONLY)) == -1)exit (1);
if ((fdwt2 = creat(argv[2], 0666)) == -1) exit (1);
if ((fdwt3 = creat(argv[3], 0666)) == -1) exit (1);
if (pid == 0)
   {
   printf("Child process starts, id = %d\n",getpid());
   for(;;)
          {
          
          if (read (fdrd,&ch1, 1) != 1) break;
            read (fdrd,&ch1, 10);
             
             //for (i=0; i<10;i++);   /* Uzun bir döngü */
             
             write (fdwt3, &ch1, 10);
             write(1,&child,1);
          } 
   exit (0);
   }
else 
   {
   printf("Parent starts, id= %d\n", getpid());
    for(;;)
          {
          
          if (read (fdrd, &ch2, 1) != 1) break;
           
            read (fdrd, &ch2, 5);
            
             //for (i=0; i<10;i++);   /* Uzun bir döngü */
             
             write (fdwt2, &ch2, 5);             
             write(1,&parent,1);
          }
   wait (0);
   }
}


