/****************************************************************************
**
**                      ÖÐRENCÝ ADI........:ÝBRAHÝM ATIF KURU
**                      ÖÐRENCÝ NUMARASI...:b191210005
**                      DERS GRUBU.........:1. Öðretim C grubu
****************************************************************************/
#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
//Matrisi yazan fonksiyonun prototipi tanýmlanýyor.
void matrisiYaz(int boyut, int matris[25][25]);

int main()
{
	int matrisBoyutu;
	//Matris boyutunun 5 ile 25 arasýnda olup olmadýðýný belirleyen döngü kuruluyor. 
	do
	{
		cout << "Matris boyutu girin:";
		cin >> matrisBoyutu;
		//Matris boyutu hatalý olursa ilgili mesajý ekrana çýkaran koþul konulur.
		if (matrisBoyutu < 5 || matrisBoyutu>25)
			cout << "Matris boyutu 25'den kucuk 5'den buyuk olmalidir" << endl << endl;
	} while (matrisBoyutu < 5 || matrisBoyutu>25);

	int Matris[25][25];
	srand(time(0));
	//Belirlenen boyuta göre matrise rand fonksiyonu ile 0 ile 9 arasýnda rastgele deðerler atanýyor.
	for (int satir = 0; satir < matrisBoyutu; satir++)
	{
		for (int sutun = 0; sutun < matrisBoyutu; sutun++)
		{
			Matris[satir][sutun] = (rand() % 10);
		}
	}
	//Caseler uygulandýktan sonra ödev dökümanýnda olduðu gibi tekrar matrisin yazýlmasýný ve menünün çýkmasýný saðlayan sonsuz döngü kurulur.
	do
	{
		//Matrisi yazan fonsiyon çaðýrýlýr.
		matrisiYaz(matrisBoyutu, Matris);

		int secenek;
		//Menüyü yazdýran ve seçimi saðlayan hatalý seçimde baþa dönen döngü kurulur.
		do {

			cout << "1.Sutun Satir Degistir" << endl
				<< "2.Tekleri Basa Al(Satir)" << endl
				<< "3.Ters Cevir(Sutun)" << endl
				<< "4.Toplamlari yazdir" << endl;
			cin >> secenek;
			//1,2,3 veya 4 dýþýnda bir deðer girildiðinde hata mesajýný ekrana çýkaran koþul yazýlýr.
			if (secenek < 1 || secenek>4)
				cout << "Hatali secim" << endl;
		} while (secenek < 1 || secenek>4);
		//Menuden seçilen iþleme göre kodu ilgili bölümden devam ettiren switch case yapýsý kurulur.
		switch (secenek)
		{
			//Satýr sütun deðiþtiren case.
		case 1:
		{
			int satir;
			int sutun;
			cout << "Satir Sutun Girin :";
			cin >> satir >> sutun;
			//Hatalý giriþte mesajý ekrana çýkaran ve caseden çýkaran koþul.
			if (satir > matrisBoyutu || sutun > matrisBoyutu || satir < 1 || sutun < 1)
			{
				cout << "Satir ve sutun matris boyutundan buyuk olamaz" << endl;
				break;
			}
			//Ayný elemana denk gelen deðerler toplanýr ve toplam deðiþkenine atanýr.
			int toplam = Matris[satir - 1][satir - 1] + Matris[sutun - 1][sutun - 1];
			//Deðiþim sýrasýnda kritik nokta kaybolmasýný önlemek için deðiþkene atanýr.
			int koruma = Matris[satir - 1][sutun - 1];

			//Satýr ve sutunlarýn deðþimini saðlayan döngü kurulur.
			for (int degisim = 0; degisim < matrisBoyutu; degisim++)
			{
				int gecici = 0;
				gecici = Matris[satir - 1][degisim];
				Matris[satir - 1][degisim] = Matris[degisim][sutun - 1];
				Matris[degisim][sutun - 1] = gecici;
			}
			//Korumaya alýnan deðer ilgli duruma göre tekrar ilgili elemana atanýr.
			if(satir==1)
				Matris[sutun - 1][sutun - 1] = koruma;
			if(sutun==1)
				Matris[satir - 1][satir - 1] = koruma;
			//Toplam deðeri ilgili deðere atanýr.
			Matris[satir - 1][sutun - 1] = toplam;
			break;
		}
		//Ýlgili satýrdaki tekleri baþa alan case.
		case 2:
		{
			int satir;
			cout << "Satir Girin :";
			cin >> satir;
			//Hatalý giriþte mesajý ekrana çýkaran ve caseden çýkaran koþul.
			if (satir > matrisBoyutu || satir < 1)
			{
				cout << "Satir matris boyutundan buyuk olamaz" << endl;
				break;
			}
			//Satýrda bulunan tek sayýyýlarý çift sayýlar ile yer deðiþtiren döngü kurulur.
			for (int sayac = 0; sayac < matrisBoyutu; sayac++)
			{
				//Eðer ilgili matris elemaný tek ise içindeki döngüyü çalýþtýran koþul konur.
				if (Matris[satir - 1][sayac] % 2 != 0)
				{
					//Satýrdaki elemanlarý gezen döngü kurulur.
					for (int sayac2 = 0; sayac2 < matrisBoyutu; sayac2++)
					{
						//Eðer eleman çift ise ilk döngüdeki tek eleman ile ilgili elemaný deðiþtiren döngü kurulur ve içteki döngüden bitmeden çýkýlýr.
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
		//Ýlgili sütunu ters çeviren case.
		case 3:
		{
			int sutun;
			cout << "Sutun Girin :";
			cin >> sutun;
			////Hatalý giriþte mesajý ekrana çýkaran ve caseden çýkran koþul.
			if (sutun > matrisBoyutu || sutun < 1)
			{
				cout << "Sutun matris boyutundan buyuk olamaz" << endl;
				break;
			}
			int gecici[25];
			//Sütun elemanlarýný geçici matrise atayan döngü kurulur
			for (int sayac = 0; sayac < matrisBoyutu; sayac++)
			{
				gecici[sayac] = Matris[sayac][sutun - 1];
			}
			int boyut = matrisBoyutu;
			//Geçici matrisindeki elemanlarý matrise tersten atayan döngü kurulur.
			for (int sayac = 0; sayac < matrisBoyutu; sayac++)
			{
				Matris[boyut - 1][sutun - 1] = gecici[sayac];
				boyut--;
			}
			break;
		}
		//Matriste eleman toplama iþlemini yapan case.
		case 4:
		{
			int toplam = 0;
			int temp = 0;
			//Matris elemanlarýný tek tek gezerek toplayan ve sonra tekrar ilgili matris elemanýna atayan döngü kurulur.
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
	//sutun numaralarýný yazan ve aralarýna boþluk býrakan döngü kurulur.
	for (int sutun = 0; sutun < boyut; sutun++) 
	{
		cout << sutun + 1 << setw(6);
	}
	cout << endl;
	cout << setw(6);
	//Sutun numaralarýnýn altýna çizgi çeken döngü kurulur.
	for (int sutun = 0; sutun < boyut * 6 ; sutun++) 
	{
		cout << "_";
	}
	cout << endl;
	//Satýr numaralarýný ve matris elemanlarýný yazan döngü kurulur.
	for (int satir = 0; satir < boyut; satir++)
	{
		cout << (satir + 1);
		//Satýr numrasýnýn tek yada çift haneli olamasýna göre az yada çok boþluk koyan koþul konur.
		if (satir < 9)
			cout << setw(4);
		else
			cout << setw(3);

		cout << "|";
		cout << setw(3);
		//Matrisin dýþtaki döngüden gelen satýrýn sutunlarýný gezerek elemanlarýný ekrana yazan döngü kurulur.
		for (int sutun = 0; sutun < boyut; sutun++)
		{
			cout << matris[satir][sutun];
			if (sutun != boyut - 1)
				cout << setw(6);
		}
		cout << endl << endl;
	}
}