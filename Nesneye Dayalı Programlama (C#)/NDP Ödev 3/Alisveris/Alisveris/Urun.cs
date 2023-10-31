/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2014-2015 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:3
**				ÖĞRENCİ ADI............:İbrahim Atıf KURU
**				ÖĞRENCİ NUMARASI.......:B191210005
**              DERSİN ALINDIĞI GRUP...:1.Ögretim C Grubu
****************************************************************************/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Alisveris
{
    class Urun
    {
        protected string Ad;
        protected string Marka;
        protected string Model;
        protected string Ozellik;
        protected int StokAdedi;
        protected int HamFiyat;
        protected int SecilenAdet;

        public string ad
        {
            get
            {
                return Ad;
            }
        }

        public int stokAdedi
        {
            get
            {
                return StokAdedi;
            }

            set
            {
                StokAdedi = value;
            }
        }

        public int hamFiyat
        {
            get
            {
                return HamFiyat;
            }
        }

        public int secilenAdet
        {
            get
            {
                return SecilenAdet;
            }

            set
            {
                SecilenAdet = value;
            }
        }

        protected Urun(string _Ad, string _Marka, string _Model, string _Ozellik, int _HamFiyat)
        {
            Ad = _Ad;
            Marka = _Marka;
            Model = _Model;
            Ozellik = _Ozellik;
            HamFiyat = _HamFiyat;
            Random rastgele1 = new Random();
            StokAdedi = rastgele1.Next(1, 100);
            //Tum urun stoklarının aynı olmaması için programı bir sure bekleten metot.
            System.Threading.Thread.Sleep(15);
        }
        public virtual double KdvliFiyatHesapla()
        {
            return hamFiyat;
        }
    }
}
