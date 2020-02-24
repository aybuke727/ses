#include <iostream>
//Aybuke Mutlu
//odev1
using namespace std;

void tersbas(int sayi) {//ters ucgen basan fonk
	int a = 0;
	int m = 0;
	int k = 0;

	int n = sayi - 2;
	int p = sayi;//sayi degerini sabit tutmak için
	int c=0;
	int y=0;

	if(sayi%2==0){//eger cift sayi girilirse
            while(c<2){//mainde de 1 kere sayi aldýðý iin burda iki kere sayi alma hakký var
        cout<<"lutfen tek sayi giriniz"<<endl;
        cin>>sayi;
        c++;
        if(sayi%2!=0){//tek sayi aldýðýnda burdaki döngüden çýkýyor
            break;
        }
	}}
	if(sayi%2!=0){//eðer aldýðý sayi tek ise bu döngüye girer
	while (a <=(p-1)/2) {
		while (m<y) {//yanlardaki bosluk sayisini belirleyecek
			cout<<" ";
			m++;}
			while (k <sayi) {//yýldýz sayýsýný belirleyecek
				cout << "*";
				k++;
			}
			cout << endl;
			sayi = sayi - 2;//yýldýz sayisi ikiþer azaldýðý için
			n--;
			a++;
			k=0;// degerleri kendimiz sýfýrlýyoruz
			m=0;
			y++;//bosluk sayisi her satýrda bir artacak
			}}}



	void duzbas(int sayi){//duz uçgen basan fonk

if(sayi%2==0){//eger cift sayi girilirse
    for(int a=1;a<=2;a++){//mainde de 1 kere sayi aldýðý iin burda iki kere sayi alma hakký var
    cout<<"3 ve 15 arasinda tek sayi degeri giriniz"<<endl;
    cin>>sayi;
    if(sayi%2!=0){//tek sayi aldýðýnda burdaki döngüden çýkýyor
        break;
    }
    }}


 if(sayi%2!=0){
   int c,m,k;//kullanacaðýmýz sayýlar
   int b=sayi-1;
   int n=sayi-2;
   int p=sayi;
   int onem=(p-1)/2;//bosluk sayýsýnýn ilk degerini belirler

      for(c=0;c<(p+1)/2;c++){//kaç satýr olacaðýný belirler
        for(m=0;m<onem;m++){
            cout<<" ";
        }
        for(k=0;k<p-b;k++){
            cout<<"*";
        }
        cout<<endl;
        m=0;//degerlerimiz sýfýrlýyoruz
        k=0;
        b=b-2;//yýldýz her satýrda ikiþer artýyor
        k=0;
        onem--;//bosluk birer birer azalýyor

      }}}





int main()
{   int d;//hangi iþlemi secmesi
    cout<<"1)ucgen"<<endl;
    cout<<"2)tersucgen"<<endl;
    cout<<"3)elmas"<<endl;
    cout<<"cizmek istediginiz sekli seciniz"<<endl;
	cin>>d;
	int sayi;
	if(d==1){
        cout<<"3ile15 arasinda tek sayi seciniz"<<endl;
        cin>>sayi;//kaç basamaklý ücgen yapmak istiyorsa seciyor
        duzbas(sayi);
	}
	else if(d==2){
            cout<<"3ile15 arasinda tek sayi seciniz"<<endl;
            cin>>sayi;//kaç basamaklý ücgen yapmak istiyorsa seciyor
            tersbas(sayi);
	}
	else if(d==3){
        cout<<"5ile15 arasinda tek sayi seciniz"<<endl;
        cin>>sayi;//kaç basamaklý ücgen yapmak istiyorsa seciyor
        duzbas(sayi);
        tersbas(sayi);
	}

	return 0;
}

