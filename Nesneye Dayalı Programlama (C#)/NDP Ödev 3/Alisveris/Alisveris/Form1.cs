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
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Alisveris
{



    public partial class Form1 : Form
    {
        Buzdolabi buzdolabi = new Buzdolabi("Buzdolabi", "Vestel", "NF520", "Beyaz", "520 LT", "A++", 2666);
        Laptop laptop = new Laptop("Laptop", "MSI", "9SC 041XTR", "I5 9300H GTX1650", "15 inc", "Full HD (1080P)", "256 GB", "8 GB", "41 Whr", 5565);
        LedTv tv = new LedTv("Televizyon", "Vestel", "49F9400", "Smart", "49 inc", "Full HD (1080P)", 2114);
        CepTel telefon = new CepTel("Cep Telefonu", "Vestel", "Venus Z40", "Mor", "128 GB", "4 GB", "3500 mAh", 1833);
        Sepet sepet = new Sepet();

        public Form1()
        {
            InitializeComponent();
            sepet.Form = this;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            formuGuncelle();
        }
        
        private void SepeteEkle_Click(object sender, EventArgs e)
        {
            buzdolabi.secilenAdet = int.Parse(BuzdolabiAdet.Value.ToString());
            laptop.secilenAdet = int.Parse(LaptopAdet.Value.ToString());
            tv.secilenAdet = int.Parse(TVAdet.Value.ToString());
            telefon.secilenAdet = int.Parse(CepTelAdet.Value.ToString());

            sepet.SepeteUrunEkle(buzdolabi,laptop,tv,telefon);
        }

        private void SepetiTemizle_Click(object sender, EventArgs e)
        {
            //Sepette urun yoksa sepeti temizleme fonksiyonunu calistirmayan kosul ifadesi
            if (SipOAdet.Items.Count != 0)
            {
                sepet.SepetiTemizle();
            }
        }

        //Urun bilgilerini(stok,fiyat) forma elemanlarina aktaran metot.
        public void formuGuncelle()
        {
            BuzdolabiFiyat.Text = buzdolabi.hamFiyat.ToString();
            BuzdolabiStok.Text = buzdolabi.stokAdedi.ToString();
            BuzdolabiAdet.Maximum = buzdolabi.stokAdedi;

            LaptopFiyat.Text = laptop.hamFiyat.ToString();
            LaptopStok.Text = laptop.stokAdedi.ToString();
            LaptopAdet.Maximum = laptop.stokAdedi;

            TVFiyat.Text = tv.hamFiyat.ToString();
            TVStok.Text = tv.stokAdedi.ToString();
            TVAdet.Maximum = tv.stokAdedi;

            CepTelFiyat.Text = telefon.hamFiyat.ToString();
            CepTelStok.Text = telefon.stokAdedi.ToString();
            CepTelAdet.Maximum = telefon.stokAdedi;
        }

        //Sepeti temizle fonksiyonu ile labellara atanan degerleri urunlerin stok bilgisine aktaran metot.
        public void stokGuncelle()
        {
            buzdolabi.stokAdedi = int.Parse(BuzdolabiStok.Text);
            laptop.stokAdedi = int.Parse(LaptopStok.Text);
            tv.stokAdedi = int.Parse(TVStok.Text);
            telefon.stokAdedi = int.Parse(CepTelStok.Text);
        }
    }
}
