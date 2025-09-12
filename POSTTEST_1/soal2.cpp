#include <iostream>
using namespace std;

int main() {
    const int baris = 3;
    const int kolom = 3;
    int matriks[baris][kolom] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int jumlah = 0;

    // Hitung jumlah elemen baris genap (indeks 0, 2, dst)
    for (int i = 0; i < baris; i++) {
        if (i % 2 == 0) { // baris genap
            for (int j = 0; j < kolom; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    // Cetak matriks
    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // Cetak hasil
    cout << "Jumlah dari elemen baris genap = " << jumlah << endl;

    return 0;
}
