#include <stdio.h>
#include <stdlib.h>

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
int curSize = 0;
Mahasiswa listMhs[max];

int main()
{
    displayMahasiswa();
    int choice;
    printf("1. Tambah Data \n");
    printf("2. Ubah Data \n");
    printf("3. Hapus Data \n");
    printf("Pilihan Anda: "); scanf("%i", &choice);
    printf("\n");

    switch(choice) {
        case 1:
            tambahData();
            displayMahasiswa();
            break;

        case 2:
            break;

        case 3:
            break;
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
