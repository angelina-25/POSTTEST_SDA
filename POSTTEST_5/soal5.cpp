#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;       // Menyimpan nilai data node
    Node* left;     // Pointer ke anak kiri
    Node* right;    // Pointer ke anak kanan

    // Constructor untuk menginisialisasi data dan pointer
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menambahkan node ke dalam tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {             // Jika belum ada root, buat node baru
        return new Node(val);
    }

    if (val < root->data) {            // Jika nilai lebih kecil, masuk ke subtree kiri
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {       // Jika nilai lebih besar, masuk ke subtree kanan
        root->right = insert(root->right, val);
    }

    return root;                       // Kembalikan root setelah penambahan selesai
}


void preOrderTraversal(Node* root) {
    if (root == nullptr) return;       // Jika kosong, langsung keluar (base case)
    cout << root->data << " ";         // Cetak data root terlebih dahulu (urutan pre-order)
    preOrderTraversal(root->left);     // Telusuri subtree kiri
    preOrderTraversal(root->right);    // Telusuri subtree kanan
}

int main() {
    Node* root = nullptr;              // Awalnya tree kosong

    // Menambahkan node ke dalam tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Menampilkan hasil traversal pre-order
    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root);           // Harus menghasilkan: 50 30 20 40 70 60 80
    cout << endl;

    return 0;                          // Program selesai
}
