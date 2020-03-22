/*Zıp zıp kurbağa bir nehri karşıdan karşıya geçmek istemektedir. Nehrin iki kenarı arasında 72 adet taş vardır. Kurbağa

sadece ileri doğru ve tek bir seferde rastgele olarak 1, 2 veya 3 sonraki taşa zıplamaktadır. 72 adet taş verildiğinde nehrin

bir kenarından diğer kenarına kaç farklı şekilde ulaşabileceği bulan bir program*/



#include <iostream>

#include <vector>

#include <iomanip>

#include <chrono>



using namespace std;



//aşağıdaki satırları yoruma alarak kodunuzu farklı şekillerde test edebilirsiniz.

#define _TEST_ITERATIVE_

#define _TEST_RECURSIVE_



// Bu odevde global veya statik degisken tanimlanamaz!!!



/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.

 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction

 * fonksiyonu cagri yapilmalidir.

 */



long long recursiveFunction(int numberOfStones)//long da tutmamız gerektiği için longla tanımladık fonksiyonu

{

	switch (numberOfStones)//durumlar için switch case kullanıyoruz

	{

	case 1:          // base case 1

		return 1;

		break;



	case 2:          //base case 2

		return 2;

		break;



	case 3:          //base case 3

		return 4;

		break;



	default://burası bütün ihtimalleri en son 3,2,1 li taşlara çeviren kısım onu dönderiyor eğer taş sayısı 4 ve 4den büyükse

		return recursiveFunction(numberOfStones - 1) + recursiveFunction(numberOfStones - 2) + recursiveFunction(numberOfStones - 3); //bu kısım memoization kısmıdır sayılar her defasında 1-2-3 adımdarındaki yollara bölünür.

	}

}



/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.

 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.

 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.

 */



long long iterativeFunction(int numberOfStones,int i)//buda recursive fonksiyonun iterative hali

{

	long long yolsayisi;

	vector <long long> zipzip;  //yol sayısını tutan vector

	zipzip.push_back(1);        //vektörün ilk elemanı 1 (base case-1)

	zipzip.push_back(2);        //vektörün ikinci  elemanı 2 (base case-2)

	zipzip.push_back(4);        //vektörün üçüncü elemanı 4 (base case-3)

	long long toplam = 7;      // her adım kendinden önceki 3 adımın toplam yol sayısı kadardır 4.adımda 1.2. ve 3.adımların toplamı olan (1+2+4=7) 7 vardır ve bu toplam vektöre arkadan eklenir.

	for (int i =1; i < numberOfStones; ++i)  //döngü ile 4. elemandan itibaren önceki 3 eleman toplanır ve toplamlar vektöre arkadan eklenir.

	{

		zipzip.push_back(toplam);//alttaki toplam vectorun son elemanı olarak eklenir

		yolsayisi = zipzip[i-1] ;//alttaki işlemde çıkarılacak yol sayısı

		toplam = toplam * 2 - yolsayisi;  //matematiksel olarak toplam  base caselerden sonraki ilk  yol sayının (7) 2 katı ve dizinin ilk elemanından başlayarak sırayla yol sayısını çıkararak bulunur.

	}

	return zipzip[i-1];  //main kısmındaki döngü buradaki vektör elmanlarını sırasıyla dizi gibi basar.

}







int main()

{

	const int MAX_NUMBER_OF_STONES{ 72 };



	cout << setfill(' ');



	cout.imbue(locale(""));



	for (auto i = 1; i < MAX_NUMBER_OF_STONES; ++i)

	{



#ifdef _TEST_ITERATIVE_

		{

			long long tempResult = { 0 };



			auto start = std::chrono::steady_clock::now();

			tempResult = iterativeFunction(i,i);

			auto stop = std::chrono::steady_clock::now();

			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();





			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";

		}

#endif



#ifdef _TEST_RECURSIVE_

		{

			long long tempResult = { 0 };



			auto start = std::chrono::steady_clock::now();

			tempResult = recursiveFunction(i);

			auto stop = std::chrono::steady_clock::now();

			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();



			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";

		}

#endif



	}

