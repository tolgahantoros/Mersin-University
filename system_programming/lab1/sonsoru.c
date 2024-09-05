#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Kullanım: %s kaynak_dosya_adı hedef_dosya_adı\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    char *kaynakDosyaAdi = argv[1];
    char *hedefDosyaAdi = argv[2];

    // Kaynak ve hedef dosya adları aynı olamaz
    if (strcmp(kaynakDosyaAdi, hedefDosyaAdi) == 0) {
        fprintf(stderr, "Hata: Kaynak ve hedef dosya adları aynı olamaz.\n");
        exit(EXIT_FAILURE);
    }

    int fdrd, fdwt;
    char c;
    char parent = 'P';
    unsigned long i;

    // Dosyaları açma işlemleri
    if ((fdrd = open(kaynakDosyaAdi, O_RDONLY)) == -1) {
        perror("Hata: Kaynak dosya açılamadı");
        exit(EXIT_FAILURE);
    }

    if ((fdwt = creat(hedefDosyaAdi, 0666)) == -1) {
        perror("Hata: Hedef dosya oluşturulamadı");
        close(fdrd);
        exit(EXIT_FAILURE);
    }

    for (;;) {
        if (read(fdrd, &c, 1) != 1) break;
        for (i = 0; i < 200000; i++);   /* Uzun bir döngü */
        write(1, &parent, 1);
        if (write(fdwt, &c, 1) == -1) {
            perror("Hata: Hedef dosyaya yazma işlemi başarısız");
            close(fdrd);
            close(fdwt);
            exit(EXIT_FAILURE);
        }
    }

    gettimeofday(&end_time, NULL);
    printf("Dosya kopyalama süresi: %ld mikrosaniye\n",
           ((end_time.tv_sec - start_time.tv_sec) * 1000000) + (end_time.tv_usec - start_time.tv_usec));

    close(fdrd);
    close(fdwt);

    return 0;
}

