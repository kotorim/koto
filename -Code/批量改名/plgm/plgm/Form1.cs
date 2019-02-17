using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace plgm
{
    public partial class 批量重命名 : Form
    {
        public 批量重命名()
        {
            InitializeComponent();
            this.oldname.Columns.Add("旧名字", 300, HorizontalAlignment.Left);
            this.newname.Columns.Add("新名字", 300, HorizontalAlignment.Left);
        }



        public static string[] filenames, extension, filenameswithoutextension, names;



        private void 选择文件_Click(object sender, EventArgs e)
        {
            this.oldname.Clear();
            this.oldname.Columns.Add("旧名字", 300, HorizontalAlignment.Left);
            filenames = new string[oldname.Items.Count];
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Multiselect = true;
            fileDialog.Title = "请选择文件";
            fileDialog.Filter = "所有文件(*.*)|*.*"; //设置要选择的文件的类型
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                string[] file = fileDialog.SafeFileNames;//返回文件的路径
                路径.Text = Path.GetDirectoryName(fileDialog.FileName);
                filenames = fileDialog.SafeFileNames;
                int len=0;
                SizeF sf;
                for(int q =0;q<filenames.Length;q++)
                {
                    if (filenames[q].Length>len)
                    {
                        len = filenames[q].Length;
                        sf = TextRenderer.MeasureText(filenames[q], new Font("微软雅黑", 9));
                        SizeF sf2 = TextRenderer.MeasureText("新名字", new Font("微软雅黑", 9));
                        if (sf2.Width + 5 < sf.Width)
                        { this.oldname.Columns[0].Width = (int)sf.Width; }
                        else
                        { this.oldname.Columns[0].Width = (int)sf2.Width+5; }
                    }
                }
                ListViewItem oldname;
                for (int i = 0; i < file.GetLength(0); i++)
                {
                    oldname = new ListViewItem(file[i]);
                    this.oldname.Items.Add(oldname);
                }
                filenameswithoutextension = new string[file.GetLength(0)];
                extension = new string[file.GetLength(0)];
                for (int x = 0; x < file.GetLength(0); x++)
                {
                    extension[x] = System.IO.Path.GetExtension(fileDialog.FileNames[x]);
                    filenameswithoutextension[x] = System.IO.Path.GetFileNameWithoutExtension(fileDialog.FileNames[x]);
                }
            }
            else
            {MessageBox.Show("未选择文件？");}
        }



        private void 确定1_Click(object sender, EventArgs e)
        {
            int len = 0;
            SizeF sf;
            string[] news = new string[this.oldname.Items.Count];
            ListViewItem newname;
            this.newname.Clear();
            this.newname.Columns.Add("新名字", 1, HorizontalAlignment.Left);
            names = new string[oldname.Items.Count];
            bool guifan = textBox1.Text.Contains("\\") || textBox1.Text.Contains("/ ") || textBox1.Text.Contains(":") || textBox1.Text.Contains("*") || textBox1.Text.Contains("?") || textBox1.Text.Contains("\"") || textBox1.Text.Contains("<") || textBox1.Text.Contains(">") || textBox1.Text.Contains("|");
            if (guifan == true)
            { MessageBox.Show("名字有不规范符号！！"); }
            else
            {
                for (int x = 0; x < this.oldname.Items.Count; x++)
                {
                    news[x] = this.oldname.Items[x].Text;
                }
                for (int y = 0; y < this.oldname.Items.Count; y++)
                {
                    bool dot = textBox2.Text.Contains(".");
                    if (rb1.Checked == true)
                    {
                        if (dot == true)
                        {
                            if (textBox1.Text.Trim() == String.Empty)
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = filenameswithoutextension[y] + (y + 1) + extension[y]; }
                                else
                                { news[y] = filenameswithoutextension[y] + (y + 1) + textBox2.Text; }
                            }
                            else
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = textBox1.Text + (y + 1) + extension[y]; }
                                else
                                { news[y] = textBox1.Text + (y + 1) + textBox2.Text; }
                            }
                            names[y] = news[y];
                            newname = new ListViewItem(news[y]);
                            this.newname.Items.Add(newname);
                        }
                        else
                        {
                            if (textBox1.Text.Trim() == String.Empty)
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = filenameswithoutextension[y] + (y + 1) + extension[y]; }
                                else
                                { news[y] = filenameswithoutextension[y] + (y + 1) + "." + textBox2.Text; }
                            }
                            else
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = textBox1.Text + (y + 1) + extension[y]; }
                                else
                                { news[y] = textBox1.Text + (y + 1) + "." + textBox2.Text; }
                            }
                            names[y] = news[y];
                            newname = new ListViewItem(news[y]);
                            this.newname.Items.Add(newname);
                        }
                    }
                    else if (rb2.Checked == true)
                    {
                        if (dot == true)
                        {
                            if (textBox1.Text.Trim() == String.Empty)
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = filenameswithoutextension[y] + "(" + (y + 1) + ")" + extension[y]; }
                                else
                                { news[y] = filenameswithoutextension[y] + "(" + (y + 1) + ")" + textBox2.Text; }
                            }
                            else
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = textBox1.Text + "(" + (y + 1) + ")" + extension[y]; }
                                else
                                { news[y] = textBox1.Text + "(" + (y + 1) + ")" + textBox2.Text; }
                            }
                            names[y] = news[y];
                            newname = new ListViewItem(news[y]);
                            this.newname.Items.Add(newname);
                        }
                        else
                        {
                            if (textBox1.Text.Trim() == String.Empty)
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = filenameswithoutextension[y] + "(" + (y + 1) + ")" + extension[y]; }
                                else
                                { news[y] = filenameswithoutextension[y] + "(" + (y + 1) + ")" + "." + textBox2.Text; }
                            }
                            else
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = textBox1.Text + "(" + (y + 1) + ")" + extension[y]; }
                                else
                                { news[y] = textBox1.Text + "(" + (y + 1) + ")" + "." + textBox2.Text; }
                            }
                            names[y] = news[y];
                            newname = new ListViewItem(news[y]);
                            this.newname.Items.Add(newname);
                        }
                    }
                    else if (rb3.Checked == true)
                    {
                        if (dot == true)
                        {
                            if (textBox1.Text.Trim() == String.Empty)
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = filenameswithoutextension[y] + extension[y]; }
                                else
                                { news[y] = filenameswithoutextension[y] + textBox2.Text; }
                            }
                            else
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = textBox1.Text + extension[y]; }
                                else
                                { news[y] = textBox1.Text + textBox2.Text; }
                            }
                            names[y] = news[y];
                            newname = new ListViewItem(news[y]);
                            this.newname.Items.Add(newname);
                        }
                        else
                        {
                            if (textBox1.Text.Trim() == String.Empty)
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = filenameswithoutextension[y]+ extension[y]; }
                                else
                                { news[y] = filenameswithoutextension[y] + "." + textBox2.Text; }
                            }
                            else
                            {
                                if (textBox2.Text.Trim() == string.Empty)
                                { news[y] = textBox1.Text + extension[y]; }
                                else
                                { news[y] = textBox1.Text + "." + textBox2.Text; }
                            }
                            names[y] = news[y];
                            newname = new ListViewItem(news[y]);
                            this.newname.Items.Add(newname);
                        }
                    }
                }
                for (int q = 0; q < names.Length; q++)
                    {
                        if (names[q].Length > len)
                        {
                            len = names[q].Length;
                            sf = TextRenderer.MeasureText(names[q], new Font("微软雅黑", 9));
                            SizeF sf2 = TextRenderer.MeasureText("新名字", new Font("微软雅黑", 9));
                            if (sf2.Width+5 < sf.Width)
                            { this.newname.Columns[0].Width = (int)sf.Width; }
                            else
                            { this.newname.Columns[0].Width = (int)sf2.Width + 5; }
                        }
                    }
            }
        }



        private void 保存_Click(object sender, EventArgs e)
        {
            int m=2;
            bool a = false;
            for (int w = 0; w < names.Length - 1; w++)
            {
                for (int r = 1; r < names.Length; r++)
                {
                    if (String.Equals(names[w], names[r]))
                    {
                        //MessageBox.Show("llllllll");
                        m = 1;
                    }
                    else if(String.Equals(names[w], names[r])==false)
                    { m = 0; }
                }
            }
            if (m == 0)
            {
                for (int i = 0; i < this.oldname.Items.Count; i++)
                {
                    File.Move(路径.Text + "\\" + filenames[i], 路径.Text + "\\" + names[i]);
                    if (System.IO.File.Exists(路径.Text + "\\" + names[i]))
                    { a = true; }
                    else
                    { a = false; }
                }
                if (a == true)
                {
                    System.Diagnostics.Process.Start(路径.Text);
                    路径.Text = textBox1.Text = textBox2.Text = null;
                    newname.Clear();
                    oldname.Clear();
                    this.oldname.Columns.Add("旧名", 300, HorizontalAlignment.Left); //一步添加
                    this.newname.Columns.Add("新名", 300, HorizontalAlignment.Left); //一步添加
                }
                else if (a == false)
                { MessageBox.Show("好像出了点问题？"); }
            }
            else if(m==1)
            { MessageBox.Show("出现相同名字，请检查修改内容"); }
        }
    }
}
