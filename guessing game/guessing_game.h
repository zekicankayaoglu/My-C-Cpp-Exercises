#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


class guessing_game {
private:
    int sayilar[20], bulunan[20];//sayilar: rastgele dizi /bulunan:bulunan say�lar� tutan dizi
    int elemenSayisi;//oyun oynanacak dizinin eleman say�s�
    int maksTahmin;//yap�labilecek maksimum tahmin
    int altLimit;//rastgele gelicek say�lar�n alt limiti
    int ustLimit;//rastgele gelicek say�lar�n �st limiti
    int denemeSayisi = 0;//kullan�c�n�n deneme say�s�
    int bilinenSayisi = 0;//kullan�c�n�n bildi�i say�

    void RastgeleDizi();//rastgele dizi olu�turan fonksiyon
    int DiziKontrol(int sayi); //girilen say�n�n dizide olup olmad���n� kontrol eden fonksyion
    int DizidekiSayisi(int sayi);//girilen say�n�n dizideki say�s�
    void AramaKaydirma();//girilen say�y� kontrol edip yerine g�re anl�k diziyi yazd�ran fonksiyon

public:
    guessing_game(int sayi, int alt, int ust) {//yap�c�
        elemenSayisi = sayi;
        altLimit = alt;
        ustLimit = ust;
        maksTahmin = elemenSayisi * 2;//maksimum tahmin say�s� eleman say�s�n�n iki kat�d�r
        denemeSayisi = 0;
        bilinenSayisi = 0;
    }
    void OyunOyna();//oyunu oynatan fonksiyon
};
