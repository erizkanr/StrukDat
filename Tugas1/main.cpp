#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int n;
  int arr[n][n];

  // Meminta input dari user
  cout << "Masukkan nilai n: ";
  cin >> n;

  // Mengisi array dengan nilai
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "Masukkan nilai arr[" << i << "][" << j << "]: ";
      cin >> arr[i][j];
    }
  }

  // Menampilkan array sebelum transpose
  cout << "Array sebelum transpose:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // Transpose array
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // Swap elemen array
      int temp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = temp;
    }
  }

  // Menampilkan array setelah transpose
  cout << "Array setelah transpose:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
