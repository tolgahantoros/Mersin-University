// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;
*/

int tip;
char mesaj;
int i=0;

int main()
{
	key_t key;
	int msgid;
    
    for(;;){
    key = rand() % 100 + 1; 
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgrcv(0, mesaj, sizeof(mesaj), 1, 0);
    
	printf("Alınan Bilgi : %c \n", mesaj);
    sleep(2);
	msgctl(msgid, IPC_RMID, NULL);
    }
	return 0;
}

