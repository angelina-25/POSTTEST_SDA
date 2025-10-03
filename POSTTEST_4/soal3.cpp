#include <iostream>   
#include <string>     
using namespace std;  

// Struktur node untuk antrian printer
struct Node {
    string document;  // Nama dokumen yang ingin diproses
    Node* next;       // Menunjuk ke dokumen berikutnya
};

// Fungsi untuk menambahkan dokumen ke antrian (enqueue)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};    // Buat node baru untuk dokumen

    if (front == nullptr) {
        front = rear = newNode;     // Kalau antrian masih kosong, node baru jadi front dan rear
    } else {
        rear->next = newNode;       // Kalau sudah ada isinya, tambahkan node baru di belakang
        rear = newNode;      // Update rear ke node terakhir yang baru dimasukkan
    }
}

// Fungsi untuk mengeluarkan dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";    // Kalau antrian kosong, langsung kembalikan string kosong

    Node* temp = front;          // Simpan node paling depan
    string doc = temp->document; // Ambil nama dokumen
    front = front->next;         // Geser front ke dokumen berikutnya

    if (front == nullptr) {      // Kalau setelah di-dequeue ternyata antriannya jadi kosong
        rear = nullptr;          // Rear juga harus di-set jadi null
    }

    delete temp;                 // Hapus node yang tadi sudah diproses
    return doc;                  // Kembalikan nama dokumen
}

// Fungsi untuk memproses semua dokumen yang ada di antrian
void processAllDocuments(Node*& front, Node*& rear) {
    // Selama masih ada dokumen di antrian
    while (front != nullptr) {
        string doc = dequeue(front, rear);             // Ambil dokumen satu per satu
        cout << "Memproses: " << doc << endl;          // Tampilkan dokumen yang sedang diproses
    }
}

int main() {
    Node* front = nullptr;  // Awal antrian (kosong)
    Node* rear = nullptr;   // Akhir antrian (juga kosong)

    // Tambahkan beberapa dokumen ke antrian
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    // Mulai proses semua dokumen yang ada di antrian
    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
