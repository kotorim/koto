using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using WindowsFormsApplication1;
using System.Drawing.Drawing2D;
using System.Runtime.InteropServices;

namespace LogIn
{

    public partial class Form1 : Form
    {
        public Form1()
        {

            InitializeComponent();



        }
        int a = 0;
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
            SqlConnection conn = new SqlConnection(str);
            conn.Open();
            string selectsql = "Select * from UserData where UserID = '" + textBox1.Text + "' and Userpassword='" + textBox2.Text + "'";
            SqlCommand cmd = new SqlCommand(selectsql, conn);
            cmd.CommandType = CommandType.Text;
            SqlDataReader sdr;
            sdr = cmd.ExecuteReader();
            if (sdr.Read())
            {
                label3.Text = "登陆成功";
                timer2.Enabled = true;
                new MainFrm().Show();
            }
            else
            {
                label3.Text = "登录失败_(:зゝ∠)_";
                return;
            }

            conn.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer2.Enabled = true;
            Form2 b = new Form2();
            b.Show();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

     
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            timer2.Enabled = true;
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
                this.Hide();         // 中止程序  
            }
        }
    }
}

    
