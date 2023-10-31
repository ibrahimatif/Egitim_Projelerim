/****************************************************************************
**
**                      ��RENC� ADI........:�BRAH�M ATIF KURU
**                      ��RENC� NUMARASI...:b191210005
**                      DERS GRUBU.........:1. ��retim C grubu
****************************************************************************/

#include<iostream>

#include<Windows.h>

using namespace std;
//Fonksiyon prototipleri giriliyor.
//Bo�luk i�in iomanip k�t�phanesi eklenerek setw de kullan�labilir.
void bosluk(int);
void yildiz(int);

int main() 
{

	int satir;
	int sutun;

	//Sat�r ve s�tun giri�lerinde d�ng�n�n en az bir kez i�lemesi i�in "do while" d�ng�s� kullan�l�r.
	//Sat�r ve s�tun girildikten sonra de�erlendirilmesi i�in en d��a "satir*2!=sutun" e�itsizli�ini kontrol eden d�ng� koyulur.
	do
	{

		//Sat�r say�s�n�n 5 ile 15 aras�nda olup olmad���n� kontrol eden d�ng� koyulur.
		do
		{
			cout << "satir girin....:";
			cin >> satir;
			cout << endl;
			//E�er sat�r say�s� 5'den k���k veya 15'den b�y�k ise ilgili mesaj ekrana ��kart�l�r.
			if (satir < 5 || satir>15)
				cout << endl << "Satir numarasi hatali.... Tekrar Deneyin...." << endl << endl;
		//D�ng� �art�n�n kontrol� yap�l�r. E�er sat�r say�s� 5 ile 15 aras�nda de�ilse d�ng� ba�a d�ner. 5 ile 15 aras�ndaysa bir sonraki sat�ra ge�er.
		} while (satir < 5 || satir>15);

		//S�tun say�s�n�n 5 ile 40 aras�nda olup olmad���n� kontrol eden d�ng� koyulur.
		
		do
		{
			cout << "sutun girin....:";
			cin >> sutun;
			cout << endl;
			//E�er s�tun say�s� 5'den k���k veya 40'dan b�y�k ise ilgili mesaj ekrana ��kart�l�r.
			if (sutun < 5 || sutun>40)
				cout << endl << "Sutun numarasi hatali.... Tekrar Deneyin...." << endl << endl;
		//D�ng� �art�n�n kontrol� yap�l�r. E�er sutun say�s� 5 ile 40 aras�nda de�ilse d�ng� ba�a d�ner. 5 ile 40 aras�ndaysa bir sonraki sat�ra ge�er.
		} while (sutun < 5 || sutun>40);
		
		//"sat�r*2!=sutun" e�itsizli�ini kontrol eden ko�ul konur. E�itsizlik sa�lan�yorsa yani sat�r*2 sutuna e�it de�ilse ilgili mesaj ekrana ��kart�l�r.
		if (satir * 2 != sutun)
			cout << endl << "sutun sayisi satir sayisinin iki kati olmalidir..... Tekrar Deneyin....." << endl << endl;
		//D�ng� �art�n�n kontrol� yap�l�r. "satir*2!=sutun" e�itsizli�ini kontrol eder. Sa�lan�yorsa ba�a d�ner. Sa�lanm�yorsa bir sonraki sat�ra ge�er.
	} while (satir * 2 != sutun);
	
	//ilk �eklin ilk sat�r� bas�l�r
	yildiz(sutun);
	cout << endl;
	//�stte olu�acak �ekli olu�turan d�ng� kurulur. ilk ve son sat�r d�ng� d���nda bas�ld���ndan sat�r - 2 kadar d�ner.
	//Her sat�r ba��nda bir y�ld�z bas�l�r. Daha sonra sutun say�s�ndan koyulacak y�ld�z say�s� yani 4 ��kar�l�r �ekil simetrik olaca�� i�in 2 ye b�l�n�r.
	//Bulunan de�er ikinci y�ld�z�n olmas� gereken sutunu verir. Bu y�zden 1 eksi�i kadar bo�luk konur. Bo�luk her d�nmede bir azalaca�� i�in i ��kar�l�r.
	//Y�ld�z bas�l�r. �ki y�ld�z aras� bo�lu�un ba�lang�� de�eri 2 dir. her d�nmede 2 artar. Bu da 2*i eklenerek sa�lan�r.
	//�ekil simetrik oldu�undan ikinci a�amadaki i�lemler tekrarlan�r ve son s�t�n bas�l�r.
	//endl ile bir sonraki sat�ra ge�ilir ve d�ng� i de�erine ba�l� olarak sat�r-2 kez d�ner.
	//�ekil olu�umunu izleyebilmek i�in d�ng� sonunda 100 ms geciktirme uygulan�r.
	
	for (int i = 0; i < (satir - 2); i++) 
	{
		cout << "*";
		
		bosluk(((sutun - 4) / 2 - 1)- i);
		cout << "*";
		
		bosluk(2 + 2 * i);
		cout << "*";
		
		bosluk(((sutun - 4) / 2 - 1) - i);
		cout << "*";
		
		cout << endl;
		Sleep(100);
	}
	//son sat�r bas�l�r.
	yildiz(sutun);
	//iki sat�r bo�luk b�rak�l�r.
	cout << endl << endl;
	//100 ms gecikme uygulan�r.
	Sleep(100);
	//�kinci �eklin ilk sat�r� bas�l�r.
	yildiz(sutun);
	//Sat�r atlan�r.
	cout << endl;
	//Altta olu�acak �ekli olu�turan d�ng� kurulur. ilk ve son sat�r d�ng� d���nda bas�ld���ndan sat�r - 2 kadar d�ner.
	//Her sat�r ba��nda bir y�ld�z bas�l�r. Daha sonra i de�eri kadar bo�luk b�rak�l�r ve ikinci y�ld�z bas�l�r.
	//Daha sonra ikinci ve ���nc� y�ld�zlar aras� bo�luk sutun say�s�ndan koyulacak y�ld�z say�s� yani 4 ��kar�larak bulunur. Bu de�er her ad�mda iki azalaca��ndan 2*i ��kar�l�r.
	//���nc� ve d�rd�nc� Y�ld�zlar aras� mesafe her ad�mda i kadar olur.
	//endl ile bir sonraki sat�ra ge�ilir ve d�ng� i de�erine ba�l� olarak sat�r-2 kez d�ner.
	//�ekil olu�umunu izleyebilmek i�in d�ng� sonunda 100 ms geciktirme uygulan�r.
	for (int i = 0; i < (satir - 2); i++)
	{

		cout << "*";

		bosluk(i);
		cout << "*";

		bosluk((sutun - 4) - 2 * i);
		cout << "*";

		bosluk(i);
		cout << "*";

		cout << endl;
		Sleep(100);
	}
	
	//Son sat�r bas�l�r
	yildiz(sutun);
	//B�r sat�r a�a�� ge�ilir.
	cout << endl;
	system("pause");
}

//Kodun okunabilirli�ini art�rmak i�in girilen de�er kadar bo�luk yapan fonksiyon tan�mlan�r( iomanip k�t�phanesi eklenerek setw de kullan�labilir).
void bosluk(int sayi) 
{
	//girilen de�er kadar bo�luk basan d�ng� kurulur.
	for (int i = 0; i < sayi; i++)
		cout << " " ;
}

//Kodun okunabilirli�ini art�rmak i�in girilen de�er kadar * basan fonksiyon tan�mlan�r.
void yildiz(int yildizSayisi) 
{
	//girilen de�er kadar * basan d�ng� kurulur.
	for (int i = 0; i < yildizSayisi; i++)
		cout << "*";
}