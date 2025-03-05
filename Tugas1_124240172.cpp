#include <iostream>
#include <string>

using namespace std;

// Struktur untuk merepresentasikan data buku
struct Buku {
    string judul;
    int tahunTerbit;
};

// Fungsi untuk menampilkan daftar buku
void tampilkanDaftarBuku(Buku buku[], int n) {
    cout << "\nDaftar Buku:\n";
    for (int i = 0; i < n; i++) {
        cout << "Judul: " << buku[i].judul << " | Tahun Terbit: " << buku[i].tahunTerbit << endl;
    }
}

// Fungsi untuk mengurutkan buku dengan Bubble Sort
void bubbleSort(Buku buku[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (buku[j].tahunTerbit > buku[j + 1].tahunTerbit) {
                Buku temp = buku[j];
                buku[j] = buku[j + 1];
                buku[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan buku dengan Quick Sort
int partition(Buku buku[], int low, int high) {
    int pivot = buku[high].tahunTerbit;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (buku[j].tahunTerbit <= pivot) {
            i++;
            Buku temp = buku[i];
            buku[i] = buku[j];
            buku[j] = temp;
        }
    }
    Buku temp = buku[i + 1];
    buku[i + 1] = buku[high];
    buku[high] = temp;
    return (i + 1);
}

void quickSort(Buku buku[], int low, int high) {
    if (low < high) {
        int pi = partition(buku, low, high);
        quickSort(buku, low, pi - 1);
        quickSort(buku, pi + 1, high);
    }
}

// Fungsi untuk mencari buku menggunakan Sequential Search
int sequentialSearch(Buku buku[], int n, int tahun) {
    for (int i = 0; i < n; i++) {
        if (buku[i].tahunTerbit == tahun) {
            return i; // Mengembalikan indeks buku yang ditemukan
        }
    }
    return -1; // Buku tidak ditemukan
}

// Fungsi untuk mencari buku menggunakan Binary Search
int binarySearch(Buku buku[], int n, int tahun) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (buku[mid].tahunTerbit == tahun) {
            return mid; // Mengembalikan indeks buku yang ditemukan
        }
        else if (buku[mid].tahunTerbit < tahun) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // Buku tidak ditemukan
}

// Fungsi untuk input data buku
void inputDataBuku(Buku buku[], int& n) {
    cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
    cin >> n;
    cin.ignore(); // Mengabaikan newline character setelah memasukkan angka
    for (int i = 0; i < n; i++) {
        cout << "\nMasukkan Judul Buku ke-" << (i + 1) << ": ";
        getline(cin, buku[i].judul);
        cout << "Masukkan Tahun Terbit Buku: ";
        cin >> buku[i].tahunTerbit;
        cin.ignore();
    }
}

int main() {
    const int MAX_BUKU = 10;
    Buku buku[MAX_BUKU];
    int n = 0; // Jumlah buku yang dimasukkan
    int pilihan;

    do {
        cout << "\n=== Menu ==="
             << "\n1. Input Data Buku"
             << "\n2. Tampilkan Data Buku"
             << "\n3. Urutkan Buku dengan Bubble Sort"
             << "\n4. Urutkan Buku dengan Quick Sort"
             << "\n5. Cari Buku dengan Sequential Search"
             << "\n6. Cari Buku dengan Binary Search"
             << "\n7. Keluar"
             << "\nPilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Mengabaikan newline character setelah memasukkan angka

        switch (pilihan) {
            case 1: {
                inputDataBuku(buku, n);
                break;
            }
            case 2: {
                if (n == 0) {
                    cout << "Daftar buku kosong.\n";
                } else {
                    tampilkanDaftarBuku(buku, n);
                }
                break;
            }
            case 3: {
                if (n == 0) {
                    cout << "Daftar buku kosong.\n";
                } else {
                    cout << "Daftar Buku Sebelum Pengurutan:\n";
                    tampilkanDaftarBuku(buku, n);
                    bubbleSort(buku, n);
                    cout << "\nDaftar Buku Setelah Pengurutan dengan Bubble Sort:\n";
                    tampilkanDaftarBuku(buku, n);
                }
                break;
            }
            case 4: {
                if (n == 0) {
                    cout << "Daftar buku kosong.\n";
                } else {
                    cout << "Daftar Buku Sebelum Pengurutan:\n";
                    tampilkanDaftarBuku(buku, n);
                    quickSort(buku, 0, n - 1);
                    cout << "\nDaftar Buku Setelah Pengurutan dengan Quick Sort:\n";
                    tampilkanDaftarBuku(buku, n);
                }
                break;
            }
            case 5: {
                if (n == 0) {
                    cout << "Daftar buku kosong.\n";
                } else {
                    int tahun;
                    cout << "Masukkan tahun terbit buku yang dicari: ";
                    cin >> tahun;
                    int hasil = sequentialSearch(buku, n, tahun);
                    if (hasil != -1) {
                        cout << "Buku ditemukan: " << buku[hasil].judul << " | Tahun Terbit: " << buku[hasil].tahunTerbit << endl;
                    } else {
                        cout << "Buku tidak ditemukan.\n";
                    }
                }
                break;
            }
            case 6: {
                if (n == 0) {
                    cout << "Daftar buku kosong.\n";
                } else {
                    int tahun;
                    cout << "Masukkan tahun terbit buku yang dicari: ";
                    cin >> tahun;
                    // Sebelum melakukan binary search, pastikan data sudah terurut
                    quickSort(buku, 0, n - 1);
                    int hasil = binarySearch(buku, n, tahun);
                    if (hasil != -1) {
                        cout << "Buku ditemukan: " << buku[hasil].judul << " | Tahun Terbit: " << buku[hasil].tahunTerbit << endl;
                    } else {
                        cout << "Buku tidak ditemukan.\n";
                    }
                }
                break;
            }
            case 7: {
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                break;
            }
        }
    } while (pilihan != 7);

    return 0;
}

// Output
// === Menu === 
// 1. Input Data Buku
// 2. Tampilkan Data Buku
// 3. Urutkan Buku dengan Bubble Sort
// 4. Urutkan Buku dengan Quick Sort
// 5. Cari Buku dengan Sequential Search
// 6. Cari Buku dengan Binary Search
// 7. Keluar
// Pilihan Anda: 1
// Masukkan jumlah buku yang ingin ditambahkan: 3
