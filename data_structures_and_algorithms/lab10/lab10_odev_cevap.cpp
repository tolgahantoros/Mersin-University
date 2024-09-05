#include <iostream>
#define SIZE 10 // Hash tablosunun boyutu

using namespace std;

// Hash tablosu sýnýfý
class HashTable {
    private:
        int *table;
        int curr_size;

    public:
        HashTable() {
            table = new int[SIZE];
            curr_size = 0;
            for (int i = 0; i < SIZE; i++) {
                table[i] = -1; // Hash tablosu baþlangýçta boþ olarak iþaretlenir
            }
        }

        // Hash deðerini hesaplayan fonksiyon
        int hash(int key) {
            return key % SIZE;
        }

        // Eleman ekleme fonksiyonu
        void insert(int key) {
            if (curr_size == SIZE) {
                cout << "Hash tablosu dolu!" << endl;
                return;
            }

            int index = hash(key);
            int i = 1;

            // Karesel ölçüm mantýðý ile eleman ekleme iþlemi
            while (table[index] != -1) {
                index = (hash(key) + i * i) % SIZE;
                i++;
            }

            table[index] = key;
            curr_size++;
        }

        // Eleman arama fonksiyonu
        int search(int key) {
            int index = hash(key);
            int i = 1;

            // Karesel ölçüm mantýðý ile eleman arama iþlemi
            while (table[index] != key) {
                if (table[index] == -1) {
                    return -1; // Eleman tabloda yok
                }
                index = (hash(key) + i * i) % SIZE;
                i++;
            }

            return index; // Elemanýn indeksi döndürülür
        }
};

// Test fonksiyonu
int main() {
    HashTable hash;

    // Eleman ekleme
    hash.insert(5);
    hash.insert(15);
    hash.insert(25);
    hash.insert(35);
    hash.insert(45);

    // Eleman arama
    int key;
    cout << "Aranacak elemani girin: ";
    cin >> key;
    int index = hash.search(key);
    if (index == -1) {
        cout << "Eleman bulunamadi" << endl;
    }
    else {
        cout << "Elemanin indeksi: " << index << endl;
    }

    return 0;
}

