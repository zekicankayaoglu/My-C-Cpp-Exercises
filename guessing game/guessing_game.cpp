#include <iostream>
#include <ctime>
#include <cstdlib>
#include "guessing_game.h"
using namespace std;

void guessing_game::RastgeleDizi() {
    srand(time(NULL));
    for (int i = 0; i < elemenSayisi; i++) {
        sayilar[i] = rand() % (ustLimit - altLimit + 1) + altLimit;//ust ve alt limit dahil rastgele sayilarla dizi olusturur
    }

}
int guessing_game::DiziKontrol(int sayi) {
    int kontrol = 0;
    for (int i = 0; i < elemenSayisi; i++) {//girilen sayi dizide varsa
        if (sayi == sayilar[i]) {
            kontrol = 1;//1 gonderir
        }
    }
    for (int j = 0; j < bilinenSayisi; j++) {//girilen sayi onceden bulunmussa -1 gonderir
        if (bulunan[j] == sayi) {
            kontrol = -1;
        }
    }
    return kontrol;//varsa say� 1 g�nderir yoksa 0
};
int guessing_game::DizidekiSayisi(int sayi) {
    int sayici = 0;
    for (int i = 0; i < elemenSayisi; i++) {
        if (sayi == sayilar[i]) {
            sayici++;//girilen say�n�n dizide ka� tane oldu�unu sayar
        }
    }
    return sayici;//say�y� geri g�nderir
}
void guessing_game::AramaKaydirma() {
    int deneme, kontrol, sayisi;
    cout << "Bir rakam tahmin edin:";//kullan�c�dan rakam ister
    cin >> deneme;
    kontrol = DiziKontrol(deneme);//rakam�n dizide olup olmad���n� ��renir

    if (kontrol == 1) {//dizide varsa say�s�n� ��renip dizi i�eri�ini ona g�re yazd�r�r
        sayisi = DizidekiSayisi(deneme);
        for (int i = 0; i < sayisi; i++) {
            bulunan[bilinenSayisi + i] = deneme;
        }
        for (int i = 0; i < sayisi; i++) {
            cout << deneme << " Bulundu" << endl;
        }
        cout << "dizi icerigi:" << endl;
        bilinenSayisi = bilinenSayisi + sayisi;//bulunan say�lar�n soluna x yazd�r�r
        for (int i = 0; i < elemenSayisi - bilinenSayisi; i++) {
            cout << "x ";
        }
        for (int i = 0; i < bilinenSayisi; i++) {//xlerden sonra bulunan say�lar�  yazd�r�r
            cout << bulunan[i] << " ";

        }
        cout << endl << endl;
    }
    else if (kontrol == 0) {//dizide yoksa eski halini yazd�r�r
        cout << "dizi icerigi:" << endl;
        for (int i = 0; i < elemenSayisi - bilinenSayisi; i++) {
            cout << "x ";
        }
        for (int i = 0; i < bilinenSayisi; i++) {
            cout << bulunan[i] << " ";

        }
        cout << endl;
        cout << deneme << " Bulunamadi";
        cout << endl << endl;

    }
    else if (kontrol == -1) {//�nceden bulunan bir say�ysa hata verir
        cout << "Daha once bu rakami denediniz. Deneme hakkinizin biri gitti." << endl;
        cout << "dizi icerigi:" << endl;
        for (int i = 0; i < elemenSayisi - bilinenSayisi; i++) {//dizinin �nceki halini tekrar yazd�r�r
            cout << "x ";
        }
        for (int i = 0; i < bilinenSayisi; i++) {
            cout << bulunan[i] << " ";


        }
        cout << endl << endl;
    }
};

void guessing_game::OyunOyna() {
    for (int i = 0; i < elemenSayisi; i++) {//dizinin ilk hali
        cout << "x ";
    }
    cout << endl << endl;
    RastgeleDizi();//rastgele diziyi olu�turup kullan�c�dan rakam almak i�in d�ng�ye girer
    while (denemeSayisi < maksTahmin) {//deneme say�s� maksimum tahminle e�itlenene kadar oyun devam eder
        AramaKaydirma();
        if (bilinenSayisi == elemenSayisi) {//kullan�c� kazan�rsa oyun biter
            cout << endl;
            cout << "Tebrikler KAZANDINIZ :)" << endl;
            break;
        }

        denemeSayisi++;
        if (denemeSayisi == maksTahmin) {//deneme say�s� tahminle e�itlenirse kullan�c� kaybeder
            cout << "dizi icerigi:";
            cout << endl;
            for (int i = 0; i < elemenSayisi; i++) {//diziyi yazd�r�r sonra kaybettiniz ��kt�s�n� verir
                cout << sayilar[i] << " ";
            }
            cout << endl;
            cout << "Uzgunuz KAYBETTINIZ :(" << endl;
            break;
        }
    }
}
