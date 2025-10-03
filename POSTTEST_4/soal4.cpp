#include <iostream>   // Buat pakai cout dan endl
using namespace std;

// Struktur node untuk Circular Doubly Linked List
struct Node {
    int data;      // Data yang disimpan
    Node* next;    // Pointer ke node selanjutnya
    Node* prev;    // Pointer ke node sebelumnya
};

// Fungsi untuk menyisipkan node baru ke list secara berurutan
void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};   // Buat node baru dan isi datanya

    // Kasus 1: Kalau list masih kosong
    if (head_ref == nullptr) {
        // Node pertama menunjuk ke dirinya sendiri, karena circular
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;  // Set head ke node baru
        return;
    }

    // Kasus 2: Data lebih kecil dari head, artinya harus disisipkan di depan
    if (data < head_ref->data) {
        Node* tail = head_ref->prev;  // Ambil node terakhir (sebelum head)

        // Sambungkan node baru di depan head
        newNode->next = head_ref;
        newNode->prev = tail;
        tail->next = newNode;
        head_ref->prev = newNode;

        // Update head ke node yang baru dimasukkan
        head_ref = newNode;
        return;
    }

    // Kasus 3: Sisipkan di tengah atau di belakang (bukan di depan)
    Node* current = head_ref;

    // Cari posisi yang tepat: selama belum kembali ke head dan data berikutnya lebih kecil
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // Sisipkan newNode setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// Fungsi untuk menampilkan semua elemen dalam circular doubly linked list
void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;  // Kalau list kosong, tampilkan pesan
        return;
    }

    Node *current = head_ref;
    // Karena circular, kita pakai do-while supaya node pertama ikut ditampilkan
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);  // Berhenti kalau sudah balik ke awal
    cout << endl;
}

int main() {
    Node *head = nullptr;  // Awalnya list kosong

    // Uji fungsi sortedInsert dengan beberapa data
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    // Tampilkan isi list setelah disisipkan
    cout << "Circular Doubly Linked List (sorted): ";
    // Hasil yang diharapkan: 10 20 30 40
    printList(head);

    return 0;
}
