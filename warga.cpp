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
        cout << "Data Warga dengan NIK " << noInduk << " berhasil dihapus!!" << endl << endl;
    } else {
        cout << "NIK tidak ditemukan" <<endl<<endl;
    }
}

void pemlihTermudaTertua(listWarga listW){
    adrWarga W = first(listW);

    int muda = 100;
    int tua = 0;
    while(nextWarga(W) != first(listW)) {
        if(info(W).umur >= 17 && pilihan(W) != nil) {
            if(info(W).umur < muda) {
                muda = info(W).umur;
            }
            if(info(W).umur > tua) {
                tua = info(W).umur;
            }
        }
        W = nextWarga(W);
    }
    if(info(W).umur >= 17 && pilihan(W) != nil) {
        if(info(W).umur < muda) {
            muda = info(W).umur;
        }
        if(info(W).umur > tua) {
            tua = info(W).umur;
        }
    }
    if (muda != 100 || tua != 0) {
        cout << "Umur pemilih termuda : " << muda << endl;
        cout << "Umur pemilih tertua : " << tua <<endl << endl;
    } else {
        cout << "Belum ada warga yang melakukan pemilihan" << endl << endl;
    }
}

adrCalon suaraTerbanyak(listWarga listW, listCalon listC) {
    adrWarga W;
    adrCalon C, cWin;
    int maks, jumlah;

    cWin = nil;
    maks = 0;
    C = first(listC);
    while(C != nil){
        jumlah = 0;
        W = first(listW);
        while(nextWarga(W) != first(listW)) {
            if(pilihan(W) == C) {
                jumlah++;
            }
            W = nextWarga(W);
        }
        if(pilihan(W) == C) {
            jumlah++;
        }
        if(jumlah > maks){
            maks = jumlah;
            cWin = C;
        }
        C = nextCalon(C);
    }
    return cWin;
}

adrWarga cekNikWarga(listWarga listW, string noInduk) {
    adrWarga W = first(listW);

    while(nextWarga(W) != first(listW) && info(W).NIK != noInduk) {
        W = nextWarga(W);
    }
    if(info(W).NIK == noInduk) {
        return W;
    } else {
        return nil;
    }
}

bool cekUmurWarga(listWarga listW, adrWarga W) {
    return (W != nil && info(W).umur >= 17);
}
/*
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
*/
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

void pemilihan(listWarga &listW, adrCalon C, adrWarga W) {
    if (pilihan(W) == nil) {
        if (cekUmurWarga(listW, W)) {
            pilihan(W) = C;
            cout << "Anda berhasil memilih" << endl << endl;
        } else {
            cout << "Maaf umur Anda belum cukup" << endl << endl;
        }
    } else {
        cout << "Maaf Anda tidak bisa memilih, karena sudah melakukan pemilihan sebelumnya" << endl << endl;
    }
}

void hitungGenderPemilihCalon(listWarga listW, listCalon listC, int &jumlahLaki, int &jumlahPerempuan, string namaCalon) {
    adrCalon C;
    C = cariCalon(listC, namaCalon);
    adrWarga W = first(listW);
    jumlahLaki = 0;
    jumlahPerempuan = 0;
    if (W != nil) {
        while (nextWarga(W) != first(listW)) {
            if (pilihan(W) == C && info(W).jenisKelamin == 1) {
                jumlahLaki++;
            } else if (pilihan(W) == C && info(W).jenisKelamin == 0) {
                jumlahPerempuan++;
            }
            W = nextWarga(W);
        }
        if (pilihan(W) == C && info(W).jenisKelamin == 1) {
            jumlahLaki++;
        } else if (pilihan(W) == C && info(W).jenisKelamin == 0) {
            jumlahPerempuan++;
        }
    }
}

void hitungUmurPemilihCalon(listWarga listW, listCalon listC, int &less20, int &over20, string namaCalon) {
    adrCalon C;
    C = cariCalon(listC, namaCalon);
    adrWarga W = first(listW);
    less20 = 0;
    over20 = 0;
    if (W != nil) {
        while (nextWarga(W) != first(listW)) {
            if (pilihan(W) == C && info(W).umur <= 20) {
                less20++;
            } else if (pilihan(W) == C && info(W).umur > 0) {
                over20++;
            }
            W = nextWarga(W);
        }
        if (pilihan(W) == C && info(W).umur <= 20) {
            less20++;
        } else if (pilihan(W) == C && info(W).umur > 0) {
            over20++;
        }
    }
}

void tampilSemuaCalon(listWarga listW, listCalon listC) {
    adrCalon C;
    int jumlahLaki, jumlahPerempuan, less20, over20;
    C = first(listC);
    while (C != nil) {
        cout << "Nama : " << info(C).namaCalon << endl;
        hitungGenderPemilihCalon(listW, listC, jumlahLaki, jumlahPerempuan, info(C).namaCalon);
        cout << "Jumlah pemilih laki-laki : " << jumlahLaki << endl;
        cout << "Jumlah pemilih perempuan : " << jumlahPerempuan << endl;
        hitungUmurPemilihCalon(listW, listC, less20, over20, info(C).namaCalon);
        cout << "Jumlah pemilih yang berumur <= 20 : " << less20 << endl;
        cout << "Jumlah pemilih yang berumur > 20 : " << over20 << endl << endl;
        C = nextCalon(C);
    }
    cout<<endl<<endl;
}

