/****************************************************************************
**
**                      ÖÐRENCÝ ADI........:ÝBRAHÝM ATIF KURU
**                      ÖÐRENCÝ NUMARASI...:b191210005
**                      DERS GRUBU.........:1. Öðretim C grubu
****************************************************************************/

#include<iostream>

#include<Windows.h>

using namespace std;
//Fonksiyon prototipleri giriliyor.
//Boþluk için iomanip kütüphanesi eklenerek setw de kullanýlabilir.
void bosluk(int);
void yildiz(int);

int main() 
{

	int satir;
	int sutun;

	//Satýr ve sütun giriþlerinde döngünün en az bir kez iþlemesi için "do while" döngüsü kullanýlýr.
	//Satýr ve sütun girildikten sonra deðerlendirilmesi için en dýþa "satir*2!=sutun" eþitsizliðini kontrol eden döngü koyulur.
	do
	{

		//Satýr sayýsýnýn 5 ile 15 arasýnda olup olmadýðýný kontrol eden döngü koyulur.
		do
		{
			cout << "satir girin....:";
			cin >> satir;
			cout << endl;
			//Eðer satýr sayýsý 5'den küçük veya 15'den büyük ise ilgili mesaj ekrana çýkartýlýr.
			if (satir < 5 || satir>15)
				cout << endl << "Satir numarasi hatali.... Tekrar Deneyin...." << endl << endl;
		//Döngü þartýnýn kontrolü yapýlýr. Eðer satýr sayýsý 5 ile 15 arasýnda deðilse döngü baþa döner. 5 ile 15 arasýndaysa bir sonraki satýra geçer.
		} while (satir < 5 || satir>15);

		//Sütun sayýsýnýn 5 ile 40 arasýnda olup olmadýðýný kontrol eden döngü koyulur.
		
		do
		{
			cout << "sutun girin....:";
			cin >> sutun;
			cout << endl;
			//Eðer sütun sayýsý 5'den küçük veya 40'dan büyük ise ilgili mesaj ekrana çýkartýlýr.
			if (sutun < 5 || sutun>40)
				cout << endl << "Sutun numarasi hatali.... Tekrar Deneyin...." << endl << endl;
		//Döngü þartýnýn kontrolü yapýlýr. Eðer sutun sayýsý 5 ile 40 arasýnda deðilse döngü baþa döner. 5 ile 40 arasýndaysa bir sonraki satýra geçer.
		} while (sutun < 5 || sutun>40);
		
		//"satýr*2!=sutun" eþitsizliðini kontrol eden koþul konur. Eþitsizlik saðlanýyorsa yani satýr*2 sutuna eþit deðilse ilgili mesaj ekrana çýkartýlýr.
		if (satir * 2 != sutun)
			cout << endl << "sutun sayisi satir sayisinin iki kati olmalidir..... Tekrar Deneyin....." << endl << endl;
		//Döngü þartýnýn kontrolü yapýlýr. "satir*2!=sutun" eþitsizliðini kontrol eder. Saðlanýyorsa baþa döner. Saðlanmýyorsa bir sonraki satýra geçer.
	} while (satir * 2 != sutun);
	
	//ilk þeklin ilk satýrý basýlýr
	yildiz(sutun);
	cout << endl;
	//Üstte oluþacak þekli oluþturan döngü kurulur. ilk ve son satýr döngü dýþýnda basýldýðýndan satýr - 2 kadar döner.
	//Her satýr baþýnda bir yýldýz basýlýr. Daha sonra sutun sayýsýndan koyulacak yýldýz sayýsý yani 4 çýkarýlýr þekil simetrik olacaðý için 2 ye bölünür.
	//Bulunan deðer ikinci yýldýzýn olmasý gereken sutunu verir. Bu yüzden 1 eksiði kadar boþluk konur. Boþluk her dönmede bir azalacaðý için i çýkarýlýr.
	//Yýldýz basýlýr. Ýki yýldýz arasý boþluðun baþlangýç deðeri 2 dir. her dönmede 2 artar. Bu da 2*i eklenerek saðlanýr.
	//Þekil simetrik olduðundan ikinci aþamadaki iþlemler tekrarlanýr ve son sütün basýlýr.
	//endl ile bir sonraki satýra geçilir ve döngü i deðerine baðlý olarak satýr-2 kez döner.
	//Þekil oluþumunu izleyebilmek için döngü sonunda 100 ms geciktirme uygulanýr.
	
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
	//son satýr basýlýr.
	yildiz(sutun);
	//iki satýr boþluk býrakýlýr.
	cout << endl << endl;
	//100 ms gecikme uygulanýr.
	Sleep(100);
	//Ýkinci þeklin ilk satýrý basýlýr.
	yildiz(sutun);
	//Satýr atlanýr.
	cout << endl;
	//Altta oluþacak þekli oluþturan döngü kurulur. ilk ve son satýr döngü dýþýnda basýldýðýndan satýr - 2 kadar döner.
	//Her satýr baþýnda bir yýldýz basýlýr. Daha sonra i deðeri kadar boþluk býrakýlýr ve ikinci yýldýz basýlýr.
	//Daha sonra ikinci ve üçüncü yýldýzlar arasý boþluk sutun sayýsýndan koyulacak yýldýz sayýsý yani 4 çýkarýlarak bulunur. Bu deðer her adýmda iki azalacaðýndan 2*i çýkarýlýr.
	//Üçüncü ve dördüncü Yýldýzlar arasý mesafe her adýmda i kadar olur.
	//endl ile bir sonraki satýra geçilir ve döngü i deðerine baðlý olarak satýr-2 kez döner.
	//Þekil oluþumunu izleyebilmek için döngü sonunda 100 ms geciktirme uygulanýr.
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
	
	//Son satýr basýlýr
	yildiz(sutun);
	//Býr satýr aþaðý geçilir.
	cout << endl;
	system("pause");
}

//Kodun okunabilirliðini artýrmak için girilen deðer kadar boþluk yapan fonksiyon tanýmlanýr( iomanip kütüphanesi eklenerek setw de kullanýlabilir).
void bosluk(int sayi) 
{
	//girilen deðer kadar boþluk basan döngü kurulur.
	for (int i = 0; i < sayi; i++)
		cout << " " ;
}

//Kodun okunabilirliðini artýrmak için girilen deðer kadar * basan fonksiyon tanýmlanýr.
void yildiz(int yildizSayisi) 
{
	//girilen deðer kadar * basan döngü kurulur.
	for (int i = 0; i < yildizSayisi; i++)
		cout << "*";
}