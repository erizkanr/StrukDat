#include <iostream>
#include <string>

using namespace std;

// Struct untuk data tiket
struct Tiket {
    string nama_konser;
    int harga;
    int jumlah_tiket;
    Tiket* next;
};

// Fungsi untuk menambahkan tiket ke linked list
void tambahTiket(Tiket*& head, string nama_konser, int harga, int jumlah_tiket) {
    Tiket* baru = new Tiket;
    baru->nama_konser = nama_konser;
    baru->harga = harga;
    baru->jumlah_tiket = jumlah_tiket;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Tiket* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Fungsi untuk menampilkan daftar tiket dari linked list
void tampilkanDaftarTiket(Tiket* head) {
    cout << "Daftar Tiket:" << endl;
    Tiket* temp = head;
    while (temp != nullptr) {
        cout << "========================================"<< endl;
        cout << "Konser                 : " << temp->nama_konser << endl;
        cout << "Harga Tiket            : " << temp->harga << endl;
        cout << "Jumlah Tiket Tersedia  : " << temp->jumlah_tiket << endl;
        cout << "========================================"<< endl;
        cout << endl;
        temp = temp->next;
    }
}

// Fungsi untuk membeli tiket
void beliTiket(Tiket* head) {
    string nama_konser;
    cout << "Masukkan Nama Konser yang Ingin Dibeli Tiketnya: ";
    cin.ignore(); // Mengabaikan newline di buffer
    getline(cin, nama_konser);

    // Mencari tiket dengan nama konser yang sesuai dalam linked list
    Tiket* temp = head;
    while (temp != nullptr) {
        if (temp->nama_konser == nama_konser) {
            break;
        }
        temp = temp->next;
    }

    // Jika tiket ditemukan
    if (temp != nullptr) {
        int jumlah_beli;
        cout << "Masukkan Jumlah Tiket yang Ingin Dibeli (maksimal 10): ";
        cin >> jumlah_beli;

        if (jumlah_beli <= 0 || jumlah_beli > 10) {
            cout << "Maaf, jumlah tiket yang dimasukkan melebihi batas maximal." << endl;
            return;
        }

        // Memeriksa ketersediaan tiket
        if (jumlah_beli <= temp->jumlah_tiket) {
            // Mengurangi jumlah tiket yang tersedia
            temp->jumlah_tiket -= jumlah_beli;
            cout << "Pembelian Tiket Berhasil." << endl;
            cout << "Berikut Total Harga yang perlu di bayar: " << (jumlah_beli * temp->harga) << endl;

            // Menyimpan pembelian dalam array sementara
            int pembelian[10];
            for (int i = 0; i < jumlah_beli; ++i) {
                pembelian[i] = temp->harga;
            }
        } else {
            cout << "Maaf, pembelian tiket melebihi batas pembelian!" << endl;
        }
    } else {
        cout << "Maaf, Tiket untuk konser tersebut tidak ada di program kami" << endl;
    }
}

int main() {
    Tiket* head = nullptr;

    // Menambahkan tiket konser ke linked list (bagian yang hilang)
    tambahTiket(head, "Konser Enhypen", 880000, 50);
    tambahTiket(head, "Konser &Team", 670000, 70);
    tambahTiket(head, "Konser TXT", 890000, 60);
    tambahTiket(head, "Konser TWS", 510000, 80);
    tambahTiket(head, "Konser ILLIT", 560000, 65);

    int pilihan;

    while (true) {
        // Tampilkan menu
        cout << endl;
        cout << "==WELCOME TO PROGRAM BUY CONSERT TIKETS==" << endl;
        cout << endl;
        cout << "Silahkan Pilih MENU berikut:" << endl;
        cout << "1. Tampilkan Daftar Tiket" << endl;
        cout << "2. Beli Tiket" << endl;
        cout << "3. Selesai" << endl;
        cout << endl;

        // Meminta user untuk memilih menu
        cout << "Silahkan Pilih menu yang diinginkan: ";
        cin >> pilihan;
        cout << endl;

        // Melakukan operasi sesuai dengan pilihan pengguna
        switch (pilihan) {
            case 1:
                tampilkanDaftarTiket(head);
                break;
            case 2:
                beliTiket(head);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program kami" << endl;
                return 0;
            default:
                cout << " Maaf pilihan yang anda masukkan tidak valid!" << endl;
        }
    }

    return 0;
}
