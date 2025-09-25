#include <iostream>
#include <string>
using namespace std;

struct Jadwal {
    string kodePenerbangan;
    string tujuan;
    string status;
    Jadwal *next;
    Jadwal *prev;
};

Jadwal *head = nullptr;
Jadwal *tail = nullptr;

// Data identitas
string nama;
string nim;

int counterKode = 0;

// Fungsi generate kode penerbangan
string generateKode() {
    string tigaDigitNim = nim.substr(nim.length() - 3); 
    string kode = "JT-" + tigaDigitNim;
    if (counterKode > 0) {
        kode += "-" + to_string(counterKode);
    }
    counterKode++;
    return kode;
}

// Tambah jadwal di akhir
void tambahJadwal() {
    Jadwal *baru = new Jadwal;
    baru->kodePenerbangan = generateKode();
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, baru->tujuan);
    cout << "Masukkan status penerbangan: ";
    getline(cin, baru->status);
    baru->next = nullptr;
    baru->prev = nullptr;

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Jadwal berhasil ditambahkan dengan kode: " << baru->kodePenerbangan << endl;
}

// Sisipkan jadwal 
void sisipkanJadwal() {
    int TigaDigitAkhir = (nim[nim.length() - 1] - '0'); 
    int posisi = TigaDigitAkhir + 1;

    Jadwal *baru = new Jadwal;
    baru->kodePenerbangan = generateKode();
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, baru->tujuan);
    cout << "Masukkan status penerbangan: ";
    getline(cin, baru->status);

    if (posisi <= 1 || head == nullptr) {
        baru->next = head;
        baru->prev = nullptr;
        if (head != nullptr) head->prev = baru;
        head = baru;
        if (tail == nullptr) tail = baru;
    } else {
        Jadwal *temp = head;
        for (int i = 1; i < posisi - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        baru->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = baru;
        } else {
            tail = baru; 
        }
        temp->next = baru;
    }

    cout << "Jadwal berhasil disisipkan di posisi " << posisi 
         << " dengan kode: " << baru->kodePenerbangan << endl;
}

// Hapus jadwal paling awal
void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Jadwal *hapus = head;
    cout << "Jadwal dengan kode " << hapus->kodePenerbangan << " berhasil dihapus.\n";
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    else tail = nullptr;
    delete hapus;
}

// Hapus jadwal paling akhir
void hapusAkhir() {
    if (tail == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Jadwal *hapus = tail;
    cout << "Jadwal dengan kode " << hapus->kodePenerbangan << " berhasil dihapus.\n";
    tail = tail->prev;
    if (tail != nullptr) tail->next = nullptr;
    else head = nullptr;
    delete hapus;
}

// Hapus jadwal berdasarkan kode
void hapusSpecific(string kode) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Jadwal *temp = head;
    while (temp != nullptr && temp->kodePenerbangan != kode) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Kode penerbangan tidak ditemukan.\n";
    } else {
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        else tail = temp->prev;
        cout << "Jadwal dengan kode " << temp->kodePenerbangan << " berhasil dihapus.\n";
        delete temp;
    }
}

// Update status penerbangan
void updateStatus() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }

    string kode;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    cin.ignore();
    getline(cin, kode);

    Jadwal *temp = head;
    while (temp != nullptr && temp->kodePenerbangan != kode) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Kode penerbangan tidak ditemukan.\n";
    } else {
        cout << "Status lama: " << temp->status << endl;
        cout << "Masukkan status baru: ";
        string newStatus;
        getline(cin, newStatus);
        temp->status = newStatus;
        cout << "Status penerbangan berhasil diperbarui.\n";
    }
}

// Tampilkan semua jadwal (dari depan)
void tampilkanJadwal() {
    if (head == nullptr) {
        cout << "Belum ada jadwal penerbangan yang tersimpan.\n";
        return;
    }

    cout << "\n+--------------+------------------------+------------------------+\n";
    cout << "|    Kode      |         Tujuan         |         Status         |\n";
    cout << "+--------------+------------------------+------------------------+\n";

    Jadwal *temp = head;
    while (temp != nullptr) {
        cout << "| " << temp->kodePenerbangan;
        int pad = 12 - (int)temp->kodePenerbangan.length();
        for (int i = 0; i < pad; i++) cout << ' ';
        cout << " | ";

        cout << temp->tujuan;
        int pad2 = 22 - (int)temp->tujuan.length();
        for (int i = 0; i < pad2; i++) cout << ' ';
        cout << " | ";

        cout << temp->status;
        int pad3 = 22 - (int)temp->status.length();
        for (int i = 0; i < pad3; i++) cout << ' ';
        cout << " |\n";

        temp = temp->next;
    }

    cout << "+--------------+------------------------+------------------------+\n";
}

// Tampilkan dari belakang (reverse traversal)
void tampilkanReverse() {
    if (tail == nullptr) {
        cout << "Belum ada jadwal penerbangan yang tersimpan.\n";
        return;
    }

    cout << "\n+--------------+------------------------+------------------------+\n";
    cout << "|    Kode      |         Tujuan         |         Status         |\n";
    cout << "+--------------+------------------------+------------------------+\n";

    Jadwal *temp = tail;
    while (temp != nullptr) {
        cout << "| " << temp->kodePenerbangan;
        int pad = 12 - (int)temp->kodePenerbangan.length();
        for (int i = 0; i < pad; i++) cout << ' ';
        cout << " | ";

        cout << temp->tujuan;
        int pad2 = 22 - (int)temp->tujuan.length();
        for (int i = 0; i < pad2; i++) cout << ' ';
        cout << " | ";

        cout << temp->status;
        int pad3 = 22 - (int)temp->status.length();
        for (int i = 0; i < pad3; i++) cout << ' ';
        cout << " |\n";

        temp = temp->prev;
    }

    cout << "+--------------+------------------------+------------------------+\n";
}

// Cari detail data berdasarkan kode atau tujuan
void cariDetail() {
    if (head == nullptr) {
        cout << "Belum ada jadwal penerbangan.\n";
        return;
    }

    string key;
    cout << "Masukkan Kode Penerbangan atau Tujuan: ";
    cin.ignore();
    getline(cin, key);

    Jadwal *temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == key || temp->tujuan == key) {
            cout << "\n=== DETAIL JADWAL ===\n";
            cout << "Kode   : " << temp->kodePenerbangan << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Data tidak ditemukan.\n";
    }
}

int main() {
    cout << "===== SISTEM JADWAL PENERBANGAN (DOUBLE LINKED LIST) =====\n";
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    cout << "==========================================================\n";

    int pilihan;
    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|                  FLIGHT SCHEDULE SYSTEM                    |\n";
        cout << "|              [ " << nama << " - " << nim << " ]             |\n";
        cout << "+----+-------------------------------------------------------+\n";
        cout << "| No | Menu                                                  |\n";
        cout << "+----+-------------------------------------------------------+\n";
        cout << "| 1  | Tambah Jadwal Penerbangan                             |\n";
        cout << "| 2  | Sisipkan Jadwal Penerbangan                           |\n";
        cout << "| 3  | Hapus Jadwal Paling Awal                              |\n";
        cout << "| 4  | Hapus Jadwal Paling Akhir                             |\n";
        cout << "| 5  | Hapus Jadwal Specific                                 |\n";
        cout << "| 6  | Update Status Penerbangan                             |\n";
        cout << "| 7  | Tampilkan Semua Jadwal (Dari Depan)                   |\n";
        cout << "| 8  | Tampilkan Semua Jadwal (Dari Belakang)                |\n";
        cout << "| 9  | Cari & Tampilkan Detail Jadwal                        |\n";
        cout << "| 0  | Keluar                                                |\n";
        cout << "+----+-------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipkanJadwal(); break;
            case 3: hapusAwal(); break;
            case 4: hapusAkhir(); break;
            case 5: {
                string kode;
                cin.ignore();
                cout << "Masukkan kode penerbangan yang ingin dihapus: ";
                getline(cin, kode);
                hapusSpecific(kode);
                break;
            }
            case 6: updateStatus(); break;
            case 7: tampilkanJadwal(); break;
            case 8: tampilkanReverse(); break;
            case 9: cariDetail(); break;
            case 0: cout << "Terimakasih telah menggunakan program ini...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
