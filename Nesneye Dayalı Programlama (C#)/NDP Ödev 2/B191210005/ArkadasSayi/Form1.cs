/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2014-2015 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:2
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
using System.Collections;

namespace ArkadasSayi
{
    public partial class Form1 : Form
    {
        int sayac = 0;
        Label labelX = null, labelY = null, labelToplam = null;
        ListBox XCarpanlari = null, YCarpanlari = null;
        TextBox textBoxX = null, textBoxY = null;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int X = int.Parse(textBox1.Text);
            int Y = int.Parse(textBox2.Text);

            int carpanXToplam = 1;
            int carpanYToplam = 1;

            ArrayList XCarpanSon = new ArrayList();
            ArrayList YCarpanSon = new ArrayList();

            //Butona kaç defa tıklandığını kontrol eden koşul
            if (sayac == 0)
            {
                labelX = new Label();
                labelY = new Label();
                labelToplam = new Label();
                XCarpanlari = new ListBox();
                YCarpanlari = new ListBox();
                textBoxX = new TextBox();
                textBoxY = new TextBox();
                // 
                // labelX
                // 
                labelX.AutoSize = true;
                labelX.Location = new Point(281, 13);
                labelX.Size = new Size(14, 13);
                labelX.TabIndex = 8;
                labelX.Text = "X";
                // 
                // labelY
                // 
                labelY.AutoSize = true;
                labelY.Location = new Point(395, 13);
                labelY.Size = new Size(14, 13);
                labelY.TabIndex = 9;
                labelY.Text = "Y";
                // 
                // labelToplam
                // 
                labelToplam.AutoSize = true;
                labelToplam.Location = new Point(167, 174);
                labelToplam.Size = new Size(72, 13);
                labelToplam.TabIndex = 10;
                labelToplam.Text = "TOPLAMLAR";
                // 
                // XCarpanlari
                // 
                XCarpanlari.FormattingEnabled = true;
                XCarpanlari.Location = new Point(245, 29);
                XCarpanlari.Size = new Size(85, 134);
                XCarpanlari.TabIndex = 0;
                // 
                // YCarpanlari
                // 
                YCarpanlari.FormattingEnabled = true;
                YCarpanlari.Location = new Point(360, 29);
                YCarpanlari.Size = new Size(85, 134);
                YCarpanlari.TabIndex = 1;
                // 
                // textBoxX
                // 
                textBoxX.Location = new Point(245, 171);
                textBoxX.Size = new Size(85, 20);
                textBoxX.TabIndex = 11;
                textBoxX.ReadOnly = true;
                // 
                // textBoxY
                // 
                textBoxY.Location = new Point(360, 171);
                textBoxY.Size = new Size(85, 20);
                textBoxY.TabIndex = 12;
                textBoxY.ReadOnly = true;

                Form1.ActiveForm.Height = 240;
                Form1.ActiveForm.Width = 480;

                this.Controls.Add(labelX);
                this.Controls.Add(labelY);
                this.Controls.Add(labelToplam);
                this.Controls.Add(XCarpanlari);
                this.Controls.Add(YCarpanlari);
                this.Controls.Add(textBoxX);
                this.Controls.Add(textBoxY);

                //X sayısının çarpanlarını bulmak için X sayısının yarısına kadar olan tüm sayıları gezen döngü.
                for (int i = 1; i <= X/2; i++)
                {
                    //X sayısı gezilen sayıya bölünüyor ise listboxa ekleyen koşul.
                    if (X % i == 0)
                    {
                        XCarpanlari.Items.Add(i);
                    }
                }
                //Listboxta bulunan çarpanların toplanmasını sağlayan döngü.
                for (int i = 1; i < XCarpanlari.Items.Count; i++)
                {
                    carpanXToplam = carpanXToplam + int.Parse(XCarpanlari.Items[i].ToString());
                }

                //Y sayısının çarpanlarını bulmak için X sayısının yarısına kadar olan tüm sayıları gezen döngü.
                for (int i = 1; i <= Y/2; i++)
                {
                    //Y sayısı gezilen sayıya bölünüyor ise listboxa ekleyen koşul.
                    if (Y % i == 0)
                    {
                        YCarpanlari.Items.Add(i);
                    }
                }
                //Listboxta bulunan çarpanların toplanmasını sağlayan döngü.
                for (int i = 1; i < YCarpanlari.Items.Count; i++)
                {
                    carpanYToplam = carpanYToplam + int.Parse(YCarpanlari.Items[i].ToString());
                }
                textBoxX.Text = carpanXToplam.ToString();
                textBoxY.Text = carpanYToplam.ToString();
                sayac++;
            }
            else
            {
                XCarpanlari.Items.Clear();
                YCarpanlari.Items.Clear();

                //X sayısının çarpanlarını bulmak için X sayısının yarısına kadar olan tüm sayıları gezen döngü.
                for (int i = 1; i <= X/2; i++)
                {
                    //X sayısı gezilen sayıya bölünüyor ise listboxa ekleyen koşul.
                    if (X % i == 0)
                    {
                        XCarpanlari.Items.Add(i);
                    }
                }
                //Listboxta bulunan çarpanların toplanmasını sağlayan döngü.
                for (int i = 1; i < XCarpanlari.Items.Count; i++)
                {
                    carpanXToplam = carpanXToplam + int.Parse(XCarpanlari.Items[i].ToString());
                }

                //Y sayısının çarpanlarını bulmak için X sayısının yarısına kadar olan tüm sayıları gezen döngü.
                for (int i = 1; i <= Y/2; i++)
                {
                    //Y sayısı gezilen sayıya bölünüyor ise listboxa ekleyen koşul.
                    if (Y % i == 0)
                    {
                        YCarpanlari.Items.Add(i);
                    }
                }
                //Listboxta bulunan çarpanların toplanmasını sağlayan döngü.
                for (int i = 1; i < YCarpanlari.Items.Count; i++)
                {
                    carpanYToplam = carpanYToplam + int.Parse(YCarpanlari.Items[i].ToString());
                }
                textBoxX.Text = carpanXToplam.ToString();
                textBoxY.Text = carpanYToplam.ToString();
                sayac++;
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Form1.ActiveForm.Close();
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }
        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }
    }
}