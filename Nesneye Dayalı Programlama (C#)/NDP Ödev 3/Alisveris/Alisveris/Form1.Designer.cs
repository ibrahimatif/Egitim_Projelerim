namespace Alisveris
{
    public partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        public System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        public void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.SipOKDVliTop = new System.Windows.Forms.Label();
            this.SipOKDVliTopL = new System.Windows.Forms.Label();
            this.SipOFiyatL = new System.Windows.Forms.Label();
            this.SipOUrunL = new System.Windows.Forms.Label();
            this.SipOAdetL = new System.Windows.Forms.Label();
            this.SipOFiyat = new System.Windows.Forms.ListBox();
            this.SipOUrun = new System.Windows.Forms.ListBox();
            this.SipOAdet = new System.Windows.Forms.ListBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.CepTelAdet = new System.Windows.Forms.NumericUpDown();
            this.LaptopAdet = new System.Windows.Forms.NumericUpDown();
            this.TVAdet = new System.Windows.Forms.NumericUpDown();
            this.BuzdolabiAdet = new System.Windows.Forms.NumericUpDown();
            this.CepTelStok = new System.Windows.Forms.Label();
            this.CepTelFiyat = new System.Windows.Forms.Label();
            this.LaptopStok = new System.Windows.Forms.Label();
            this.LaptopFiyat = new System.Windows.Forms.Label();
            this.TVStok = new System.Windows.Forms.Label();
            this.TVFiyat = new System.Windows.Forms.Label();
            this.BuzdolabiStok = new System.Windows.Forms.Label();
            this.BuzdolabiFiyat = new System.Windows.Forms.Label();
            this.CepTelAdetL = new System.Windows.Forms.Label();
            this.CepTelStokL = new System.Windows.Forms.Label();
            this.CepTelFiyatL = new System.Windows.Forms.Label();
            this.CepTelResim = new System.Windows.Forms.PictureBox();
            this.BuzdolabiAdetL = new System.Windows.Forms.Label();
            this.BuzdolabiStokL = new System.Windows.Forms.Label();
            this.BuzdolabiFiyatL = new System.Windows.Forms.Label();
            this.BuzdolabiResim = new System.Windows.Forms.PictureBox();
            this.LaptopAdetL = new System.Windows.Forms.Label();
            this.LaptopStokL = new System.Windows.Forms.Label();
            this.LaptopFiyatL = new System.Windows.Forms.Label();
            this.LaptopResim = new System.Windows.Forms.PictureBox();
            this.TVAdetL = new System.Windows.Forms.Label();
            this.TVStokL = new System.Windows.Forms.Label();
            this.TVFiyatL = new System.Windows.Forms.Label();
            this.TVResim = new System.Windows.Forms.PictureBox();
            this.SepeteEkle = new System.Windows.Forms.Button();
            this.SepetiTemizle = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.CepTelAdet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LaptopAdet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.TVAdet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BuzdolabiAdet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.CepTelResim)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BuzdolabiResim)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LaptopResim)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.TVResim)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.SipOKDVliTop);
            this.groupBox1.Controls.Add(this.SipOKDVliTopL);
            this.groupBox1.Controls.Add(this.SipOFiyatL);
            this.groupBox1.Controls.Add(this.SipOUrunL);
            this.groupBox1.Controls.Add(this.SipOAdetL);
            this.groupBox1.Controls.Add(this.SipOFiyat);
            this.groupBox1.Controls.Add(this.SipOUrun);
            this.groupBox1.Controls.Add(this.SipOAdet);
            this.groupBox1.Location = new System.Drawing.Point(495, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(300, 470);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Sipariş Özeti";
            // 
            // SipOKDVliTop
            // 
            this.SipOKDVliTop.AutoSize = true;
            this.SipOKDVliTop.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.SipOKDVliTop.Location = new System.Drawing.Point(131, 437);
            this.SipOKDVliTop.Name = "SipOKDVliTop";
            this.SipOKDVliTop.Size = new System.Drawing.Size(51, 24);
            this.SipOKDVliTop.TabIndex = 8;
            this.SipOKDVliTop.Text = "0 TL";
            // 
            // SipOKDVliTopL
            // 
            this.SipOKDVliTopL.AutoSize = true;
            this.SipOKDVliTopL.Location = new System.Drawing.Point(7, 442);
            this.SipOKDVliTopL.Name = "SipOKDVliTopL";
            this.SipOKDVliTopL.Size = new System.Drawing.Size(107, 13);
            this.SipOKDVliTopL.TabIndex = 7;
            this.SipOKDVliTopL.Text = "KDV\'li Toplam Fiyat  :";
            // 
            // SipOFiyatL
            // 
            this.SipOFiyatL.AutoSize = true;
            this.SipOFiyatL.Location = new System.Drawing.Point(222, 13);
            this.SipOFiyatL.Name = "SipOFiyatL";
            this.SipOFiyatL.Size = new System.Drawing.Size(60, 13);
            this.SipOFiyatL.TabIndex = 6;
            this.SipOFiyatL.Text = "KDV\'li Fiyat";
            // 
            // SipOUrunL
            // 
            this.SipOUrunL.AutoSize = true;
            this.SipOUrunL.Location = new System.Drawing.Point(118, 13);
            this.SipOUrunL.Name = "SipOUrunL";
            this.SipOUrunL.Size = new System.Drawing.Size(30, 13);
            this.SipOUrunL.TabIndex = 5;
            this.SipOUrunL.Text = "Ürün";
            // 
            // SipOAdetL
            // 
            this.SipOAdetL.AutoSize = true;
            this.SipOAdetL.Location = new System.Drawing.Point(16, 13);
            this.SipOAdetL.Name = "SipOAdetL";
            this.SipOAdetL.Size = new System.Drawing.Size(29, 13);
            this.SipOAdetL.TabIndex = 3;
            this.SipOAdetL.Text = "Adet";
            // 
            // SipOFiyat
            // 
            this.SipOFiyat.FormattingEnabled = true;
            this.SipOFiyat.Location = new System.Drawing.Point(216, 29);
            this.SipOFiyat.Name = "SipOFiyat";
            this.SipOFiyat.Size = new System.Drawing.Size(78, 134);
            this.SipOFiyat.TabIndex = 2;
            // 
            // SipOUrun
            // 
            this.SipOUrun.FormattingEnabled = true;
            this.SipOUrun.Location = new System.Drawing.Point(66, 29);
            this.SipOUrun.Name = "SipOUrun";
            this.SipOUrun.Size = new System.Drawing.Size(143, 134);
            this.SipOUrun.TabIndex = 1;
            // 
            // SipOAdet
            // 
            this.SipOAdet.AccessibleDescription = "";
            this.SipOAdet.FormattingEnabled = true;
            this.SipOAdet.Location = new System.Drawing.Point(6, 29);
            this.SipOAdet.Name = "SipOAdet";
            this.SipOAdet.Size = new System.Drawing.Size(54, 134);
            this.SipOAdet.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.CepTelAdet);
            this.groupBox2.Controls.Add(this.LaptopAdet);
            this.groupBox2.Controls.Add(this.TVAdet);
            this.groupBox2.Controls.Add(this.BuzdolabiAdet);
            this.groupBox2.Controls.Add(this.CepTelStok);
            this.groupBox2.Controls.Add(this.CepTelFiyat);
            this.groupBox2.Controls.Add(this.LaptopStok);
            this.groupBox2.Controls.Add(this.LaptopFiyat);
            this.groupBox2.Controls.Add(this.TVStok);
            this.groupBox2.Controls.Add(this.TVFiyat);
            this.groupBox2.Controls.Add(this.BuzdolabiStok);
            this.groupBox2.Controls.Add(this.BuzdolabiFiyat);
            this.groupBox2.Controls.Add(this.CepTelAdetL);
            this.groupBox2.Controls.Add(this.CepTelStokL);
            this.groupBox2.Controls.Add(this.CepTelFiyatL);
            this.groupBox2.Controls.Add(this.CepTelResim);
            this.groupBox2.Controls.Add(this.BuzdolabiAdetL);
            this.groupBox2.Controls.Add(this.BuzdolabiStokL);
            this.groupBox2.Controls.Add(this.BuzdolabiFiyatL);
            this.groupBox2.Controls.Add(this.BuzdolabiResim);
            this.groupBox2.Controls.Add(this.LaptopAdetL);
            this.groupBox2.Controls.Add(this.LaptopStokL);
            this.groupBox2.Controls.Add(this.LaptopFiyatL);
            this.groupBox2.Controls.Add(this.LaptopResim);
            this.groupBox2.Controls.Add(this.TVAdetL);
            this.groupBox2.Controls.Add(this.TVStokL);
            this.groupBox2.Controls.Add(this.TVFiyatL);
            this.groupBox2.Controls.Add(this.TVResim);
            this.groupBox2.Location = new System.Drawing.Point(12, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(470, 470);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Ürünlere Ait KDV\'siz Fiyatlar";
            // 
            // CepTelAdet
            // 
            this.CepTelAdet.Location = new System.Drawing.Point(344, 441);
            this.CepTelAdet.Name = "CepTelAdet";
            this.CepTelAdet.Size = new System.Drawing.Size(43, 20);
            this.CepTelAdet.TabIndex = 27;
            // 
            // LaptopAdet
            // 
            this.LaptopAdet.Location = new System.Drawing.Point(56, 441);
            this.LaptopAdet.Name = "LaptopAdet";
            this.LaptopAdet.Size = new System.Drawing.Size(43, 20);
            this.LaptopAdet.TabIndex = 26;
            // 
            // TVAdet
            // 
            this.TVAdet.Location = new System.Drawing.Point(56, 214);
            this.TVAdet.Name = "TVAdet";
            this.TVAdet.Size = new System.Drawing.Size(43, 20);
            this.TVAdet.TabIndex = 25;
            // 
            // BuzdolabiAdet
            // 
            this.BuzdolabiAdet.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.BuzdolabiAdet.Location = new System.Drawing.Point(344, 214);
            this.BuzdolabiAdet.Name = "BuzdolabiAdet";
            this.BuzdolabiAdet.Size = new System.Drawing.Size(43, 20);
            this.BuzdolabiAdet.TabIndex = 24;
            // 
            // CepTelStok
            // 
            this.CepTelStok.AutoSize = true;
            this.CepTelStok.Location = new System.Drawing.Point(347, 422);
            this.CepTelStok.Name = "CepTelStok";
            this.CepTelStok.Size = new System.Drawing.Size(35, 13);
            this.CepTelStok.TabIndex = 23;
            this.CepTelStok.Text = "label2";
            // 
            // CepTelFiyat
            // 
            this.CepTelFiyat.AutoSize = true;
            this.CepTelFiyat.Location = new System.Drawing.Point(347, 400);
            this.CepTelFiyat.Name = "CepTelFiyat";
            this.CepTelFiyat.Size = new System.Drawing.Size(35, 13);
            this.CepTelFiyat.TabIndex = 22;
            this.CepTelFiyat.Text = "label1";
            // 
            // LaptopStok
            // 
            this.LaptopStok.AutoSize = true;
            this.LaptopStok.Location = new System.Drawing.Point(53, 422);
            this.LaptopStok.Name = "LaptopStok";
            this.LaptopStok.Size = new System.Drawing.Size(35, 13);
            this.LaptopStok.TabIndex = 21;
            this.LaptopStok.Text = "label2";
            // 
            // LaptopFiyat
            // 
            this.LaptopFiyat.AutoSize = true;
            this.LaptopFiyat.Location = new System.Drawing.Point(53, 400);
            this.LaptopFiyat.Name = "LaptopFiyat";
            this.LaptopFiyat.Size = new System.Drawing.Size(35, 13);
            this.LaptopFiyat.TabIndex = 20;
            this.LaptopFiyat.Text = "label1";
            // 
            // TVStok
            // 
            this.TVStok.AutoSize = true;
            this.TVStok.Location = new System.Drawing.Point(53, 195);
            this.TVStok.Name = "TVStok";
            this.TVStok.Size = new System.Drawing.Size(35, 13);
            this.TVStok.TabIndex = 19;
            this.TVStok.Text = "label2";
            // 
            // TVFiyat
            // 
            this.TVFiyat.AutoSize = true;
            this.TVFiyat.Location = new System.Drawing.Point(53, 173);
            this.TVFiyat.Name = "TVFiyat";
            this.TVFiyat.Size = new System.Drawing.Size(35, 13);
            this.TVFiyat.TabIndex = 18;
            this.TVFiyat.Text = "label1";
            // 
            // BuzdolabiStok
            // 
            this.BuzdolabiStok.AutoSize = true;
            this.BuzdolabiStok.Location = new System.Drawing.Point(347, 195);
            this.BuzdolabiStok.Name = "BuzdolabiStok";
            this.BuzdolabiStok.Size = new System.Drawing.Size(35, 13);
            this.BuzdolabiStok.TabIndex = 17;
            this.BuzdolabiStok.Text = "label2";
            // 
            // BuzdolabiFiyat
            // 
            this.BuzdolabiFiyat.AutoSize = true;
            this.BuzdolabiFiyat.Location = new System.Drawing.Point(347, 173);
            this.BuzdolabiFiyat.Name = "BuzdolabiFiyat";
            this.BuzdolabiFiyat.Size = new System.Drawing.Size(35, 13);
            this.BuzdolabiFiyat.TabIndex = 16;
            this.BuzdolabiFiyat.Text = "label1";
            // 
            // CepTelAdetL
            // 
            this.CepTelAdetL.AutoSize = true;
            this.CepTelAdetL.Location = new System.Drawing.Point(303, 443);
            this.CepTelAdetL.Name = "CepTelAdetL";
            this.CepTelAdetL.Size = new System.Drawing.Size(38, 13);
            this.CepTelAdetL.TabIndex = 15;
            this.CepTelAdetL.Text = "Adet  :";
            // 
            // CepTelStokL
            // 
            this.CepTelStokL.AutoSize = true;
            this.CepTelStokL.Location = new System.Drawing.Point(303, 422);
            this.CepTelStokL.Name = "CepTelStokL";
            this.CepTelStokL.Size = new System.Drawing.Size(38, 13);
            this.CepTelStokL.TabIndex = 14;
            this.CepTelStokL.Text = "Stok  :";
            // 
            // CepTelFiyatL
            // 
            this.CepTelFiyatL.AutoSize = true;
            this.CepTelFiyatL.Location = new System.Drawing.Point(303, 400);
            this.CepTelFiyatL.Name = "CepTelFiyatL";
            this.CepTelFiyatL.Size = new System.Drawing.Size(38, 13);
            this.CepTelFiyatL.TabIndex = 13;
            this.CepTelFiyatL.Text = "Fiyat  :";
            // 
            // CepTelResim
            // 
            this.CepTelResim.Image = global::Alisveris.Properties.Resources.CepTel;
            this.CepTelResim.Location = new System.Drawing.Point(303, 246);
            this.CepTelResim.Name = "CepTelResim";
            this.CepTelResim.Size = new System.Drawing.Size(161, 144);
            this.CepTelResim.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.CepTelResim.TabIndex = 12;
            this.CepTelResim.TabStop = false;
            // 
            // BuzdolabiAdetL
            // 
            this.BuzdolabiAdetL.AutoSize = true;
            this.BuzdolabiAdetL.Location = new System.Drawing.Point(303, 216);
            this.BuzdolabiAdetL.Name = "BuzdolabiAdetL";
            this.BuzdolabiAdetL.Size = new System.Drawing.Size(38, 13);
            this.BuzdolabiAdetL.TabIndex = 11;
            this.BuzdolabiAdetL.Text = "Adet  :";
            // 
            // BuzdolabiStokL
            // 
            this.BuzdolabiStokL.AutoSize = true;
            this.BuzdolabiStokL.Location = new System.Drawing.Point(303, 195);
            this.BuzdolabiStokL.Name = "BuzdolabiStokL";
            this.BuzdolabiStokL.Size = new System.Drawing.Size(38, 13);
            this.BuzdolabiStokL.TabIndex = 10;
            this.BuzdolabiStokL.Text = "Stok  :";
            // 
            // BuzdolabiFiyatL
            // 
            this.BuzdolabiFiyatL.AutoSize = true;
            this.BuzdolabiFiyatL.Location = new System.Drawing.Point(303, 173);
            this.BuzdolabiFiyatL.Name = "BuzdolabiFiyatL";
            this.BuzdolabiFiyatL.Size = new System.Drawing.Size(38, 13);
            this.BuzdolabiFiyatL.TabIndex = 9;
            this.BuzdolabiFiyatL.Text = "Fiyat  :";
            // 
            // BuzdolabiResim
            // 
            this.BuzdolabiResim.Image = global::Alisveris.Properties.Resources.buzdolabı;
            this.BuzdolabiResim.Location = new System.Drawing.Point(303, 19);
            this.BuzdolabiResim.Name = "BuzdolabiResim";
            this.BuzdolabiResim.Size = new System.Drawing.Size(161, 144);
            this.BuzdolabiResim.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BuzdolabiResim.TabIndex = 8;
            this.BuzdolabiResim.TabStop = false;
            // 
            // LaptopAdetL
            // 
            this.LaptopAdetL.AutoSize = true;
            this.LaptopAdetL.Location = new System.Drawing.Point(9, 443);
            this.LaptopAdetL.Name = "LaptopAdetL";
            this.LaptopAdetL.Size = new System.Drawing.Size(38, 13);
            this.LaptopAdetL.TabIndex = 7;
            this.LaptopAdetL.Text = "Adet  :";
            // 
            // LaptopStokL
            // 
            this.LaptopStokL.AutoSize = true;
            this.LaptopStokL.Location = new System.Drawing.Point(9, 422);
            this.LaptopStokL.Name = "LaptopStokL";
            this.LaptopStokL.Size = new System.Drawing.Size(38, 13);
            this.LaptopStokL.TabIndex = 6;
            this.LaptopStokL.Text = "Stok  :";
            // 
            // LaptopFiyatL
            // 
            this.LaptopFiyatL.AutoSize = true;
            this.LaptopFiyatL.Location = new System.Drawing.Point(9, 400);
            this.LaptopFiyatL.Name = "LaptopFiyatL";
            this.LaptopFiyatL.Size = new System.Drawing.Size(38, 13);
            this.LaptopFiyatL.TabIndex = 5;
            this.LaptopFiyatL.Text = "Fiyat  :";
            // 
            // LaptopResim
            // 
            this.LaptopResim.Image = global::Alisveris.Properties.Resources.Laptop;
            this.LaptopResim.Location = new System.Drawing.Point(9, 246);
            this.LaptopResim.Name = "LaptopResim";
            this.LaptopResim.Size = new System.Drawing.Size(161, 144);
            this.LaptopResim.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.LaptopResim.TabIndex = 4;
            this.LaptopResim.TabStop = false;
            // 
            // TVAdetL
            // 
            this.TVAdetL.AutoSize = true;
            this.TVAdetL.Location = new System.Drawing.Point(6, 216);
            this.TVAdetL.Name = "TVAdetL";
            this.TVAdetL.Size = new System.Drawing.Size(38, 13);
            this.TVAdetL.TabIndex = 3;
            this.TVAdetL.Text = "Adet  :";
            // 
            // TVStokL
            // 
            this.TVStokL.AutoSize = true;
            this.TVStokL.Location = new System.Drawing.Point(6, 195);
            this.TVStokL.Name = "TVStokL";
            this.TVStokL.Size = new System.Drawing.Size(38, 13);
            this.TVStokL.TabIndex = 2;
            this.TVStokL.Text = "Stok  :";
            // 
            // TVFiyatL
            // 
            this.TVFiyatL.AutoSize = true;
            this.TVFiyatL.Location = new System.Drawing.Point(6, 173);
            this.TVFiyatL.Name = "TVFiyatL";
            this.TVFiyatL.Size = new System.Drawing.Size(38, 13);
            this.TVFiyatL.TabIndex = 1;
            this.TVFiyatL.Text = "Fiyat  :";
            // 
            // TVResim
            // 
            this.TVResim.Image = global::Alisveris.Properties.Resources.Led_Tv;
            this.TVResim.Location = new System.Drawing.Point(6, 19);
            this.TVResim.Name = "TVResim";
            this.TVResim.Size = new System.Drawing.Size(161, 144);
            this.TVResim.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.TVResim.TabIndex = 0;
            this.TVResim.TabStop = false;
            // 
            // SepeteEkle
            // 
            this.SepeteEkle.Location = new System.Drawing.Point(83, 488);
            this.SepeteEkle.Name = "SepeteEkle";
            this.SepeteEkle.Size = new System.Drawing.Size(132, 23);
            this.SepeteEkle.TabIndex = 2;
            this.SepeteEkle.Text = "Ürünleri Sepete Ekle";
            this.SepeteEkle.UseVisualStyleBackColor = true;
            this.SepeteEkle.Click += new System.EventHandler(this.SepeteEkle_Click);
            // 
            // SepetiTemizle
            // 
            this.SepetiTemizle.Location = new System.Drawing.Point(221, 488);
            this.SepetiTemizle.Name = "SepetiTemizle";
            this.SepetiTemizle.Size = new System.Drawing.Size(132, 22);
            this.SepetiTemizle.TabIndex = 3;
            this.SepetiTemizle.Text = "Sepeti Temizle";
            this.SepetiTemizle.UseVisualStyleBackColor = true;
            this.SepetiTemizle.Click += new System.EventHandler(this.SepetiTemizle_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 522);
            this.Controls.Add(this.SepetiTemizle);
            this.Controls.Add(this.SepeteEkle);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximumSize = new System.Drawing.Size(816, 561);
            this.MinimumSize = new System.Drawing.Size(816, 561);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.CepTelAdet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LaptopAdet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.TVAdet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BuzdolabiAdet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.CepTelResim)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BuzdolabiResim)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LaptopResim)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.TVResim)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.PictureBox TVResim;
        private System.Windows.Forms.Label TVAdetL;
        private System.Windows.Forms.Label TVStokL;
        private System.Windows.Forms.Label TVFiyatL;
        private System.Windows.Forms.Label CepTelAdetL;
        private System.Windows.Forms.Label CepTelStokL;
        private System.Windows.Forms.Label CepTelFiyatL;
        private System.Windows.Forms.PictureBox CepTelResim;
        private System.Windows.Forms.Label BuzdolabiAdetL;
        private System.Windows.Forms.Label BuzdolabiStokL;
        private System.Windows.Forms.Label BuzdolabiFiyatL;
        private System.Windows.Forms.PictureBox BuzdolabiResim;
        private System.Windows.Forms.Label LaptopAdetL;
        private System.Windows.Forms.Label LaptopStokL;
        private System.Windows.Forms.Label LaptopFiyatL;
        private System.Windows.Forms.PictureBox LaptopResim;
        private System.Windows.Forms.Label SipOUrunL;
        private System.Windows.Forms.Label SipOAdetL;
        public System.Windows.Forms.ListBox SipOFiyat;
        public System.Windows.Forms.ListBox SipOUrun;
        public System.Windows.Forms.ListBox SipOAdet;
        private System.Windows.Forms.NumericUpDown CepTelAdet;
        private System.Windows.Forms.NumericUpDown LaptopAdet;
        private System.Windows.Forms.NumericUpDown TVAdet;
        private System.Windows.Forms.NumericUpDown BuzdolabiAdet;
        public System.Windows.Forms.Label CepTelStok;
        private System.Windows.Forms.Label CepTelFiyat;
        public System.Windows.Forms.Label LaptopStok;
        private System.Windows.Forms.Label LaptopFiyat;
        public System.Windows.Forms.Label TVStok;
        private System.Windows.Forms.Label TVFiyat;
        public System.Windows.Forms.Label BuzdolabiStok;
        private System.Windows.Forms.Label BuzdolabiFiyat;
        private System.Windows.Forms.Label SipOFiyatL;
        private System.Windows.Forms.Button SepeteEkle;
        private System.Windows.Forms.Button SepetiTemizle;
        public System.Windows.Forms.Label SipOKDVliTop;
        private System.Windows.Forms.Label SipOKDVliTopL;
    }
}

