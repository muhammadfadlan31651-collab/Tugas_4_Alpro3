#include <iostream>   
#include <vector>     // ini buat vector, kayak array tapi bisa nambah sendiri ukurannya
#include <string>   
using namespace std;  

// class mahasiswa buat nyimpen data tiap mahasiswa
class Mahasiswa {
public:
    string nama, nim;  // nama sama nim tipe string karena isinya huruf dan angka campur
    float ipk;         // ipk pake float karena nilainya bisa desimal kayak 3.75, 2.50, dll

    // ini constructor, dipanggil otomatis waktu kita bikin objek mahasiswa baru
    // parameter n, id, nilai itu nilai yang kita kirim waktu bikin objeknya
    Mahasiswa(string n, string id, float nilai) {
        nama = n;      // nilai dari parameter n disimpen ke atribut nama
        nim = id;      // nilai dari parameter id disimpen ke atribut nim
        ipk = nilai;   // nilai dari parameter nilai disimpen ke atribut ipk
    }

    // fungsi buat nampilin data mahasiswa ini ke layar
    // void artinya fungsi ini gak ngembaliin nilai apapun, cuma nampilin aja
    void tampil() {
        cout << "Nama : " << nama << endl;  // nampilin nama
        cout << "NIM  : " << nim << endl;   // nampilin nim
        cout << "IPK  : " << ipk << endl;   // nampilin ipk
        cout << "-------------------" << endl;  // garis pemisah biar keliatan rapi
    }
};

// vector ini kayak wadah buat nyimpen semua objek mahasiswa yang udah dibuat
// dia global jadi bisa diakses dari fungsi manapun
vector<Mahasiswa> dataMhs;

// fungsi buat nambahin data mahasiswa baru ke dalam vector
void tambah() {
    string nama, nim;  // variabel sementara buat nyimpen input dari user
    float ipk;

    cout << "\nMasukkan data mahasiswa baru" << endl;

    // cin.ignore() ini penting banget, fungsinya buat buang karakter newline
    // yang tersisa di buffer setelah cin >>, kalau gak ada ini getline bakal kelewat
    cout << "Nama : ";
    cin.ignore();
    getline(cin, nama);  // getline dipake biar bisa input nama yang ada spasinya

    cout << "NIM  : ";
    getline(cin, nim);   // sama kayak nama, pake getline biar aman

    cout << "IPK  : ";
    cin >> ipk;  // ipk langsung pake cin >> karena cuma angka

    // setelah semua data diinput, langsung bikin objek mahasiswa baru
    // terus dimasukin ke vector dataMhs pake push_back
    // push_back itu nambahin elemen baru di posisi paling belakang vector
    dataMhs.push_back(Mahasiswa(nama, nim, ipk));

    cout << "Data berhasil ditambahkan!" << endl;
}

// fungsi buat nampilin semua data mahasiswa yang ada di vector
void tampilSemua() {
    // sebelum nampilin, cek dulu apakah vectornya kosong atau tidak
    // kalau kosong langsung kasih tau user terus keluar dari fungsi pake return
    if (dataMhs.empty()) {
        cout << "\nBelum ada data mahasiswa." << endl;
        return;  // langsung balik, gak perlu lanjut ke bawah
    }

    cout << "\n=== Daftar Mahasiswa ===" << endl;

    // loop dari index 0 sampai habis semua data di vector
    // dataMhs.size() itu ngasih tau jumlah data yang ada di vector
    for (int i = 0; i < dataMhs.size(); i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;  // i+1 biar mulai dari 1 bukan 0
        dataMhs[i].tampil();  // panggil fungsi tampil() punya masing-masing objek
    }
}

// fungsi buat ngitung rata-rata ipk semua mahasiswa
void rataRata() {
    // sama kayak fungsi lain, cek dulu datanya ada atau tidak
    if (dataMhs.empty()) {
        cout << "\nBelum ada data mahasiswa." << endl;
        return;
    }

    float total = 0;  // variabel penampung total ipk, awalnya 0

    // loop semua data, tiap iterasi ipk nya ditambahin ke total
    for (int i = 0; i < dataMhs.size(); i++) {
        total += dataMhs[i].ipk;  // total = total + ipk mahasiswa ke-i
    }

    // setelah semua ipk dijumlahin, bagi sama jumlah mahasiswanya
    // dataMhs.size() itu jumlah mahasiswa yang ada
    float rata = total / dataMhs.size();

    cout << "\nRata-rata IPK seluruh mahasiswa : " << rata << endl;
}

// fungsi buat nyari dan nampilin mahasiswa yang ipknya paling tinggi
void ipkTertinggi() {
    if (dataMhs.empty()) {
        cout << "\nBelum ada data mahasiswa." << endl;
        return;
    }

    // idx itu index mahasiswa yang ipknya tertinggi
    // dianggap dulu index 0 (mahasiswa pertama) yang tertinggi
    int idx = 0;

    // mulai loop dari index 1 karena index 0 udah jadi pembanding awal
    for (int i = 1; i < dataMhs.size(); i++) {
        // kalau ketemu mahasiswa yang ipknya lebih tinggi dari yang sekarang
        // update idx ke index mahasiswa itu
        if (dataMhs[i].ipk > dataMhs[idx].ipk) {
            idx = i;
        }
    }

    // setelah loop selesai, idx udah nunjuk ke mahasiswa dengan ipk tertinggi
    cout << "\nMahasiswa dengan IPK Tertinggi :" << endl;
    dataMhs[idx].tampil();  // tinggal tampilin datanya
}

// fungsi buat nyari dan nampilin mahasiswa yang ipknya paling rendah
// logikanya sama persis kayak ipkTertinggi, cuma tandanya dibalik jadi <
void ipkTerendah() {
    if (dataMhs.empty()) {
        cout << "\nBelum ada data mahasiswa." << endl;
        return;
    }

    int idx = 0;  // anggap dulu mahasiswa pertama yang terendah

    for (int i = 1; i < dataMhs.size(); i++) {
        // bedanya disini, kalau ketemu yang lebih KECIL baru di update
        if (dataMhs[i].ipk < dataMhs[idx].ipk) {
            idx = i;
        }
    }

    cout << "\nMahasiswa dengan IPK Terendah :" << endl;
    dataMhs[idx].tampil();
}

// fungsi utama, program mulai jalan dari sini
int main() {
    int pilih;  // variabel buat nyimpen pilihan menu dari user

    // pake do-while biar menu ditampilin minimal sekali dulu
    // baru ngecek kondisinya di belakang
    do {
        // tampilin semua pilihan menu
        cout << "\n===== Menu =====" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Tampilkan Seluruh Data Mahasiswa" << endl;
        cout << "3. Hitung Rata-rata IPK Mahasiswa" << endl;
        cout << "4. Mahasiswa dengan IPK Tertinggi" << endl;
        cout << "5. Mahasiswa dengan IPK Terendah" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilih;  // baca pilihan dari user

        // switch case buat nentuin fungsi mana yang dipanggil
        // sesuai sama angka yang diinput user
        switch(pilih) {
            case 1: tambah(); break;        // kalau pilih 1, panggil fungsi tambah
            case 2: tampilSemua(); break;   // kalau pilih 2, tampil semua data
            case 3: rataRata(); break;      // kalau pilih 3, hitung rata-rata
            case 4: ipkTertinggi(); break;  // kalau pilih 4, cari ipk tertinggi
            case 5: ipkTerendah(); break;   // kalau pilih 5, cari ipk terendah
            case 6: cout << "Keluar dari program..." << endl; break;  // kalau 6, keluar
            default: cout << "Pilihan tidak ada, coba lagi!" << endl; // selain itu salah
        }

    } while (pilih != 6);  // terus looping sampai user pilih 6 buat keluar

    return 0;  // return 0 artinya program selesai tanpa error
}
