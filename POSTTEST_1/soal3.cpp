#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    // Input data mahasiswa
    cout << "Input data 4 mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore(); 
    }

    // Sorting (Ascending berdasarkan IPK) - Bubble Sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (mhs[j].ipk > mhs[j + 1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }

    // Tampilkan hasil setelah diurutkan
    cout << "\nData Mahasiswa setelah diurutkan (berdasarkan IPK ascending):\n";
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". Nama: " << mhs[i].nama
             << " | NIM: " << mhs[i].nim
             << " | IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}

