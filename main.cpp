#include "warga.h"

int main() {
    // testing warga
    cout << "----- test warga -----" << endl;
    listWarga listW;
    createListWarga(listW);
    cout << first(listW) << endl;

    adrWarga W;
    dataWarga dataW;
    dataW.NIK = "3404011";
    dataW.namaWarga = "Susanto";
    dataW.jenisKelamin = 1;
    dataW.umur = 45;
    createElmWarga(dataW, W);
    tambahWarga(listW, W);

    dataW.NIK = "34044343";
    dataW.namaWarga = "AHAHA";
    dataW.jenisKelamin = 1;
    dataW.umur = 20;
    createElmWarga(dataW, W);
    tambahWarga(listW, W);

    dataW.NIK = "120121";
    dataW.namaWarga = "AASW";
    dataW.jenisKelamin = 0;
    dataW.umur = 14;
    createElmWarga(dataW, W);
    tambahWarga(listW, W);


    adrWarga P = first(listW);
    while(nextWarga(P) != first(listW)) {
        cout << info(P).NIK << " ";
        cout << info(P).namaWarga << " ";
        cout << info(P).jenisKelamin << " ";
        cout << info(P).umur << endl;
        P = nextWarga(P);
    }
    cout << info(P).NIK << " ";
    cout << info(P).namaWarga << " ";
    cout << info(P).jenisKelamin << " ";
    cout << info(P).umur << endl<<endl;

    pemlihTermudaTertua(listW);

    cout << endl<<endl;
    //hapusWarga(listW, "3404011");
    // cout<<cekNikWarga(listW, "3404011")<<endl;
    // cout<<cekUmurWarga(listW, "3404011")<<endl<<"nama belum milih : ";
    // cetakBelumMilih(listW);
    //cout << first(listW) << endl;

    // testing calon
    cout << "----- test calon -----" << endl;
    listCalon listC;
    createListCalon(listC);
    //cout << first(listC) << endl;

    adrCalon C;
    dataCalon dataC;
    // dataC.noCalon = "01";
    dataC.namaCalon = "Susilo";
    dataC.visi = "maju terus";
    dataC.misi = "mengayomi";
    createElmCalon(dataC, C);
    tambahCalon(listC, C);
    pemilihan(listW, C, "34044343");

    dataC.namaCalon = "SASA";
    dataC.visi = "kiri terus";
    dataC.misi = "memakan";
    createElmCalon(dataC, C);
    tambahCalon(listC, C);
    pemilihan(listW, C, "3404011");
    pemilihan(listW, C, "120121");

    adrCalon Q = first(listC);
    while(Q != nil) {
        cout << info(Q).noCalon << " ";
        cout << info(Q).namaCalon << " ";
        cout << info(Q).visi << " ";
        cout << info(Q).misi << endl;
        Q = nextCalon(Q);
    }
    //hapusCalon(listC, 1);
    //cout << first(listC) << endl;

    cout<<endl<<endl;
    cout<<info(suaraTerbanyak(listW, listC)).noCalon;

    return 0;
}
