namespace LogIn
{
    partial class PasswordChange
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ID = new System.Windows.Forms.TextBox();
            this.Oldpassword = new System.Windows.Forms.TextBox();
            this.Newpassword = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.M = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ID
            // 
            this.ID.Location = new System.Drawing.Point(259, 50);
            this.ID.Name = "ID";
            this.ID.Size = new System.Drawing.Size(165, 25);
            this.ID.TabIndex = 0;
            // 
            // Oldpassword
            // 
            this.Oldpassword.Location = new System.Drawing.Point(259, 148);
            this.Oldpassword.Name = "Oldpassword";
            this.Oldpassword.Size = new System.Drawing.Size(165, 25);
            this.Oldpassword.TabIndex = 1;
            // 
            // Newpassword
            // 
            this.Newpassword.Location = new System.Drawing.Point(259, 245);
            this.Newpassword.Name = "Newpassword";
            this.Newpassword.Size = new System.Drawing.Size(165, 25);
            this.Newpassword.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(62, 53);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 15);
            this.label1.TabIndex = 3;
            this.label1.Text = "用户名：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(62, 151);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 15);
            this.label2.TabIndex = 4;
            this.label2.Text = "旧的密码：";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(62, 248);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(82, 15);
            this.label3.TabIndex = 5;
            this.label3.Text = "新的密码：";
            // 
            // M
            // 
            this.M.AutoSize = true;
            this.M.ForeColor = System.Drawing.Color.Red;
            this.M.Location = new System.Drawing.Point(175, 300);
            this.M.Name = "M";
            this.M.Size = new System.Drawing.Size(15, 15);
            this.M.TabIndex = 6;
            this.M.Text = " ";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(49, 324);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(146, 42);
            this.button1.TabIndex = 7;
            this.button1.Text = "确 定 修 改";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(259, 324);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(165, 42);
            this.button2.TabIndex = 8;
            this.button2.Text = "关   闭";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // PasswordChange
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(449, 390);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.M);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Newpassword);
            this.Controls.Add(this.Oldpassword);
            this.Controls.Add(this.ID);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PasswordChange";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "PasswordChange";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox ID;
        private System.Windows.Forms.TextBox Oldpassword;
        private System.Windows.Forms.TextBox Newpassword;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label M;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}