#pragma once

namespace Sudoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_content;
	protected:

	private: System::Windows::Forms::Button^ button_heavyLvl;
	protected:

	private: System::Windows::Forms::Button^ button_middleLvl;

	private: System::Windows::Forms::Button^ button_lightLvl;

	private: System::Windows::Forms::Label^ label_Head;
	private: System::Windows::Forms::Button^ button_openSave;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panel_content = (gcnew System::Windows::Forms::Panel());
			this->button_openSave = (gcnew System::Windows::Forms::Button());
			this->button_heavyLvl = (gcnew System::Windows::Forms::Button());
			this->button_middleLvl = (gcnew System::Windows::Forms::Button());
			this->button_lightLvl = (gcnew System::Windows::Forms::Button());
			this->label_Head = (gcnew System::Windows::Forms::Label());
			this->panel_content->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_content
			// 
			this->panel_content->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_content->Controls->Add(this->button_openSave);
			this->panel_content->Controls->Add(this->button_heavyLvl);
			this->panel_content->Controls->Add(this->button_middleLvl);
			this->panel_content->Controls->Add(this->button_lightLvl);
			this->panel_content->Controls->Add(this->label_Head);
			this->panel_content->Location = System::Drawing::Point(12, 12);
			this->panel_content->Name = L"panel_content";
			this->panel_content->Size = System::Drawing::Size(726, 537);
			this->panel_content->TabIndex = 0;
			// 
			// button_openSave
			// 
			this->button_openSave->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button_openSave->BackColor = System::Drawing::Color::Gray;
			this->button_openSave->FlatAppearance->BorderSize = 3;
			this->button_openSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_openSave->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_openSave->Location = System::Drawing::Point(59, 439);
			this->button_openSave->Name = L"button_openSave";
			this->button_openSave->Size = System::Drawing::Size(609, 60);
			this->button_openSave->TabIndex = 4;
			this->button_openSave->Text = L"Продолжить\?";
			this->button_openSave->UseVisualStyleBackColor = false;
			this->button_openSave->Click += gcnew System::EventHandler(this, &MainForm::button_openSave_Click);
			// 
			// button_heavyLvl
			// 
			this->button_heavyLvl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_heavyLvl->BackColor = System::Drawing::Color::Brown;
			this->button_heavyLvl->FlatAppearance->BorderSize = 3;
			this->button_heavyLvl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_heavyLvl->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_heavyLvl->Location = System::Drawing::Point(59, 309);
			this->button_heavyLvl->Name = L"button_heavyLvl";
			this->button_heavyLvl->Size = System::Drawing::Size(609, 57);
			this->button_heavyLvl->TabIndex = 3;
			this->button_heavyLvl->Text = L"Тяжёлая";
			this->button_heavyLvl->UseVisualStyleBackColor = false;
			this->button_heavyLvl->Click += gcnew System::EventHandler(this, &MainForm::button_heavyLvl_Click);
			// 
			// button_middleLvl
			// 
			this->button_middleLvl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_middleLvl->BackColor = System::Drawing::Color::Gold;
			this->button_middleLvl->FlatAppearance->BorderSize = 3;
			this->button_middleLvl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_middleLvl->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_middleLvl->Location = System::Drawing::Point(59, 244);
			this->button_middleLvl->Name = L"button_middleLvl";
			this->button_middleLvl->Size = System::Drawing::Size(609, 59);
			this->button_middleLvl->TabIndex = 2;
			this->button_middleLvl->Text = L"Средняя";
			this->button_middleLvl->UseVisualStyleBackColor = false;
			this->button_middleLvl->Click += gcnew System::EventHandler(this, &MainForm::button_middleLvl_Click);
			// 
			// button_lightLvl
			// 
			this->button_lightLvl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_lightLvl->BackColor = System::Drawing::Color::LawnGreen;
			this->button_lightLvl->FlatAppearance->BorderSize = 3;
			this->button_lightLvl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_lightLvl->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lightLvl->Location = System::Drawing::Point(59, 178);
			this->button_lightLvl->Name = L"button_lightLvl";
			this->button_lightLvl->Size = System::Drawing::Size(609, 60);
			this->button_lightLvl->TabIndex = 1;
			this->button_lightLvl->Text = L"Лёгкая";
			this->button_lightLvl->UseVisualStyleBackColor = false;
			this->button_lightLvl->Click += gcnew System::EventHandler(this, &MainForm::button_lightLvl_Click);
			// 
			// label_Head
			// 
			this->label_Head->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label_Head->Font = (gcnew System::Drawing::Font(L"Mistral", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Head->Location = System::Drawing::Point(3, 75);
			this->label_Head->Name = L"label_Head";
			this->label_Head->Size = System::Drawing::Size(720, 64);
			this->label_Head->TabIndex = 0;
			this->label_Head->Text = L"Новая игра:";
			this->label_Head->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::Ivory;
			this->ClientSize = System::Drawing::Size(750, 561);
			this->Controls->Add(this->panel_content);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Судоку \"Серые клеточки\"";
			this->panel_content->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_lightLvl_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_middleLvl_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_heavyLvl_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_openSave_Click(System::Object^ sender, System::EventArgs^ e);
};
}
