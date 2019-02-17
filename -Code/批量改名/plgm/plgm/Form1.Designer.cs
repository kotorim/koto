namespace plgm
{
    partial class 批量重命名
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(批量重命名));
            this.选择文件 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.确定 = new System.Windows.Forms.Button();
            this.newname = new System.Windows.Forms.ListView();
            this.oldname = new System.Windows.Forms.ListView();
            this.保存 = new System.Windows.Forms.Button();
            this.rb1 = new System.Windows.Forms.RadioButton();
            this.rb2 = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.路径 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.rb3 = new System.Windows.Forms.RadioButton();
            this.groupBox1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // 选择文件
            // 
            this.选择文件.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.选择文件.Location = new System.Drawing.Point(12, 12);
            this.选择文件.Name = "选择文件";
            this.选择文件.Size = new System.Drawing.Size(176, 61);
            this.选择文件.TabIndex = 0;
            this.选择文件.Text = "选择文件";
            this.选择文件.UseVisualStyleBackColor = true;
            this.选择文件.Click += new System.EventHandler(this.选择文件_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 99);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(176, 25);
            this.textBox1.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(8, 76);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(184, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "修改文件名字(不填不改)：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.Location = new System.Drawing.Point(8, 127);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(184, 20);
            this.label2.TabIndex = 6;
            this.label2.Text = "修改文件后缀(不填不改)：";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(12, 150);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(176, 25);
            this.textBox2.TabIndex = 7;
            // 
            // 确定
            // 
            this.确定.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.确定.Location = new System.Drawing.Point(12, 267);
            this.确定.Name = "确定";
            this.确定.Size = new System.Drawing.Size(176, 65);
            this.确定.TabIndex = 8;
            this.确定.Text = "确定";
            this.确定.UseVisualStyleBackColor = true;
            this.确定.Click += new System.EventHandler(this.确定1_Click);
            // 
            // newname
            // 
            this.newname.Dock = System.Windows.Forms.DockStyle.Right;
            this.newname.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.newname.Location = new System.Drawing.Point(421, 0);
            this.newname.Name = "newname";
            this.newname.Size = new System.Drawing.Size(229, 403);
            this.newname.TabIndex = 9;
            this.newname.UseCompatibleStateImageBehavior = false;
            this.newname.View = System.Windows.Forms.View.Details;
            // 
            // oldname
            // 
            this.oldname.Dock = System.Windows.Forms.DockStyle.Right;
            this.oldname.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.oldname.Location = new System.Drawing.Point(192, 0);
            this.oldname.Name = "oldname";
            this.oldname.Size = new System.Drawing.Size(229, 403);
            this.oldname.TabIndex = 10;
            this.oldname.UseCompatibleStateImageBehavior = false;
            this.oldname.View = System.Windows.Forms.View.Details;
            // 
            // 保存
            // 
            this.保存.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.保存.Location = new System.Drawing.Point(12, 338);
            this.保存.Name = "保存";
            this.保存.Size = new System.Drawing.Size(176, 65);
            this.保存.TabIndex = 11;
            this.保存.Text = "保存";
            this.保存.UseVisualStyleBackColor = true;
            this.保存.Click += new System.EventHandler(this.保存_Click);
            // 
            // rb1
            // 
            this.rb1.AutoSize = true;
            this.rb1.Checked = true;
            this.rb1.Location = new System.Drawing.Point(4, 22);
            this.rb1.Name = "rb1";
            this.rb1.Size = new System.Drawing.Size(52, 19);
            this.rb1.TabIndex = 0;
            this.rb1.TabStop = true;
            this.rb1.Text = "123";
            this.rb1.UseVisualStyleBackColor = true;
            // 
            // rb2
            // 
            this.rb2.AutoSize = true;
            this.rb2.Location = new System.Drawing.Point(4, 47);
            this.rb2.Name = "rb2";
            this.rb2.Size = new System.Drawing.Size(100, 19);
            this.rb2.TabIndex = 1;
            this.rb2.Text = "(1)(2)(3)";
            this.rb2.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rb3);
            this.groupBox1.Controls.Add(this.rb2);
            this.groupBox1.Controls.Add(this.rb1);
            this.groupBox1.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.groupBox1.Location = new System.Drawing.Point(12, 178);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(0);
            this.groupBox1.Size = new System.Drawing.Size(176, 77);
            this.groupBox1.TabIndex = 12;
            this.groupBox1.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.路径);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point(0, 403);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(650, 38);
            this.panel1.TabIndex = 13;
            // 
            // 路径
            // 
            this.路径.AutoSize = true;
            this.路径.Location = new System.Drawing.Point(74, 14);
            this.路径.Name = "路径";
            this.路径.Size = new System.Drawing.Size(0, 15);
            this.路径.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 14);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 15);
            this.label3.TabIndex = 0;
            this.label3.Text = "路径：";
            // 
            // rb3
            // 
            this.rb3.AutoSize = true;
            this.rb3.Location = new System.Drawing.Point(97, 21);
            this.rb3.Name = "rb3";
            this.rb3.Size = new System.Drawing.Size(58, 19);
            this.rb3.TabIndex = 2;
            this.rb3.TabStop = true;
            this.rb3.Text = "不加";
            this.rb3.UseVisualStyleBackColor = true;
            // 
            // 批量重命名
            // 
            this.AcceptButton = this.确定;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(650, 441);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.保存);
            this.Controls.Add(this.oldname);
            this.Controls.Add(this.newname);
            this.Controls.Add(this.确定);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.选择文件);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "批量重命名";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "批量重命名";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button 选择文件;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button 确定;
        private System.Windows.Forms.ListView newname;
        private System.Windows.Forms.ListView oldname;
        private System.Windows.Forms.Button 保存;
        private System.Windows.Forms.RadioButton rb1;
        private System.Windows.Forms.RadioButton rb2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label 路径;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RadioButton rb3;
    }
}

