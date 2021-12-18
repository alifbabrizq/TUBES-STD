#ifndef CALON_H_INCLUDED
#define CALON_H_INCLUDED
#include <iostream>

using namespace std;

#define info(P) (P)->info
#define nextCalon(P) (P)->nextCalon
#define first(L) ((L).first)
#define nil NULL

struct dataCalon {
    string noCalon, namaCalon, visi, misi;
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
void createElmCalon(dataCalon data, adrCalon &C);
void lastCalon(listCalon listC, adrCalon &last);
void tambahCalon(listCalon &listC, adrCalon C);
void hapusCalon(listCalon &listC, string noCalon);

#endif // CALON_H_INCLUDED
