/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:1
**				ÖĞRENCİ ADI............:İbrahim Atıf KURU
**				ÖĞRENCİ NUMARASI.......:b191210005
**              DERSİN ALINDIĞI GRUP...:1.Ögretim C Grubu
****************************************************************************/


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Collections;

namespace OdevNDP
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList veriler = new ArrayList();
            dosyadanOku(veriler);
            string[] hesaplanmisVeri = hesapla(veriler);
            Console.WriteLine(string.Format("{0,-15} | {1,-15} | {2,-15} | {3,-6} | {4,-10}", "ISIM", "SOYISIM", "NUMARA", "ORTALAMA", "HARF NOTU"));
            Console.WriteLine("__________________________________________________________________________");
            //Hesaplama sonrası olusan veri dizisinin ogrencilerle ilgili bolumunu ekrana yazdırıyoruz
            for (int i = 0; i < (hesaplanmisVeri.Length-18); i=i+5)
            {
                Console.WriteLine(string.Format("{0,-15} | {1,-15} | {2,-15} | {3,-8} | {4,-10}", hesaplanmisVeri[i], hesaplanmisVeri[i + 1], hesaplanmisVeri[i + 2], hesaplanmisVeri[i + 3], hesaplanmisVeri[i + 4]));
            }
            //Hesaplama sonrası olusan veri dizisinin istatistikle ilgili bolumunu ekrana yazdırıyoruz
            for (int i = (hesaplanmisVeri.Length - 18); i < hesaplanmisVeri.Length; i = i + 2)
            {
                Console.WriteLine(string.Format("{0,-5} | {1,-5}", hesaplanmisVeri[i], hesaplanmisVeri[i + 1]));
            }
            dosyayaYaz(hesaplanmisVeri);
            Console.WriteLine("Programi kapatmak icin ENTER tusuna basin...");
            Console.ReadLine();
        }
        static void dosyadanOku(ArrayList _veriler)
        {
            string[] satirVeri = File.ReadAllLines("kaynak.txt");
            //Dosyadan okunan verileri satırlara ayıran döngü
            for(int i = 0; i<satirVeri.Length; i++)
            {
                string[] temp = satirVeri[i].Split(' ');
                //Boşluklara gore birimlerine ayrilarak diziye atanan satirlari _veriler dizisine atayan dongu
                for (int j = 0; j < temp.Length; j++)
                    _veriler.Add(temp[j]);
            }
        }
        static string[] hesapla(ArrayList _veriler)
        {
            double odev1Etki = double.Parse(_veriler[0].ToString()) / 100;
            double odev2Etki = double.Parse(_veriler[1].ToString()) / 100;
            double vizeEtki = double.Parse(_veriler[2].ToString()) / 100;
            double finalEtki = double.Parse(_veriler[3].ToString()) / 100;

            string[] cikti = new string[(((_veriler.Count-4)/7)*5)+18];
            int ciktiSayaci = 0;
            double AA = 0;
            double BA = 0;
            double BB = 0;
            double CB = 0;
            double CC = 0;
            double DC = 0;
            double DD = 0;
            double FD = 0;
            double FF = 0;
            //Disardan gelen _veriler dizisindeki notlarla ilgili islemleri yaparak yeni diziye ortalamayi ve harf notlarini atayan dongu
            for (int i = 4; i < _veriler.Count ; i=i+7)
            {
                double ort;
                cikti[ciktiSayaci] = _veriler[i].ToString();
                cikti[ciktiSayaci + 1] = _veriler[i+1].ToString();
                cikti[ciktiSayaci + 2] = _veriler[i+2].ToString();
                ort = (double.Parse(_veriler[i + 3].ToString())*odev1Etki) + (double.Parse(_veriler[i + 4].ToString()) * odev2Etki) + (double.Parse(_veriler[i + 5].ToString()) * vizeEtki) + (double.Parse(_veriler[i + 6].ToString()) * finalEtki);
                cikti[ciktiSayaci + 3] = ort.ToString();
                //Harf notlarini ilgili dizi elemanlarina ilgili kosullara gore atayan ifade blogu
                if(ort > 89.99)
                {
                    AA++;
                    cikti[ciktiSayaci + 4] = "AA";
                }
                else if(ort > 84.99)
                {
                    BA++;
                    cikti[ciktiSayaci + 4] = "BA";
                }
                else if (ort > 79.99)
                {
                    BB++;
                    cikti[ciktiSayaci + 4] = "BB";
                }
                else if (ort > 74.99)
                {
                    CB++;
                    cikti[ciktiSayaci + 4] = "CB";
                }
                else if (ort > 64.99)
                {
                    CC++;
                    cikti[ciktiSayaci + 4] = "CC";
                }
                else if (ort > 57.99)
                {
                    DC++;
                    cikti[ciktiSayaci + 4] = "DC";
                }
                else if (ort > 49.99)
                {
                    DD++;
                    cikti[ciktiSayaci + 4] = "DD";
                }
                else if (ort > 39.99)
                {
                    FD++;
                    cikti[ciktiSayaci + 4] = "FD";
                }
                else
                {
                    FF++;
                    cikti[ciktiSayaci + 4] = "FF";
                }
                ciktiSayaci += 5;
            }
            double ogrSayi = (_veriler.Count - 4) / 7;

                double temp;
                temp = (AA / ogrSayi)*100;
                cikti[cikti.Length-18] = "AA:  " + AA.ToString() + " kisi";
                cikti[cikti.Length - 17] = "%" + temp.ToString();
                temp = (BA / ogrSayi)*100;
                cikti[cikti.Length - 16] = "BA:  " + BA.ToString() + " kisi";
                cikti[cikti.Length - 15] = "%" + temp.ToString();
                temp = (BB / ogrSayi)*100;
                cikti[cikti.Length - 14] = "BB:  " + BB.ToString() + " kisi";
                cikti[cikti.Length - 13] = "%" + temp.ToString();
                temp = (CB / ogrSayi) * 100;
                cikti[cikti.Length - 12] = "CB:  " + CB.ToString() + " kisi";
                cikti[cikti.Length - 11] = "%" + temp.ToString();
                temp = (CC / ogrSayi)*100;
                cikti[cikti.Length - 10] = "CC:  " + CC.ToString() + " kisi";
                cikti[cikti.Length - 9] = "%" + temp.ToString();
                temp = (DC / ogrSayi)*100;
                cikti[cikti.Length - 8] = "DC:  " + DC.ToString() + " kisi";
                cikti[cikti.Length - 7] = "%" + temp.ToString();
                temp = (DD / ogrSayi)*100;
                cikti[cikti.Length - 6] = "DD:  " + DD.ToString() + " kisi";
                cikti[cikti.Length - 5] = "%" + temp.ToString();
                temp = (FD / ogrSayi)*100;
                cikti[cikti.Length - 4] = "FD:  " + FD.ToString() + " kisi";
                cikti[cikti.Length - 3] = "%" + temp.ToString();
                temp = (FF / ogrSayi)*100;
                cikti[cikti.Length - 2] = "FF:  " + FF.ToString() +" kisi";
            cikti[cikti.Length - 1] = "%" + temp.ToString();
            return cikti;
        }
        static void dosyayaYaz(string[] _yazilacakVeri)
        {
            FileStream fs = new FileStream("Notlar.txt", FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine(string.Format("{0,-15} | {1,-15} | {2,-15} | {3,-6} | {4,-10}", "ISIM", "SOYISIM", "NUMARA", "ORTALAMA", "HARF NOTU"));
            sw.WriteLine("__________________________________________________________________________");
            //Hesaplama sonrası olusan veri dizisinin ogrencilerle ilgili bolumunu Notlar.txt ye yazdırıyoruz
            for (int i = 0; i < (_yazilacakVeri.Length - 18); i = i + 5)
            {
                sw.WriteLine(string.Format("{0,-15} | {1,-15} | {2,-15} | {3,-5} | {4,-5}", _yazilacakVeri[i], _yazilacakVeri[i + 1], _yazilacakVeri[i + 2], _yazilacakVeri[i + 3], _yazilacakVeri[i + 4]));
            }
            //Hesaplama sonrası olusan veri dizisinin istatistikle ilgili bolumunu Notlar.txt ye yazdırıyoruz
            for (int i = (_yazilacakVeri.Length - 18); i < _yazilacakVeri.Length; i = i + 2)
            {
                sw.WriteLine(string.Format("{0,-5} | {1,-5}", _yazilacakVeri[i], _yazilacakVeri[i + 1]));
            }
            sw.Flush();
            sw.Close();
            fs.Close();
            Console.WriteLine("Veriler Notlar.txt dosyasina yazildi...");
        }
    }
}
