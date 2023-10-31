/****************************************************************************
**
**                      ÖÐRENCÝ ADI........:ÝBRAHÝM ATIF KURU
**                      ÖÐRENCÝ NUMARASI...:b191210005
**                      DERS GRUBU.........:1. Öðretim C grubu
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
		//kayitlar.txt dosyasýnýn açýk olup olmadýðý kontrol ediliyor açýksa iþlemler devam ediyor.
		if (okulOku.is_open())
		{
			int kontrol = 0;
			string temp;
			//Dosya sonuna gelinmediyse devam eden döngü kuruluyor.
			while (!okulOku.eof())
			{
				okulOku >> temp;
				// endl kullanýldýðý için yukarýdaki kontrolden geçiyor dolayýsýyla hatalarý önlemek için ikinci bir kontrol koyuluyor.
				if (okulOku.eof())
				{
					break;
				}
				s[sinifSayisi].sinifAdiAta(temp);
				okulOku >> temp;
				s[sinifSayisi].ogrenciSayisiAta(stoi(temp));
				//Sýnýftaki öðrenci sayýsýný yukarýdan çekip o kadar dönerek dosyadan okuduðu isimleri sýnýf dizisindeki oðrenci sýnýf dizisine atayan döngü.
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
			//Dosyadaki tüm öðrenci numaralarýný gezrek en büyük olaný bulan ve bunu programýn baþýnda statik numara deðiþkenine atayan ve bu sayede ayný numarada öðrenci oluþmasýný engelleyen döngü.
			//Sýnýflarý gezer
			for (int i = 0; i < sinifSayisi; i++)
			{
				//Sýnýflardaki üðrencileri gezer.
				for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
				{
					gecici = stoi(s[i].ogrNumaraDondur(j));
					if (gecici > buyuk)
						//Eðer numara önceki numaralardan büyükse büyük deðþkenine atayan koþul.
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
	//Dosyanýn açýk olup olmadýðýný kontrol eden koþul.
	if (isimOku.is_open())
	{
		int sayi;
		sayi = (rand() % 4945) + 1;
		//Dosya içinden random kadar isimi çeken ve en son çektiði ismi döndüren döngü.
		for (int i = 1; i <= sayi; i++)
		{
			string isim;
			isimOku >> isim;
			//Rastgele sayýya geldiðinde mevut ismi döndüren ve indeksi tekrar 1 yapan koþul.
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
	//Dosyanýn açýk olup olmadýðýný kontrol eden koþul.
	if (soyisimOku.is_open())
	{
		int sayi;
		sayi = (rand() % 288) + 1;
		//Dosya içinden random kadar soyisim çeken ve en son çektiði soyismi döndüren döngü.
		for (int i = 1; i <= sayi; i++)
		{
			string soyisim;
			soyisimOku >> soyisim;
			//Rastgele sayýya geldiðinde mevut soyismi döndüren ve indeksi tekrar 1 yapan koþul.
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
	//Parametre olarak girilen deðer kadar üste düz çizgi bastýran döngü.
	for (int i = 0; i < tane; i++)
	{
		cout << Duz;
	}
	cout << SagUK;
}
void Okul::altY(int tane)
{
	cout << SolAK;
	//Parametre olarak girilen deðer kadar alta düz çizgi bastýran döngü.
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
	//16 birim geniþlikteki sýnýf tablolarýný indexe baðlý olarak yan yana yazdýran döngü.
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
	//Siniflarý gezen döngü.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//Mevcut sýnýftaki öðrencileri gezen ve öðrencilerin bilgilerini indekslere baðlý olarak ilgili sýnýflarýn altýna yazdýran döngü.
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
	//Okul sýnýfýndaki sýnýf dizilerini dönen ve sýnýf adýný ve sýnýftaki öðrenci sayýsýný dosyaya döngü
	for (int i = 0; i < sinifSayisi; i++)
	{
		okulYaz << s[i].SinifAdiDondur() << endl;
		okulYaz << s[i].ogrenciSayisiDondur() << endl;
		//Ýlgili sýnýftaki öðrencileri dönen ve öðrenci bilgilerini aralarýnda birar boþluk býrakarak alt alta dosyaya yazan döngü.
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
	//Okul sýnýfýndaki sinif dizilerini gezen döngü.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//ilgili sýnýflardaki öðrencileri gezen döngü.
		for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
		{
			//Parametre olarak verilen numara sýradaki ogrencinin numarasýna eþitse sýnýf sýnýfýna ait fonksiyon ile parametre olarak gelen öðrenci sýnýfýný mevcut öðrenci üzerine yazan koþul.
			if (aranan == stoi(s[i].ogrNumaraDondur(j)))
			{
				s[i].ogrUstuneYaz(j, o);
			}
		}
	}
}
void Okul::ogrenciSil(int aranan)
{
	//Okul sýnýfýndaki sinif dizilerini gezen döngü.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//ilgili sýnýflardaki öðrencileri gezen döngü.
		for (int j = 0; j < s[i].ogrenciSayisiDondur(); j++)
		{
			//Parametre olarak verilen numara sýradaki öðrencinin numarasýna eþitse devreye giren koþul.
			if (aranan == stoi(s[i].ogrNumaraDondur(j)))
			{
				//Mevcut öðrenci üzerine bir sonraki öðrenciyi yazan döngü.
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
	//Okul sýnýfýndaki sinif dizilerini gezen döngü.
	for (int i = 0; i < sinifSayisi; i++)
	{
		//Eðer sinif adi parametre olarak girilen deðere iþitse devreye giren koþul.
		if (a == s[i].SinifAdiDondur())
		{
			//Mevcut sýnýf üzerine bir sonraki sýnýfý yazan döngü.
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
	//Programýn 6 ya basýlana kadar sonsuz kez dönemsini saðlayan döngü.
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
		//Dýþarýdan girilen deðeri kontrol eden ve ilgili iþlemi yapan switch case koþulu.
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
			//koþula girene kadar dönen sonsuz döngü.
			while (true)
			{
				//Sýnýf adlarýný tarayan ve dýþardan girilen deðere eþit olunca ilgili oðrenciyi ekleyip döngüyü kýran koþul.
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