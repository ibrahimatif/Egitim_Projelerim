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
    class Laptop : Urun
    {
        private string EkranBoyutu;
        private string EkranCozunurlugu;
        private string DahiliHafiza;
        private string RamKapasitesi;
        private string PilGucu;

        public Laptop (string _Ad, string _Marka, string _Model, string _Ozellik, string _EkranBoyutu, string _EkranCozunurlugu, string _DahiliHafıza, string _RamKapasitesi, string _PilGucu, int _HamFiyat) : base(_Ad,_Marka,_Model,_Ozellik,_HamFiyat)
        {
            EkranBoyutu = _EkranBoyutu;
            EkranCozunurlugu = _EkranCozunurlugu;
            DahiliHafiza = _DahiliHafıza;
            RamKapasitesi = _RamKapasitesi;
            PilGucu = _PilGucu;
        }
        public override double KdvliFiyatHesapla()
        {
            return hamFiyat * 1.15;
        }
    }
}
