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

void hapusWarga(listWarga &listW, string noInduk) {
    adrWarga P,Q;

    P = first(listW);
    Q = nil;

    while((info(P).NIK != noInduk) && (nextWarga(P) != first(listW))) {
        Q = P;
        P = nextWarga(P);
    }

    if(info(P).NIK == noInduk) {
        if(P == first(listW)) {
            deleteFirstWarga(listW);
        } else {
            nextWarga(Q) = nextWarga(P);
            delete P;
        }
    }
}

adrWarga cekNikWarga(listWarga listW, string NIK) {
    adrWarga P = first(listW);

    while(info(P).NIK != NIK && nextWarga(P)!= first(listW)) {
        P = nextWarga(P);
    }
    if(info(P).NIK == NIK) {
        return P;
    } else {
        return nil;
    }
}

bool cekUmurWarga(listWarga listW, string NIK) {
    adrWarga P = cekNikWarga(listW, NIK);
    return (P != nil && info(P).umur >= 17);
}

void pilihCalon(listWarga &listW, adrWarga &pW, listCalon listC, string NIK, int noCalon) {
    pW = cekNikWarga(listW, NIK);
    adrCalon pC = first(listC);

    if(pW != nil && pilihan(pW) == nil){
        if(cekUmurWarga(listW, NIK)) {
            while(info(pC).noCalon != noCalon && nextCalon(pC) != nil) {
                pC = nextCalon(pC);
            }
            if(info(pC).noCalon == noCalon){
                pilihan(pW) = pC;
            } else {
                cout<<"Calon tidak ditemukan";
            }
        }
    }
}

void cetakBelumMilih(listWarga listW) {
    adrWarga pW = first(listW);
    adrCalon pC = pilihan(pW);

    while(nextWarga(pW) != first(listW)) {
        pC = pilihan(pW);
        //cout<<pC;
        if((pC == nil) && (info(pW).umur >= 17)) {
            cout<<info(pW).namaWarga;
        }
        pW = nextWarga(pW);
    }
    if((pC == nil) && (info(pW).umur >= 17)) {
        cout<<info(pW).namaWarga;
    }
}

void pemilihan(listWarga &listW, adrCalon P, string NIK) {
    adrWarga W;
    W = first(listW);

    while (info(W).NIK != NIK && nextWarga(W) != nil) {
        W = nextWarga(W);
    }
    if (info(W).NIK == NIK) {
        pilihan(W) = P;
    }
}

