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
    class LedTv : Urun
    {
        private string EkranBoyutu;
        private string EkranCozunurlugu;

        public LedTv(string _Ad, string _Marka, string _Model, string _Ozellik, string _EkranBoyutu, string _EkranCozunurlugu, int _HamFiyat) : base(_Ad, _Marka, _Model, _Ozellik, _HamFiyat)
        {
            EkranBoyutu = _EkranBoyutu;
            EkranCozunurlugu = _EkranCozunurlugu;
        }
        public override double KdvliFiyatHesapla()
        {
            return hamFiyat * 1.18;
        }
    }
}
