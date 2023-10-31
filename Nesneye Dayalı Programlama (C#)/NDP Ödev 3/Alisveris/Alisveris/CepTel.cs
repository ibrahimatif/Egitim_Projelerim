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
    class CepTel : Urun
    {
        private string DahiliHafiza;
        private string RamKapasitesi;
        private string PilGucu;

        public CepTel(string _Ad, string _Marka, string _Model, string _Ozellik, string _DahiliHafıza, string _RamKapasitesi, string _PilGucu, int _HamFiyat) : base( _Ad,  _Marka,  _Model,  _Ozellik,  _HamFiyat)
        {
            DahiliHafiza = _DahiliHafıza;
            RamKapasitesi = _RamKapasitesi;
            PilGucu = _PilGucu;
        }
        public override double KdvliFiyatHesapla()
        {
            return hamFiyat * 1.20;
        }
    }
}
