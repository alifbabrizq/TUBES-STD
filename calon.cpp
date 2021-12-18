#include "calon.h"

void createListCalon(listCalon &listC) {
    first(listC) = nil;
}

void createElmCalon(dataCalon data, adrCalon &C) {
    C = new elmCalon;
    info(C) = data;
    nextCalon(C) = nil;
}

void lastCalon(listCalon listC, adrCalon &last) {
    last = first(listC);
    while (nextCalon(last) != nil) {
        last = nextCalon(last);
    }
}

void tambahCalon(listCalon &listC, adrCalon C) {
    adrCalon last;

    if (first(listC) == nil) {
        first(listC) = C;
    } else {
        lastCalon(listC, last);
        nextCalon(last) = C;
    }
}

void hapusCalon(listCalon &listC, string noCalon) {
    adrCalon P, Q;
    P = first(listC);
    Q = nil;

    while ((info(P).noCalon != noCalon) && (nextCalon(P) != nil)) {
        Q = P;
        P = nextCalon(P);
    }
    if (info(P).noCalon == noCalon) {
        if (P == first(listC)) {
            first(listC) = nextCalon(P);
        } else {
            nextCalon(Q) = nextCalon(P);
        }
        delete P;
    }
}
