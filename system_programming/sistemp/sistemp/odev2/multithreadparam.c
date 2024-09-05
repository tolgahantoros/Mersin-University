/********************************************************
 * 
 *
 * A  simple example of using  threads in Linux
 *      
 *   Files: multithread.c, func1.c, func2.c 
 *
 *       A.Kostin    September 15, 2005
 ********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
 
/* Function declarations */
 void func1(void);
 void func2(void); 

int r1 = 0, r2 = 0; /* Global variables, accessible to functions if necessary */

int 
main(void)
{
  pthread_t       td1, td2; /* Descriptors for two child threads */
  int p;
  int j;
  float delta;
  struct timeval time1, time2;


  printf("Multithreaded rocess starts as the main thread here...\n");
   gettimeofday(&time1, 0); /* Starting time */

/* Creation of two child threads */
  p = pthread_create(&td1, 
		 NULL,		 
                 (void *)func1,
		 NULL); 

  if (p != 0) {perror("Thread 1 creation problem"); exit(1);}

  p = pthread_create(&td2,
                 NULL,                 
                 (void *)func2,
                 NULL);
  if (p != 0) {perror("Thread 2 creation problem"); exit(1);} 
          
/* Now the main thread does something */ 
  for (j=1; j<=4; ++j)
    {
    printf("Main thread works: %d\n", j);
    r1++;
    sleep(3); /* Sleep 3 seconds */
    r2++;
    }
   
  
   //pthread_join(td1, NULL); /* Wait  child thread 1 to terminate */
  // pthread_join(td2, NULL); /* Wait child thread 2 to terminate */

/* Determining the total time of running the multithreaded process */
   gettimeofday (&time2, 0);
   delta = (float)((1000000*time2.tv_sec + time2.tv_usec) -
                   (1000000*time1.tv_sec + time1.tv_usec))/1000000;
   printf("Total elapsed time = %f seconds\n", delta);
    printf("r1=%i değerlerine sahip...\n",r1);
    printf("r2=%i değerlerine sahip...\n",r2);
   printf("Main thread terminated...\n");

   return 0; 
}
void func1(void)
{
  int i;
  
  for (i = 1; i <10; ++i)   
    {
    printf("Function func1 prints and then sleeps 4 s: %d\n", i); 
    r1++;
    sleep(4);
    r2++;
    } 
  return;

}

void func2(void)
{ 
  int i;
  
  for (i = 1; i < 8; ++i)   
    {
    printf("Function func2 prints and then sleeps 3 s: %d\n", i); 
    r1++;
    sleep(3);r2++;
    } 
  return;

}



