#include <iostream>   
#include <string>     
using namespace std;  

// Struktur data Node untuk stack
struct Node {
    char data;     // Menyimpan satu karakter
    Node* next;    // Pointer ke node berikutnya
};

// Fungsi untuk menambahkan data ke stack (push)
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top}; // Membuat node baru dan langsung menghubungkannya ke node paling atas
    top = newNode;  // Update top agar menunjuk ke node yang baru
}

// Fungsi untuk mengambil data dari stack (pop)
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Kalau stack kosong, kembalikan karakter kosong
    Node* temp = top;               // Simpan node yang paling atas
    char poppedValue = temp->data;  // Ambil data dari node tersebut
    top = top->next;                // Geser top ke node berikutnya
    delete temp;                    // Hapus node lama 
    return poppedValue;             // Kembalikan data yang sudah di-pop
}

// Fungsi untuk membalikkan string menggunakan stack
string reverseString(string s) {
    Node* stackTop = nullptr;  // Awalnya stack kosong
    string reversed = "";      // Menyimpan hasil string terbalik
    for (char c : s) {              // Masukkan semua karakter dari string ke stack satu per satu
        push(stackTop, c);
    }
    while (stackTop != nullptr) {     // Ambil satu per satu karakter dari stack untuk membentuk string terbalik
        reversed += pop(stackTop);
    }

    return reversed;            // Kembalikan string yang sudah dibalik
}

int main() {
    string text = "Struktur Data";  // String yang ingin dibalik
    cout << "Teks asli: " << text << endl;  // Tampilkan string awal
    cout << "Teks terbalik: " << reverseString(text) << endl;  // Tampilkan hasil string setelah dibalik

    return 0;
}
