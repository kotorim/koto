using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using LogIn;
using System.Data.SqlClient;

namespace WindowsFormsApplication1
{
    public partial class MainFrm : Form
    {
        public MainFrm()
        {
            InitializeComponent();
        }

        private void tsmStuMsgmag_Click(object sender, EventArgs e)
        {
             all a = new all();
            a.MdiParent = this;
            a.Show();
        }

        private void MainFrm_Load(object sender, EventArgs e)
        {

        }

        private void passwordcange(object sender, EventArgs e)
        {
            

        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            all a = new all();
            a.MdiParent = this;
         
            a.Show();

        }

        private void 添加学生信息ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 b = new Form3();
            b.MdiParent = this;
            b.Show();
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            timer2.Enabled = true;

        }

        private void tsmSystemMsg_Click(object sender, EventArgs e)
        {

        }

        private void passwordchange_Click(object sender, EventArgs e)
        {
            PasswordChange a = new PasswordChange();
            a.MdiParent = this;
            a.Show();
        }

        private void toolStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            timer2.Enabled = true;
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            if (this.WindowState == FormWindowState.Normal)
            {this.WindowState = FormWindowState.Maximized; }
            else
            { this.WindowState = FormWindowState.Normal; }

        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.Opacity += 0.05;
            if (this.Opacity >= 1.0)
            {
                timer1.Enabled = false;
            }
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            this.Opacity -= 0.05;           // 降低窗体透明度  
            if (this.Opacity <= 0.0)
            {
                timer2.Enabled = false;
                System.Environment.Exit(0);        // 中止程序  
            }
        }

        private void timer3_Tick(object sender, EventArgs e)
        {
            DateTime dt = DateTime.Now;
            toolStripStatusLabel3.Text = dt.ToString();
        }
    }
}
