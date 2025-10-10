#include <iostream>     // Library standar untuk input dan output
using namespace std;    // Agar tidak perlu menulis std:: di setiap perintah

// Struktur Node untuk Binary Tree
struct Node {
    int data;           // Menyimpan nilai data node
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
    if (root == nullptr) {              // Jika tree kosong
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


void postOrderTraversal(Node* root) {
    if (root == nullptr) {              // Jika tree kosong, langsung kembali
        return;                         // Base case untuk menghentikan rekursi
    }

    postOrderTraversal(root->left);     // Telusuri subtree kiri terlebih dahulu
    postOrderTraversal(root->right);    // Lalu telusuri subtree kanan
    cout << root->data << " ";          // Terakhir cetak data node saat ini
}

int main() {
    Node* root = nullptr;               // Inisialisasi tree masih kosong

    root = insert(root, 50);            // Masukkan node root
    insert(root, 30);                   // Tambahkan node kiri dari 50
    insert(root, 70);                   // Tambahkan node kanan dari 50
    insert(root, 20);                   // Tambahkan node kiri dari 30
    insert(root, 40);                   // Tambahkan node kanan dari 30
    insert(root, 60);                   // Tambahkan node kiri dari 70
    insert(root, 80);                   // Tambahkan node kanan dari 70

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);           // Jalankan traversal post-order
    cout << endl;                       // Pindah baris setelah output

    return 0;                           // Program selesai
}
