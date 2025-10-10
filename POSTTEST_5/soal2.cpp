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

// Fungsi untuk menyisipkan nilai ke dalam BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {              // Jika tree kosong, buat node baru
        return new Node(val);           // Node baru dijadikan root
    }

    if (val < root->data) {             // Jika nilai lebih kecil dari root
        root->left = insert(root->left, val);  // Masukkan ke subtree kiri
    } 
    else if (val > root->data) {        // Jika nilai lebih besar dari root
        root->right = insert(root->right, val); // Masukkan ke subtree kanan
    }

    return root;                        // Kembalikan root setelah disisipkan
}

/*
@brief Fungsi untuk mencari nilai terkecil dalam sebuah BST.
@param root Pointer ke node root dari tree.
@return Nilai integer terkecil. Mengembalikan -1 jika tree kosong.
 */
int findMinValue(Node* root) {
    if (root == nullptr) {              // Jika tree kosong
        return -1;                      // Kembalikan -1 sebagai tanda kosong
    }

    Node* current = root;               // Mulai dari node root
    while (current->left != nullptr) {  // Selama masih ada anak kiri
        current = current->left;        // Pindah ke anak kiri
    }

    return current->data;               // Node paling kiri = nilai terkecil
}

int main() {
    Node* root = nullptr;               // Inisialisasi tree masih kosong

    root = insert(root, 50);            // Masukkan node pertama
    insert(root, 30);                   // Masukkan node kiri
    insert(root, 70);                   // Masukkan node kanan
    insert(root, 20);                   // Masukkan node paling kiri
    insert(root, 40);                   // Masukkan node kanan dari 30

    // Cetak nilai terkecil di dalam tree
    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;

    return 0;                           // Program selesai
}
