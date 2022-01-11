#include "menu.h"

void selectMenu(listCalon &listC, listWarga &listW) {
    string user;
    cout << "\nAnda Siapa ?(admin/warga) : ";
    cin >> user;

    if (user == "admin") {
        selectMenuAdmin(listC, listW);
    } else if (user == "warga") {
        selectMenuWarga(listC, listW);
    } else {
        cout << "Silakan masukkan sebagai admin/warga" << endl;
        selectMenu(listC, listW);
    }
}

void selectMenuAdmin(listCalon &listC, listWarga &listW) {
    string username, password;
    cout << "username : ";
    cin >> username;
    cout << "password : ";
    cin >> password;
    if (username == "admin" && password == "admin") {
        int pilihMenu;
        printMenuAdmin();
        cout << "Masukkan pilihan Menu : ";
        cin >> pilihMenu;
        while (pilihMenu != 0) {
            if (pilihMenu == 1) {
                createListCalon(listC);
                adrCalon C;
                dataCalon dataC;
                string s;

                ifstream file;
                file.open("inputDataCalon.txt");

                while (getline(file,s)) {
                    string data;
                    int i, panjangLine, j;
                    i = 0;
                    j = 0;
                    panjangLine = (int)s.length();
                    data = "";
                    while (i < panjangLine) {
                        if (s[i] != ',' && i != panjangLine-1) {
                            data += s[i];
                        } else if (s[i] == ',' && j == 0){
                            dataC.namaCalon = data;
                            data = "";
                            j++;
                        } else if (s[i] == ',' && j == 1) {
                            dataC.visi = data;
                            data = "";
                            j++;
                        } else if (i == panjangLine-1) {
                            data += s[i];
                            dataC.misi = data;
                            data = "";
                            j++;
                        }
                        i++;
                    }
                    createElmCalon(dataC, C);
                    tambahCalon(listC, C);
                }
                cout << "Data calon telah berhasil ditambahkan!!" << endl << endl;
            } else if (pilihMenu == 2) {
                int nomorCalon;
                cout << "Masukkan nomor calon yang ingin dihapus : ";
                cin >> nomorCalon;
                hapusCalon(listC, nomorCalon);
            } else if (pilihMenu == 3) {
                createListWarga(listW);
                adrWarga W;
                dataWarga dataW;
                string s;

                // test file input
                ifstream file;
                file.open("inputDataWarga.txt");

                while (getline(file,s)) {
                    string data;
                    int i, panjangLine, j;
                    i = 0;
                    j = 0;
                    panjangLine = (int)s.length();
                    data = "";
                    while (i < panjangLine) {
                        if (s[i] != ',' && i != panjangLine-1) {
                            data += s[i];
                        } else if (s[i] == ',' && j == 0){
                            dataW.NIK = data;
                            data = "";
                            j++;
                        } else if (s[i] == ',' && j == 1) {
                            dataW.namaWarga = data;
                            data = "";
                            j++;
                        } else if (s[i] == ',' && j == 2) {
                            dataW.jenisKelamin = stoi(data);
                            data = "";
                            j++;
                        } else if (i == panjangLine-1) {
                            data += s[i];
                            dataW.umur = stoi(data);
                            data = "";
                            j++;
                        }
                        i++;
                    }
                    createElmWarga(dataW, W);
                    tambahWarga(listW, W);
                }
                cout << "Data warga telah berhasil ditambahkan!!" << endl << endl;
            } else if (pilihMenu == 4) {
                string noInduk;
                cout << "Masukkan NIK yang ingin dihapus : ";
                cin >> noInduk;
                hapusWarga(listW, noInduk);
            } else if (pilihMenu == 5) {
                pemlihTermudaTertua(listW);
            } else if (pilihMenu == 6) {
                adrCalon cWin;
                cWin = suaraTerbanyak(listW, listC);
                if (cWin != nil) {
                    templateTampilCalon(cWin);
                } else {
                    cout << "Belum ada warga yang melakukan pemilihan" << endl << endl;
                }
            } else if (pilihMenu == 7) {
                adrCalon C;
                string nama;

                cout << "Input nama calon yang dicari : ";
                cin.ignore();
                getline(cin, nama);
                C = cariCalon(listC, nama);

                if (C != nil) {
                    templateTampilCalon(C);
                } else {
                    cout << "Calon tidak ditemukan " << endl << endl;
                }
            } else if (pilihMenu == 8) {
                tampilSemuaCalon(listW, listC);
            } else if (pilihMenu == 9) {
                selectMenu(listC, listW);
            } else {
                cout << "Silakan masukkan menu yang tersedia" << endl <<endl;
            }
            if (pilihMenu != 9) {
                printMenuAdmin();
                cout << "Masukkan pilihan Menu : ";
                cin >> pilihMenu;
            } else {
                pilihMenu = 0;
            }
        }
    } else {
        cout << "username atau password salah" << endl;
        selectMenuAdmin(listC, listW);
    }
}

void selectMenuWarga(listCalon &listC, listWarga &listW) {
    int pilihMenu;

    printMenuWarga();
    cout << "Masukkan pilihan Menu : ";
    cin >> pilihMenu;
    while (pilihMenu != 0) {
        if (pilihMenu == 1) {
            string noInduk, namaPilihan;
            adrWarga W;
            adrCalon C;

            cout << "Masukkan NIK anda : ";
            cin >> noInduk;
            W = cekNikWarga(listW, noInduk);
            if (W != nil) {
                tampilkanCalon(listC);
                cout << "Masukkan nama calon yang di pilih : ";
                cin.ignore();
                getline(cin, namaPilihan);
                C = cariCalon(listC, namaPilihan);
                if (C != nil) {
                    pemilihan(listW, C, W);
                } else {
                    cout << "Masukkan sesuai nama calon yang tertera!!" << endl << endl;
                }
            } else {
                cout << "Maaf NIK anda tidak terdaftar" << endl << endl;
            }
        } else if (pilihMenu == 2){
            pemlihTermudaTertua(listW);
        } else if (pilihMenu == 3){
            adrCalon C;
            string nama;

            cout << "Input nama calon yang dicari : ";
            cin.ignore();
            getline(cin, nama);
            C = cariCalon(listC, nama);

            if (C != nil) {
                templateTampilCalon(C);
            } else {
                cout << "Calon tidak ditemukan " << endl << endl;
            }
        } else if (pilihMenu == 4){
            tampilSemuaCalon(listW, listC);
        } else if (pilihMenu == 5){
            adrCalon cWin;
            cWin = suaraTerbanyak(listW, listC);
            templateTampilCalon(cWin);
        } else if (pilihMenu == 9) {
                selectMenu(listC, listW);
        } else {
            cout << "Silakan masukkan menu yang tersedia" << endl <<endl;
        }
        if (pilihMenu != 9) {
            printMenuWarga();
            cout << "Masukkan pilihan Menu : ";
            cin >> pilihMenu;
        } else {
            pilihMenu = 0;
        }
    }
}

void printMenuAdmin() {
    cout << "+===========================================================================+" << endl;
    cout << "|                           SELAMAT DATANG ADMIN                            |" << endl;
    cout << "+====+======================================================================+" << endl;
    cout << "| 1. | Menambah Calon Kepala Desa                                           |" << endl;
    cout << "| 2. | Menghapus Calon Kepala Desa                                          |" << endl;
    cout << "| 3. | Menambah Warga Desa                                                  |" << endl;
    cout << "| 4. | Menghapus Warga Desa                                                 |" << endl;
    cout << "| 5. | Tampilkan Pemilih Termuda & Tertua                                   |" << endl;
    cout << "| 6. | Tampilkan Calon dengan Suara Terbanyak Terkini                       |" << endl;
    cout << "| 7. | Tampilkan Informasi Calon Kepala Desa dengan Nama Tertentu           |" << endl;
    cout << "| 8. | Tampilkan Nama, banyaknya pemilih dengan gender Laki2 & Perempuan,   |" << endl;
    cout << "|    | usia <= 20thn, dan usia > 20thn untuk setiap Calon                   |" << endl;
    cout << "| 9. | LogOut (Halaman Utama)                                               |" << endl;
    cout << "| 0. | Exit (Close Program)                                                 |" << endl;
    cout << "+====+======================================================================+" << endl;
}

void printMenuWarga() {
    cout << "+===========================================================================+" << endl;
    cout << "|                           SELAMAT DATANG WARGA                            |" << endl;
    cout << "+====+======================================================================+" << endl;
    cout << "| 1. | Melakukan Pemilihan                                                  |" << endl;
    cout << "| 2. | Tampilkan Pemilih Termuda & Tertua                                   |" << endl;
    cout << "| 3. | Tampilkan Informasi Calon Kepala Desa dengan Nama Tertentu           |" << endl;
    cout << "| 4. | Tampilkan Nama, banyaknya pemilih dengan gender Laki2 & Perempuan,   |" << endl;
    cout << "|    | usia <= 20thn, dan usia > 20thn untuk setiap Calon                   |" << endl;
    cout << "| 5. | Tampilkan Calon dengan Suara Terbanyak Terkini                       |" << endl;
    cout << "| 9. | LogOut (Halaman Utama)                                               |" << endl;
    cout << "| 0. | Exit (Close Program)                                                 |" << endl;
    cout << "+====+======================================================================+" << endl;
}
