#include <iostream>
#include <cmath>
#include <string.h>
#define i sqrt(-1) //i gördugu yere karakök -1 yazacak
using namespace std;
void yazdir(int k,int l);//fonksiyonu global olarak tanımladım
class KarmasikSayi {
private:
	double reel;
	double sanal;
public:

	KarmasikSayi() {
		this->reel=0;//1.istenileni yaptım 0 atadım reel ve sanal a
		this->sanal =0;
	} //1.default constructor oluşturduk.

	KarmasikSayi(int a) {//2. istenilen reel kısmı kullanıcıdan aldık bit tamsayı yazdırıyor çünkü sanaal kısım 0
    reel=a;
	sanal=0;
	cout<<"Olusuturulan karmasik sayi:" <<reel<<"+"<<sanal<<"i"<<endl;
	//2.integer sayiyi karmaşik sayiya çevirme
		}

	KarmasikSayi(double b) {//3. istenilen reel kısmı kullanıcıdan aldık double sayi yazdırıyor çünkü sanal kısım 0
		sanal=0;
		reel=b;
		cout<<"oluþturulan karmasik sayi:"<<reel<<"+"<<sanal<<"i"<<endl;
		//3.double sayiyi karmaþik sayiya çevirme
	}

	KarmasikSayi(int c, int d) {//4.istenilen kullanıcı reel ve sanal kısmı giriyor ve karmasık sayı üretiliyor
		reel=c;
		sanal=d;
		cout<<c<<"+"<<d<<"i"<<endl;
	}
	void setter(int c, int d){//private de olduğu için setter fonksiyonu kullandık
		reel = c;
		sanal = d;
  }
	int getReel() const {//get fonksiyonu ile reel degerimizi döndürüyoruz
		return reel;
	}
	int getSanal() const {//get fonksiyonu ile sanal degerimizi döndürüyoruz
		return sanal;
	}

	int Karmasikyap(int e,int f)//karmasık sayı yapan fonksiyon
	{cout<<"karmasık sayı yapmak için reel ve sanal degerelri isaretleriyle girniz"<<endl;
		cin>>e;
		cin>>f;
		cout<<"Karmasik yapmak istediginiz sayilari giriniz(isaretleriyle)"<<endl;
		cout<<""<<e<<""<<f<<"i"<<endl;
	}

	void karmasikTopla(int reeltoplam,int sanaltoplam){
        int h,t,p,g;//toplama yapacağımız karmasık sayıların sanal ve reel kısımları
		cout<<"Toplama yapmak istediginiz karmasik sayinin reel ve sanal kisimlarini giriniz"<<endl;
		cin>>h;
		cin>>g;
		cout<<"Toplama yapmak istediginiz karmasik sayinin reel ve sanal kisimlarini giriniz"<<endl;
		cin>>t;
		cin>>p;
		reeltoplam=h+t;//reel kısımlar kendi içinde toplanıyor
		sanaltoplam=g+p;//sanal kısımlar kendi içinde toplanıyor
		cout<<"Toplanmis hali: "<<endl;
		cout<<reeltoplam<<""<<sanaltoplam<<"i"<<endl;//sonuc ekrana basılır
	}
		void karmasikcikartma(int reelcikar,int sanalcikar){
     	int r,t,y,e;//cıkarma yapacağımız karmasık sayıların sanal ve reel kısımları
		cout<<"Cýkarma yapmak istediginiz karmasik sayinin reel ve sanal kisimlarini giriniz(isaretleriyle)"<<endl;
		cin>>r;
		cin>>t;
		cout<<"Cýkarma yapmak istediginiz karmasik sayinin reel ve sanal kisimlarini giriniz(isaretleriyle)"<<endl;
		cin>>y;
		cin>>e;
		reelcikar=r-y;//reelden reel çıkıyor
		sanalcikar=t-e;//sanaldan sanal çıkıyor

        if(sanalcikar>0){
		cout<<""<<reelcikar<<"+"<<sanalcikar<<"i"<<endl;
		}
		else{
           cout<<""<<reelcikar<<""<<sanalcikar<<"i"<<endl;//sonuc ekrana bastırılıyor
		}
		}

		void karmasikbolme(){
     	double gercek,sanal,gercel,karmasik;
     	double t1,t2,k1,k2;//bölme yapacağımız karmasık sayıların reel ve sanaal kısımları giriliyor
		cout<<"karmasik sayinin reel ve sanal kisimlarini giriniz"<<endl;
		cin>>gercel;
		cin>>sanal;
		cout<<"karmasik sayinin reel ve sanal kisimlarini giriniz"<<endl;
		cin>>gercek;
		cin>>karmasik;
		t1=(gercel*gercek)+(sanal*karmasik);//eslenik ile çarpma yapılıyor
		t2=(gercek*gercek)+(karmasik*karmasik);
		double tam=t1/t2;
		k1=(sanal*gercek)-(gercel*karmasik);
		k2=(gercek*gercek)+(karmasik*karmasik);
		double kompleks=k1/k2;
		if(kompleks<0){
            cout<<"Karmasik sayilarin bolümü: "<<tam<<kompleks<<"i"<<endl;//sanal kısım negatif çıktığında - işareti zaten konulacağı için tekrar işaret koymuyoruz
		}
		else {

            cout<<"Karmasik sayilarin bolümü: "<<tam<<"+"<<kompleks<<"i"<<endl;//sanal kısım pozitifse işareti ortaya koyuyoruz

		}

    }
};
int main()
{
	KarmasikSayi k1,k2,k3,k4;//objelerimizi tanımladık
    yazdir(k1.getReel(),k1.getSanal());//global fonksiyonuzmuzla degerleri çağırıdk
    k2.Karmasikyap(k2.getReel(),k2.getSanal());//class ın içindeki fonk ile karmasık sayı yapıyoruz
    k2.karmasikTopla(k2.getReel(),k2.getSanal());//karmasık sayıları toplama fonksiyonunu çağırdık
    k2.karmasikcikartma(k2.getReel(),k2.getSanal());//karmasık sayıları çıkarma fonk çağırdık
    k3.karmasikbolme();//karmasık sayıları bölme fonk çağırdık
    KarmasikSayi(2,6);//karmasık sayı yapan constructor çağırıdık
    KarmasikSayi(5);//int gönderdiğimiz 2. istenen constructor a deger gönderdik
    KarmasikSayi(2.7);//double gönderdiğimiz 3. istenen constructor a deger gönderdik

	return 0;
}
void yazdir(int k,int l){//global yazdığımız karmasık sayıyı reel ve sanal şeklinde gösteren fonksiyonumuz
	cout<<"Olusturmak istediginiz karmasik sayiyi giriniz(isaretleriyle)"<<endl;
	cin>>k;
	cin>>l;
	cout<<""<<k<<""<<l<<"i"<<endl;
	cout<<"reel kisim: "<<k<<endl;
	cout<<"sanal kisim:"<<l<<endl;
}
