#include <iostream>
using namespace std;

// Fungsi untuk menukar nilai dengan reference
void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "Masukkan nilai pertama (x): ";
    cin >> x;
    cout << "Masukkan nilai kedua (y): ";
    cin >> y;

    cout << "\nNilai Sebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Panggil fungsi tukar
    tukar(x, y);

    cout << "\nNilai Sesudah ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
