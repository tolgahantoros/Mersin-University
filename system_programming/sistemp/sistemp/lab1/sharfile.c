/*
 * Kullanim: program_adi kaynak_dosya_adi hedef_dosya_adi
 * ornegin: sharfile a.txt b.txt:wq
*/
  
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (argc,argv)
int argc;
char  *argv[];

main(void)
{

float delta;
float timeval time1, time2;
int fdrd,fdwt;
char c;
char parent = 'P';
char child ='C'; 
int pid;
unsigned long i;

if (argc != 3) exit (1);

if ((fdrd = open(argv[1], O_RDONLY)) == -1) {perror ("Hata: Dosya Acilamadi");exit (1); }
if ((fdwt = creat(argv[2], 0666)) == -1) exit (1);
printf("Parent: creating a child process\n ",gettimeofday(&time1,0));

pid = fork ();
if (pid == 0)
   {
   printf("Child process starts, id = %d\n",getpid());
   for (;;)
          {
       
        
          if (read (fdrd, &c, 1) != 1)break;
         
         for (i=0; i<200000;i++);   /* Uzun bir döngü */
          write(1,&child,1);
          write (fdwt, &c, 1);
         
          
          } 
   exit (0);
   }



}


