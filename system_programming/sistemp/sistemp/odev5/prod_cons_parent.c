/*
********************************************************************************
* Parent process for the producer-consumer task
* Adapted by A.Kostin from J.S.Gray, Interprocess Communication in UNIX
*
* The process needs one parameter - number of messages to be produced
* and consumed (not more than MAXMSGS, see common.h) 
* 
*
* File cons_prod_parent.c   Date: Sept 20 2005
********************************************************************************
*/

#include "common.h"

main (int argc, char *argv[])
{
static struct MEMORY sharmemory;   /* Shared memory for producer and consumer */
static ushort init_val[2] = {N_SLOTS, 0}; /* Initial values of two semaphores */
int semid, shmid;      /* Identifiers for semaphore set and for shared memory */
int child;                                                /* Working variable */
char *shmptr;                                     /* Pointer to shared memory */
int prod_id, cons_id, parent_id;                  /* Identifiers of processes */
union semun arguments;         /* Arguments to set init values for semaphores */

printf ("Parent process starting...\n");
if (argc != 2) {printf("Usage: %s num_of_messages\n", argv[0]); exit(1); }
if (atoi(argv[1]) > MAXMSGS)   {printf("Too many messages...\n"); exit(1);}
printf("%d messages will be produced and consumed\n", atoi(argv[1]));

parent_id = getpid();                               /* To get a unique number */
sharmemory.head = sharmemory.tail = 0;        /* Initial queue indexes values */

/* Create and attach shared memory */
shmid = shmget(parent_id, sizeof(sharmemory), IPC_CREAT|0666);
if (shmid < 0){perror("shmget problem"); exit(1);}
shmptr = shmat(shmid, 0, 0);
if (shmptr == (char *) -1) {perror("shmat problem"); exit(1);}

/* Initialize shared memory with zero indexes of head and tail of queue */
memcpy(shmptr, (char *)&sharmemory, sizeof(sharmemory));
printf("Shared memory is ready...\n");

/* Create and initialize two semaphores */
semid = semget(parent_id, 2, IPC_CREAT|0666);
if (semid == -1){perror("semget problem"); exit(1);}
arguments.array = init_val;
if (semctl(semid, 0, SETALL, arguments) == -1){perror("semctl problem"); exit(1);}
printf ("Semaphores are ready...\n");

/* Create producer and consumer child processes */
prod_id = fork();
if (prod_id == -1) {perror("fork problem 1 in parent"); exit (1);}
if (prod_id == 0) execl("producer", "producer", argv[1], 0);

cons_id = fork();
if (cons_id == -1) {perror("fork problem 2 in parent"); exit(1);}
if (cons_id == 0) execl("consumer", "consumer", argv[1], 0);

/* Waiting for producer and consumer to terminate */
printf("Parent process is waiting...\n");
wait(0);
wait(0);

/* Remove shared memory and semaphores */
shmdt(shmptr);
shmctl(shmid, IPC_RMID, 0);
semctl(semid, 0, IPC_RMID, 0);
printf("\nAll processes terminated...\n");
exit(0); 
}
