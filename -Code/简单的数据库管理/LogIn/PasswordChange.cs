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
    public partial class PasswordChange : Form
    {
        public PasswordChange()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
            SqlConnection conn = new SqlConnection(str);
            conn.Open();
            string selectsql = "Select * from UserData where UserID = '" + ID.Text + "' and Userpassword='" + Oldpassword.Text + "'";
            SqlCommand cmd = new SqlCommand(selectsql, conn);
            cmd.CommandType = CommandType.Text;
            SqlDataReader sdr;
            sdr = cmd.ExecuteReader();

            if (sdr.Read())
            {
                conn.Close();
                if (Newpassword.Text != "")
                {
                    string str2 = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
                    SqlConnection conn2 = new SqlConnection(str2);
                    conn2.Open();
                    string sql = "delete from UserData where UserID='" + ID.Text + "'";
                    SqlCommand cmd2 = new SqlCommand(sql, conn2);
                    cmd2.CommandType = CommandType.Text;
                    SqlDataReader sdr2;
                    sdr2 = cmd2.ExecuteReader();
                    conn2.Close();



                    string str3 = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
                    SqlConnection conn3 = new SqlConnection(str3);
                    conn3.Open();
                    string sql2 = "insert into UserData values('" + ID.Text + "','" + Newpassword.Text + "')";
                    SqlCommand cmd3 = new SqlCommand(sql2, conn3);
                    cmd3.CommandType = CommandType.Text;
                    SqlDataReader sdr3;
                    sdr3 = cmd3.ExecuteReader();
                    conn3.Close();
                    M.Text = "修改成功";
                }
                else
                { M.Text = "请输入新的密码"; }
            }
           
            else
            {
                conn.Close();
               M .Text = "账号或者密码错误_(:зゝ∠)_";
                return;
            }




        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
