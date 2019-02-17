using NetworksSwitch;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 快捷键
{
    public partial class fvck : Form
    {
        
        public fvck()
        {
            InitializeComponent();
        }
        public void OnHotkey1(int HotkeyID) //设置热键的行为
        {
            if (HotkeyID == Hotkey.Hotkey1)
            {
                if (this.Visible == true)
                    this.Visible = false;
                else
                    this.Visible = true;
            }
            else
            {
                this.Visible = false;
            }
        }
        public void OnHotkey2(int HotkeyID)
        {
            int r = 0;
            if (HotkeyID == Hotkey.Hotkey2)
            {
                System.Diagnostics.Process[] processList = System.Diagnostics.Process.GetProcesses();
                
                foreach (System.Diagnostics.Process process in processList)
                {
                    if (process.ProcessName.ToString() == "Calculator")
                    {
                        process.Kill();
                        r = 1;
                        return;
                    }
                    else
                    {
                        r = 0;
                    }
                }
            }
            if (r == 0)
            { 
                Process.Start(@"calc.exe");
                return;
            }
        }
        public void OnHotkey3(int HotkeyID)
        {
            if (HotkeyID == Hotkey.Hotkey3)
            {
               Process.Start(@"C:\WINDOWS\System32\notepad.exe");
            }
        }
        public void OnHotkey4(int HotkeyID)
        {
            int r = 0;
            if (HotkeyID == Hotkey.Hotkey4)
            {
                System.Diagnostics.Process[] processList = System.Diagnostics.Process.GetProcesses();

                foreach (System.Diagnostics.Process process in processList)
                {
                    if (process.ProcessName.ToString() == "hh")
                    {
                        process.Kill();
                        r = 1;
                        return;
                    }
                    else
                    {
                        r = 0;
                    }
                }
            }
            if (r == 0)
            {
                Process.Start(@"E:\feisi project\C++\C&C++语言参考手册.chm");
                return;
            }
        }
        public void OnHotkey5(int HotkeyID)
        {
            int r = 0;
            if (HotkeyID == Hotkey.Hotkey5)
            {
                System.Diagnostics.Process[] processList = System.Diagnostics.Process.GetProcesses();

                foreach (System.Diagnostics.Process process in processList)
                {
                    if (process.ProcessName.ToString() == "onenoteim")
                    {
                        process.CloseMainWindow();
                        process.Kill();
                        r = 1;
                        return;
                    }
                    else
                    {
                        r = 0;
                    }
                }
            }
            if (r == 0)
            {
                System.Diagnostics.Process.Start("D:/工具/OneNote.lnk");
                return;
            }
        }
        public void OnHotkey6(int HotkeyID)
        {
            if (HotkeyID == Hotkey.Hotkey6)
            {
                Process.Start("E:/飞思/VS2013/Common7/IDE/devenv.exe");
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            Hotkey hotkey1;
            hotkey1 = new Hotkey(this.Handle);
            Hotkey.Hotkey1 = hotkey1.RegisterHotkey(System.Windows.Forms.Keys.NumPad0, Hotkey.KeyFlags.MOD_CONTROL);   //定义快键
            hotkey1.OnHotkey += new HotkeyEventHandler(OnHotkey1);

            Hotkey hotkey2;
            hotkey2 = new Hotkey(this.Handle);
            Hotkey.Hotkey2 = hotkey2.RegisterHotkey(System.Windows.Forms.Keys.NumPad2, Hotkey.KeyFlags.MOD_CONTROL);
            hotkey2.OnHotkey += new HotkeyEventHandler(OnHotkey2);

            Hotkey hotkey3;
            hotkey3 = new Hotkey(this.Handle);
            Hotkey.Hotkey3 = hotkey3.RegisterHotkey(System.Windows.Forms.Keys.NumPad1, Hotkey.KeyFlags.MOD_CONTROL);
            hotkey3.OnHotkey += new HotkeyEventHandler(OnHotkey3);

            Hotkey hotkey4;
            hotkey4 = new Hotkey(this.Handle);
            Hotkey.Hotkey4 = hotkey4.RegisterHotkey(System.Windows.Forms.Keys.NumPad3, Hotkey.KeyFlags.MOD_CONTROL);
            hotkey4.OnHotkey += new HotkeyEventHandler(OnHotkey4);

            Hotkey hotkey5;
            hotkey5 = new Hotkey(this.Handle);
            Hotkey.Hotkey5 = hotkey5.RegisterHotkey(System.Windows.Forms.Keys.NumPad4, Hotkey.KeyFlags.MOD_CONTROL);
            hotkey5.OnHotkey += new HotkeyEventHandler(OnHotkey5);

            Hotkey hotkey6;
            hotkey6 = new Hotkey(this.Handle);
            Hotkey.Hotkey6 = hotkey6.RegisterHotkey(System.Windows.Forms.Keys.Home,Hotkey.KeyFlags.MOD_CONTROL);
            hotkey6.OnHotkey += new HotkeyEventHandler(OnHotkey6);
        }
        private void notifyIcon1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                Menu.Show();
            }
        }

        private void Menu_Opening(object sender, CancelEventArgs e)
        {
           
        }

        private void open_Click(object sender, EventArgs e)
        {
            this.Visible = true;
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Visible = false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.Visible = false;
            this.timer1.Enabled = false;
        }
    }
}
