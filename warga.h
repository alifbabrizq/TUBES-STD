#ifndef WARGA_H_INCLUDED
#define WARGA_H_INCLUDED
#include "calon.h"
/*
Kelompok 7 :
  1. Alif Babrizq Kuncara (1301204228)
  2. Aryya Bagus Padmanawijaya (1301204310)
*/
#define info(P) (P)->info
#define nextWarga(P) (P)->nextWarga
#define pilihan(P) (P)->pilihan
#define first(L) ((L).first)
#define nil NULL

struct dataWarga {
    string NIK, namaWarga;
    int jenisKelamin, umur;
};

typedef struct elmWarga *adrWarga;

struct elmWarga {
    dataWarga info;
    adrCalon pilihan;
    adrWarga nextWarga;
};

struct listWarga {
    adrWarga first;
};

void createListWarga(listWarga &listW);
/*
{ I.S. -
  F.S. listW adalah list kosong }
*/
void createElmWarga(dataWarga data, adrWarga &W);
/*
{ I.S. terdefinisi data adalah info
  F.S. W telah dialokasi dan menyimpan data }
*/
void tambahWarga(listWarga &listW, adrWarga W);
/*
{ I.S. listW mungkin kosong, mungkin tidak. W adalah elemen baru yang akan dimasukkan pada listW
  F.S. W adalah elemen terakhir dari listW }
*/
void hapusWarga(listWarga &listW, string noInduk);
/*
{ I.S. listW tidak kosong. data terdefinisi noInduk
  F.S. elemen dengan NIK = noInduk telah dihapus }
*/
void pemlihTermudaTertua(listWarga listW);
/*
{ I.S. listW mungkin kosong.
  F.S. menampilkan pemilih termuda dan tertua }
*/
adrCalon suaraTerbanyak(listWarga listW, listCalon listC);
/*
{ Mengembalikan address dari calon yang memiliki suara terbanyak, jika ada dua atau lebih  calon
  yang memiliki suara terbanyak dan sama, maka kembalikan address calon dengan noCalon terbesar }
*/
void hitungGenderPemilihCalon(listWarga listW, listCalon listC, int &jumlahLaki, int &jumlahPerempuan, string namaCalon);
/*
{ I.S. listW mungkin kosong.
  F.S. jumlahLaki telah menyimpan banyaknya pemilih ber-gender laki-laki dan
       jumlahPerempuan telah menyimpan banyaknya pemilih ber-gender perempuan yang memilih calon dengan nama namaCalon }
*/
void hitungUmurPemilihCalon(listWarga listW, listCalon listC, int &less20, int &over20, string namaCalon);
/*
{ I.S. listW mungkin kosong.
  F.S. less20 telah menyimpan banyaknya pemilih berumur <= 20 dan
       over20 telah menyimpan banyaknya pemilih berumur > 20 yang memilih calon dengan nama namaCalon }
*/
void tampilSemuaCalonDenganStatistik(listWarga listW, listCalon listC);
/*
{ I.S. listW mungkin kosong.
  F.S. menampilkan namaCalon, jumlah pemilih dengan gender laki-laki dan jumlah pemilih dengan gender perempuan, dan
       jumlah pemilih yang usianya di bawah 20 tahun dan yang usianya di atas 20 tahun tiap calon }
*/
void lastWarga(listWarga listW, adrWarga &last);
/*
{ I.S. listW tidak kosong.
  F.S. last adalah address elemen terakhir dari listWarga }
*/
void deleteFirstWarga(listWarga &listW);
/*
{ I.S. listW tidak kosong.
  F.S. elemen pertama dari listW akan dihapus. listW mungkin menjadi kosong }
*/
adrWarga cekNikWarga(listWarga listW, string noInduk);
/*
{ Mengembalikan address dari warga jika NIK == noInduk,
  mengembalikan nil jika noInduk tidak ditemukan }
*/
bool cekUmurWarga(listWarga listW, adrWarga W);
/*
{ Mengembalikan true jika umur >= 17,
  mengembalikan false jika < 17 }
*/
void pemilihan(listWarga &listW, adrCalon C, adrWarga W);
/*
{ I.S. listW tidak kosong, W menyimpan address warga yang melilih, dan C menyimpan addres calon yang dipilih
  F.S. pilihan W menunjuk C }
*/
void tampilSemuaWarga(listWarga listW);
/*
{ I.S. listW mungkin kosong,
  F.S. menampilkan semua warga}
*/

#endif // WARGA_H_INCLUDED
