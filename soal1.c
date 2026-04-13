/* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman
* Modul : 1 - Overview Of C Language
* Pembuat : Farras Fuady Hakim
* Deskripsi : Program untuk menentukan status akhir peneliti berdasarkan level izin, suhu tubuh, kadar radiasi, dan jam kedatnagan.
*/
#include <stdio.h>

// validasi : 0(Masuk), 1(Karantina), 2(Tolak), 3(Pemerikasaan)
int cekStatus(int izin, int suhu, int radiasi, int jam) {
    int validasi;
    if (radiasi >= 6) {
        validasi = 2;
    } else if (suhu >= 390) {
        validasi = 1;
    } else if (izin == 1 && (jam < 6 || jam > 20)) {
        validasi = 2;
    } else if (izin == 1) {
        validasi = 0;
    } else if (izin == 2 && radiasi <= 2 && 8 <= jam <= 18) {
        validasi = 0;
    } else if (izin == 2) {
        validasi = 3;
    } else if (izin == 3 && radiasi == 0 && suhu < 380) {
        validasi = 0;
    } else {
        validasi = 2;
    }

    return validasi;
}

int main() {
    int izin, suhu, radiasi, jam, validasi;

    printf("Masukkan input (izin, suhu, radiasi, jam) : ");
    scanf("%d %d %d %d", &izin, &suhu, &radiasi, &jam);

    switch (validasi) {
    case 0:
        printf("MASUK");
        break;
    case 1:
        printf("KARANTINA");
        break;
    case 2:
        printf("TOLAK");
        break;
    case 3:
        printf("PEMERIKSAAN");
        break;
    default:
        break;
    }

    return 0;
}
