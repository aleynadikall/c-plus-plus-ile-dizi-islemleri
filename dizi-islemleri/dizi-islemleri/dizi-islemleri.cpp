#include <iostream> //cin,cout,endl
#include <time.h> //srand(time(0)) icin eklenmis kutuphane

using namespace std;

const int MAX = 100;

//SoruA icin yazilmis fonksiyon.
void soruA() {

    //ekrana ok isaretini bastirmak icin kullanilan degisken.
    string okIsareti = "--->";
    //okKonumu sayesinde ok isareti istenilen konuma bastirilir
    int okKonumu = 0, calismaSayisi = 0;
    //maksimum 100 elemanli dizi.
    int dizi[MAX];

    int elemanSayisi;
    cout << "Lutfen dizi boyutunu giriniz(Maks 100 Karakter):";
    cin >> elemanSayisi;

    //random degerler diziye atanir.
    for (int i = 0; i < elemanSayisi; i++) {
        dizi[i] = rand() % 10;
    }

    //kullanicidan istenilen karakter atamasi.
    char karakter;


    while (true) {

        //dizi ve okun ekrana bastirilmasi.
        for (int i = 0; i < elemanSayisi; i++) {
            if (i == okKonumu) {
                cout << okIsareti << dizi[i] << endl;
            }
            else {
                cout << "    " << dizi[i] << endl;
            }
        }

        //ilk calisamada girilmesi gereken karakterler ve yaptigi islemler belirtilmistir.
        if (calismaSayisi == 0) {
            cout << "[a veya A]:Okun Konumunu Bir Asagiya Indirir." << endl;
            cout << "[d veya D]:Okun Konumunu Bir Yukariya Cikarir." << endl;
            cout << "[c veya C]:Programdan Cikis Yapar." << endl;
            //calisma sayisi arttýrýlarak sadece bir kez ve programýn ilk calimasinda ekrana bastirilir.
            calismaSayisi++;
        }

        cout << "Lutfen Bir Karakter Giriniz:";
        cin >> karakter;
        if (karakter == 'a' || karakter == 'A') {

            //ilk elemandaki okun son elemana kadar konumunu arttirir.
            if (okKonumu < elemanSayisi - 1) {
                okKonumu++;
            }
            //ok konumumuz son elemandayken a ya basildiginda ok isaretini ilk elemana tasir.
            else {
                okKonumu = 0;
            }

        }
        else if (karakter == 'd' || karakter == 'D') {
            //ok konumumuz ilk elemandayken d ye basildiginda ok isaretini son elemana tasir.
            if (okKonumu == 0) {
                okKonumu = elemanSayisi - 1;
            }
            else {
                okKonumu--;
            }

        }
        //programdan cikma kontrolu.
        else if (karakter == 'c' || karakter == 'C') {
            cout << "Programdan Cikiliyor...." << endl;
            break;
        }
        else {
            cout << "Hatali Secim..." << endl;
        }

    }
}

//SoruB icin yazilmis fonksiyon.
void soruB() {

    //100x100 elemanli olusturulmus iki boyutlu dizi.
    int ikiBoyutluDizi[MAX][MAX];

    //kullanicidan alinacak girdiler.
    int diziElemanSayisi, smallNumber, largeNumber;
    cout << "Enter N for NxN array:" << endl;
    cin >> diziElemanSayisi;
    cout << endl;

    //dizinin elemanlari rastgele olarak 0-9 arasi iki boyutlu dizi icine atandi.
    for (int i = 0; i < diziElemanSayisi; i++) {
        for (int j = 0; j < diziElemanSayisi; j++) {
            ikiBoyutluDizi[i][j] = rand() % 10;
        }
    }

    //Kullanicidan karsilastirma yapilan aralik istendi.
    cout << "Enter Small Number:";
    cin >> smallNumber;
    cout << endl;
    cout << "Enter Large Number:";
    cin >> largeNumber;
    cout << endl;

    //dizinin ilk hali ekrana bastirildi.
    cout << "Normal Array:" << endl;
    for (int i = 0; i < diziElemanSayisi; i++) {
        for (int j = 0; j < diziElemanSayisi; j++) {
            cout << ikiBoyutluDizi[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Crypted Array:" << endl;
    //dizinin elemanlari araliga göre kontrol edilerek elemanlarinin icine istenilen karakterler atandi.
    //karakterler char olarak atanmasina ragmen dizi int tipinde oldugu icin ascii karsiliklari diziye atanmistir.
    for (int i = 0; i < diziElemanSayisi; i++) {
        for (int j = 0; j < diziElemanSayisi; j++) {
            int kontrolElemani = ikiBoyutluDizi[i][j];
            if (kontrolElemani < smallNumber) {
                ikiBoyutluDizi[i][j] = '*';
            }
            else if (kontrolElemani > largeNumber) {
                ikiBoyutluDizi[i][j] = '-';
            }
            else {
                ikiBoyutluDizi[i][j] = '~';
            }
        }

    }

    /*ascii karsiliklari dizide bulunan elemanlar char tipine donusturlerek istenilen hale
    getirlmis ve ekrana bastirilmistir. */

    for (int i = 0; i < diziElemanSayisi; i++) {
        for (int j = 0; j < diziElemanSayisi; j++) {
            cout << char(ikiBoyutluDizi[i][j]) << " ";
        }
        cout << endl;
    }


}


int main()
{
    //benzersiz rastgele sayilar olusturmamizi saglar.
    srand(time(0));

    //soruA ekrana bastirildi.
    cout << "Cevap 1:" << endl;
    soruA();
    cout << endl << "--------------------------------" << endl;

    //soruB ekrana bastirildi.
    cout << "Cevap 2:" << endl;
    soruB();
    cout << endl << "--------------------------------" << endl;

    system("PAUSE");
    return 0;
}