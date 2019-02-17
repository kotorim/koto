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

    public partial class all : Form
    {
        
        public all()
        {
            InitializeComponent();

        }
        public static int RowCount = 0;
        public static int SetGetRow
        {
            set
            {
                if (RowCount != value) { RowCount = value; }
            }
            get { return RowCount; }
        }
        private void all_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“kDataSet2.Message”中。您可以根据需要移动或删除它。
            this.messageTableAdapter1.Fill(this.kDataSet2.Message);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                for (int j = 0; j < dataGridView1.Columns.Count; j++)
                {
                    if (dataGridView1.Rows[i].Cells[j].Value.ToString() == textBox1.Text)
                    {
                        dataGridView1.ClearSelection();
                        dataGridView1.Rows[i].Cells[j].Selected = true; //找到后单元格被选中
                        dataGridView1.CurrentCell = dataGridView1.Rows[i].Cells[j];

                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                for (int j = 0; j < dataGridView1.Columns.Count; j++)
                {
                    if (dataGridView1.Rows[i].Cells[j].Selected == true)
                    {
                        dataGridView1.Rows.RemoveAt(i);
                    }
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string str = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
            SqlConnection conn = new SqlConnection(str);
            conn.Open();
            string selectsql = "TRUNCATE TABLE Message";
            SqlCommand cmd = new SqlCommand(selectsql, conn);
            cmd.CommandType = CommandType.Text;
            SqlDataReader sdr;
            sdr = cmd.ExecuteReader();
            conn.Close();
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                string str2 = @"Data Source=KOTO;Initial catalog=K;integrated Security=True  ";
                SqlConnection conn2 = new SqlConnection(str2);
                conn2.Open();
                string StudentName = dataGridView1.Rows[i].Cells[0].Value.ToString();
                string Tel = dataGridView1.Rows[i].Cells[1].Value.ToString();
                string StudentSex = dataGridView1.Rows[i].Cells[2].Value.ToString();
                string StudentBirthday = dataGridView1.Rows[i].Cells[3].Value.ToString();
                string StudentQQ = dataGridView1.Rows[i].Cells[4].Value.ToString();
                string Homeaddress = dataGridView1.Rows[i].Cells[5].Value.ToString();
                string Email = dataGridView1.Rows[i].Cells[6].Value.ToString();
                string Job = dataGridView1.Rows[i].Cells[7].Value.ToString();
                string selectsql2 = "insert into Message values('" + StudentName + "','" +Tel+"','" + StudentSex + "','" + StudentBirthday + "','" + StudentQQ + "','" + Homeaddress + "','"+Email+"','"+Job+"')";
                SqlCommand cmd2 = new SqlCommand(selectsql2, conn2);
                cmd2.CommandType = CommandType.Text;
                SqlDataReader sdr2;
                sdr2 = cmd2.ExecuteReader();
                conn2.Close();
            }
            check a = new check();
            a.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
