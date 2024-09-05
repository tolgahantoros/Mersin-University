/*
********************************************************************************
* Consumer  process for the producer-consumer task
* Adapted by A.Kostin  from J.S.Gray, Interprocess Communication in UNIX
*
* The proces   needs one parameter - number of messages to be produced
* (not more than MAXMSGS, see the header file common.h) 
* 
*
* File consumer.c   Date: Sept  20 2005
********************************************************************************
*/

#include "common.h"
#define MAXSLEEPTIME 5
main (int argc, char *argv[])
{       
static char local[SLOT_LEN];                /* A local buffer for one message */
static struct MEMORY  *memptr;         /* Pointer to structured shared memory */
char  *shmptr;                       /* Pointer to unstructured shared memory */

int myparid = getppid(); /* ID of the parent process for use as key of shared */
int semid, shmid;      /* Identifiers for semaphore set and for shared memory */
int i, j, sleeptime;                                     /* Working variables */
int maxmsg;                              /* Number of messages to be produced */
int curmsg;                            /* Current number og produced messages */         

printf ("CONSUMER started...\n");
maxmsg = atoi(argv[1]);
srand((unsigned)getpid());                /* Seed for random number generator */

/* Access,  attach  and reference the shared memory created by parent process */
shmid = shmget(myparid, 0, 0);
if (shmid < 0){perror("shmget problem in consumer"); exit(1);}
shmptr = shmat(shmid, 0, 0);
if (shmptr == (char *) -1) {perror("shmat problem in consumer"); exit(1);}
memptr = (struct MEMORY *) shmptr; /* Get a pointer to structured shar memory */


/* Access the semaphore set created by parent process */
semid = semget(myparid, 2, 0);
if (semid == -1){perror("Consumer: semget problem"); exit(1);}

/* The main loop of producer: preparing and passing messages in shared memory */
for (curmsg = 0; curmsg < maxmsg; curmsg++)
    {
    memset(local, '\0', sizeof(local));             /* Clear the local buffer */
    sleeptime = rand() % MAXSLEEPTIME;    /* Random sleep time < MAXSLEEPTIME */ 
    sleep(sleeptime);
 
    /* Get next message from shared memory if available */
    acquire.sem_num = TO_CONSUME; 
    j = semop(semid, &acquire, 1);         /* Wait a message in shared memory */
    if (j == -1) {perror("semop problem 1 in consumer"); exit(1);}

    /* Copy a message from shared memory to array local */
    strcpy(local, memptr->buffer[memptr->head]);
    /* Move index for buffer array in shared memory */   
    memptr->head = (memptr->head + 1) % N_SLOTS; 

    /* Now make one more slot empty in shared memory for producer */
    release.sem_num = AVAIL_SLOTS;
    j = semop(semid, &release, 1);       /* A new empty slot is available now */
    if (j == -1){perror("semop problem 2 in consumer"); exit(1);}
    printf
   ("..........................................Consumer received: %s\n", local);
    }

printf("\n Consumer terminated...\n");
exit(0); 
}
