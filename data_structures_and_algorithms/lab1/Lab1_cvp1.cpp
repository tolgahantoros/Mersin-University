#include <iostream>

/*using namespace std; kullanılmadığından
std::cout ve std::cin ile işlem yapılmıştır.*/
int main() {
    int hiz;
    char tur;
/****************
AZAMİ HIZ
Otomobil:82
Otobüs  :70
Kamyonet:50
*****************/
    std::cout << "Aracin turunu giriniz:";
    std::cout << std::endl;
    std::cout << "(Otomobil: o, Otobus: t, Kamyonet: k): ";
    std::cin >> tur;
    std::cout << "Aracin hizini giriniz: ";
    std::cin >> hiz;

    if (tur == 'o') {
        std::cout << "Arac otomobildir";
        std::cout << std::endl;
        if (hiz > 82)
            std::cout << "Arac cezalidir";
        else
            std::cout << "Kurallara uygun";
    } else if (tur == 't') {
        std::cout << "Arac otobustur";
        std::cout << std::endl;
        if (hiz > 70)
            std::cout << "Arac cezalidir";
        else
            std::cout << "Kurallara uygun";
    } else if (tur == 'k') {
        std::cout << "Arac kamyonettir";
        std::cout << std::endl;
        if (hiz > 50)
            std::cout << "Arac cezalidir";
        else
            std::cout << "Kurallara uygun";
    } else
        std::cout << "Arac turunu yanlis girdiniz";

    return 0;
}
