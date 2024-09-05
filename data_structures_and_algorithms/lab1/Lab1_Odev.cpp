#include <iostream>

using namespace std;

int main()
{
    int atis_1, atis_2, atis_sayisi = 0, puan = 0;
    int kuka_sayilari[22];

    // atislari al
    for (int i = 0; i < 10; ++i) {
        cin >> atis_1;
        kuka_sayilari[atis_sayisi++] = atis_1;
        if (atis_1 != 10) {
            cin >> atis_2;
            kuka_sayilari[atis_sayisi++] = atis_2;
        }
        if (atis_1 == 10 && i == 9) {
            cin >> atis_1;
            kuka_sayilari[atis_sayisi++] = atis_1;
            cin >> atis_2;
            kuka_sayilari[atis_sayisi++] = atis_2;
        } else if (atis_1 + atis_2 == 10 && i == 9) {
            cin >> atis_1;
            kuka_sayilari[atis_sayisi++] = atis_1;
        }
    }

    // puan hesapla
    bool strike, spare;
    for (int i = 0, j = 0; i < 10; ++i) {
        strike = false;
        spare = false;
        if (kuka_sayilari[j] == 10) {
            puan += kuka_sayilari[j] + kuka_sayilari[j+1] + kuka_sayilari[j+2];
            j += 1;
            strike = true;
        } else if (kuka_sayilari[j] + kuka_sayilari[j+1] == 10) {
            puan += kuka_sayilari[j] + kuka_sayilari[j+1] + kuka_sayilari[j+2];
            j += 2;
            spare = true;
        } else {
            puan += kuka_sayilari[j] + kuka_sayilari[j+1];
            j += 2;
        }
    }

    cout <<  puan;
    return 0;
}
