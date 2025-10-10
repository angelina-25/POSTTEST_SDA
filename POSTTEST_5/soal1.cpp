#include <iostream>    
using namespace std;    

// Struktur Node untuk Binary Search Tree
struct Node {
    int data;           // Menyimpan nilai data dari node
    Node* left;         // Pointer ke anak kiri
    Node* right;        // Pointer ke anak kanan

    // membuat node baru
    Node(int val) {
        data = val;     // Isi data dengan nilai val
        left = nullptr; // Awalnya anak kiri belum ada
        right = nullptr;// Awalnya anak kanan belum ada
    }
};

// Fungsi untuk menyisipkan (insert) nilai ke dalam BST (Binary Search Tree)
Node* insert(Node* root, int val) {
    if (root == nullptr) {              // Jika root kosong, buat node baru
        return new Node(val);           // Kembalikan node baru sebagai root
    }

    if (val < root->data) {             // Jika nilai lebih kecil dari data root
        root->left = insert(root->left, val); // Masuk ke subtree kiri
    } 
    else if (val > root->data) {        // Jika nilai lebih besar dari data root
        root->right = insert(root->right, val); // Masuk ke subtree kanan
    }

    return root;                        // Kembalikan root setelah disisipkan
}

// Fungsi untuk menghitung jumlah semua node dalam tree
int countNodes(Node* root) {
    if (root == nullptr)                // Jika tree kosong, jumlah node = 0
        return 0;

    // Hitung total node: 1 (node saat ini) + jumlah di kiri + jumlah di kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;               // Inisialisasi tree masih kosong

    root = insert(root, 50);            // Masukkan node pertama sebagai root
    insert(root, 30);                   // Masukkan node ke subtree kiri
    insert(root, 70);                   // Masukkan node ke subtree kanan
    insert(root, 20);                   // Masukkan node ke subtree kiri dari 30

    // Tampilkan jumlah total node yang ada di tree
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;

    return 0;                           // Program selesai dengan sukses
}
