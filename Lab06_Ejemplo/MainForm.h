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
			misPokemon = gcnew array<Pokemon^>(ARRAY_SIZE);
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
	private: System::Windows::Forms::Button^ ObtenerArchivo;
	protected:

	private: System::Windows::Forms::OpenFileDialog^ ofdEjemploArchivos;
	private: System::Windows::Forms::ListBox^ lstNombres;
	private: System::Windows::Forms::TextBox^ txtDescription;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::ComponentModel::IContainer^ components;


	protected:

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
			this->ObtenerArchivo = (gcnew System::Windows::Forms::Button());
			this->ofdEjemploArchivos = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lstNombres = (gcnew System::Windows::Forms::ListBox());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->SuspendLayout();
			// 
			// ObtenerArchivo
			// 
			this->ObtenerArchivo->Location = System::Drawing::Point(113, 98);
			this->ObtenerArchivo->Margin = System::Windows::Forms::Padding(2);
			this->ObtenerArchivo->Name = L"ObtenerArchivo";
			this->ObtenerArchivo->Size = System::Drawing::Size(56, 19);
			this->ObtenerArchivo->TabIndex = 0;
			this->ObtenerArchivo->Text = L"Cargar Archivo";
			this->ObtenerArchivo->UseVisualStyleBackColor = true;
			this->ObtenerArchivo->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// ofdEjemploArchivos
			// 
			this->ofdEjemploArchivos->FileName = L"ofdEjemploArchivos";
			// 
			// lstNombres
			// 
			this->lstNombres->FormattingEnabled = true;
			this->lstNombres->Location = System::Drawing::Point(327, 48);
			this->lstNombres->Margin = System::Windows::Forms::Padding(2);
			this->lstNombres->Name = L"lstNombres";
			this->lstNombres->Size = System::Drawing::Size(91, 69);
			this->lstNombres->TabIndex = 1;
			this->lstNombres->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lstNombres_SelectedIndexChanged);
			// 
			// txtDescription
			// 
			this->txtDescription->Location = System::Drawing::Point(327, 154);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(123, 85);
			this->txtDescription->TabIndex = 2;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 343);
			this->Controls->Add(this->txtDescription);
			this->Controls->Add(this->lstNombres);
			this->Controls->Add(this->ObtenerArchivo);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		array<Pokemon^>^ misPokemon;
		int ARRAY_SIZE = 10;
		int pokemonQty = 0;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (System::Windows::Forms::DialogResult::OK == ofdEjemploArchivos->ShowDialog()) {
			StreamReader^ inputStream = gcnew StreamReader(ofdEjemploArchivos->FileName);

			if (inputStream != nullptr) {
				String ^ linea = inputStream->ReadLine();
				while (linea && (pokemonQty < ARRAY_SIZE))  {

					array<String^>^ datos = linea->Split(',');
					Pokemon^ myPokemon = gcnew Pokemon();
					myPokemon->setGeneration(datos[0]);
					myPokemon->setName(datos[1]);
					myPokemon->setType(datos[2]);

					misPokemon[pokemonQty] = myPokemon;

					linea = inputStream->ReadLine();
					pokemonQty++;
				}
			}
			inputStream->Close();

			for (int i = 0; i < pokemonQty; i++) {
				lstNombres->Items->Add(misPokemon[i]->getName());
			}
		}
		

	}

	private: System::Void lstNombres_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (lstNombres->SelectedIndex >= 0) {
			String^ pokeInfo = "Nombre: " + misPokemon[lstNombres->SelectedIndex]->getName() + "\r\n"
			+" Generación: " + misPokemon[lstNombres->SelectedIndex]->getGeneration() + "\r\n"
			+" Tipo: " + misPokemon[lstNombres->SelectedIndex]->getType();

			txtDescription->Text = pokeInfo;
		}
	}
};
}
