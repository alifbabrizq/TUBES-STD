#ifndef CALON_H_INCLUDED
#define CALON_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
Kelompok 7 :
  1. Alif Babrizq Kuncara (1301204228)
  2. Aryya Bagus Padmanawijaya (1301204310)
*/
#define info(P) (P)->info
#define nextCalon(P) (P)->nextCalon
#define first(L) ((L).first)
#define nil NULL

struct dataCalon {
    int noCalon;
    string namaCalon, visi, misi;
};

typedef struct elmCalon *adrCalon;

struct elmCalon {
    dataCalon info;
    adrCalon nextCalon;
};

struct listCalon {
    adrCalon first;
};

void createListCalon(listCalon &listC);
/*
{ I.S. -
  F.S. listC adalah list kosong }
*/
void createElmCalon(dataCalon data, adrCalon &C);
/*
{ I.S. terdefinisi data adalah info
  F.S. C telah dialokasi dan menyimpan data }
*/
void tambahCalon(listCalon &listC, adrCalon C);
/*
{ I.S. listC mungkin kosong, mungkin tidak. C adalah elemen baru yang akan dimasukkan pada listC
  F.S. C adalah elemen pertama dari listC }
*/
void hapusCalon(listCalon &listC, int nomorCalon);
/*
{ I.S. listC tidak kosong. terdefinisi nomorCalon
  F.S. elemen dengan noCalon = nomorCalon telah dihapus }
*/
adrCalon cariCalon(listCalon listC, string namaCalon);
/*
{ Mengembalikan address dari calon jika ditemukan namaCalon,
  sebaliknya akan mengembalikan nil jika tidak ditemukan }
*/
void tampilSemuaCalon(listCalon listC);
/*
{ I.S. listC mungkin kosong,
  F.S. menampilkan semua calon}
*/
void templateTampilCalon(adrCalon C);

#endif // CALON_H_INCLUDED
