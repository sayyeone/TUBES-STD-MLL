# Sistem Bimbingan Tugas Akhir

Program ini merupakan implementasi Multi Linked-List untuk mengelola data dosen dan mahasiswa yang saling berelasi dalam sistem bimbingan tugas akhir. Seorang dosen dapat membimbing banyak mahasiswa, sementara seorang mahasiswa dapat memiliki 1 hingga 2 dosen pembimbing.

## Deskripsi Project

Program ini dibangun menggunakan struktur data multi linked-list dengan relasi Many-to-Many (M:N) antara dosen sebagai parent dan mahasiswa sebagai child. Implementasi ini dirancang secara modular dengan pemisahan file yang jelas untuk memudahkan maintenance dan pengembangan lebih lanjut.

### Struktur Data yang Digunakan

Program menggunakan tiga jenis linked list yang berbeda:

**List Dosen (Parent)** menggunakan Circular Single Linked List dengan metode insert first. Setiap node dosen menyimpan informasi NIP, nama, dan jumlah bimbingan, serta memiliki pointer ke list relasi yang berisi mahasiswa bimbingannya.

**List Mahasiswa (Child)** menggunakan Double Linked List dengan metode insert first. Setiap node mahasiswa menyimpan informasi NIM, nama, dan IPK sebagai data akademik.

**List Relasi** menggunakan Single Linked List yang menyimpan pointer ke mahasiswa. List ini berfungsi sebagai penghubung antara dosen dan mahasiswa bimbingannya.

## Fitur Program

Program ini menyediakan berbagai fitur untuk mengelola data bimbingan tugas akhir:

**Manajemen Data Dosen** - Pengguna dapat menambahkan data dosen baru ke dalam sistem dan menghapus data dosen tertentu beserta seluruh relasinya dengan mahasiswa.

**Manajemen Data Mahasiswa** - Sistem memungkinkan penambahan data mahasiswa baru dan penghapusan data mahasiswa tertentu yang secara otomatis juga akan menghapus relasi dengan semua dosen pembimbingnya.

**Manajemen Relasi** - Pengguna dapat menentukan relasi bimbingan antara dosen dan mahasiswa, dengan sistem yang memastikan seorang mahasiswa tidak memiliki lebih dari 2 dosen pembimbing.

**Tampilan Data** - Program dapat menampilkan data keseluruhan mahasiswa beserta dosen pembimbingnya, menampilkan daftar mahasiswa yang dibimbing oleh dosen tertentu, menampilkan dosen pembimbing dari mahasiswa tertentu, dan menampilkan statistik dosen dengan jumlah bimbingan terbanyak dan tersedikit.

## Struktur Folder Project

```
TUBES_MLL/
│
├── include/              Header files untuk deklarasi
│   ├── dosen.h          Struktur dan fungsi dosen
│   ├── mahasiswa.h      Struktur dan fungsi mahasiswa
│   └── relasi.h         Struktur dan fungsi relasi
│
├── src/                  Implementation files
│   ├── dosen.cpp        Implementasi fungsi dosen
│   ├── mahasiswa.cpp    Implementasi fungsi mahasiswa
│   └── relasi.cpp       Implementasi fungsi relasi
│
├── app/                  Application logic
│   ├── injector.cpp     Mode inject data otomatis
│   ├── manual.cpp       Mode input manual user
│   └── mode.cpp         Pemilih mode operasi
│
├── build/                Folder hasil compile (auto-generated)
├── main.cpp              Entry point program
├── Makefile              Build automation
└── README.md             Dokumentasi
```

## Cara Instalasi dan Menjalankan

### Persiapan Awal

Pertama, clone repository ini ke komputer lokal Anda:

```bash
git clone https://github.com/username/TUBES_MLL.git
cd TUBES_MLL
```

Pastikan compiler C++ sudah terinstall di sistem Anda. Untuk Linux/Ubuntu, install dengan:

```bash
sudo apt update
sudo apt install g++ make
```

Untuk Windows, Anda dapat menggunakan MinGW atau MSYS2. Download dari [mingw-w64.org](https://www.mingw-w64.org/).

Untuk MacOS, install Command Line Tools:

```bash
xcode-select --install
```

### Kompilasi Program

Cara termudah adalah menggunakan Makefile yang sudah disediakan:

```bash
make
```

Perintah ini akan mengcompile semua source file dan menghasilkan executable `bimbingan_ta`. Folder `build/` akan dibuat secara otomatis untuk menyimpan object files.

Jika Anda tidak menggunakan Makefile, compile secara manual dengan:

```bash
g++ -Wall -std=c++11 -o bimbingan_ta \
    src/dosen.cpp \
    src/mahasiswa.cpp \
    src/relasi.cpp \
    app/injector.cpp \
    app/manual.cpp \
    app/mode.cpp \
    main.cpp
```

### Menjalankan Program

Setelah kompilasi berhasil, jalankan program dengan:

```bash
./bimbingan_ta          # Linux/MacOS
bimbingan_ta.exe        # Windows
```

### Membersihkan Build Files

Untuk menghapus file hasil kompilasi:

```bash
make clean
```

## Cara Penggunaan

Saat program dijalankan, Anda akan disambut dengan menu pemilihan mode:

### Mode Otomatis (Inject Data)

Mode ini akan langsung mengisi sistem dengan data sample yang terdiri dari 4 dosen, 7 mahasiswa, dan 10 relasi bimbingan. Mode ini sangat berguna untuk testing dan demonstrasi fitur program tanpa perlu input manual. Setelah data terisi, Anda akan langsung masuk ke menu utama.

### Mode Manual (Input User)

Mode ini memberikan sistem kosong yang siap diisi dengan data sesuai kebutuhan Anda. Cocok untuk eksperimen dan customisasi data sendiri.

### Menu Utama

Setelah memilih mode, program akan menampilkan menu utama dengan 11 pilihan:

**Menu 1 - Tambah Data Dosen**: Input NIP dan nama dosen baru ke sistem.

**Menu 2 - Tambah Data Mahasiswa**: Input NIM, nama, dan IPK mahasiswa baru.

**Menu 3 - Hubungkan Dosen-Mahasiswa**: Membuat relasi bimbingan dengan memasukkan NIP dosen dan NIM mahasiswa.

**Menu 4 - Hapus Data Dosen**: Menghapus dosen beserta seluruh relasi bimbingannya.

**Menu 5 - Hapus Data Mahasiswa**: Menghapus mahasiswa dan memutus relasi dengan semua dosen pembimbingnya.

**Menu 6 - Tampilkan Semua Mahasiswa & Dosennya**: Menampilkan daftar lengkap mahasiswa beserta informasi dosen pembimbing masing-masing.

**Menu 7 - Tampilkan Mahasiswa oleh Dosen**: Melihat daftar mahasiswa yang dibimbing oleh dosen tertentu.

**Menu 8 - Tampilkan Dosen dari Mahasiswa**: Melihat dosen pembimbing dari mahasiswa tertentu.

**Menu 9 - Tampilkan Semua Dosen**: Menampilkan daftar lengkap semua dosen.

**Menu 10 - Tampilkan Semua Mahasiswa**: Menampilkan daftar lengkap semua mahasiswa.

**Menu 11 - Statistik Bimbingan**: Menampilkan dosen dengan jumlah bimbingan terbanyak dan tersedikit.

**Menu 0 - Keluar**: Menutup program.

## Contoh Output Program

Berikut contoh interaksi dengan program saat menambahkan relasi:

```
--- HUBUNGKAN DOSEN-MAHASISWA ---
NIP Dosen: D001
NIM Mahasiswa: 1301210001
Relasi berhasil dibuat!
Dosen Dr. Budi Santoso, M.Kom -> Mahasiswa Andi Wijaya
```

Contoh tampilan statistik bimbingan:

```
=== STATISTIK BIMBINGAN ===
Dosen dengan bimbingan TERBANYAK:
  NIP: D003
  Nama: Prof. Ahmad Dahlan, Ph.D
  Jumlah: 4 mahasiswa

Dosen dengan bimbingan TERSEDIKIT:
  NIP: D004
  Nama: Dr. Rina Kartika, S.Kom, M.Kom
  Jumlah: 1 mahasiswa
```

## Data Sample (Mode Inject)

Dalam mode inject, sistem akan terisi dengan data berikut:

**Dosen**: Dr. Budi Santoso dengan 3 mahasiswa bimbingan, Dr. Siti Nurhaliza dengan 2 mahasiswa, Prof. Ahmad Dahlan dengan 4 mahasiswa (terbanyak), dan Dr. Rina Kartika dengan 1 mahasiswa (tersedikit).

**Mahasiswa**: Andi Wijaya (IPK 3.75), Bella Safira (IPK 3.89), Citra Dewi (IPK 3.92) yang memiliki 2 pembimbing, Dimas Pratama (IPK 3.65), Eka Putri (IPK 3.88), Fajar Ramadhan (IPK 3.70), dan Gita Savitri (IPK 3.95) yang juga memiliki 2 pembimbing.

## Spesifikasi Teknis

### Implementasi Struktur Data

Program menggunakan tiga jenis linked list yang berbeda sesuai requirement tugas:

List Dosen menggunakan Circular Single Linked List dimana node terakhir menunjuk kembali ke node pertama. Operasi insert menggunakan insert first untuk efisiensi O(1). Setiap node dosen memiliki pointer ke List Relasi yang menyimpan mahasiswa bimbingannya.

List Mahasiswa menggunakan Double Linked List dengan pointer next dan prev untuk traversal dua arah. Insert first digunakan untuk menambah mahasiswa baru di awal list.

List Relasi menggunakan Single Linked List sederhana yang menyimpan address pointer ke node mahasiswa. List ini embedded dalam setiap node dosen untuk menyimpan relasi bimbingan.

### Menghindari Circular Dependency

Program menggunakan forward declaration untuk menghindari circular dependency antara header files. File header hanya mendeklarasikan pointer ke struct lain tanpa perlu mengetahui implementasi lengkapnya. Include lengkap baru dilakukan di file implementation (.cpp) dimana circular dependency tidak menjadi masalah karena file dicompile terpisah.

### Aturan Bisnis

Sistem menerapkan batasan bahwa satu mahasiswa maksimal dapat memiliki 2 dosen pembimbing sesuai dengan aturan umum bimbingan tugas akhir. Sementara satu dosen dapat membimbing banyak mahasiswa tanpa batasan jumlah.

Ketika dosen dihapus, semua relasi bimbingannya akan dihapus secara otomatis namun data mahasiswa tetap tersimpan. Sebaliknya, ketika mahasiswa dihapus, relasi dengan semua dosen pembimbingnya akan diputus terlebih dahulu sebelum data mahasiswa dihapus dari sistem.

## Troubleshooting

**Compiler tidak ditemukan**: Pastikan g++ sudah terinstall dengan benar. Cek dengan command `g++ --version`. Jika belum terinstall, ikuti panduan instalasi di bagian Persiapan Awal.

**Make command not found**: Jika make tidak tersedia, gunakan cara compile manual yang sudah dijelaskan di bagian Kompilasi Program.

**Permission denied saat menjalankan**: Di Linux/MacOS, berikan permission execute dengan `chmod +x bimbingan_ta` kemudian jalankan dengan `./bimbingan_ta`.

**File not found error**: Pastikan Anda berada di dalam folder TUBES_MLL saat menjalankan command. Cek dengan `pwd` di Linux/MacOS atau `cd` di Windows.

## Catatan Penting

Data yang diinput ke dalam program bersifat sementara dan tersimpan di memori. Ketika program ditutup, semua data akan hilang. Untuk penggunaan production, sistem perlu ditambahkan fitur penyimpanan ke file atau database.

Program ini dibuat untuk memenuhi tugas besar mata kuliah Struktur Data dengan fokus pada implementasi Multi Linked-List dan pemahaman konsep relasi Many-to-Many dalam struktur data.

---

**Dibuat untuk memenuhi tugas besar Struktur Data - Multi Linked List**
