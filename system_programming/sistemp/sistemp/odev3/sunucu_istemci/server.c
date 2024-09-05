/* A server using FIFO pipes */
/* Usage: server pipe1 pipe2 & */
/* It works only in background, even with two
   terminals */
/* Dec. 24, 1999 */

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

  int main(argc,argv)
 
  int argc; 
  char *argv[];

{ 
int fd1,fd11, fd2, fd22, n1,n2;
char buf1[1024];
char buf2[21];

if(argc<3) 
  { printf("usage: server pipename1 pipename2 &");
               exit(1); } 
printf("SERVER STARTS...\n"); 

/* Remove previously created pipes if any */
unlink(argv[1]); 
unlink(argv[2]); 

/* Create two pipes */
if(mkfifo(argv[1],0666)<0) 
  {perror("MKFIFO ERROR FOR FIRST PIPE"); exit(1);}
printf("FIRST PIPE IS CREATED\n");
  
if(mkfifo(argv[2],0666)<0)  
  {perror("MKFIFO ERROR FOR SECOND PIPE"); exit(1);} 
printf("SECOND PIPE IS CREATED\n"); 

/* Make sure that created pipes have the desired permissions */
if(chmod(argv[1],0666)<0) 
  {perror("CHMOD ERROR FOR FIRST PIPE"); exit(1);}
if(chmod(argv[2],0666)<0) 
  {perror("CHMOD ERROR FOR SECOND PIPE NAME"); exit(1);}

/* Working with the first pipe */
printf("TRYING TO OPEN THE FIRST PIPE...\n");
if(fd1=open(argv[1],O_RDONLY)<0) /* O_RDONLY !!! */ 
  {perror("OPEN ERROR FOR FIRST PIPE"); exit(1);}
printf("THE FIRST PIPE IS OPENED FOR READING\n"); 
  
printf("TRYING TO READ A REQUEST FROM CLIENT...\n"); 
 
while(n1=read(fd1,buf1,sizeof(buf1))>0) 
write(1,buf1,n1);
close (fd1);
printf("A REQUEST IS RECEIVED FROM CLIENT...\n");

printf("\nTRYING TO OPEN THE SECOND PIPE...\n");
/* Working with the second pipe */
if(fd2=open(argv[2],O_WRONLY)<0) 
  {perror("OPEN ERROR FOR SECOND PIPE"); exit(1);} 
printf("SECOND PIPE IS OPENED FOR WRITING\n"); 
 
write(fd2,"THIS IS A REPLY FROM SERVER\n",28);
printf("A REPLY MESSAGE SENT TO CLIENT\n");  
close(fd2); 

printf("SERVER TERMINATED...\n");
exit(0);

 }
