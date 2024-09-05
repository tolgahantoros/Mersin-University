 
/* A client using the FIFO pipes */
/* Usage: client pipe1 pipe2 */
/* Dec. 24, 1999 */

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
  
 int main(argc,argv)
 int argc;
 char *argv[];

{ 
int fd1,fd2,n1,n2;
char buf1[1024];
char buf2[21];

if(argc<3) { printf("USAGE: client pipename1 pipename2");
               exit(1); }
 
printf("CLIENT STARTED...\n");
 
if((fd1=open(argv[1],O_WRONLY))<0) 
  {perror("OPEN ERROR FOR FIRST PIPE"); exit(1);}
printf("A PIPE IS OPENED FOR WRITING\n");
 /*while((n1=read(0,buf1,sizeof(buf1)))>0)*/
  
write(fd1,"THIS IS A REQUEST FROM CLIENT\n", 30);
close (fd1);

printf("A REQUEST IS SENT TO SERVER...\n");

if((fd2=open(argv[2],O_RDONLY))<0) 
  {perror("OPEN ERROR FOR SECOND PIPE"); exit(1);} 
 
while((n2=read(fd2,buf2,sizeof(buf2)))>0)
      write(1,buf2,n2); 
close(fd2);
printf("CLIENT TERMINATED...\n");
 
return 0;
}  
