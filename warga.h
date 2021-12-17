#ifndef WARGA_H_INCLUDED
#define WARGA_H_INCLUDED
#include "calon.h"

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
void createElmWarga(dataWarga data, adrWarga &W);
void lastWarga(listWarga listW, adrWarga &W);
void tambahWarga(listWarga &listW, adrWarga W);
void deleteFirst(listWarga &listW);
void hapusWarga(listWarga &listW, string NIK);

#endif // WARGA_H_INCLUDED
