#include <stdio.h>
#include <stdlib.h>
#define max 300

unsigned char kelime[max];

void giris();        //Klavyeden Cumle alma
void yazdir();       //Ekrana yazdýrma fonksiyonu
int satirsay();      //Oluþacak satýr sayýsý fonksiyonu
void istatistikler ();         //Oluþan istatistikler fonksiyonu
int gettrknum(const unsigned char *str);   //Turkçe karakter fonksiyonu
int DortHarf(int *dizi, int boyut);        //4 harften kýsa kelime fonksiyonu
int OnHarf(int *dizi, int boyut);          //On haften uzun kelýme fonksiyonu
int EnUzunKelime(int *dizi, int boyut);    //En uzun kelime fonksiyonu
int UcKelime(int *dizi,int boyut);         //Uc kelime den kýsa cumle fonksiyonu

int main(void)
{
  giris ();
  yazdir();
  istatistikler ();
  return 0;
}

void giris (){
  int i=0;
  char c;
  printf ("Cumleyi giriniz: ");
  while ((c=getchar ())!='#'){
      kelime[i]=c;
      i++;
  }
  //While ile kelime oluþturma
  kelime[i]='\0';
  puts(kelime);
}

void yazdir(){
  int i,j,k=0,a=0,b,c,d=0;
  int satir=satirsay ();
  //Oluþacak satýr sayýsý
  for (i=0;i<satir+2;i++){
      b=0;
      for (j=k+a;j<a+k+i;j++){
          if (kelime[j]!='.' && kelime[j]!='?' && kelime[j]!='!' && kelime[j]!=':'){
              if (kelime[j]!=' ' && kelime[j]!=',' && kelime[j]!=';'){
                  printf ("%c",kelime[j],d++);
                  //Harfleri yazdýrma
                  if (kelime[j+1]=='.' || kelime[j+1]=='?' || kelime[j+1]=='!'){
                      for (c=d;c<i;c++){
                          printf ("+");
                          //Artý iþareti yazma
                        }
                    }
                }
              else{
                  k++;
                }
            }
          else{
              printf ("\n");
              a=j+1,k=0,i=0,b=1;
              //Yeni cümle baslangýcý
            }
        }
      if (b==0){
          k=k+i;
         }
      printf ("\n");
      //Yeni satýr baþlangýcý
      d=0;
    }
}

int satirsay (){
  int fib0=0,fib1=1,i=0,fib=0;
  while (fib<strlen(kelime)){
      fib=fib0+fib1;
      fib0=fib1;
      fib1=fib;
      i++;
    }
  //Fibonacciden faydalanarak satýr sayýsý belirleme
  return i;
}

void istatistikler (){
  int i,j=0,k=0,cumle=0,kelime0=0,harf=0,sayac0=0,kelDizi[max],kelSayi[max];
  for (i=0;i<strlen(kelime);i++){
      if (kelime[i]!='.' || kelime[i]!='?' || kelime[i]!='!' || kelime[i]!=' ' || kelime[i]!=',' || kelime[i]!=';' || kelime[i]!=':'){
          sayac0++;
        }
      if (kelime[i]=='.' || kelime[i]=='?' || kelime[i]=='!'){
          cumle++;
          kelime0++;
          kelSayi[k]=kelime0;
          k++;
          harf++;
          kelDizi[j]=sayac0;
          sayac0=0;j++;
        }
      //Cumle,kelime,harf sayýsýnýn belirlenmesi
      //Kelimelerin harf sayýlarýnýn diziye eklenmesi
      //Cumlelerin kelime sayýlarýnýn diziye eklenmesi
      if (kelime[i]==' ' || kelime[i]==',' || kelime[i]==';' || kelime[i]==':'){
          kelime0++;
          harf++;
          kelDizi[j]=sayac0;
          sayac0=0;j++;
        }
      //Kelime ve harf sayýsýnýn belirlenmesi
      //Kelimelerin harf sayýlarýnýn diziye eklenmesi
      if (i==strlen(kelime)-1){
          kelDizi[j]=sayac0+1;
          sayac0=0;j++;
        }
    }
  harf=strlen(kelime)-harf;
  //Karakter sayýsýndan harf sayýsý çýkartýlmasý
  printf ("\nMetindeki Toplam Cumle Sayisi=%d",cumle);
  printf ("\nMetindeki Toplam Kelime Sayisi=%d",kelime0);
  printf ("\nMetindeki Toplam Karakter Ssyisi=%d",strlen(kelime));
  printf ("\nMetindeki Toplam Harf Sayisi=%d",harf);
  printf ("\nTurkce karakter sayisi ve yuzdesi= %d\t%f",gettrknum (kelime),(float)100*(gettrknum (kelime))/harf);
  printf ("\nCumelelerin Ortalama Kelime Sayisi=%f",(float)(kelime0)/(float)(cumle));
  printf ("\nKelimlerin Ortalama Harf Sayisi=%f",(float)harf/(kelime0));
  printf ("\n4 Harften Kisa Kelimelerin Sayisi=%d",DortHarf (kelDizi,kelime0));
  printf ("\n10 Harten Uzun Kelimelerin Sayisi=%d",OnHarf (kelDizi,kelime0));
  printf ("\nEn Uzun Kelimenin Harf Sayisi=%d",EnUzunKelime (kelDizi,kelime0));
  printf ("\n3 Kelimeden Kisa Cumlelerin Sayisi=%d\n",UcKelime(kelSayi,cumle));

}

int gettrknum (const unsigned char *str){
   int counter=0,i;
   //148=ö 128=Ç 129=ü 135=ç 154=Ü 153=Ö ð=167 Ð=166 Þ=158 þ=159 ý=141 Ý=152
   //Türkçe karakterlerin ASCII da karþýlýk gelen numaralarý
   for (i=0;str[i]!='\0';i++){
      if (str[i]==153 || str[i]==135 || str[i]==128 || str[i]==129 || str[i]==154 || str[i]==148 || str[i]==167 || str[i]==166 || str[i]==158 || str[i]==159 || str[i]==152 || str[i]==141){
           counter++;
          }
     }
   return counter;
}

int DortHarf (int *dizi,int boyut){
  int i,sayac=0;
  for (i=0;i<boyut+1;i++){
      if (dizi[i]<=4)
        sayac++;
    }
  //Dört harften kýsa kelime sayýsý
  return sayac;
}

int OnHarf (int *dizi, int boyut){
  int i,sayac=0;
  for (i=0;i<boyut+1;i++){
      if (dizi[i]>10)
         sayac++;
  }
  //On harften uzun kelime sayýsý
  return sayac;
}

int EnUzunKelime (int *dizi, int boyut){
  int i,enuzun=dizi[0];
  for (i=1;i<boyut+1;i++){
      if (dizi[i]>enuzun){
          enuzun=dizi[i];
        }
    }
  //En uzun kelime sayýsý
  return enuzun-1;
}

int UcKelime (int *dizi, int boyut){
  int i,sayac=0;
  for (i=boyut+1;i>0;i--){
      dizi[i]=dizi[i]-dizi[i-1];
    }
  for (i=0;i<boyut+1;i++){
      if (dizi[i]<3){
         sayac++;
        }
    }
  //Uc kelimeden az cumle sayýsý
  return sayac;
}
