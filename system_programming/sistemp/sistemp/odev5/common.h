/*
**********************************************************************************
* A common header file common.h for the producer-consumer task
**********************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


#define MSGNUMBER 10           /* Number of different messages in producer */
#define SLOT_LEN  50            /* Max number of characters in one message */
#define N_SLOTS   6      /* Max length of queue for messages from producer */
#define MAXMSGS   25       /* Max number of produced and consumed messages */
struct MEMORY {                                 /* Shared memory structure */
       char buffer [N_SLOTS][SLOT_LEN];         /* Space for message queue */
       int head, tail;            /* Indexes of head and tail of the queue */
       };  

struct sembuf acquire = {0, -1, SEM_UNDO}, /* Operation to acquire */
              release = {0,  1, SEM_UNDO}; /* Operation to release */

enum {AVAIL_SLOTS, TO_CONSUME}; /* Indexes 0 and 1 in the array of descriptors 
                                   of two semaphores in OS kernel */
/* If the following declaration is missing in sem.h,
   then remove comments around it */

/*
union semun {
  int      val;
  struct semid_ds  *buf;
  ushort *array;
  };
*/

