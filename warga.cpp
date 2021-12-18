#include "warga.h"

void createListWarga(listWarga &listW) {
    first(listW) = nil;
}

void createElmWarga(dataWarga data, adrWarga &W) {
    W = new elmWarga;
    info(W) = data;
    pilihan(W) = nil;
    nextWarga(W) = W;
}

void lastWarga(listWarga listW, adrWarga &last) {
    last = first(listW);
    while(nextWarga(last) != first(listW)) {
        last = nextWarga(last);
    }
}

void tambahWarga(listWarga &listW, adrWarga W){
    adrWarga last;

    if(first(listW) == nil) {
        first(listW) = W;
    } else {
        lastWarga(listW, last);
        nextWarga(last) = W;
        nextWarga(W) = first(listW);
    }
}

void deleteFirstWarga(listWarga &listW) {
    adrWarga last, P;

    P = first(listW);
    if(nextWarga(first(listW)) == first(listW)) {
        first(listW) = nil;
    } else {
        lastWarga(listW, last);
        first(listW) = nextWarga(first(listW));
        nextWarga(last) = first(listW);
    }
    delete P;
}

void hapusWarga(listWarga &listW, string NIK) {
    adrWarga P,Q,last;

    P = first(listW);
    Q = nil;

    while((info(P).NIK != NIK) && (nextWarga(P) != first(listW))) {
        Q = P;
        P = nextWarga(P);
    }

    if(info(P).NIK == NIK) {
        if(P == first(listW)) {
            deleteFirstWarga(listW);
        } else {
            nextWarga(Q) = nextWarga(P);
            delete P;
        }
    }
}

bool cekNikWarga(listWarga listW, string NIK) {
    adrWarga P = first(listW);

    while(info(P).NIK != NIK) {
        P = nextWarga(P);
    }
    return (info(P).NIK == NIK);
}
