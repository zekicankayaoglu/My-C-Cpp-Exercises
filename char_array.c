#include <stdlib.h>
#include <stdio.h>


//kullanicidan aldigimiz karakter dizisini ters ceviren yardimci fonksiyon
void karakter_dizinin_tersten_yazimi(char girilen_dizi[9999]){//ana fonksiyonda alinan dizi bu fonksiyona gonderilir
	int x,y;//for donguleri icin degiskenler
    for(x = 0; x < 9999 ; x++){//9999 elemani kontrol eden bir dongu olusturulur
        if(girilen_dizi[x] == '\0'){//dizinin son elemanini bulan bir if kosulu olusturulur
            for(y = x-1; y >= 0; y--){//son eleman bulununca tekrar dizinin son elemanindan baslayip ilk elemanina kadar giden bir dongu olusturulur
                printf("%c",girilen_dizi[y]);//son elemandan ilk elemana kadar dizinin tum elemanlari yazdirilir
            }
            break;//dizinin son elemanini bir kere bulmak yeterli olacagindan donguyu bitirebiliriz
        }
    }
    printf("\n\n");
}


int main(){
    char girilen_dizi[9999];//girilen asil dizi bu diziye atilir ve fonksiyona gonderilir
    char gecici_dizi[9999];//gecici dizi girilen karakter dizisinin nerde bittigini ogrenmek icin kullanilan gecici bir dizidir
    int eleman = 0;//diziyi doldururken indislerini arttirabilmek icin 0'dan baslayan bir degisken tanimlanir
 
    printf("Ters cevirmek istediginiz bir karakter dizisi giriniz:");//kullanicidan karakter dizisi istenir

    while(eleman<9999){//dongu kullanicinin girdigi karakterlerin sonuna kadar devam eder
        scanf("%c",&gecici_dizi[eleman]);//girilen dizi tek tek gecici dizisine atilir ve kontrol edilir
        if(gecici_dizi[eleman]!='\n'){//girilen dizi bitene kadar 
            girilen_dizi[eleman] = gecici_dizi[eleman];//tum elemanlari asil dizinin icine atilir
            eleman++;
        }
        else break; //eger son karaktere gelinmisse dongu biter
    }

    printf("\n");
    karakter_dizinin_tersten_yazimi(girilen_dizi);//alinan dizi fonksiyona gonderilir
    return 0;
}
