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
        cout << "Data Calon dengan nomor calon " << nomorCalon << " berhasil dihapus!!" << endl << endl;
    } else  {
        cout << "Nomor Calon tidak ditemukan" <<endl<<endl;
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

void tampilkanCalon(listCalon listC) {
    adrCalon C = first(listC);
    cout << "      DAFTAR  CALON      "<<endl;
    while(C != nil) {
        templateTampilCalon(C);
        C = nextCalon(C);
    }
}

void templateTampilCalon(adrCalon C) {
    cout << "+=====================+"<<endl;
    cout << "|          " << info(C).noCalon << "          |"<<endl;
    cout << "+=====================+"<<endl;
    cout << "  nama :  " << info(C).namaCalon <<endl;
    cout << "  visi :  " << info(C).visi <<endl;
    cout << "  misi :  " << info(C).misi << endl;
    cout << "+=====================+"<<endl;
    cout <<endl;
}

