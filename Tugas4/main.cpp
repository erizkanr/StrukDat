#include <iostream>
using namespace std;

struct strukAngka {
    int angka;        // Data yang disimpan dalam node
    strukAngka *next;   // Pointer ke node berikutnya dalam list
    strukAngka *prev;   // Pointer ke node sebelumnya dalam list
};

// Inisialisasi pointer head dan tail ke NULL
strukAngka *awal = NULL, *akhir = NULL, *curr, *baru;

// Fungsi untuk menyisipkan sebuah node di awal doubly linked list
void inputdidepan(int isiAngka) {
    // membuat sebuah node baru
    baru = new strukAngka;

    // pointer next dan previous dari node baru ke NULL
    baru->next = NULL;
    baru->prev = NULL;

    // data dalam node baru
    baru->angka = isiAngka;

    // Jika list kosong,pointer head dan tail ke node baru
    if (awal == NULL) {
        awal = akhir = baru;
    }
    // Jika tidak, sisipkan node baru di awal list
    else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }

    // Bersihkan layar
    system("cls");
}

// Fungsi untuk menyisipkan sebuah node di akhir doubly linked list
void inputdibelakang(int isiAngka) {
    // Buat sebuah node baru
    baru = new strukAngka;

    // pointer next dan previous dari node baru ke NULL
    baru->next = NULL;
    baru->prev = NULL;

    // data dalam node baru
    baru->angka = isiAngka;

    // Jika list kosong, pointer head dan tail ke node baru
    if (awal == NULL) {
        awal = akhir = baru;
    }
    // Jika tidak, sisipkan node baru di akhir list
    else {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }

    // Bersihkan layar
    system("cls");
}

// Fungsi untuk mencetak data dalam doubly linked list
void outputData() {
    // pointer current ke head list
    curr = awal;

    // Lintasi list dan cetak data dalam setiap node
    while (curr != NULL) {
        cout << curr->angka << " ";
        curr = curr->next;
    }

    // Cetak karakter newline
    cout << endl;
}

// Fungsi untuk membalikkan doubly linked list
void balikangka() {
    // pointer current ke head list
    strukAngka* curr = awal;

    // pointer previous dan next ke NULL
    strukAngka *prev = NULL, *next = NULL;

    // Lintasi list dan balikkan pointer
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // pointer head ke head baru dari list
    awal = prev;
}

int main() {
    // Sisipkan angka 5, 4, 3, 2, dan 1 ke dalam doubly linked list
    inputdidepan(5);
    inputdibelakang(4);
    inputdibelakang(3);
    inputdibelakang(2);
    inputdibelakang(1);

    // Cetak doubly linked list asli
    outputData();

    // Balikkan doubly linked list
    balikangka();

    // Cetak doubly linked list yang sudah dibalik
    outputData();

    return 0;
}
