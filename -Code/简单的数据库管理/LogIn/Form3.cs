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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (name.Text == "" || Tel.Text == "" || sex.Text == "" || QQ.Text == "" || address.Text == "" || Email.Text == "" || job.Text == "")
            { M.Text = "有未输入的项目"; }
            else
            {
                if (radioButton1.Checked)
                { sex.Text = "男"; }
                else if (radioButton2.Checked)
                { sex.Text = "女"; }
                string str = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
                SqlConnection conn = new SqlConnection(str);
                conn.Open();
                string selectsql = "insert into Message values('" + name.Text + "','" + Tel.Text + "','" + sex.Text + "','" + dateTimePicker1.Value.Date.ToString("yyyy.mm.dd") + "','" + QQ.Text + "','" + address.Text + "','" + Email.Text + "','" + job.Text + "')";
                SqlCommand cmd = new SqlCommand(selectsql, conn);
                cmd.CommandType = CommandType.Text;
                SqlDataReader sdr;
                sdr = cmd.ExecuteReader();
                conn.Close();
                name.Text = "";
                QQ.Text = "";
                address.Text = "";
                Tel.Text = "";
                job.Text = "";
                Email.Text = "";


                check a = new check();
                a.Show();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }
    }
}

