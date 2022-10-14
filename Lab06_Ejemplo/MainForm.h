#pragma once
#include "Pokemon.h"

namespace Lab06Ejemplo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(121, 163);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"ofdEjemploArchivos";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(365, 229);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 84);
			this->listBox1->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 422);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		
		if (System::Windows::Forms::DialogResult::OK == openFileDialog1->ShowDialog()) {
			StreamReader^ InputStream = gcnew StreamReader(openFileDialog1->FileName);
			array<Pokemon^>^ misPokemon;

			if (InputStream != nullptr)
			{			
				misPokemon = gcnew array<Pokemon^>(10);
				int pokemonIndex = 0;

				while (String^ lineOfText = InputStream->ReadLine())
				{
					char separador = ',';
					array<String^>^ palabras = lineOfText->Split(separador);
					

					Pokemon^ miPokemon = gcnew Pokemon();
					miPokemon->generacion = palabras[0];
					miPokemon->pokemonName = palabras[1];
					
					misPokemon[pokemonIndex] = miPokemon;
					pokemonIndex++;
				}

				InputStream->Close(); 

				for (int i = 0; i < misPokemon->Length; i++) {
					if (misPokemon[i]) {
						listBox1->Items->Add(misPokemon[i]->pokemonName);
					}
					
				}
			}
			
		}	
	}

	};
}
