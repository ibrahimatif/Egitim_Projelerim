/****************************************************************************
**
**                      ��RENC� ADI........:�BRAH�M ATIF KURU
**                      ��RENC� NUMARASI...:b191210005
**                      DERS GRUBU.........:1. ��retim C grubu
****************************************************************************/

/* Hocam �dev d�k�man�nda L �ekli i�in 2 ile 7 aras�nda bir boyut almal� denmi� ayr�ca boyut da dok�mandaki foto�rafta alt 
taban olarak tan�mlanm��. �al��t�r�labilir programda ise alt taban 4 ile 14 aras�nda de�erler alm��. Ben de �dev d�k�man�n� 
baz alarak �devi yapt�m. Yani L �eklinin alt taban� 2 ile 7 aras�nda de�er al�yor. */

#include<iostream>
#include<ctime>
#include<Windows.h>

using namespace std;
//Kurs�r� girilen parametrelere atayan fonksiyon. 
void koordinataGit(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Sahne elemanlar�n� tutan yap�.
struct Sahne
{
	int yukseklik;
	int genislik;
	char karakter;
};
//Sahne t�r�nde bir de�i�ken olu�turan, bu de�i�kenin elemanlar�na ilgili kurallara g�re belirleyen ve bunu de�er olarak d�nd�ren fonksiyon.
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
//Parametre olarak girilen Sahne t�r�ndeki de�i�kenin elemanlar�na g�re sahneyi �izdiren fonksiyon.
void sahneCiz(Sahne sahnem)
{
	koordinataGit(1, 1);
	//Sahnenin �st�n� �izdiren d�ng�.
	for (int i = 0; i < sahnem.genislik; i++) 
	{
		cout << sahnem.karakter;
	}
	//Sahnenin sa��n� �izdiren d�ng�.
	for (int i = 0; i < sahnem.yukseklik - 1; i++)
	{
		koordinataGit(sahnem.genislik, i+1);
		cout << sahnem.karakter;
	}
	//Sahnenin alt�n� �izdiren d�ng�.
	for (int i = 0; i < sahnem.genislik; i++)
	{
		koordinataGit(sahnem.genislik - i, sahnem.yukseklik);
		cout << sahnem.karakter;
	}
	//Sahnenin solunu �izdiren d�ng�.
	for (int i = 0; i < sahnem.yukseklik - 1; i++)
	{
		koordinataGit(1, sahnem.yukseklik-i);
		cout << sahnem.karakter;
	}
}
//L �eklinin elemanlar�n� tutan yap�.
struct LSekli
{
	int x;
	int y;
	int boyut;
	char karakter;
};
//LSekli t�r�nde bir de�i�ken olu�turan, bu de�i�kenin elemanlar�na ilgili kurallara g�re belirleyen ve bunu de�er olarak d�nd�ren fonksiyon.
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
//Parametre olarak girilen de�er kadar bo�luk b�rakan fonksiyon.
void bosluk(int a)
{
	//Girilen de�er kadar bo�lu�u ekrana ��karan d�ng�.
	for (int i = 0; i < a; i++)
	{
		cout << " ";
	}
}
//Parametre olarak girilen LSekli t�r�ndeki de�i�kenin elemanlar�na g�re L �eklini �izdiren fonksiyon.
void lSekliCiz(LSekli lseklim)
{
	//E�er �ekil boyutu iki ise i�letilecek komutlar� tutan ko�ul.
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
	//E�er �ekil boyutu ikiden b�y�k ve �ift ise i�letilecek komutlar� tutan ko�ul.
	else if (lseklim.boyut % 2 == 0 )
	{
		koordinataGit(lseklim.x, lseklim.y);
		//L �eklinin �st k�sm�n� �izen d�ng�.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			cout << lseklim.karakter;
		}
		//L �eklinin �stteki ince k�sm�n�n sa��n� ve solunu �izen d�ng�.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			koordinataGit(lseklim.x, (lseklim.y + 1) + i);
			cout << lseklim.karakter;
			bosluk((lseklim.boyut / 2) - 2);
			cout << lseklim.karakter;
		}
		//L �eklinin ��k�nt�s�n�n �st�n� �izen d�ng�.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			cout << lseklim.karakter;
		}
		//L �eklinin kal�n k�sm�n�n sa��n� ve solunu �izen d�ng�.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			koordinataGit(lseklim.x, lseklim.y + (lseklim.boyut / 2) + 1 + i);
			cout << lseklim.karakter;
			bosluk(lseklim.boyut - 2);
			cout << lseklim.karakter;
		}
		koordinataGit(lseklim.x + 1, lseklim.y + (lseklim.boyut));
		//L �eklinin taban�n� �izen d�ng�.
		for (int i = 0; i < lseklim.boyut-2; i++)
		{
			cout << lseklim.karakter;
		}
	}
	//Di�er ko�ullarda(boyut tekse) uygulanacak komutlar� saklayan d�ng�.
	else
	{
		koordinataGit(lseklim.x, lseklim.y);
		//L �eklinin �st k�sm�n� �izen d�ng�.
		for (int i = 0; i < (lseklim.boyut / 2) + 1; i++)
		{
			cout << lseklim.karakter;
		}
		//L �eklinin �stteki ince k�sm�n�n sa��n� ve solunu �izen d�ng�.
		for (int i = 0; i < ((lseklim.boyut + 1) / 2); i++)
		{
			koordinataGit(lseklim.x, (lseklim.y + 1) + i);
			cout << lseklim.karakter;
			bosluk((lseklim.boyut / 2) - 1);
			cout << lseklim.karakter;
		}
		//L �eklinin ��k�nt�s�n�n �st�n� �izen d�ng�.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			cout << lseklim.karakter;
		}
		//L �eklinin kal�n k�sm�n�n sa��n� ve solunu �izen d�ng�.
		for (int i = 0; i < (lseklim.boyut / 2); i++)
		{
			koordinataGit(lseklim.x, lseklim.y + (lseklim.boyut / 2) + 2 + i);
			cout << lseklim.karakter;
			bosluk(lseklim.boyut - 2);
			cout << lseklim.karakter;
		}
		koordinataGit(lseklim.x , lseklim.y + (lseklim.boyut));
		//L �eklinin taban�n� �izen d�ng�.
		for (int i = 0; i < lseklim.boyut - 1; i++)
		{
			cout << lseklim.karakter;
		}
	}
}
//L �eklinin y koordinat�n� 1 art�rarak bir birim a�a��ya ta��yan fonksiyon.
LSekli lSekliAsag�Gotur(LSekli l) 
{
	l.y = l.y ++;
	return l;
}

int main() 
{
	//Her seferinde fakl� random sonu�lar ��kmas�n� sa�layan fonksiyon.
	srand(time(0));
	Sahne sahne = sahneOlustur();
	//Program� sonsuz kez d�nd�ren d�ng�.
	while(true) 
	{
		//Ekran� temizleyen fonksiyon.
		system("cls");
		//Sahneyi ekrana ��karan fonksiyon.
		sahneCiz(sahne);
		//L �eklini ilgili fonksiyon ile olu�turup sekil isimli de�i�kene atayan komut.
		LSekli sekil = lSekliOlustur();
		//L �eklini �izen fonksiyon.
		lSekliCiz(sekil);
		//L �eklini alt �izgiye kadar a�a��ya �teleyen d�ng�.
		while (sekil.y < sahne.yukseklik-sekil.boyut-1)
		{
			system("cls");
			sahneCiz(sahne);
			//L �eklinin y koordinat�n� 1 artt�r�p tekrar sekil isimli de�i�kene atayan komut.
			sekil = lSekliAsag�Gotur(sekil);
			lSekliCiz(sekil);
			Sleep(100);
		}
	}	
}