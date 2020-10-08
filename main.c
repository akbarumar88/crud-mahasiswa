#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char kecamatan[15];
    char kota[15];
} Alamat;

typedef struct
{
    char nama[32];
    char npm[15];
    char fakultas[20];
    char jurusan[20];
    int semester;
    Alamat alamat;
} Mahasiswa;

#define max 100
// Taruh variable size dan array global, biar bisa diakses dimana saja
int curSize = 1;
// Array kasih maxLength, kalau tidak maka terjadi eror ketika tambah/ubah data
Mahasiswa listMhs[max] = {
    {
        "Akbar", "19081010043", "Ilmu Komputer", "Teknik Informatika", 3, {"Suko", "Sidoarjo"}
    }
};

int main()
{
    displayMahasiswa();
    bool exit = false;
    while (!exit) {
        int choice;
        printf("1. Tambah Data \n");
        printf("2. Ubah Data \n");
        printf("3. Hapus Data \n");
        printf("4. Keluar \n");
        printf("Pilihan Anda: "); scanf("%i", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                tambahData();
                displayMahasiswa();
                break;

            case 2:
                ubahData();
                displayMahasiswa();
                break;

            case 3:
                hapusData();
                displayMahasiswa();
                break;

            case 4:
                exit = true;
                break;

            default:
                printf("Pilihan tidak tersedia\n\n");
                break;
        }
    }
    return 0;
}

void tambahData() {
    Mahasiswa m;
    printf("Nama        : "); scanf("%s", m.nama);
    printf("NPM         : "); scanf("%s", m.npm);
    printf("Fakultas    : "); scanf("%s", m.fakultas);
    printf("Jurusan     : "); scanf("%s", m.jurusan);
    printf("Semester    : "); scanf("%i", &m.semester);
    printf("Kota 	    : "); scanf("%s", m.alamat.kota);
    printf("Kecamatan   : "); scanf("%s", m.alamat.kecamatan);
    printf("\n\nData berhasil ditambahkan! \n\n");
    listMhs[curSize] = m; curSize++;
}

void ubahData() {
    int urutan, urutanIndex;
    bool salah=true;
    while (salah) {
        printf("Urutan yang akan diubah : "); scanf("%i", &urutan);
        if (urutan < 1) {
            printf("Urutan tidak boleh lebih kecil dari 1\n");
            continue;
        } else if (urutan > curSize) {
            printf("Urutan tidak boleh lebih besar dari %i\n", curSize);
            continue;
        }
        salah=false;
    }

    urutanIndex = urutan-1;

    Mahasiswa m;
    printf("Nama        : "); scanf("%s", m.nama);
    printf("NPM         : "); scanf("%s", m.npm);
    printf("Fakultas    : "); scanf("%s", m.fakultas);
    printf("Jurusan     : "); scanf("%s", m.jurusan);
    printf("Semester    : "); scanf("%i", &m.semester);
    printf("Kota 	    : "); scanf("%s", m.alamat.kota);
    printf("Kecamatan   : "); scanf("%s", m.alamat.kecamatan);
    printf("\n\nData berhasil diubah! \n\n");
    listMhs[urutanIndex] = m;
}

void hapusData() {
    int urutan, urutanIndex;
    bool salah=true;
    while (salah) {
        printf("Urutan yang akan dihapus : "); scanf("%i", &urutan);
        if (urutan < 1) {
            printf("Urutan tidak boleh lebih kecil dari 1\n");
            continue;
        } else if (urutan > curSize) {
            printf("Urutan tidak boleh lebih besar dari %i\n", curSize);
            continue;
        }
        salah=false;
    }
    urutanIndex = urutan-1;

    Mahasiswa newList[max];
    for (int i = 0;i < curSize; i++) {
        if (i == urutanIndex) continue;
        newList[i] = listMhs[i];
    }
    curSize--;
    printf("\n\nData berhasil dihapus! \n\n");
}

void displayMahasiswa() {
    for (int i = 0; i < curSize; i++) {
        printf("Nama        : %s \n", listMhs[i].nama);
        printf("NPM         : %s \n", listMhs[i].npm);
        printf("Fakultas    : %s \n", listMhs[i].fakultas);
        printf("Jurusan     : %s \n", listMhs[i].jurusan);
        printf("Semester    : %i \n", listMhs[i].semester);
        printf("Alamat      : %s, %s \n\n", listMhs[i].alamat.kecamatan, listMhs[i].alamat.kota);
    }
}
