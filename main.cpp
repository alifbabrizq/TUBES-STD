#include "warga.h"

int main() {
    cout << "mantapu jiwa" << endl;

    cout<<"ihiuyyy"<<endl;
    cout<<"dsds";

    cout << "cek" << endl;
    cout<<"tetetetetetetet"<<endl;

    // testing warga
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
    cout << info(first(listW)).NIK << " ";
    cout << info(first(listW)).namaWarga << " ";
    cout << info(first(listW)).jenisKelamin << " ";
    cout << info(first(listW)).umur << endl;
    hapusWarga(listW, "3404011");
    cout << first(listW) << endl;

    // testing calon
    listCalon listC;
    createListCalon(listC);
    cout << first(listC) << endl;

    adrCalon C;
    dataCalon dataC;
    dataC.noCalon = "01";
    dataC.namaCalon = "Susilo";
    dataC.visi = "maju terus";
    dataC.misi = "mengayomi";
    createElmCalon(dataC, C);
    tambahCalon(listC, C);
    cout << info(first(listC)).noCalon << " ";
    cout << info(first(listC)).namaCalon << " ";
    cout << info(first(listC)).visi << " ";
    cout << info(first(listC)).misi << endl;
    hapusCalon(listC, "01");
    cout << first(listC) << endl;

    return 0;
}
