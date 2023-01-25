#include <stdlib.h>
#include <stdio.h>

int main(){
    int asal_sayi_dizisi[1000];//1000 elemanli bir dizi olusturulur
    int eleman;//eleman indisi icin degisken
    int indis = 2;//asal sayilar 2den basladigi icin 2 ye esit bir indis degiskeni olusturulur
    int x;//for dongulerinde kullanmak icin degisken

    for(eleman = 0; eleman < 1000; eleman++){//basit bir for dongusu ile dizinin tüm elemanlari 1'e esitlenir
        asal_sayi_dizisi[eleman] = 1;
    }
    
    while(indis<=999){//999a kadar dizinin tum elemanlarini gezen bir dongu olusturulur
        if(asal_sayi_dizisi[indis] == 1){
            //dizinin 1e esit olan elemanlarini bulmak icin bir if kosulu olusturulur
            x = indis + 1;
            while(x<1000){//eger o kosula uyan eleman varsa yeni bir dongu olusturulur ve bu dongude
            //elemanin indisinden baslayarak sonraki tum indislerin o elemanin indisine tam bolunup bolunmedigi kontrol edilir
                if(x % indis == 0){
                    //eger o indisten sonraki indisleri tam boldukleri varsa o indisteki dizinin elemanlari asal olmadigi icin 0a esitlenir
                    asal_sayi_dizisi[x] = 0;
                }
                x++;
            }
        }
        indis++;
    }
    
    //basit bir while dongusuyle dizinin tum elemanlarini kontrol edip dizideki 1e esit olan elemanlar bulunup onlarin indisleri (yani asal sayilari) yazdiririz
    indis = 2;//indis 2den baslayarak
    while(indis < 1000){
        if(asal_sayi_dizisi[indis] == 1){//eger eleman 1'esit ise
            printf("%d ",indis);//o elemanin indisi asaldir
        }
        indis++;
    }
    printf("\n");
    return 0;
}
