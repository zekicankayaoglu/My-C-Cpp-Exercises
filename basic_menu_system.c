#include <stdlib.h>
#include <stdio.h>

//diziyi yazdirmak icin kullandigimiz fonksiyon
void dizi_yazdirma(int Dizi[2][10]){
	int x;//for donguleri icin degisken olusturulur
    printf("\n");
    //ilk dongu numaralari yazdirir
    for(x = 0; x < 10; x++){
        printf("%d  ",Dizi[0][x]);
        //ilk once ogrencilerin numaralari yazdirilir           
    }
    printf("\n");
    //ikinci dongu numaralarin altlarina notlarini yazdirir
    for(x = 0; x < 10; x++){
        printf("%d      ",Dizi[1][x]);//bosluklar dizinin duzenli gorunmesi icin birakildi
        //numaralarinin altlarinda duzenli olarak notlari yazdirilir
    }
    
    printf("\n");
}

//dizideki en yuksek notu bulan fonksiyon
void maksimum_notu_bul(int Dizi[2][10]){
    int i,y;//kullanacagimiz donguler icin degisken tanimlariz
    int bayrak;//bayrak degiskeni en yuksek not bulunduysa 1 olarak kalir aksinde 0 olur ve dongu en yuksek notu aramaya devam eder
    i=0;//i degiskeni 0dan baslayarak dizideki tum notlari while dongusu ile artarak gezer
    printf("\n");
    while(i<10 && bayrak != 1){//bayrak 1 olmadikca ve i 10'dan kucuk oldukca dongu devam eder
        bayrak = 1;
        for(y = 0;y < 10; y++){
            if(Dizi[1][i] < Dizi[1][y]){//eger o anki nottan daha yuksek not varsa bayrak 0 olur dongu devam eder
                bayrak = 0;//eger o nottan daha yuksek not yoksa maksimum not olmus olur ve bayrak 1 olarak kalir degismez
            }
        }
        if(bayrak == 1){//bayrak 1 kalmasi durumunda o not en yuksek nottur 
            printf("En yuksek not: %d\n",Dizi[1][i]);
            printf("Alan ogrencinin numarasi: %d\n",Dizi[0][i]); 
        }
        i++;
    }
    printf("\n");
}

//dizideki en dusuk notu bulan fonksiyon
void minimum_notu_bul(int Dizi[2][10]){
    int i,y;//kullanacagimiz donguler icin degisken tanimlariz
    int bayrak;//bayrak degiskeni en dusuk not bulunduysa 1 olarak kalir aksinde 0 olur ve dongu en dusuk notu aramaya devam eder
    i=0;//i degiskeni 0dan baslayarak dizideki tum notlari while dongusu ile artarak gezer
    printf("\n");
    while(i<10 && bayrak != 1){//bayrak 1 olmadikca ve i 10'dan kucuk oldukca dongu devam eder
        bayrak = 1;
        for(y = 0;y < 10; y++){
            if(Dizi[1][i] > Dizi[1][y]){//eger o anki nottan daha dusuk not varsa bayrak 0 olur dongu devam eder
                bayrak = 0;//eger o nottan daha dusuk not yoksa maksimum not olmus olur ve bayrak 1 olarak kalir degismez
            }
        }
        if(bayrak == 1){//bayrak 1 kalmasi durumunda o not en dusuk nottur 
            printf("En dusuk not: %d\n",Dizi[1][i]);
            printf("Alan ogrencinin numarasi: %d\n",Dizi[0][i]); 
        }
        i++;
    }
    printf("\n");
}

//notlarin ortalamasini hesaplayan fonksiyon
void ort_hesaplayici(int Dizi[2][10]){
    int eleman;//dizinin indislerini gezerken yardimci degisken tanimlariz
    double notOrtalamasi,notlarToplami = 0;//notlar toplamini basta 0 olarak tanimlariz
    printf("\n");
    //oncelikler tum notlarin toplamini buluruz
    eleman = 0;//0. elemandan baslayarak donguye girer
	while(eleman < 10){//elemanlar bitene kadar dongu devam eder
        notlarToplami = notlarToplami + Dizi[1][eleman];//tum elemanlari gezerek not toplami degiskenine o notu ekleriz
        eleman++;
    }
    notOrtalamasi = notlarToplami / 10;//sonrasinda elde ettigimiz toplami toplam not sayisina bolerek not ortalamasini elde ederiz
    printf("Not ortalamasi: %.2f\n",notOrtalamasi);
    printf("\n");
}

//ogrenci numarasini alarak ogrencinin notunu bulan fonksiyon
void not_bulan_fonksiyon(int Dizi[2][10],int ogrenciNotu){
    int tutucu,eleman;
    int min_indis = 0;//dizinin en dusuk indisini tutan degisken
    int maks_indis = 10;//dizinin en yuksek indisini tutan degisken
    printf("\n");
    //ikili arama algoritmasi icin oncelikle diziyi kucukten buyuge siralamamiz gerek
    eleman = 0;//eleman degiskeni sira sira tum indisleri gezmek icin 0dan baslatilip while dongusune sokuluyor
    while(eleman<9){
        if(Dizi[0][eleman] > Dizi[0][eleman+1]){//dizinin her elemani kendinden sonrakiyle karsilastirilir eger daha buyukse yer degistirilir
            tutucu = Dizi[0][eleman+1];//elemanlarin yeri degistirilirken tutucu degiskeni bir tanesinin degerini tutar
            Dizi[0][eleman+1] = Dizi[0][eleman];//sagdaki deger soldakine esitlenir
            Dizi[0][eleman] = tutucu;//sonrasinda soldaki deger de tutucunun tuttugu degere esitlenir ve yer degistirme tamamlanmiş olur
            //ogrenci numaralarini siraladiktan sonra ayni islemi notlari icin de gerceklestirip notlari da siraliyoruz
            tutucu = Dizi[1][eleman+1];
            Dizi[1][eleman+1] = Dizi[1][eleman];
            Dizi[1][eleman] = tutucu;
        }
            eleman++;//islem bittiginde siradaki indise geciyoruz
    }
    
    //diziyi kucukten buyuge dogru siraladiktan sonra devreye ikili arama algoritmasi giriyor
    
    while(min_indis < maks_indis){//en dusuk indis en yuksek indisten kucuk oldugu surece dongu bitmez
        int orta_indis = (maks_indis + min_indis) / 2;//dongu her basladiginda eldeki indislerin ortancasi bulunur
        //ve ortadaki elemanin aranan eleman olup olmadigi kontrol edilir
        if(Dizi[0][orta_indis] == ogrenciNotu){//eger aranan eleman ortadaki ise direkt bulunmus olur ve dongu biter
            printf("Girilen ogrencinin notu: %d", Dizi[1][orta_indis]);
            break;
        }
        //eger aranan eleman orta indisteki elemandan kucukse yeni maksimum indis o anki ortanca indis olur ve donguye tekrar girer 
        else if(Dizi[0][orta_indis] > ogrenciNotu){
            maks_indis = orta_indis;
        }
        //eger aranan eleman orta indisteki elemandan buyukse yeni minimum indis o anki ortanca indis olarak donguye yeniden girilir
        else{
            min_indis = orta_indis;//kalan durumlarda maksimum i olmus olur
        }
        //bu sekilde aranan eleman bulunana dek dongu devam eder
    }
    printf("\n\n");
    
}


int main(){
    int Dizi[2][10] = {{108745, 109356, 112567, 150042, 127633, 137821, 143266, 116423,157894,146278},
    {25, 66, 84, 75, 39, 86, 91, 72, 54, 36}};//elimizdeki dizi
    int kullanici_secimi = 0,ogrenciNotu;//kullanici secimi degiskeni kullanicinin secimi icin
    
    do{//kullanici cikis secenegini secmedigi surece menu basilmaya devam eder
        printf("0.Diziyi yazdir\n");
        printf("1.Maksimum notu bul\n");
        printf("2.Minimum notu bul\n");
        printf("3.Ortalamayi hesapla\n");
        printf("4.Ogrenci numarasi kullanarak siralama yap ve notu bul\n");
        printf("5.Cikis\n");

        scanf("%d",&kullanici_secimi);
        switch(kullanici_secimi){
            //kullanicinin secimine gore farkli fonksiyonlar cagirilir
            case 0://kullanici 0'i secerse diziyi yazdiran fonksiyona gidilir
                dizi_yazdirma(Dizi);
                break;
             
            case 1://kullanici 1'i secerse dizideki en yuksek notu bulan fonksiyona gidilir
                maksimum_notu_bul(Dizi);
                break;
            
            case 2://kullanici 2'yi secerse dizideki en dusuk notu bulan fonksiyona gidilir
                minimum_notu_bul(Dizi);
                break;
            case 3://ekullanici 3'u secerse ort hesaplayici fonksiyona gidilir
                ort_hesaplayici(Dizi);
                break;
            case 4://kullanici 4'u secerse not bulan fonksiyona gidilir
                printf("Aranan ogrencinin numarasi:");//notu ogrenilmek istenen ogrencinin numarasi istenir
                scanf("%d",&ogrenciNotu);
                not_bulan_fonksiyon(Dizi,ogrenciNotu);//alinan not ve dizi fonksiyona gonderilir
                break;
        }
     
    }while(kullanici_secimi!=5);
    
    return 0;
    
}