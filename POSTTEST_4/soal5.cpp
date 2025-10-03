#include <iostream>  // Buat pakai cout dan endl
using namespace std;

// Struktur dasar untuk Circular Doubly Linked List
struct Node {
    int data;       // Menyimpan data integer
    Node* next;     // Penunjuk ke node setelahnya
    Node* prev;     // Penunjuk ke node sebelumnya
};

// Fungsi untuk menukar posisi head dan tail dalam list
void exchangeHeadAndTail(Node *&head_ref) {
    // Cek dulu, kalau list kosong atau isinya cuma 1 node, nggak perlu ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    // Ambil referensi ke node penting
    Node* head = head_ref;
    Node* tail = head_ref->prev;
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // Kasus khusus: kalau hanya ada 2 node
    if (head_next == tail) {
        // Atur pointer supaya tetap circular dan doubly
        head->next = head;
        head->prev = tail;
        tail->next = tail;
        tail->prev = head;
        head_ref = tail;  // Ganti head dengan tail
        return;
    }

    // Kalau jumlah node lebih dari 2, lakukan penukaran node head dan tail

    // Langkah 1: Sambungkan tail ke node setelah head
    tail->next = head_next;
    head_next->prev = tail;

    // Langkah 2: Sambungkan head ke node sebelum tail
    head->prev = tail_prev;
    tail_prev->next = head;

    // Langkah 3: Hubungkan head dan tail satu sama lain (mereka bertukar posisi)
    tail->prev = head;
    head->next = tail;

    // Terakhir, update head supaya menunjuk ke tail lama (yang sekarang jadi head)
    head_ref = tail;
}

// Fungsi untuk mencetak isi list dari head sampai kembali ke head
void printList(Node *head_ref) {
    // Kalau list kosong, tampilkan pesan
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    // Karena circular, pakai do-while supaya node pertama ikut tercetak
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);  // Berhenti kalau sudah balik ke head
    cout << endl;
}

// Fungsi untuk menambahkan node baru di akhir list
void insertEnd(Node *&head_ref, int data) {
    // Buat node baru
    Node *newNode = new Node{data, nullptr, nullptr};

    // Kalau list masih kosong, node menunjuk ke dirinya sendiri
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Kalau list sudah ada isinya
    Node *tail = head_ref->prev;

    newNode->next = head_ref;   // Node baru menunjuk ke head
    newNode->prev = tail;       // dan ke node terakhir (tail)

    head_ref->prev = newNode;   // Update head.prev ke node baru
    tail->next = newNode;       // Tail sekarang menunjuk ke node baru
}

int main() {
    Node *head = nullptr;  // Awalnya list kosong

    // Tambahkan elemen-elemen ke list
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    // Tampilkan isi list sebelum ditukar
    cout << "List sebelum exchange: ";
    printList(head);

    // Tukar posisi head dan tail
    exchangeHeadAndTail(head);

    // Tampilkan isi list setelah ditukar
    cout << "List setelah exchange head dan tail: ";
    // Expected output setelah pertukaran: 5 2 3 4 1
    printList(head);

    return 0;
}
