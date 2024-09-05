#include <iostream>
#include <iomanip>

using namespace std;

float ortalama_hesapla(int n);

int main()
{
    int n;
    cout << "Kac sayi gireceksiniz: ";
    cin >> n;
    /*cout << fixed << setprecision(2); daha öncede belirttiğimiz gibi,
    iomanip kütüphanesi yardımıyla çalışır ve virgülden sonra iki basamak
    yazdırılmasını sağlar.*/
    cout << fixed << setprecision(2);
    cout << "Girilen sayilarin ortalamasi: " << ortalama_hesapla(n);
    return 0;
}

float ortalama_hesapla(int n)
{
    int sayi;
    float toplam = 0;
    cout << "Sayilari giriniz: ";
    for (int i = 0; i < n; ++i) {
        cin >> sayi;
        toplam += sayi;
    }
    return toplam / n;
}
