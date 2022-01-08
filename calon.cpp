#include "calon.h"

void createListCalon(listCalon &listC) {
    first(listC) = nil;
}

void createElmCalon(dataCalon data, adrCalon &C) {
    C = new elmCalon;
    info(C) = data;
    nextCalon(C) = nil;
}

void tambahCalon(listCalon &listC, adrCalon C) {
    adrCalon last;

    if (first(listC) == nil) {
        first(listC) = C;
        info(C).noCalon = 1;
    } else {
        nextCalon(C) = first(listC);
        info(C).noCalon = info(first(listC)).noCalon + 1;
        first(listC) = C;
    }
}

void hapusCalon(listCalon &listC, int nomorCalon) {
    adrCalon P, Q;
    P = first(listC);
    Q = nil;

    while ((info(P).noCalon != nomorCalon) && (nextCalon(P) != nil)) {
        Q = P;
        P = nextCalon(P);
    }
    if (info(P).noCalon == nomorCalon) {
        if (P == first(listC)) {
            first(listC) = nextCalon(P);
        } else {
            nextCalon(Q) = nextCalon(P);
        }
        delete P;
    }
}

adrCalon cariCalon(listCalon listC, string namaCalon) {
    adrCalon C;
    C = first(listC);
    while (nextCalon(C) != nil && info(C).namaCalon != namaCalon) {
        C = nextCalon(C);
    }
    if (info(C).namaCalon == namaCalon) {
        return C;
    } else {
        return nil;
    }
}



