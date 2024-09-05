#include <iostream>

using namespace std;

void kabuk_sort(int dizi[], int boyut) {
    int mesafe = boyut / 2;

    while (mesafe > 0) {
        for (int i = mesafe; i < boyut; i++) {
            int temp = dizi[i];
            int j = i;

            while (j >= mesafe && dizi[j - mesafe] > temp) {
                dizi[j] = dizi[j - mesafe];
                j -= mesafe;
            }

            dizi[j] = temp;
        }

        mesafe /= 2;
    }
}

int main() {
    int dizi[] = {7, 3, 5, 8, 2, 9, 4, 15, 6};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    kabuk_sort(dizi, boyut);

    for (int i = 0; i < boyut; i++) {
        cout << dizi[i] << " ";
    }
    cout << endl;

    return 0;
}

