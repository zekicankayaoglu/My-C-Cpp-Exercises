#include <iostream>
#include <ctime>
#include <cstdlib>
#include "guessing_game.h"

int main() {

    int girilenSayi, alt, ust;

    cout << "Alt limit giriniz:" << endl;//kullanıcıdan alt limit alır
    cin >> alt;
    cout << "Ust limit giriniz:" << endl;//kullanıcıdan üst limit alır
    cin >> ust;
    cout << "Dizideki rakam sayisini giriniz:" << endl;//dizideki rakam sayısını alır
    cin >> girilenSayi;
    while (girilenSayi > 20 || girilenSayi < 2) {//eğer rakam sayısı 2 - 20 arasında değilse hata verir
        cout << "Gireceginiz sayi 2 ile 20 arasinda olmalidir!" << endl;
        cout << "Dizideki rakam sayisini giriniz:" << endl;
        cin >> girilenSayi;
    }
    guessing_game nsn(girilenSayi, alt, ust);//girilen değerleri sınıftaki değişkenlere gönderir
    cout << endl << endl;
    nsn.OyunOyna();//oynatma fonksiyonunu çağırıp oyunu başlatır

    return 0;
}