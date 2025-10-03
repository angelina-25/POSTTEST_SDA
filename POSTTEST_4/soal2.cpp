#include <iostream>   
#include <string>     
using namespace std;  

// Struktur dasar untuk Node (digunakan untuk implementasi stack manual)
struct Node {
    char data;     // Menyimpan karakter (dalam kasus ini kurung)
    Node* next;    // Menunjuk ke node berikutnya
};

// Fungsi untuk menambahkan elemen ke atas stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};  // Buat node baru, isi datanya, dan sambungkan ke node yang lama
    top = newNode;  // Update top supaya menunjuk ke node baru
}

// Fungsi untuk mengambil elemen paling atas dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0';  // Kalau stack kosong, kembalikan karakter kosong

    Node* temp = top;             // Simpan node yang mau diambil
    char poppedValue = temp->data; // Ambil datanya
    top = top->next;              // Geser top ke node berikutnya
    delete temp;                  // Hapus node lama dari memori
    return poppedValue;           // Kembalikan data yang tadi diambil
}

// Fungsi untuk mengecek apakah kurung dalam string seimbang atau tidak
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;  // Awalnya stack kosong

    // Periksa setiap karakter dalam string
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {     // Kalau karakter adalah kurung buka, langsung masukin ke stack
            push(stackTop, c);
        }
        else if (c == ')' || c == '}' || c == ']') {    // Kalau karakter adalah kurung tutup, kita cek pasangannya
            if (stackTop == nullptr) return false;      // Kalau stack kosong tapi ada kurung tutup, berarti salah
            char topChar = pop(stackTop);       // Ambil elemen teratas dari stack

            // Cek apakah pasangannya cocok
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;  // Kalau nggak cocok, langsung return false
            }
        }
    }

    // Setelah semua karakter dicek, stack harus kosong kalau seimbang
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";  // Kurung buka dan tutup sesuai urutan
    cout << expr1 << " -> " 
         << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";  // Ada kurung yang tidak berpasangan dengan benar
    cout << expr2 << " -> " 
         << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr3 = "((()))";  // Semua kurung buka dan tutup berurutan dengan benar
    cout << expr3 << " -> " 
         << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr4 = "([{}])";  // Kombinasi berbagai jenis kurung, tapi semuanya cocok
    cout << expr4 << " -> " 
         << (areBracketsBalanced(expr4) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
