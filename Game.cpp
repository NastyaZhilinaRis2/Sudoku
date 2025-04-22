#include "Game.h"
#include "TimerGame.h"
#include "PartyGame.h"
#include <fstream>
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>

extern PartyGame newGame;
TimerGame timerGame;
System::Void Sudoku::Game::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	closeForm();
}
System::Void Sudoku::Game::Game_Load(System::Object^ sender, System::EventArgs^ e)
{
	label_Head->Text = "Сложность: " + newGame.getLvlName();
	label_errors->Text = newGame.getErrors() + "/3";
	label_time->Text = gcnew System::String((newGame.getTime()).c_str());

	СreatingFieldGrid(panel_game->Size.Width / 2, panel_game->Size.Height / 2);
	Game^ game = gcnew Game();

	if (!newGame.haveFullField())
	{
		newGame.generatingTasks(panel_game, game);
		timerGame.setStartTime();
	}
	else
	{
		newGame.printFieldStart(panel_game);
		timerGame.setStartTime(newGame.getTime());
	}
	button_exit->Select();

	timer->Start();
}
System::Void Sudoku::Game::СreatingFieldGrid(int middleX, int middleY)
{
	int sizeMatrix = newGame.getSize();
	int sizeSquare = 38;
	int probel = 10;

	//координаты верхнего левого угла, от которого будет строиться поле
	int leftX = middleX - (sizeSquare * sizeMatrix + probel * 2) / 2;
	int leftY = middleY - (sizeSquare * sizeMatrix + probel * 2) / 2;
	int probelCountY = 0;
	//прорисовка таблицы
	for (int i = 0; i < sizeMatrix; i++)
	{
		int probelCountX = 0;
		for (int j = 0; j < sizeMatrix; j++)
		{
			System::Windows::Forms::TextBox^ textBox = gcnew System::Windows::Forms::TextBox();
			textBox->Location = System::Drawing::Point(leftX + sizeSquare * j + probelCountX, leftY + sizeSquare * i + probelCountY);
			textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			textBox->Name = i.ToString() + j.ToString();
			textBox->Size = System::Drawing::Size(38, 38);
			textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			textBox->BackColor = System::Drawing::Color::White;
			textBox->Anchor = System::Windows::Forms::AnchorStyles::Bottom |
				System::Windows::Forms::AnchorStyles::Top;
			
			textBox->Enter += gcnew System::EventHandler(this, &Sudoku::Game::Field_Enter);
			panel_game->Controls->Add(textBox);

			if (j == 2 || j == 5) probelCountX += 10;
		}
		if (i == 2 || i == 5) probelCountY += 10;
	}
	//прорисовка кнопок ответов
	int length = sizeSquare * sizeMatrix + probel * (sizeMatrix - 1);
	int startX = (panel_game->Size.Width - length) / 2;
	int startY = panel_game->Size.Height - sizeSquare - probel * 2;
	for (int i = 0; i < sizeMatrix; i++)
	{
		System::Windows::Forms::Button^ button = gcnew System::Windows::Forms::Button();
		button->Location = System::Drawing::Point(startX + sizeSquare * i + probel * i, startY);
		button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		button->Name = (i + 1).ToString();
		button->Size = System::Drawing::Size(38, 38);
		button->BackColor = System::Drawing::Color::DarkKhaki;
		button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
		button->Text = (i + 1).ToString();
		button->Click += gcnew System::EventHandler(this, &Sudoku::Game::InputOptions_MouseClick);
		panel_game->Controls->Add(button);
	}
}
System::Void Sudoku::Game::Field_Enter(System::Object^ sender, System::EventArgs^ e)
{
	TextBox^ tbCell = (TextBox^)sender;
	String^ nameTB = tbCell->Name;
	String^ textBoxName = newGame.getCurrentСell().first.ToString() + newGame.getCurrentСell().second.ToString();
	TextBox^ textBox = this->Controls->Find(textBoxName, true)->Length > 0
		? safe_cast<TextBox^>(this->Controls->Find(textBoxName, true)[0])
		: nullptr;
	if (textBox != nullptr)
	{
		textBox->BackColor = System::Drawing::Color::White;
	}
	int row, col;
	Int32::TryParse(nameTB[0].ToString(), row);
	Int32::TryParse(nameTB[1].ToString(), col);
	newGame.setCurrentСell(row, col);
	tbCell->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void Sudoku::Game::InputOptions_MouseClick(System::Object^ sender, System::EventArgs^ e)
{
	Button^ btnInputOptions = (Button^)sender;
	int row = newGame.getCurrentСell().first;
	int col = newGame.getCurrentСell().second;
	int value = Convert::ToInt32(btnInputOptions->Text);
	//если значение, которое должно стоять в сетке совпадает со значением, которое хотим ввести
	if (newGame.getCellValue(row, col) == value)
	{
		newGame.setCellValue(row, col, value);
		System::String^ name = row.ToString() + col.ToString();
		for each (System::Windows::Forms::Control ^ control in panel_game->Controls) //для всех контролов панели
		{
			System::Windows::Forms::TextBox^ tbCell = dynamic_cast<System::Windows::Forms::TextBox^>(control);
			if (tbCell != nullptr)
			{
				if (tbCell->Name == name)
				{
					tbCell->Text = value.ToString();
					tbCell->Enabled = false;
					break;
				}
			}
		}
		if (!newGame.haveEmptyCells())
		{
			MessageBox::Show("Вы выйграли!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
			closeForm();
		}
	}
	else
	{
		MessageBox::Show("Неверный ввод!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		newGame.setErrors();
		int countErr = newGame.getErrors();
		if (countErr <= 3)
		{
			label_errors->Text = countErr.ToString() + "/3";
		}
		else
		{
			MessageBox::Show("Игра окончена!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
			closeForm();
		}
	}
}
System::Void Sudoku::Game::button_save_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::vector<std::vector<int>> matrixSolving = newGame.getMatrixSolving();
	std::vector<std::vector<int>> matrixField = newGame.getMatrixField();
	std::vector<std::vector<int>> maskField = newGame.getMaskField();
	// Запись в файл
	try
	{
		std::ofstream file("Saved field.txt", std::ios::out);
		if (file.is_open())
		{
			file << newGame.getLvl() << "\n";
			file << newGame.getSize() << "\n";
			file << newGame.getErrors() << "\n";
			file << newGame.getTime() << "\n";
			for (int i = 0; i < newGame.getSize(); i++)
			{
				for (int j = 0; j < newGame.getSize(); j++)
				{
					file << matrixSolving[i][j] << " ";
				}
				file << "\n";
			}
			for (int i = 0; i < newGame.getSize(); i++)
			{
				for (int j = 0; j < newGame.getSize(); j++)
				{
					file << matrixField[i][j] << " ";
				}
				file << "\n";
			}
			for (int i = 0; i < newGame.getSize(); i++)
			{
				for (int j = 0; j < newGame.getSize(); j++)
				{
					file << maskField[i][j] << " ";
				}
				file << "\n";
			}
			file.close();
			MessageBox::Show("Сохранено!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("Не удалось открыть файл для записи.", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Ошибка: " + ex->Message, "Ошибка!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
	}
}
System::Void Sudoku::Game::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	label_time->Text = timerGame.getDifferenceTime();
	std::string time = msclr::interop::marshal_as<std::string>(label_time->Text);
	newGame.setTime(time);
}
System::Void Sudoku::Game::closeForm()
{
	timer->Stop();
	newGame.deleteField();
	timerGame.resetTime();
	this->Close();
}