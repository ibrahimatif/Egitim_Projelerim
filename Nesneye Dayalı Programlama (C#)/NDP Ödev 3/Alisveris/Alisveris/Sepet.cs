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
    class Sepet
    {
        private Form1 form;
        private string cesit;
        private double kdvliTop;

        //Sepete urun ekleyen metot. "Params" ile programa daha sonra urun eklenmek kolaylastirildi.
        public void SepeteUrunEkle(params Urun[] urun)
        {
            //Sepet doluysa sepeti temizle metodunu calistiran kosul ifadesi.
            if (form.SipOUrun.Items.Count != 0)
            {
                SepetiTemizle();
            }
            kdvliTop = 0;

            //eklenen urun cesidi kadar donen dongu.
            for (int i = 0; i < urun.Length; i++)
            {
                //urun cesidinden hic eklenmemis ise yani secilen adet 0 ise onun adının listeye eklenmemesini saglayan kosul ifadesi. 
                if (urun[i].secilenAdet != 0)
                {
                    
                    form.SipOAdet.Items.Add(urun[i].secilenAdet);
                    form.SipOUrun.Items.Add(urun[i].ad);
                    form.SipOFiyat.Items.Add(Math.Round((urun[i].KdvliFiyatHesapla()*urun[i].secilenAdet),2).ToString("N2"));
                    urun[i].stokAdedi = urun[i].stokAdedi - urun[i].secilenAdet;
                    kdvliTop += (urun[i].KdvliFiyatHesapla() * urun[i].secilenAdet);
                }
            }
            //Toplam fiyat 1 kurusun altinda oldugunda KDV'li fiyat label'ina 0 TL yazan kosul.
            if (kdvliTop < 0.01)
            {
                form.SipOKDVliTop.Text = "0 TL";
            }
            //KDV'li toplam 1 kurusun ustunde ise virgulden sonra iki basamak olacak sekilde yazan kosul.
            else
                form.SipOKDVliTop.Text = kdvliTop.ToString("N2") +" TL";
            form.formuGuncelle();
        }

        public void SepetiTemizle()
        {
            //Urun adlari kadar donen dongu.
            for (int i = 0; i < form.SipOUrun.Items.Count; i++)
            {
                cesit = form.SipOUrun.Items[i].ToString();
                //Urun adina gore ilgili labellara stoklari yeniden yazan kosul yapisi.
                switch (cesit)
                {
                    case "Buzdolabi":
                        form.BuzdolabiStok.Text = (int.Parse(form.BuzdolabiStok.Text) + int.Parse(form.SipOAdet.Items[i].ToString())).ToString();
                        break;
                    case "Laptop":
                        form.LaptopStok.Text = (int.Parse(form.LaptopStok.Text) + int.Parse(form.SipOAdet.Items[i].ToString())).ToString();
                        break;
                    case "Televizyon":
                        form.TVStok.Text = (int.Parse(form.TVStok.Text) + int.Parse(form.SipOAdet.Items[i].ToString())).ToString();
                        break;
                    case "Cep Telefonu":
                        form.CepTelStok.Text = (int.Parse(form.CepTelStok.Text) + int.Parse(form.SipOAdet.Items[i].ToString())).ToString();
                        break;
                }
            }
            form.stokGuncelle();
            form.SipOAdet.Items.Clear();
            form.SipOUrun.Items.Clear();
            form.SipOFiyat.Items.Clear();
            form.formuGuncelle();
            form.SipOKDVliTop.Text= "0 TL";
        }
        public Form1 Form
        {
            set
            {
                form = value;
            }
        }
    }
}
