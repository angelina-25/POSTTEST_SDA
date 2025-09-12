#include <iostream>
using namespace std;

// Fungsi untuk membalik isi array menggunakan pointer
void balikArray(int* arr, int n) {
    int *awal = arr;        // pointer awal
    int *akhir = arr + n - 1; // pointer akhir
    
    while (awal < akhir) {
        // Tukar nilai yang ditunjuk pointer
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        
        awal++;
        akhir--;
    }
}

int main() {
    // Array berisi 7 bilangan prima
    int arr[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    // Tampilkan sebelum dibalik
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Panggil fungsi untuk membalik
    balikArray(arr, n);

    // Tampilkan sesudah dibalik
    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
