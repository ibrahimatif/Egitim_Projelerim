/****************************************************************************
**
**                      ��RENC� ADI........:�BRAH�M ATIF KURU
**                      ��RENC� NUMARASI...:b191210005
**                      DERS GRUBU.........:1. ��retim C grubu
****************************************************************************/
#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
#include<windows.h>
#include<iomanip>
#include<sstream>

using namespace std;
//
void koordinataGit(int, int);
class Ogrenci
{
private:
	string isim;
	string soyisim;
	int no;
public:
	Ogrenci()
	{}
	static int numara;
	void isimAta(string Ad);
	void SoyisimAta(string Soyad);
	void numaraAta();
	void numaraBelirle(int _numara);
	void Numara(int _numara);
	string ogrenciIsimDondur();
	int ogrenciNumaraDondur();
	string ogrenciSoyisimDondur();
	~Ogrenci()
	{}
};
class DosyaYonetim
{
private:
public:
	DosyaYonetim()
	{}
	string rastgeleIsim();
	string rastgeleSoyisim();
	~DosyaYonetim()
	{}
};
class Sinif
{
private:
	string sinifIsmi;
	int sinifSayisi = 1;
	int *ptrsinif = &sinifSayisi;
	char Alfabe[25] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'W', 'V', 'X', 'Y', 'Z' };
	Ogrenci o1[100];
	int ogrenciSayisi = 0;
	int *ptrOgrSayi = &ogrenciSayisi;
	int atanacakOgrSayisi = 0;
public:
	Sinif()
	{}
	void ogrenciEkle(Ogrenci o);
	void manuelOgrEkle(string _isim, string _soyisim, string _numara);
	string sinifAdiOlustur(int sinifSayisi);
	void sinifAdiAta(string _isim);
	void ogrenciSayisiAta(int _ogrsayi);
	string SinifAdiDondur();
	int ogrenciSayisiDondur();
	string ogrIsimDondur(int i);
	string ogrSoyisimDondur(int i);
	string ogrNumaraDondur(int i);
	void ogrUstuneYaz(int j, Ogrenci o);
	Ogrenci ogrDondur(int istenen);
	~Sinif()
	{}
};
class Okul
{
private:
	char SolUK = 201;
	char Duz = 205;
	char SagUK = 187;
	char SolAK = 200;
	char sagAK = 188;
	char Dik = 186;
	Sinif s[100];
	int sinifSayisi = 0;
	int* ptrSinifSayisi = &sinifSayisi;
	int buyuk = 0;
	
	void ustY(int tane);
	void altY(int tane);
public:
	Okul()
	{
		ifstream okulOku;
		okulOku.open("kayitlar.txt");
		//kayitlar.txt dosyas�n�n a��k olup olmad��� kontrol ediliyor a��ksa i�lemler devam ediyor.
		if (okulOku.is_open())
		{
			int kontrol = 0;
			string temp;
			//Dosya sonuna gelinmediyse devam eden d�ng� kuruluyor.
			while (!okulOku.eof())
			{
				okulOku >> temp;
				// endl kullan�ld��� i�in yukar�daki kontrolden ge�iyor dolay�s�yla hatalar� �nlemek i�in ikinci bir kontrol koyuluyor.
				if (okulOku.eof())
				{
					break;
				}
				s[sinifSayisi].sinifAdiAta(temp);
				okulOku >> temp;
				s[sinifSayisi].ogrenciSayisiAta(stoi(temp));
				//S�n�ftaki ��renci say�s�n� yukar�dan �ekip o kadar d�nerek dosyadan okudu�u isimleri s�n�f dizisindeki o�renci s�n�f dizisine atayan d�ng�.
				for (int a = 0; a < stoi(temp); a++)
				{
					string geciciIsim, geciciSoyisim, geciciNumara;
					okulOku >> geciciIsim;
					okulOku >> geciciSoyisim;
					okulOku >> geciciNumara;
					s[sinifSayisi].manuelOgrEkle(geciciIsim, geciciSoyisim, geciciNumara);
					kontrol = stoi(geciciNumara);
				}
				(*ptrSinifSayisi)++;
			}
			okulOku.close();
			int gecici;
			//Dosyadaki t�m ��renci numaralar�n� gezrek en b�y�k olan� bulan ve bunu program�n ba��nda statik numara de�i�kenine atayan ve bu sayede ayn� numarada ��renci olu�mas�n� engelleyen d�ng�.
			//S�n�flar� gezer
			for (int i = 0; i < sinifSayisi; i++)
			{
				//S�n�flardaki ��rencileri gezer.
				for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
				{
					gecici = stoi(s[i].ogrNumaraDondur(j));
					if (gecici > buyuk)
						//E�er numara �nceki numaralardan b�y�kse b�y�k de��kenine atayan ko�ul.
						buyuk = gecici;
				}
			}
		}
		Ogrenci o;
		o.Numara((buyuk+1));
	}
	int numaraDondur();
	void yazdir();
	void kaydet();
	string sinifIsmiDondur(int i);
	void sinifaOgrEkle(int i, Ogrenci o);
	void sinifEkle();
	void ogrenciDegisitir(int aranan, Ogrenci o);
	void ogrenciSil(int aranan);
	void sinifSil(string a);
	~Okul()
	{}
};
class Program
{
public:
	Program()
	{}
	void calistir();
	~Program()
	{}
};
int Ogrenci::numara = 100 ;
int main()
{
	Program prog;
	prog.calistir();
} 
void koordinataGit(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Ogrenci::isimAta(string Ad)
{
	isim = Ad;
}
void Ogrenci::SoyisimAta(string Soyad)
{
	soyisim = Soyad;
}
void Ogrenci::numaraAta()
{
	no = numara;
	numara++;
}
void Ogrenci::numaraBelirle(int _numara)
{
	no = _numara;
}
void Ogrenci::Numara(int _numara)
{
	numara = _numara;
}
string Ogrenci::ogrenciIsimDondur()
{
	return isim;
}
int Ogrenci::ogrenciNumaraDondur()
{
	return no;
}
string Ogrenci:: ogrenciSoyisimDondur()
{
	return soyisim;
}
string DosyaYonetim::rastgeleIsim()
{
	ifstream isimOku;
	isimOku.open("isimler.txt");
	//Dosyan�n a��k olup olmad���n� kontrol eden ko�ul.
	if (isimOku.is_open())
	{
		int sayi;
		sayi = (rand() % 4945) + 1;
		//Dosya i�inden random kadar isimi �eken ve en son �ekti�i ismi d�nd�ren d�ng�.
		for (int i = 1; i <= sayi; i++)
		{
			string isim;
			isimOku >> isim;
			//Rastgele say�ya geldi�inde mevut ismi d�nd�ren ve indeksi tekrar 1 yapan ko�ul.
			if (i == sayi)
			{
				return isim;
				i = 1;
			}
		}
	}
	isimOku.close();
}
string DosyaYonetim::rastgeleSoyisim()
{
	ifstream soyisimOku;
	soyisimOku.open("soyisimler.txt");
	//Dosyan�n a��k olup olmad���n� kontrol eden ko�ul.
	if (soyisimOku.is_open())
	{
		int sayi;
		sayi = (rand() % 288) + 1;
		//Dosya i�inden random kadar soyisim �eken ve en son �ekti�i soyismi d�nd�ren d�ng�.
		for (int i = 1; i <= sayi; i++)
		{
			string soyisim;
			soyisimOku >> soyisim;
			//Rastgele say�ya geldi�inde mevut soyismi d�nd�ren ve indeksi tekrar 1 yapan ko�ul.
			if (i == sayi)
			{
				return soyisim;
				i = 1;
			}
		}
	}
	soyisimOku.close();
}
void Sinif::ogrenciEkle(Ogrenci o)
{
	o1[ogrenciSayisi].isimAta(o.ogrenciIsimDondur());
	o1[ogrenciSayisi].SoyisimAta(o.ogrenciSoyisimDondur());
	o1[ogrenciSayisi].numaraBelirle(o.ogrenciNumaraDondur());
	(*ptrOgrSayi)++;
}
void Sinif::manuelOgrEkle(string _isim, string _soyisim, string _numara)
{
	o1[atanacakOgrSayisi].isimAta(_isim);
	o1[atanacakOgrSayisi].SoyisimAta(_soyisim);
	o1[atanacakOgrSayisi].numaraBelirle(stoi(_numara));
	atanacakOgrSayisi++;
}
string Sinif::sinifAdiOlustur(int sinifSayisi)
{
	int temp = rand() % 25;
	string sayikismi;
	string harfkismi;
	sayikismi = to_string((sinifSayisi + 1));
	harfkismi = Alfabe[temp];
	sinifIsmi = sayikismi + harfkismi;
	return sinifIsmi;
	(*ptrsinif)++;
}
void Sinif::sinifAdiAta(string _isim)
{
	sinifIsmi = _isim;
}
void Sinif::ogrenciSayisiAta(int _ogrsayi)
{
	ogrenciSayisi = _ogrsayi;
}
string Sinif::SinifAdiDondur()
{
	return sinifIsmi;
}
int Sinif::ogrenciSayisiDondur()
{
	return ogrenciSayisi;
}
string Sinif::ogrIsimDondur(int i)
{
	return o1[i].ogrenciIsimDondur();
}
string Sinif::ogrSoyisimDondur(int i)
{
	return o1[i].ogrenciSoyisimDondur();
}
string Sinif::ogrNumaraDondur(int i)
{
	return to_string(o1[i].ogrenciNumaraDondur());
}
void Sinif::ogrUstuneYaz(int j, Ogrenci o)
{
	o1[j] = o;
}
Ogrenci Sinif::ogrDondur(int istenen)
{
	return o1[istenen];
}
void Okul::ustY(int tane)
{
	cout << SolUK;
	//Parametre olarak girilen de�er kadar �ste d�z �izgi bast�ran d�ng�.
	for (int i = 0; i < tane; i++)
	{
		cout << Duz;
	}
	cout << SagUK;
}
void Okul::altY(int tane)
{
	cout << SolAK;
	//Parametre olarak girilen de�er kadar alta d�z �izgi bast�ran d�ng�.
	for (int i = 0; i < tane; i++)
	{
		cout << Duz;
	}
	cout << sagAK;
}
int Okul::numaraDondur()
{
	return buyuk;
}
void Okul::yazdir()
{
	//16 birim geni�likteki s�n�f tablolar�n� indexe ba�l� olarak yan yana yazd�ran d�ng�.
	for (int i = 0; i < sinifSayisi; i++)
	{
		koordinataGit((i * 16) + 1, 0);
		ustY(14);
		koordinataGit((i * 16) + 1, 1);
		cout << Dik << setw(8) << s[i].SinifAdiDondur() << setw(7) << Dik;
		koordinataGit((i * 16) + 1, 2);
		altY(14);
		cout << endl;
	}
	//Siniflar� gezen d�ng�.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//Mevcut s�n�ftaki ��rencileri gezen ve ��rencilerin bilgilerini indekslere ba�l� olarak ilgili s�n�flar�n alt�na yazd�ran d�ng�.
		for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
		{
			koordinataGit((i * 16) + 3, 3 + (j * 5));
			ustY(10);
			koordinataGit((i * 16) + 3, 4 + (j * 5));
			cout << Dik << setw(10) << s[i].ogrIsimDondur(j) << Dik;
			koordinataGit((i * 16) + 3, 5 + (j * 5));
			cout << Dik << setw(10) << s[i].ogrSoyisimDondur(j) << Dik;
			koordinataGit((i * 16) + 3, 6 + (j * 5));
			cout << Dik << setw(10) << s[i].ogrNumaraDondur(j) << Dik;
			koordinataGit((i * 16) + 3, 7 + (j * 5));
			altY(10);
		}
	}
	koordinataGit(0, s[0].ogrenciSayisiDondur() * 5 + 4);
}
void Okul::kaydet()
{
	ofstream okulYaz;
	okulYaz.open("kayitlar.txt", ios::out);
	//Okul s�n�f�ndaki s�n�f dizilerini d�nen ve s�n�f ad�n� ve s�n�ftaki ��renci say�s�n� dosyaya d�ng�
	for (int i = 0; i < sinifSayisi; i++)
	{
		okulYaz << s[i].SinifAdiDondur() << endl;
		okulYaz << s[i].ogrenciSayisiDondur() << endl;
		//�lgili s�n�ftaki ��rencileri d�nen ve ��renci bilgilerini aralar�nda birar bo�luk b�rakarak alt alta dosyaya yazan d�ng�.
		for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
		{
			okulYaz << s[i].ogrIsimDondur(j) << " " << s[i].ogrSoyisimDondur(j) << " " << s[i].ogrNumaraDondur(j) << endl;
		}

	}
	okulYaz.close();
}
string Okul::sinifIsmiDondur(int i)
{
	return s[i].SinifAdiDondur();
}
void Okul::sinifaOgrEkle(int i, Ogrenci o)
{
	s[i].ogrenciEkle(o);
}
void Okul::sinifEkle()
{
	s[sinifSayisi].sinifAdiAta(s[sinifSayisi].sinifAdiOlustur(sinifSayisi));
	(*ptrSinifSayisi)++;
}
void Okul::ogrenciDegisitir(int aranan, Ogrenci o)
{
	//Okul s�n�f�ndaki sinif dizilerini gezen d�ng�.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//ilgili s�n�flardaki ��rencileri gezen d�ng�.
		for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
		{
			//Parametre olarak verilen numara s�radaki ogrencinin numaras�na e�itse s�n�f s�n�f�na ait fonksiyon ile parametre olarak gelen ��renci s�n�f�n� mevcut ��renci �zerine yazan ko�ul.
			if (aranan == stoi(s[i].ogrNumaraDondur(j)))
			{
				s[i].ogrUstuneYaz(j, o);
			}
		}
	}
}
void Okul::ogrenciSil(int aranan)
{
	//Okul s�n�f�ndaki sinif dizilerini gezen d�ng�.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//ilgili s�n�flardaki ��rencileri gezen d�ng�.
		for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
		{
			//Parametre olarak verilen numara s�radaki ��rencinin numaras�na e�itse devreye giren ko�ul.
			if (aranan == stoi(s[i].ogrNumaraDondur(j)))
			{
				//Mevcut ��renci �zerine bir sonraki ��renciyi yazan d�ng�.
				for (; j < (s[i].ogrenciSayisiDondur() - 1); j++)
				{
					s[i].ogrUstuneYaz(j, s[i].ogrDondur(j + 1));
				}
				s[i].ogrenciSayisiAta((s[i].ogrenciSayisiDondur() - 1));
				break;
			}
		}
	}
}
void Okul::sinifSil(string a)
{
	//Okul s�n�f�ndaki sinif dizilerini gezen d�ng�.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//E�er sinif adi parametre olarak girilen de�ere i�itse devreye giren ko�ul.
		if (a == s[i].SinifAdiDondur())
		{
			//Mevcut s�n�f �zerine bir sonraki s�n�f� yazan d�ng�.
			for (; i < sinifSayisi; i++)
			{
				s[i] = s[i + 1];
			}
			sinifSayisi--;
			break;
		}
	}
}
void Program::calistir()
{
	Ogrenci o;
	DosyaYonetim d;
	Sinif s;
	Okul ok;
	//Program�n 6 ya bas�lana kadar sonsuz kez d�nemsini sa�layan d�ng�.
	while (true)
	{
		system("cls");
		srand(time(0));

		ok.yazdir();

		int a;
		cout << "1.Ogrenci Ekle" << endl
			<< "2.Sinif Ekle" << endl
			<< "3.Ogrenci Degistir" << endl
			<< "4.Ogrenci Sil" << endl
			<< "5.Sinif sil" << endl
			<< "6.Cikis" << endl;
		cin >> a;
		string sinifAdi;
		int OgrenciNo;
		int kontrol = 0;
		//D��ar�dan girilen de�eri kontrol eden ve ilgili i�lemi yapan switch case ko�ulu.
		switch (a)
		{
		case 1:
			cout << "sinif adi:";
			cin >> sinifAdi;
			o.isimAta(d.rastgeleIsim());
			o.SoyisimAta(d.rastgeleSoyisim());
			o.numaraAta();
			cout << "Ogrenci Adi     :" << o.ogrenciIsimDondur() << endl
				<< "Ogrenci Soyadi  :" << o.ogrenciSoyisimDondur() << endl
				<< "Ogrenci Numarasi:" << o.ogrenciNumaraDondur() << endl;
			//ko�ula girene kadar d�nen sonsuz d�ng�.
			while (true)
			{
				//S�n�f adlar�n� tarayan ve d��ardan girilen de�ere e�it olunca ilgili o�renciyi ekleyip d�ng�y� k�ran ko�ul.
				if (sinifAdi == ok.sinifIsmiDondur(kontrol))
				{
					ok.sinifaOgrEkle(kontrol, o);
					break;
				}
				else
					kontrol++;
			}
			system("pause");
			break;
		case 2:
			ok.sinifEkle();
			break;
		case 3:
			cout << "Ogrenci No:";
			cin >> OgrenciNo;
			o.isimAta(d.rastgeleIsim());
			o.SoyisimAta(d.rastgeleSoyisim());
			o.numaraAta();
			cout << "Ogrenci Adi     :" << o.ogrenciIsimDondur() << endl
				<< "Ogrenci Soyadi  :" << o.ogrenciSoyisimDondur() << endl
				<< "Ogrenci Numarasi:" << o.ogrenciNumaraDondur() << endl;
			ok.ogrenciDegisitir(OgrenciNo, o);
			system("pause");
			break;
		case 4:
			cout << "Ogrenci No:";
			cin >> OgrenciNo;
			ok.ogrenciSil(OgrenciNo);
			break;
		case 5:
			cout << "Sinif Adi:";
			cin >> sinifAdi;
			ok.sinifSil(sinifAdi);
			break;
		case 6:
			ok.kaydet();
			break;
		}
		if (a == 6)
		{
			break;
		}
	}
}