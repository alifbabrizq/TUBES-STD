#include "menu.h"
/*
Kelompok 7 :
  1. Alif Babrizq Kuncara (1301204228)
  2. Aryya Bagus Padmanawijaya (1301204310)
*/
int main() {
    listCalon listC;
    listWarga listW;
    createListCalon(listC);
    createListWarga(listW);
    selectMenu(listC, listW);

    return 0;
}
