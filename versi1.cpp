#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Menggunakan struct agar kode lebih pendek dibanding class (tidak perlu Getter/Setter)
struct Mahasiswa {
    string nama, nim;
    float ipk;
};

// Fungsi input data mahasiswa
void tambahMahasiswa(vector<Mahasiswa>& daftar) {
    Mahasiswa m;
    cout << "\nNAMA: "; cin >> m.nama; cin.ignore();
    cout << "NIM: "; getline(cin, m.nim);
    cout << "IPK: "; cin >> m.ipk;
    daftar.push_back(m);
    cout << "Data berhasil ditambahkan!\n";
}

// Fungsi menampilkan semua data
void tampilkanSemua(const vector<Mahasiswa>& daftar) {
    if (daftar.empty()) { cout << "Data kosong.\n"; return; }
    int i = 1;
    for (const auto& mhs : daftar) {
        cout << i++ << ". NAMA: " << mhs.nama << " | NIM: " << mhs.nim << " | IPK: " << mhs.ipk << "\n";
    }
}

// Fungsi hitung rata-rata IPK
void hitungRataRata(const vector<Mahasiswa>& daftar) {
    if (daftar.empty()) { cout << "Data kosong.\n"; return; }
    float total = 0;
    for (const auto& mhs : daftar) total += mhs.ipk;
    cout << "Rata-rata IPK: " << total / daftar.size() << "\n";
}

// Fungsi pencarian ekstrem (bisa cari Tertinggi atau Terendah sekaligus)
// Jika 'cariTertinggi' bernilai true -> cari tertinggi. Jika false -> cari terendah.
void cariEkstrem(const vector<Mahasiswa>& daftar, bool cariTertinggi) {
    if (daftar.empty()) { cout << "Data kosong.\n"; return; }
    const Mahasiswa* target = &daftar[0];
    
    for (const auto& mhs : daftar) {
        if (cariTertinggi ? (mhs.ipk > target->ipk) : (mhs.ipk < target->ipk)) {
            target = &mhs;
        }
    }
    cout << "NAMA: " << target->nama << " | NIM: " << target->nim << " | IPK: " << target->ipk << "\n";
}

int main() {
    vector<Mahasiswa> daftar;
    int pilihan;

    do {
        cout << "\nMenu:\n1. Tambah Data Mahasiswa \n2. Tampilkan Seluruh Data Mahasiswa \n3. Rata-rata IPK dari Seluruh Mahasiswa \n4. IPK Tertinggi\n5. IPK Terendah\n6. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahMahasiswa(daftar); break;
            case 2: tampilkanSemua(daftar); break;
            case 3: hitungRataRata(daftar); break;
            case 4: cout << "\n--- IPK Tertinggi ---\n"; cariEkstrem(daftar, true); break;
            case 5: cout << "\n--- IPK Terendah ---\n"; cariEkstrem(daftar, false); break;
            case 6: cout << "Keluar program.\n"; break;
            default: cout << "Pilihan salah!\n";
        }
    } while (pilihan != 6);

    return 0;
}
