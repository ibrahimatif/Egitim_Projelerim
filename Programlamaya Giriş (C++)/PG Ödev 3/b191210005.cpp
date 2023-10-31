/****************************************************************************
**
**                      ÖÐRENCÝ ADI........:ÝBRAHÝM ATIF KURU
**                      ÖÐRENCÝ NUMARASI...:b191210005
**                      DERS GRUBU.........:1. Öðretim C grubu
****************************************************************************/

/* Hocam ödev dökümanýnda L þekli için 2 ile 7 arasýnda bir boyut almalý denmiþ ayrýca boyut da dokümandaki fotoðrafta alt 
taban olarak tanýmlanmýþ. Çalýþtýrýlabilir programda ise alt taban 4 ile 14 arasýnda deðerler almýþ. Ben de ödev dökümanýný 
baz alarak ödevi yaptým. Yani L þeklinin alt tabaný 2 ile 7 arasýnda deðer alýyor. */

#include<iostream>
#include<ctime>
#include<Windows.h>

using namespace std;
//Kursörü girilen parametrelere atayan fonksiyon. 
void koordinataGit(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Sahne elemanlarýný tutan yapý.
struct Sahne
{
	int yukseklik;
	int genislik;
	char karakter;
};
//Sahne türünde bir deðiþken oluþturan, bu deðiþkenin elemanlarýna ilgili kurallara göre belirleyen ve bunu deðer olarak döndüren fonksiyon.
Sahne sahneOlustur()
{
	Sahne sahnem;
	sahnem.genislik = (rand() % 3 + 3) * 10;
	sahnem.yukseklik = (rand() % 11) + 20;
	int kar = rand() % 5;
	char karakter[5] = { '*','#','$','+','@' };
	sahnem.karakter = karakter[kar];
	return sahnem;
}
//Parametre olarak girilen Sahne türündeki deðiþkenin elemanlarýna göre sahneyi çizdiren fonksiyon.
void sahneCiz(Sahne sahnem)
{
	koordinataGit(1, 1);
	//Sahnenin üstünü çizdiren döngü.
	for (int i = 0; i < sahnem.genislik; i++) 
	{
		cout << sahnem.karakter;
	}
	//Sahnenin saðýný çizdiren döngü.
	for (int i = 0; i < sahnem.yukseklik - 1; i++)
	{
		koordinataGit(sahnem.genislik, i+1);
		cout << sahnem.karakter;
	}
	//Sahnenin altýný çizdiren döngü.
	for (int i = 0; i < sahnem.genislik; i++)
	{
		koordinataGit(sahnem.genislik - i, sahnem.yukseklik);
		cout << sahnem.karakter;
	}
	//Sahnenin solunu çizdiren döngü.
	for (int i = 0; i < sahnem.yukseklik - 1; i++)
	{
		koordinataGit(1, sahnem.yukseklik-i);
		cout << sahnem.karakter;
	}
}
//L þeklinin elemanlarýný tutan yapý.
struct LSekli
{
	int x;
	int y;
	int boyut;
	char karakter;
};
//LSekli türünde bir deðiþken oluþturan, bu deðiþkenin elemanlarýna ilgili kurallara göre belirleyen ve bunu deðer olarak döndüren fonksiyon.
LSekli lSekliOlustur()
{
	LSekli lseklim;
	lseklim.x = (rand() % 21) + 5;
	lseklim.y = 3;
	lseklim.boyut = (rand() % 6) + 2;
	int kar = rand() % 5;
	char karakter[5] = { '*','#','$','+','@' };
	lseklim.karakter = karakter[kar];
	return lseklim;
}
//Parametre olarak girilen deðer kadar boþluk býrakan fonksiyon.
void bosluk(int a)
{
	//Girilen deðer kadar boþluðu ekrana çýkaran döngü.
	for (int i = 0; i < a; i++)
	{
		cout << " ";
	}
}
//Parametre olarak girilen LSekli türündeki deðiþkenin elemanlarýna göre L þeklini çizdiren fonksiyon.
void lSekliCiz(LSekli lseklim)
{
	//Eðer þekil boyutu iki ise iþletilecek komutlarý tutan koþul.
	if (lseklim.boyut == 2)
	{
		koordinataGit(lseklim.x, lseklim.y);
		cout << lseklim.karakter;
		koordinataGit(lseklim.x, lseklim.y+1);
		cout << lseklim.karakter;
		cout << lseklim.karakter;
		koordinataGit(lseklim.x, lseklim.y + 2);
		cout << lseklim.karakter;
		cout << lseklim.karakter;
	}
	//Eðer þekil boyutu ikiden büyük ve çift ise iþletilecek komutlarý tutan koþul.
	else if (lseklim.boyut % 2 == 0 )
	{
		koordinataGit(lseklim.x, lseklim.y);
		//L þeklinin üst kýsmýný çizen döngü.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			cout << lseklim.karakter;
		}
		//L þeklinin üstteki ince kýsmýnýn saðýný ve solunu çizen döngü.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			koordinataGit(lseklim.x, (lseklim.y + 1) + i);
			cout << lseklim.karakter;
			bosluk((lseklim.boyut / 2) - 2);
			cout << lseklim.karakter;
		}
		//L þeklinin çýkýntýsýnýn üstünü çizen döngü.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			cout << lseklim.karakter;
		}
		//L þeklinin kalýn kýsmýnýn saðýný ve solunu çizen döngü.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			koordinataGit(lseklim.x, lseklim.y + (lseklim.boyut / 2) + 1 + i);
			cout << lseklim.karakter;
			bosluk(lseklim.boyut - 2);
			cout << lseklim.karakter;
		}
		koordinataGit(lseklim.x + 1, lseklim.y + (lseklim.boyut));
		//L þeklinin tabanýný çizen döngü.
		for (int i = 0; i < lseklim.boyut-2; i++)
		{
			cout << lseklim.karakter;
		}
	}
	//Diðer koþullarda(boyut tekse) uygulanacak komutlarý saklayan döngü.
	else
	{
		koordinataGit(lseklim.x, lseklim.y);
		//L þeklinin üst kýsmýný çizen döngü.
		for (int i = 0; i < (lseklim.boyut / 2) + 1; i++)
		{
			cout << lseklim.karakter;
		}
		//L þeklinin üstteki ince kýsmýnýn saðýný ve solunu çizen döngü.
		for (int i = 0; i < ((lseklim.boyut + 1) / 2); i++)
		{
			koordinataGit(lseklim.x, (lseklim.y + 1) + i);
			cout << lseklim.karakter;
			bosluk((lseklim.boyut / 2) - 1);
			cout << lseklim.karakter;
		}
		//L þeklinin çýkýntýsýnýn üstünü çizen döngü.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			cout << lseklim.karakter;
		}
		//L þeklinin kalýn kýsmýnýn saðýný ve solunu çizen döngü.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			koordinataGit(lseklim.x, lseklim.y + (lseklim.boyut / 2) + 2 + i);
			cout << lseklim.karakter;
			bosluk(lseklim.boyut - 2);
			cout << lseklim.karakter;
		}
		koordinataGit(lseklim.x , lseklim.y + (lseklim.boyut));
		//L þeklinin tabanýný çizen döngü.
		for (int i = 0; i < lseklim.boyut - 1; i++)
		{
			cout << lseklim.karakter;
		}
	}
}
//L þeklinin y koordinatýný 1 artýrarak bir birim aþaðýya taþýyan fonksiyon.
LSekli lSekliAsagýGotur(LSekli l) 
{
	l.y = l.y ++;
	return l;
}

int main() 
{
	//Her seferinde faklý random sonuçlar çýkmasýný saðlayan fonksiyon.
	srand(time(0));
	Sahne sahne = sahneOlustur();
	//Programý sonsuz kez döndüren döngü.
	while(true) 
	{
		//Ekraný temizleyen fonksiyon.
		system("cls");
		//Sahneyi ekrana çýkaran fonksiyon.
		sahneCiz(sahne);
		//L þeklini ilgili fonksiyon ile oluþturup sekil isimli deðiþkene atayan komut.
		LSekli sekil = lSekliOlustur();
		//L þeklini çizen fonksiyon.
		lSekliCiz(sekil);
		//L þeklini alt çizgiye kadar aþaðýya öteleyen döngü.
		while (sekil.y < sahne.yukseklik-sekil.boyut-1)
		{
			system("cls");
			sahneCiz(sahne);
			//L þeklinin y koordinatýný 1 arttýrýp tekrar sekil isimli deðiþkene atayan komut.
			sekil = lSekliAsagýGotur(sekil);
			lSekliCiz(sekil);
			Sleep(100);
		}
	}	
}