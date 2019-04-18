#include <stdio.h>
#include <stdlib.h>
#define max 300

unsigned char kelime[max];

void giris();        //Klavyeden Cumle alma
void yazdir();       //Ekrana yazd�rma fonksiyonu
int satirsay();      //Olu�acak sat�r say�s� fonksiyonu
void istatistikler ();         //Olu�an istatistikler fonksiyonu
int gettrknum(const unsigned char *str);   //Turk�e karakter fonksiyonu
int DortHarf(int *dizi, int boyut);        //4 harften k�sa kelime fonksiyonu
int OnHarf(int *dizi, int boyut);          //On haften uzun kel�me fonksiyonu
int EnUzunKelime(int *dizi, int boyut);    //En uzun kelime fonksiyonu
int UcKelime(int *dizi,int boyut);         //Uc kelime den k�sa cumle fonksiyonu

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
  //While ile kelime olu�turma
  kelime[i]='\0';
  puts(kelime);
}

void yazdir(){
  int i,j,k=0,a=0,b,c,d=0;
  int satir=satirsay ();
  //Olu�acak sat�r say�s�
  for (i=0;i<satir+2;i++){
      b=0;
      for (j=k+a;j<a+k+i;j++){
          if (kelime[j]!='.' && kelime[j]!='?' && kelime[j]!='!' && kelime[j]!=':'){
              if (kelime[j]!=' ' && kelime[j]!=',' && kelime[j]!=';'){
                  printf ("%c",kelime[j],d++);
                  //Harfleri yazd�rma
                  if (kelime[j+1]=='.' || kelime[j+1]=='?' || kelime[j+1]=='!'){
                      for (c=d;c<i;c++){
                          printf ("+");
                          //Art� i�areti yazma
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
              //Yeni c�mle baslang�c�
            }
        }
      if (b==0){
          k=k+i;
         }
      printf ("\n");
      //Yeni sat�r ba�lang�c�
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
  //Fibonacciden faydalanarak sat�r say�s� belirleme
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
      //Cumle,kelime,harf say�s�n�n belirlenmesi
      //Kelimelerin harf say�lar�n�n diziye eklenmesi
      //Cumlelerin kelime say�lar�n�n diziye eklenmesi
      if (kelime[i]==' ' || kelime[i]==',' || kelime[i]==';' || kelime[i]==':'){
          kelime0++;
          harf++;
          kelDizi[j]=sayac0;
          sayac0=0;j++;
        }
      //Kelime ve harf say�s�n�n belirlenmesi
      //Kelimelerin harf say�lar�n�n diziye eklenmesi
      if (i==strlen(kelime)-1){
          kelDizi[j]=sayac0+1;
          sayac0=0;j++;
        }
    }
  harf=strlen(kelime)-harf;
  //Karakter say�s�ndan harf say�s� ��kart�lmas�
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
   //148=� 128=� 129=� 135=� 154=� 153=� �=167 �=166 �=158 �=159 �=141 �=152
   //T�rk�e karakterlerin ASCII da kar��l�k gelen numaralar�
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
  //D�rt harften k�sa kelime say�s�
  return sayac;
}

int OnHarf (int *dizi, int boyut){
  int i,sayac=0;
  for (i=0;i<boyut+1;i++){
      if (dizi[i]>10)
         sayac++;
  }
  //On harften uzun kelime say�s�
  return sayac;
}

int EnUzunKelime (int *dizi, int boyut){
  int i,enuzun=dizi[0];
  for (i=1;i<boyut+1;i++){
      if (dizi[i]>enuzun){
          enuzun=dizi[i];
        }
    }
  //En uzun kelime say�s�
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
  //Uc kelimeden az cumle say�s�
  return sayac;
}
