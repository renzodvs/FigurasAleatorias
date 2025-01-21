#pragma once

#include "Moneda.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		CMoneda* oMoneda;
		bool agregar;
	private: System::Windows::Forms::PictureBox^  PbxCuadrado2;
	private: System::Windows::Forms::Button^  btn_Agregar;
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::PictureBox^  pbxMoneda;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			oMoneda = new CMoneda(50,50);
			agregar = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pbxMoneda = (gcnew System::Windows::Forms::PictureBox());
			this->PbxCuadrado2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_Agregar = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxMoneda))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PbxCuadrado2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pbxMoneda
			// 
			this->pbxMoneda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxMoneda.Image")));
			this->pbxMoneda->Location = System::Drawing::Point(139, 214);
			this->pbxMoneda->Name = L"pbxMoneda";
			this->pbxMoneda->Size = System::Drawing::Size(628, 159);
			this->pbxMoneda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbxMoneda->TabIndex = 0;
			this->pbxMoneda->TabStop = false;
			this->pbxMoneda->Visible = false;
			// 
			// PbxCuadrado2
			// 
			this->PbxCuadrado2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PbxCuadrado2.Image")));
			this->PbxCuadrado2->Location = System::Drawing::Point(150, 450);
			this->PbxCuadrado2->Name = L"PbxCuadrado2";
			this->PbxCuadrado2->Size = System::Drawing::Size(628, 159);
			this->PbxCuadrado2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PbxCuadrado2->TabIndex = 1;
			this->PbxCuadrado2->TabStop = false;
			this->PbxCuadrado2->Visible = false;
			// 
			// btn_Agregar
			// 
			this->btn_Agregar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_Agregar->Location = System::Drawing::Point(43, 60);
			this->btn_Agregar->Name = L"btn_Agregar";
			this->btn_Agregar->Size = System::Drawing::Size(311, 105);
			this->btn_Agregar->TabIndex = 2;
			this->btn_Agregar->Text = L"Cambiar diseño del cubo";
			this->btn_Agregar->UseVisualStyleBackColor = false;
			this->btn_Agregar->Click += gcnew System::EventHandler(this, &MyForm::btn_Agregar_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Location = System::Drawing::Point(43, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(311, 96);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Arreglar Posicion";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1368, 1312);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btn_Agregar);
			this->Controls->Add(this->PbxCuadrado2);
			this->Controls->Add(this->pbxMoneda);
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"MyForm";
			this->Text = L"Transformaciones en el plano";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->DoubleClick += gcnew System::EventHandler(this, &MyForm::MyForm_DoubleClick);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxMoneda))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PbxCuadrado2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^Canvas;
		Canvas = this->CreateGraphics();
		BufferedGraphicsContext^Espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^MiBufer = Espacio->Allocate(Canvas, this->ClientRectangle);
		MiBufer->Graphics->Clear(Color::LightCyan);
		if (agregar)
		{
			oMoneda->dibujar(MiBufer, pbxMoneda->Image);
			oMoneda->Cambiar(MiBufer);
		}
		else
		{
			oMoneda->dibujar(MiBufer, PbxCuadrado2->Image);
			oMoneda->Cambiar(MiBufer);
		}
		MiBufer->Render(Canvas);
		delete MiBufer;
		delete Espacio;
		delete Canvas;

	}
	private: System::Void MyForm_Click(System::Object^  sender, System::EventArgs^  e) {
		

	}
	private: System::Void MyForm_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {		
	}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

}
private: System::Void btn_Agregar_Click(System::Object^  sender, System::EventArgs^  e) {
	if (agregar == false)
	{
		agregar = true;
	}
	else
	{
		agregar = false;
	}

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	oMoneda->Set_X(50);
	oMoneda->Set_Y(100);
}
};
}
