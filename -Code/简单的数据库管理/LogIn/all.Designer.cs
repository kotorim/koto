namespace LogIn
{
    partial class all
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
            this.components = new System.ComponentModel.Container();
            this.masterDataSet = new LogIn.masterDataSet();
            this.studentInfoBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.studentInfoTableAdapter = new LogIn.masterDataSetTableAdapters.StudentInfoTableAdapter();
            this.studentInfoBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.nameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.telDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sexDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.birthdayDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.qQDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.homeAddressDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.emailDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.jobDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.messageBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.kDataSet2 = new LogIn.KDataSet2();
            this.messageBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.kDataSet1 = new LogIn.KDataSet1();
            this.studentInfoBindingSource2 = new System.Windows.Forms.BindingSource(this.components);
            this.kDataSet = new LogIn.KDataSet();
            this.studentInfoTableAdapter1 = new LogIn.KDataSetTableAdapters.StudentInfoTableAdapter();
            this.messageTableAdapter = new LogIn.KDataSet1TableAdapters.MessageTableAdapter();
            this.messageTableAdapter1 = new LogIn.KDataSet2TableAdapters.MessageTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.masterDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentInfoBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentInfoBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.messageBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.kDataSet2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.messageBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.kDataSet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentInfoBindingSource2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.kDataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // masterDataSet
            // 
            this.masterDataSet.DataSetName = "masterDataSet";
            this.masterDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // studentInfoBindingSource
            // 
            this.studentInfoBindingSource.DataMember = "StudentInfo";
            this.studentInfoBindingSource.DataSource = this.masterDataSet;
            // 
            // studentInfoTableAdapter
            // 
            this.studentInfoTableAdapter.ClearBeforeFill = true;
            // 
            // studentInfoBindingSource1
            // 
            this.studentInfoBindingSource1.DataMember = "StudentInfo";
            this.studentInfoBindingSource1.DataSource = this.masterDataSet;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(265, 245);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(202, 36);
            this.button1.TabIndex = 1;
            this.button1.Text = "搜   索";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("宋体", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox1.Location = new System.Drawing.Point(12, 275);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(216, 34);
            this.textBox1.TabIndex = 2;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(265, 302);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(202, 36);
            this.button2.TabIndex = 3;
            this.button2.Text = "删除该学生信息";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(503, 245);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(202, 36);
            this.button3.TabIndex = 4;
            this.button3.Text = "保   存";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(503, 302);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(202, 36);
            this.button4.TabIndex = 5;
            this.button4.Text = "关   闭";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToOrderColumns = true;
            this.dataGridView1.AllowUserToResizeColumns = false;
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.nameDataGridViewTextBoxColumn,
            this.telDataGridViewTextBoxColumn,
            this.sexDataGridViewTextBoxColumn,
            this.birthdayDataGridViewTextBoxColumn,
            this.qQDataGridViewTextBoxColumn,
            this.homeAddressDataGridViewTextBoxColumn,
            this.emailDataGridViewTextBoxColumn,
            this.jobDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.messageBindingSource1;
            this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Top;
            this.dataGridView1.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 27;
            this.dataGridView1.Size = new System.Drawing.Size(717, 231);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // nameDataGridViewTextBoxColumn
            // 
            this.nameDataGridViewTextBoxColumn.DataPropertyName = "Name";
            this.nameDataGridViewTextBoxColumn.HeaderText = "Name";
            this.nameDataGridViewTextBoxColumn.Name = "nameDataGridViewTextBoxColumn";
            // 
            // telDataGridViewTextBoxColumn
            // 
            this.telDataGridViewTextBoxColumn.DataPropertyName = "Tel";
            this.telDataGridViewTextBoxColumn.HeaderText = "Tel";
            this.telDataGridViewTextBoxColumn.Name = "telDataGridViewTextBoxColumn";
            // 
            // sexDataGridViewTextBoxColumn
            // 
            this.sexDataGridViewTextBoxColumn.DataPropertyName = "Sex";
            this.sexDataGridViewTextBoxColumn.HeaderText = "Sex";
            this.sexDataGridViewTextBoxColumn.Name = "sexDataGridViewTextBoxColumn";
            // 
            // birthdayDataGridViewTextBoxColumn
            // 
            this.birthdayDataGridViewTextBoxColumn.DataPropertyName = "Birthday";
            this.birthdayDataGridViewTextBoxColumn.HeaderText = "Birthday";
            this.birthdayDataGridViewTextBoxColumn.Name = "birthdayDataGridViewTextBoxColumn";
            // 
            // qQDataGridViewTextBoxColumn
            // 
            this.qQDataGridViewTextBoxColumn.DataPropertyName = "QQ";
            this.qQDataGridViewTextBoxColumn.HeaderText = "QQ";
            this.qQDataGridViewTextBoxColumn.Name = "qQDataGridViewTextBoxColumn";
            // 
            // homeAddressDataGridViewTextBoxColumn
            // 
            this.homeAddressDataGridViewTextBoxColumn.DataPropertyName = "HomeAddress";
            this.homeAddressDataGridViewTextBoxColumn.HeaderText = "HomeAddress";
            this.homeAddressDataGridViewTextBoxColumn.Name = "homeAddressDataGridViewTextBoxColumn";
            // 
            // emailDataGridViewTextBoxColumn
            // 
            this.emailDataGridViewTextBoxColumn.DataPropertyName = "Email";
            this.emailDataGridViewTextBoxColumn.HeaderText = "Email";
            this.emailDataGridViewTextBoxColumn.Name = "emailDataGridViewTextBoxColumn";
            // 
            // jobDataGridViewTextBoxColumn
            // 
            this.jobDataGridViewTextBoxColumn.DataPropertyName = "Job";
            this.jobDataGridViewTextBoxColumn.HeaderText = "Job";
            this.jobDataGridViewTextBoxColumn.Name = "jobDataGridViewTextBoxColumn";
            // 
            // messageBindingSource1
            // 
            this.messageBindingSource1.DataMember = "Message";
            this.messageBindingSource1.DataSource = this.kDataSet2;
            // 
            // kDataSet2
            // 
            this.kDataSet2.DataSetName = "KDataSet2";
            this.kDataSet2.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // messageBindingSource
            // 
            this.messageBindingSource.DataMember = "Message";
            this.messageBindingSource.DataSource = this.kDataSet1;
            // 
            // kDataSet1
            // 
            this.kDataSet1.DataSetName = "KDataSet1";
            this.kDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // studentInfoBindingSource2
            // 
            this.studentInfoBindingSource2.DataMember = "StudentInfo";
            this.studentInfoBindingSource2.DataSource = this.kDataSet;
            // 
            // kDataSet
            // 
            this.kDataSet.DataSetName = "KDataSet";
            this.kDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // studentInfoTableAdapter1
            // 
            this.studentInfoTableAdapter1.ClearBeforeFill = true;
            // 
            // messageTableAdapter
            // 
            this.messageTableAdapter.ClearBeforeFill = true;
            // 
            // messageTableAdapter1
            // 
            this.messageTableAdapter1.ClearBeforeFill = true;
            // 
            // all
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(717, 366);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "all";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "学生信息查询和编辑";
            this.Load += new System.EventHandler(this.all_Load);
            ((System.ComponentModel.ISupportInitialize)(this.masterDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentInfoBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentInfoBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.messageBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.kDataSet2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.messageBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.kDataSet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentInfoBindingSource2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.kDataSet)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private masterDataSet masterDataSet;
        private System.Windows.Forms.BindingSource studentInfoBindingSource;
        private masterDataSetTableAdapters.StudentInfoTableAdapter studentInfoTableAdapter;
        private System.Windows.Forms.BindingSource studentInfoBindingSource1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.DataGridView dataGridView1;
        private KDataSet kDataSet;
        private System.Windows.Forms.BindingSource studentInfoBindingSource2;
        private KDataSetTableAdapters.StudentInfoTableAdapter studentInfoTableAdapter1;
        private KDataSet1 kDataSet1;
        private System.Windows.Forms.BindingSource messageBindingSource;
        private KDataSet1TableAdapters.MessageTableAdapter messageTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn nameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn telDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sexDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn birthdayDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn qQDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn homeAddressDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn emailDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn jobDataGridViewTextBoxColumn;
        private KDataSet2 kDataSet2;
        private System.Windows.Forms.BindingSource messageBindingSource1;
        private KDataSet2TableAdapters.MessageTableAdapter messageTableAdapter1;
    }
}