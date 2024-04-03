#include <iostream>

using namespace std;


// Fungsi untuk membuat matriks persegi n x n
int** createSquareMatriks(int n) {
    int** matriks = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriks[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matriks[i][j] = i * n + j + 1;  // Isi matriks dengan angka sesuai urutan
        }
    }
    return matriks;
}

// Fungsi untuk menampilkan matriks
void displayMatriks(int n, int** matriks) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk melakukan transpose matriks secara in-place
void transposeMatriks(int n, int** matriks) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Tukar elemen (i, j) dengan elemen (j, i) secara in-place
            matriks[i][j] = matriks[i][j] + matriks[j][i];
            matriks[j][i] = matriks[i][j] - matriks[j][i];
            matriks[i][j] = matriks[i][j] - matriks[j][i];
        }
    }
}

// Fungsi untuk menghapus matriks dan mencegah kebocoran memori
void deleteMatriks(int n, int** matriks) {
    for (int i = 0; i < n; ++i) {
        delete[] matriks[i];
    }
    delete[] matriks;
}

int main() {
    // Ukuran matriks
    int n;
    cout << "Masukkan ukuran matriks (n x n): ";
    cin >> n;
    cout << endl;

    // Membuat matriks persegi
    int** matriks = createSquareMatriks(n);

    // Menampilkan matriks sebelum transpose
    cout << "Matriks Sebelum Transpose:" << endl;
    displayMatriks(n, matriks);

    // Melakukan transpose matriks secara in-place
    transposeMatriks(n, matriks);

    // Menampilkan matriks setelah transpose
    cout << "\nMatriks Setelah Transpose:" << endl;
    displayMatriks(n, matriks);

    // Menghapus matriks untuk mencegah kebocoran memori
    deleteMatriks(n, matriks);

    return 0;
}
