#include <iostream>
#include <string>

using namespace std;

// Struct untuk data mahasiswa
struct Mahasiswa {
    string npm;
    string nama;
};

// Struct untuk data nilai
struct Nilai {
    int absen;
    int tugas;
    int uts;
    int uas;
    double akhir;
    char huruf;
};

// Array untuk menyimpan data mahasiswa dan nilai
Mahasiswa mahasiswa[20];
Nilai nilai[20];

// Jumlah data mahasiswa
int jumlah_mahasiswa = 0;

// Fungsi untuk menghitung nilai akhir
double hitungNilaiAkhir(Nilai nilai) {
    return 0.1 * nilai.absen + 0.2 * nilai.tugas + 0.3 * nilai.uts + 0.4 * nilai.uas;
}

// Fungsi untuk menentukan nilai huruf
char tentukanNilaiHuruf(double nilaiAkhir) {
    if (nilaiAkhir > 80) {
        return 'A';
    } else if (nilaiAkhir >= 70) {
        return 'B';
    } else if (nilaiAkhir >= 60) {
        return 'C';
    } else {
        return 'D';
    }
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << endl;
    cout << "Silahkan Pilih MENU berikut:" << endl;
    cout << "1. Input Data Mahasiswa" << endl;
    cout << "2. Tampil Data Mahasiswa" << endl;
    cout << "3. Edit Data Mahasiswa" << endl;
    cout << "4. Hapus Data Mahasiswa" << endl;
    cout << "5. Keluar" << endl;
    cout << endl;
}

// Fungsi untuk input data mahasiswa
void inputDataMahasiswa() {
    cout << "    Data Mahasiswa   " << endl;
    cout << "Masukkan NPM: ";
    cin >> mahasiswa[jumlah_mahasiswa].npm;
    cout << "Masukkan Nama: ";
    cin >> mahasiswa[jumlah_mahasiswa].nama;
    cout << "Masukkan Nilai Absen: ";
    cin >> nilai[jumlah_mahasiswa].absen;
    cout << "Masukkan Nilai Tugas: ";
    cin >> nilai[jumlah_mahasiswa].tugas;
    cout << "Masukkan Nilai UTS: ";
    cin >> nilai[jumlah_mahasiswa].uts;
    cout << "Masukkan Nilai UAS: ";
    cin >> nilai[jumlah_mahasiswa].uas;

    // Menghitung nilai akhir
    nilai[jumlah_mahasiswa].akhir = hitungNilaiAkhir(nilai[jumlah_mahasiswa]);

    // Menentukan nilai huruf
    nilai[jumlah_mahasiswa].huruf = tentukanNilaiHuruf(nilai[jumlah_mahasiswa].akhir);

    jumlah_mahasiswa++;
}

// Fungsi untuk menampilkan data mahasiswa
void tampilDataMahasiswa() {
    cout << "      Data Mahasiswa   " << endl;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "NPM: " << mahasiswa[i].npm << endl;
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "Nilai Absen: " << nilai[i].absen << endl;
        cout << "Nilai Tugas: " << nilai[i].tugas << endl;
        cout << "Nilai UTS: " << nilai[i].uts << endl;
        cout << "Nilai UAS: " << nilai[i].uas << endl;
        cout << "Nilai Akhir: " << nilai[i].akhir << endl;
        cout << "Nilai Huruf: " << nilai[i].huruf << endl;
        cout << endl;
    }
}

// Fungsi untuk mengedit data mahasiswa
void editDataMahasiswa() {
    string npm;
    cout << "Masukkan NPM mahasiswa yang ingin diedit: ";
    cin >> npm;

    // Mencari indeks mahasiswa dengan NPM yang diberikan
    int index = -1;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (mahasiswa[i].npm == npm) {
            index = i;
            break;
        }
    }

    // Jika mahasiswa ditemukan, edit datanya
    if (index != -1) {
        cout << "Masukkan Nama Baru: ";
        cin >> mahasiswa[index].nama;
        cout << "Masukkan Nilai Absen Baru: ";
        cin >> nilai[index].absen;
        cout << "Masukkan Nilai Tugas Baru: ";
        cin >> nilai[index].tugas;
        cout << "Masukkan Nilai UTS Baru: ";
        cin >> nilai[index].uts;
        cout << "Masukkan Nilai UAS Baru: ";
        cin >> nilai[index].uas;

        // Menghitung nilai akhir
        nilai[index].akhir = hitungNilaiAkhir(nilai[index]);

        // Menentukan nilai huruf
        nilai[index].huruf = tentukanNilaiHuruf(nilai[index].akhir);

        cout << "Data mahasiswa berhasil diedit." << endl;
    } else {
        cout << "Mahasiswa dengan NPM tersebut tidak ditemukan." << endl;
    }
}

// Fungsi untuk Menghapus data mahasiswa
void hapusDataMahasiswa() {
    string npm;
    cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
    cin >> npm;

    // Mencari indeks mahasiswa dengan NPM yang diberikan
    int index = -1;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (mahasiswa[i].npm == npm) {
            index = i;
            break;
        }
    }

    // Jika mahasiswa ditemukan, hapus datanya
    if (index != -1) {
        // Mengeser data mahasiswa setelahnya ke depan
        for (int i = index; i < jumlah_mahasiswa - 1; i++) {
            mahasiswa[i] = mahasiswa[i + 1];
            nilai[i] = nilai[i + 1];
        }

        // Kurangi jumlah mahasiswa
        jumlah_mahasiswa--;

        cout << "Data mahasiswa berhasil dihapus." << endl;
    } else {
        cout << "Mahasiswa dengan NPM tersebut tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;

    while (true) {
        // Tampilkan menu
        tampilkanMenu();

        // Meminta user untuk memilih menu
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << endl;

        // Melakukan operasi sesuai dengan pilihan pengguna
        switch (pilihan) {
            case 1:
                inputDataMahasiswa();
                break;
            case 2:
                tampilDataMahasiswa();
                break;
            case 3:
                editDataMahasiswa();
                break;
            case 4:
                hapusDataMahasiswa();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
