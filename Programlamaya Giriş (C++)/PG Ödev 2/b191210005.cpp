/****************************************************************************
**
**                      ��RENC� ADI........:�BRAH�M ATIF KURU
**                      ��RENC� NUMARASI...:b191210005
**                      DERS GRUBU.........:1. ��retim C grubu
****************************************************************************/
#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
//Matrisi yazan fonksiyonun prototipi tan�mlan�yor.
void matrisiYaz(int boyut, int matris[25][25]);

int main()
{
	int matrisBoyutu;
	//Matris boyutunun 5 ile 25 aras�nda olup olmad���n� belirleyen d�ng� kuruluyor. 
	do
	{
		cout << "Matris boyutu girin:";
		cin >> matrisBoyutu;
		//Matris boyutu hatal� olursa ilgili mesaj� ekrana ��karan ko�ul konulur.
		if (matrisBoyutu < 5 || matrisBoyutu>25)
			cout << "Matris boyutu 25'den kucuk 5'den buyuk olmalidir" << endl << endl;
	} while (matrisBoyutu < 5 || matrisBoyutu>25);

	int Matris[25][25];
	srand(time(0));
	//Belirlenen boyuta g�re matrise rand fonksiyonu ile 0 ile 9 aras�nda rastgele de�erler atan�yor.
	for (int satir = 0; satir < matrisBoyutu; satir++)
	{
		for (int sutun = 0; sutun < matrisBoyutu; sutun++)
		{
			Matris[satir][sutun] = (rand() % 10);
		}
	}
	//Caseler uyguland�ktan sonra �dev d�k�man�nda oldu�u gibi tekrar matrisin yaz�lmas�n� ve men�n�n ��kmas�n� sa�layan sonsuz d�ng� kurulur.
	do
	{
		//Matrisi yazan fonsiyon �a��r�l�r.
		matrisiYaz(matrisBoyutu, Matris);

		int secenek;
		//Men�y� yazd�ran ve se�imi sa�layan hatal� se�imde ba�a d�nen d�ng� kurulur.
		do {

			cout << "1.Sutun Satir Degistir" << endl
				<< "2.Tekleri Basa Al(Satir)" << endl
				<< "3.Ters Cevir(Sutun)" << endl
				<< "4.Toplamlari yazdir" << endl;
			cin >> secenek;
			//1,2,3 veya 4 d���nda bir de�er girildi�inde hata mesaj�n� ekrana ��karan ko�ul yaz�l�r.
			if (secenek < 1 || secenek>4)
				cout << "Hatali secim" << endl;
		} while (secenek < 1 || secenek>4);
		//Menuden se�ilen i�leme g�re kodu ilgili b�l�mden devam ettiren switch case yap�s� kurulur.
		switch (secenek)
		{
			//Sat�r s�tun de�i�tiren case.
		case 1:
		{
			int satir;
			int sutun;
			cout << "Satir Sutun Girin :";
			cin >> satir >> sutun;
			//Hatal� giri�te mesaj� ekrana ��karan ve caseden ��karan ko�ul.
			if (satir > matrisBoyutu || sutun > matrisBoyutu || satir < 1 || sutun < 1)
			{
				cout << "Satir ve sutun matris boyutundan buyuk olamaz" << endl;
				break;
			}
			//Ayn� elemana denk gelen de�erler toplan�r ve toplam de�i�kenine atan�r.
			int toplam = Matris[satir - 1][satir - 1] + Matris[sutun - 1][sutun - 1];
			//De�i�im s�ras�nda kritik nokta kaybolmas�n� �nlemek i�in de�i�kene atan�r.
			int koruma = Matris[satir - 1][sutun - 1];

			//Sat�r ve sutunlar�n de��imini sa�layan d�ng� kurulur.
			for (int degisim = 0; degisim < matrisBoyutu; degisim++)
			{
				int gecici = 0;
				gecici = Matris[satir - 1][degisim];
				Matris[satir - 1][degisim] = Matris[degisim][sutun - 1];
				Matris[degisim][sutun - 1] = gecici;
			}
			//Korumaya al�nan de�er ilgli duruma g�re tekrar ilgili elemana atan�r.
			if(satir==1)
				Matris[sutun - 1][sutun - 1] = koruma;
			if(sutun==1)
				Matris[satir - 1][satir - 1] = koruma;
			//Toplam de�eri ilgili de�ere atan�r.
			Matris[satir - 1][sutun - 1] = toplam;
			break;
		}
		//�lgili sat�rdaki tekleri ba�a alan case.
		case 2:
		{
			int satir;
			cout << "Satir Girin :";
			cin >> satir;
			//Hatal� giri�te mesaj� ekrana ��karan ve caseden ��karan ko�ul.
			if (satir > matrisBoyutu || satir < 1)
			{
				cout << "Satir matris boyutundan buyuk olamaz" << endl;
				break;
			}
			//Sat�rda bulunan tek say�y�lar� �ift say�lar ile yer de�i�tiren d�ng� kurulur.
			for (int sayac = 0; sayac < matrisBoyutu; sayac++)
			{
				//E�er ilgili matris eleman� tek ise i�indeki d�ng�y� �al��t�ran ko�ul konur.
				if (Matris[satir - 1][sayac] % 2 != 0)
				{
					//Sat�rdaki elemanlar� gezen d�ng� kurulur.
					for (int sayac2 = 0; sayac2 < matrisBoyutu; sayac2++)
					{
						//E�er eleman �ift ise ilk d�ng�deki tek eleman ile ilgili eleman� de�i�tiren d�ng� kurulur ve i�teki d�ng�den bitmeden ��k�l�r.
						if (Matris[satir - 1][sayac2] % 2 == 0)
						{
							int gecici = Matris[satir - 1][sayac];
							Matris[satir - 1][sayac] = Matris[satir - 1][sayac2];
							Matris[satir - 1][sayac2] = gecici;
							break;
						}
					}
				}
			}
			break;
		}
		//�lgili s�tunu ters �eviren case.
		case 3:
		{
			int sutun;
			cout << "Sutun Girin :";
			cin >> sutun;
			////Hatal� giri�te mesaj� ekrana ��karan ve caseden ��kran ko�ul.
			if (sutun > matrisBoyutu || sutun < 1)
			{
				cout << "Sutun matris boyutundan buyuk olamaz" << endl;
				break;
			}
			int gecici[25];
			//S�tun elemanlar�n� ge�ici matrise atayan d�ng� kurulur
			for (int sayac = 0; sayac < matrisBoyutu; sayac++)
			{
				gecici[sayac] = Matris[sayac][sutun - 1];
			}
			int boyut = matrisBoyutu;
			//Ge�ici matrisindeki elemanlar� matrise tersten atayan d�ng� kurulur.
			for (int sayac = 0; sayac < matrisBoyutu; sayac++)
			{
				Matris[boyut - 1][sutun - 1] = gecici[sayac];
				boyut--;
			}
			break;
		}
		//Matriste eleman toplama i�lemini yapan case.
		case 4:
		{
			int toplam = 0;
			int temp = 0;
			//Matris elemanlar�n� tek tek gezerek toplayan ve sonra tekrar ilgili matris eleman�na atayan d�ng� kurulur.
			for (int sayac = matrisBoyutu; sayac > 0; sayac--) {
				for (int sayac2 = matrisBoyutu; sayac2 > 0; sayac2--) {
					temp = Matris[sayac - 1][sayac2 - 1];
					Matris[sayac - 1][sayac2 - 1] = toplam;
					toplam += temp;
				}
			}
			break;
		}
		}
		system("pause");
	} while (true);
}
void matrisiYaz(int boyut, int matris[25][25]) 
{
	cout << setw(8);
	//sutun numaralar�n� yazan ve aralar�na bo�luk b�rakan d�ng� kurulur.
	for (int sutun = 0; sutun < boyut; sutun++) 
	{
		cout << sutun + 1 << setw(6);
	}
	cout << endl;
	cout << setw(6);
	//Sutun numaralar�n�n alt�na �izgi �eken d�ng� kurulur.
	for (int sutun = 0; sutun < boyut * 6 ; sutun++) 
	{
		cout << "_";
	}
	cout << endl;
	//Sat�r numaralar�n� ve matris elemanlar�n� yazan d�ng� kurulur.
	for (int satir = 0; satir < boyut; satir++)
	{
		cout << (satir + 1);
		//Sat�r numras�n�n tek yada �ift haneli olamas�na g�re az yada �ok bo�luk koyan ko�ul konur.
		if (satir < 9)
			cout << setw(4);
		else
			cout << setw(3);

		cout << "|";
		cout << setw(3);
		//Matrisin d��taki d�ng�den gelen sat�r�n sutunlar�n� gezerek elemanlar�n� ekrana yazan d�ng� kurulur.
		for (int sutun = 0; sutun < boyut; sutun++)
		{
			cout << matris[satir][sutun];
			if (sutun != boyut - 1)
				cout << setw(6);
		}
		cout << endl << endl;
	}
}