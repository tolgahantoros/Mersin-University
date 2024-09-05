#include <iostream>

using namespace std;

int main() {
  int sayi = 0, sayac = 1;
  char secim = 'e';
  while (secim == 'e') {
    cout << "Asal olup-olmadığı kontrol edilecek bir sayi giriniz!" << endl;
    cin >> sayi;
    if (sayi > 2) {
      while (sayac < sayi - 1) {
        sayac++;
        /*sayi sayac'a tam bölünüyor mu?*/
        if (sayi % sayac == 0) {
          cout << "Sayi asal değildir!" << endl;
          break;
        } else if (sayac + 1 == sayi) {
          cout << "Sayi asaldir" << endl;
        }
      }
    } else if (sayi == 2) {
      cout << "Girilen sayi en küçük asal sayidir" << endl;
    } else {
      cout << "Asallık pozitif sayılarda aranır!!" << endl;
    }
    cout << "e-devam , h-cikis" << endl;
    cin >> secim;
    sayac = 1;
  }
  return 0;
}
