#include <iostream>     
using namespace std;    

// Struktur Node untuk Binary Tree
struct Node {
    int data;           // Menyimpan nilai data dari node
    Node* left;         // Pointer ke anak kiri
    Node* right;        // Pointer ke anak kanan

    // Constructor untuk membuat node baru
    Node(int val) {
        data = val;     // Isi data dengan nilai val
        left = nullptr; // Awalnya anak kiri kosong
        right = nullptr;// Awalnya anak kanan kosong
    }
};

// Fungsi untuk menambahkan data ke dalam BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {              // Jika tree masih kosong
        return new Node(val);           // Buat node baru sebagai root
    }

    if (val < root->data) {             // Jika nilai lebih kecil dari root
        root->left = insert(root->left, val);   // Masukkan ke subtree kiri
    } 
    else if (val > root->data) {        // Jika nilai lebih besar dari root
        root->right = insert(root->right, val); // Masukkan ke subtree kanan
    }

    return root;                        // Kembalikan root setelah disisipkan
}

int findMaxValue(Node* root) {
    if (root == nullptr) {              // Jika tree kosong
        return -1;                      // Kembalikan -1 sebagai tanda kosong
    }

    Node* current = root;               // Mulai dari node root
    while (current->right != nullptr) { // Selama masih ada anak kanan
        current = current->right;       // Pindah ke anak kanan
    }

    return current->data;               // Node paling kanan = nilai terbesar
}

int main() {
    Node* root = nullptr;               // Inisialisasi tree kosong

    root = insert(root, 50);            // Masukkan node pertama sebagai root
    insert(root, 30);                   // Masukkan node kiri
    insert(root, 70);                   // Masukkan node kanan
    insert(root, 20);                   // Masukkan node kiri dari 30
    insert(root, 80);                   // Masukkan node kanan dari 70 (paling besar)

    // Cetak nilai terbesar di dalam tree
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;

    return 0;                           // Program selesai
}
