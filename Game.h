#pragma once

namespace Sudoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
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
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_content;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label_Head;
	private: System::Windows::Forms::Panel^ panel_game;
	private: System::Windows::Forms::Button^ button_exit;


	private: System::Windows::Forms::Label^ label_time;
	private: System::Windows::Forms::Label^ label_timeHead;
	private: System::Windows::Forms::Button^ button_save;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ label_errors;

	private: System::Windows::Forms::Label^ errorsHeader;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->panel_content = (gcnew System::Windows::Forms::Panel());
			this->label_errors = (gcnew System::Windows::Forms::Label());
			this->errorsHeader = (gcnew System::Windows::Forms::Label());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->label_time = (gcnew System::Windows::Forms::Label());
			this->label_timeHead = (gcnew System::Windows::Forms::Label());
			this->panel_game = (gcnew System::Windows::Forms::Panel());
			this->label_Head = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel_content->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_content
			// 
			this->panel_content->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_content->Controls->Add(this->label_errors);
			this->panel_content->Controls->Add(this->errorsHeader);
			this->panel_content->Controls->Add(this->button_save);
			this->panel_content->Controls->Add(this->button_exit);
			this->panel_content->Controls->Add(this->label_time);
			this->panel_content->Controls->Add(this->label_timeHead);
			this->panel_content->Controls->Add(this->panel_game);
			this->panel_content->Controls->Add(this->label_Head);
			this->panel_content->Location = System::Drawing::Point(12, 12);
			this->panel_content->Name = L"panel_content";
			this->panel_content->Size = System::Drawing::Size(736, 644);
			this->panel_content->TabIndex = 1;
			// 
			// label_errors
			// 
			this->label_errors->AutoSize = true;
			this->label_errors->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_errors->Location = System::Drawing::Point(91, 69);
			this->label_errors->Name = L"label_errors";
			this->label_errors->Size = System::Drawing::Size(31, 20);
			this->label_errors->TabIndex = 7;
			this->label_errors->Text = L"0/3";
			// 
			// errorsHeader
			// 
			this->errorsHeader->AutoSize = true;
			this->errorsHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->errorsHeader->Location = System::Drawing::Point(12, 69);
			this->errorsHeader->Name = L"errorsHeader";
			this->errorsHeader->Size = System::Drawing::Size(73, 20);
			this->errorsHeader->TabIndex = 6;
			this->errorsHeader->Text = L"Ошибки:";
			// 
			// button_save
			// 
			this->button_save->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button_save->BackColor = System::Drawing::Color::DarkKhaki;
			this->button_save->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_save->FlatAppearance->BorderSize = 0;
			this->button_save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_save->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_save->Location = System::Drawing::Point(282, 598);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(167, 35);
			this->button_save->TabIndex = 2;
			this->button_save->Text = L"Сохранить";
			this->button_save->UseVisualStyleBackColor = false;
			this->button_save->Click += gcnew System::EventHandler(this, &Game::button_save_Click);
			// 
			// button_exit
			// 
			this->button_exit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_exit->Location = System::Drawing::Point(16, 598);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(120, 35);
			this->button_exit->TabIndex = 1;
			this->button_exit->Text = L"Назад";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &Game::button_exit_Click);
			// 
			// label_time
			// 
			this->label_time->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label_time->AutoSize = true;
			this->label_time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_time->Location = System::Drawing::Point(546, 598);
			this->label_time->Name = L"label_time";
			this->label_time->Size = System::Drawing::Size(71, 20);
			this->label_time->TabIndex = 3;
			this->label_time->Text = L"00:00:00";
			// 
			// label_timeHead
			// 
			this->label_timeHead->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label_timeHead->AutoSize = true;
			this->label_timeHead->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_timeHead->Location = System::Drawing::Point(474, 598);
			this->label_timeHead->Name = L"label_timeHead";
			this->label_timeHead->Size = System::Drawing::Size(66, 20);
			this->label_timeHead->TabIndex = 2;
			this->label_timeHead->Text = L"Время: ";
			// 
			// panel_game
			// 
			this->panel_game->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_game->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel_game->Location = System::Drawing::Point(16, 92);
			this->panel_game->Name = L"panel_game";
			this->panel_game->Size = System::Drawing::Size(700, 500);
			this->panel_game->TabIndex = 1;
			// 
			// label_Head
			// 
			this->label_Head->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_Head->Font = (gcnew System::Drawing::Font(L"Mistral", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Head->Location = System::Drawing::Point(6, 25);
			this->label_Head->Name = L"label_Head";
			this->label_Head->Size = System::Drawing::Size(727, 64);
			this->label_Head->TabIndex = 0;
			this->label_Head->Text = L"Сложность:";
			this->label_Head->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &Game::timer_Tick);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Ivory;
			this->ClientSize = System::Drawing::Size(760, 668);
			this->Controls->Add(this->panel_content);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Игра";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			this->panel_content->ResumeLayout(false);
			this->panel_content->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
public: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
public: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e);
public: System::Void Field_Enter(System::Object^ sender, System::EventArgs^ e);
public: System::Void InputOptions_MouseClick(System::Object^ sender, System::EventArgs^ e);
public: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e);
public: System::Void СreatingFieldGrid(int middleX, int middleY);
public: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);
public: System::Void closeForm();
};
}
