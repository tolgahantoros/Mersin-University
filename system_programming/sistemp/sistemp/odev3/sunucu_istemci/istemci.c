/* ISTEMCI PROGRAM*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define boru

int main(void)
{
int n, fd;
char buf[1024];
printf ("ISTEMCI BASLAR...\n");

if ((fd = open("boru", O_WRONLY)) < 0) {
    perror("open problem in client");
    exit(1);
            }

while ((n = read(0, buf, sizeof(buf))) > 0)
write(fd, buf, n);

printf ("ISTEMCI SONLANDI...\n");
close(fd);
exit(0);
}
