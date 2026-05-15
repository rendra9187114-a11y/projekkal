#include <iostream>
#include <string>
using namespace std;

// =====================
// STRUCT
// =====================
struct Buku {
    string nama;
};

struct Peminjam {
    string nama;
    string buku;
};

// =====================
// DATA BUKU
// =====================
Buku daftarBuku[] = {
    {"Algoritma"},
    {"Algoritma nyoto"},
    {"Struktur Data"},
    {"Matematika"}
};

int jumlahBuku = sizeof(daftarBuku)/sizeof(daftarBuku[0]);

// =====================
// QUEUE ARRAY
// =====================
Peminjam antrian[100];

int front = 0;
int rear = -1;

// =====================
// SORTING
// Bubble Sort berdasarkan nama buku
// =====================
void bubbleSort() {
    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = 0; j < jumlahBuku - i - 1; j++) {
            if (daftarBuku[j].nama > daftarBuku[j + 1].nama) {
                Buku temp;
                
                temp = daftarBuku[j];
                daftarBuku[j] = daftarBuku[j+1];
                daftarBuku[j+1] = temp;
            }
        }
    }
}

// =====================
// TAMPILKAN BUKU
// =====================
void tampilkanBuku() {

    bubbleSort();
    cout << "\n=== DAFTAR BUKU ===\n";
    for (int i = 0; i < jumlahBuku; i++) {
        cout << i + 1<<". "<<daftarBuku[i].nama<< endl;
    }
}

// =====================
// TAMBAH BUKU
// =====================
void tambahBuku() {
    cin.ignore();
    cout << "\n=== TAMBAH BUKU ===\n";
    cout << "Masukkan nama buku : ";
    getline(cin, daftarBuku[jumlahBuku].nama);
    jumlahBuku++;
    cout << "Buku berhasil ditambahkan.\n";
}

// =====================
// SEARCHING
// Linear Search
// =====================
void cariBuku() {

    string cari;
    bool ketemu = false;
    cin.ignore();
    cout << "Masukkan nama buku: ";
    getline(cin, cari);
    cout << "\nHasil pencarian:\n";
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].nama.find(cari) != string::npos) {
            cout << daftarBuku[i].nama<< endl;
            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "Buku tidak ditemukan.\n";
    }
}

// =====================
// TAMBAH PEMINJAM
// =====================
void tambahPeminjam() {
    string namaPeminjam;
    string namaBuku;
    bool ketemu = false;
    cin.ignore();
    cout << "Masukkan nama peminjam: ";
    getline(cin, namaPeminjam);
    cout << "Masukkan nama buku: ";
    getline(cin, namaBuku);
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].nama == namaBuku) {
            rear++;
            antrian[rear].nama = namaPeminjam;
            antrian[rear].buku = namaBuku;
            cout << "Peminjaman berhasil ditambahkan.\n";
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Buku tidak tersedia.\n";
    }
}

// =====================
// LIHAT ANTRIAN
// =====================
void lihatAntrian() {

    if (front > rear) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "\n=== ANTRIAN PEMINJAM ===\n";
    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". "
             << antrian[i].nama
             << " meminjam "
             << antrian[i].buku
             << endl;
    }
}

/*
=====================
  PROSES PEMINJAMAN
=====================*/
void prosesPeminjaman() {
    if (front > rear) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "\nPeminjaman diproses:\n";
    cout << "Nama : "<<antrian[front].nama<<endl;
    cout << "Buku : "<<antrian[front].buku<<endl;
    front++;
}

// =====================
// MAIN
// =====================
int main() {
    int pilihan;
    do {
        cout << "\n===== SISTEM PERPUSTAKAAN =====\n";
        cout << "1. Tampilkan daftar buku\n";
        cout << "2. Cari buku\n";
        cout << "3. Tambah buku\n";
        cout << "4. Tambah peminjam\n";
        cout << "5. Lihat antrian\n";
        cout << "6. Proses peminjaman\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tampilkanBuku();
                break;

            case 2:
                cariBuku();
                break;

            case 3:
                tambahBuku();
                break;

            case 4:
                tambahPeminjam();
                break;

            case 5:
                lihatAntrian();
                break;

            case 6:
                prosesPeminjaman();
                break;

            case 7:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 7);

    return 0;
}
