#include "warga.h"
/*
Kelompok 7 :
  1. Alif Babrizq Kuncara (1301204228)
  2. Aryya Bagus Padmanawijaya (1301204310)
*/
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
    adrWarga last, W;

    W = first(listW);
    if(nextWarga(first(listW)) == first(listW)) {
        first(listW) = nil;
    } else {
        lastWarga(listW, last);
        first(listW) = nextWarga(first(listW));
        nextWarga(last) = first(listW);
    }
    delete W;
}

void hapusWarga(listWarga &listW, string noInduk) {
    adrWarga W,prevW;

    W = first(listW);
    prevW = nil;

    while((info(W).NIK != noInduk) && (nextWarga(W) != first(listW))) {
        prevW = W;
        W = nextWarga(W);
    }

    if(info(W).NIK == noInduk) {
        if(W == first(listW)) {
            deleteFirstWarga(listW);
        } else {
            nextWarga(prevW) = nextWarga(W);
            delete W;
        }
        cout << "Data Warga dengan NIK " << noInduk << " berhasil dihapus!!" << endl << endl;
    } else {
        cout << "NIK tidak ditemukan" <<endl<<endl;
    }
}

void pemlihTermudaTertua(listWarga listW){
    adrWarga W = first(listW);

    if (W != nil) {
        int muda = 200;
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
        if (muda != 200 || tua != 0) {
            cout << "Umur pemilih termuda : " << muda << endl;
            cout << "Umur pemilih tertua : " << tua <<endl << endl;
        } else {
            cout << "Belum ada warga yang melakukan pemilihan" << endl << endl;
        }
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

    if (W != nil) {
        while(nextWarga(W) != first(listW) && info(W).NIK != noInduk) {
            W = nextWarga(W);
        }
        if(info(W).NIK == noInduk) {
            return W;
        } else {
            return nil;
        }
    } else {
        return nil;
    }
}

bool cekUmurWarga(listWarga listW, adrWarga W) {
    return (W != nil && info(W).umur >= 17);
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

void tampilSemuaCalonDenganStatistik(listWarga listW, listCalon listC) {
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
}

void tampilSemuaWarga(listWarga listW) {
    adrWarga W = first(listW);
    if (W == nil) {
        cout << "Data warga masih kosong" << endl << endl;
    } else {
        while (nextWarga(W) != first(listW)) {
            cout << "NIK : " << info(W).NIK << endl;
            cout << "Nama : " << info(W).namaWarga << endl;
            cout << "Umur : " << info(W).umur << endl;
            cout << "Jenis Kelamin : " << (info(W).jenisKelamin ? "Laki-Laki" : "Perempuan")<< endl << endl;
            W = nextWarga(W);
        }
        cout << "NIK : " << info(W).NIK << endl;
        cout << "Nama : " << info(W).namaWarga << endl;
        cout << "Umur : " << info(W).umur << endl;
        cout << "Jenis Kelamin : " << (info(W).jenisKelamin ? "Laki-Laki" : "Perempuan")<< endl << endl;
    }
}

