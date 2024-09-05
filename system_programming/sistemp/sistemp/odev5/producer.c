/*
********************************************************************************
* Producer   process for the producer-consumer task
* Adapted by A.Kostin  from J.S.Gray, Interprocess Communication in UNIX
*
* The proces   needs one parameter - number of messages to be produced
* (not more than MAXMSGS, see the header file common.h) 
* 
*
* File producer.c   Date: Dec  21 2005
********************************************************************************
*/

#include "common.h"

main (int argc, char *argv[])
{
static char *messages[MSGNUMBER] =
       {
       "First message", "Second message", "Third message", "Fourth message",
       "Fifth message", "Sixth message", "Seventh message", "Eighth message",
       "Ninth message", "Tenth message"
       };         
static char local[SLOT_LEN];                /* A local buffer for one message */
static struct MEMORY  *memptr;         /* Pointer to structured shared memory */
char  *shmptr;                       /* Pointer to unstructured shared memory */

int myparid = getppid(); /* ID of the parent process for use as key of shared */
int semid, shmid;      /* Identifiers for semaphore set and for shared memory */
int i, j, sleeptime;                                     /* Working variables */
int maxmsg;                              /* Number of messages to be produced */
int curmsg;                            /* Current number og produced messages */         

printf ("PRODUCER started...\n");
maxmsg = atoi(argv[1]);
srand((unsigned)getpid());                /* Seed for random number generator */

/* Access,  attach  and reference the shared memory created by parent process */
shmid = shmget(myparid, 0, 0);
if (shmid < 0){perror("shmget problem in producer"); exit(1);}
shmptr = shmat(shmid, 0, 0);
if (shmptr == (char *) -1) {perror("shmat problem in producer"); exit(1);}
memptr = (struct MEMORY *) shmptr; /* Get a pointer to structured shar memory */


/* Access the semaphore set created by parent process */
semid = semget(myparid, 2, 0);
if (semid == -1){perror("producer: semget problem"); exit(1);}

/* The main loop of producer: preparing and passing messages in shared memory */
for (curmsg = 0; curmsg < maxmsg; curmsg++)
    {
    memset(local, '\0', sizeof(local));                     /* Clear the local buffer */
    sleeptime = rand() % 6;          /* Sleep time is random, not more than 5 seconds */
    sleep(sleeptime);
    i = curmsg % MSGNUMBER;                                /* Index in array messages */
    strcat(local, messages[i]);      /* Store next message temporarily in array local */
    printf("Message prepared by producer: %s\n", local);

    /* Get a free slot in shared memory */
    acquire.sem_num = AVAIL_SLOTS; 
    j = semop(semid, &acquire, 1);
    if (j == -1) {perror("semop problem 1 in producer"); exit(1);}

    /* Copy the prepared message from array local to buffer in shared memory */
    strcpy(memptr->buffer[memptr->tail], local);
    /* Move index for buffer array in shared memory */   
    memptr->tail = (memptr->tail + 1) % N_SLOTS; 

    /* Now make one more message is available in shared memory for consumer */
    release.sem_num = TO_CONSUME;
    j = semop(semid, &release, 1);
    if (j == -1){perror("semop problem 2 in producer"); exit(1);}
    }
sleep (20); /* A techniqual delay before termination */
printf("\n Producer terminated...\n");
exit(0); 
}
