/* SUNUCU PROGRAM */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define boru
/*"myfifo"  burada pipe ozel bir ad verin */
int main(void)
{
int n, fd;
char buf[1024]; /* okuma ve yazma icin kullanilacak buffer */
printf ("SUNUCU BASLAR...\n");

unlink(boru);

if (mkfifo("boru", 0666) < 0) {
    perror("mkfifo problem in server");
    exit(1);
                            }

//if (chmod(boru, 0666) < 0) perror("chmod problem in server"); exit(1);


fd = open("boru", 0666);
if (fd < 0) {
    perror("open problem in server");
    exit(1);
                    }
while ((n = read(fd, buf, sizeof(buf))) > 0)
write(1, buf, n);

close(fd);
printf ("SUNUCU SONLANDI...\n");
exit(0);
}
