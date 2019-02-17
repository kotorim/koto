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

namespace LogIn
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
            SqlConnection conn = new SqlConnection(str);
            conn.Open();
            string a = "Select * from UserData where UserID = '" + ID.Text + "'" ;
            SqlCommand cmd = new SqlCommand(a, conn);
            cmd.CommandType = CommandType.Text;
            SqlDataReader sdr;
            sdr = cmd.ExecuteReader();
 
            if (sdr.Read())
            {
                conn.Close();
                label3.Text = "此账户名已存在_(:зゝ∠)_";

            }

            else if (ID.Text == "" || password.Text == "")
            {
                conn.Close();
                label3.Text = "至少输入点什么_(:зゝ∠)_";
            }

            else
            {
                conn.Close();
                string str2 = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
                SqlConnection conn2 = new SqlConnection(str2);
                conn2.Open();
                string selectsql = "insert into UserData values('" + ID.Text + "','" + password.Text + "')";
                SqlCommand cmd2 = new SqlCommand(selectsql, conn2);
                cmd2.CommandType = CommandType.Text;
                SqlDataReader sdr3;
                sdr3 = cmd2.ExecuteReader();
                label3.Text = "注册成功";
                conn2.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer2.Enabled = true;
            Form1 b = new Form1();
            b.Show();



        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            timer2.Enabled = true;
            Form1 b = new Form1();
            b.Show();
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
                    this.Close();         // 中止程序  
                }
        }
    }
}
