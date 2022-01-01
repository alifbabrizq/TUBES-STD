#ifndef CALON_H_INCLUDED
#define CALON_H_INCLUDED
#include <iostream>

using namespace std;

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
{I.S. -
 F.S. listC adalah list kosong}
*/
void createElmCalon(dataCalon data, adrCalon &C);
/*
{I.S. terdefinisi data adalah info
 F.S. C telah dialokasi dan menyimpan data}
*/
void tambahCalon(listCalon &listC, adrCalon C);
/*
{I.S. listC mungkin kosong, mungkin tidak. C adalah elemen baru yang akan dimasukkan pada listC
 F.S. C adalah elemen pertama dari listC}
*/
void hapusCalon(listCalon &listC, int noCalon);
/*
{I.S. listC tidak kosong. data terdefinisi noCalon
 F.S. elemen dengan noCalon tertentu akan dihapus}
*/
adrCalon cariCalon(listCalon listC, string namaCalon);
/*
{fungsi akan mengembalikan address dari Calon jika ditemukan.
 Jika tidak maka akan mengembalikan nil}
*/

//void lastCalon(listCalon listC, adrCalon &last);

#endif // CALON_H_INCLUDED
