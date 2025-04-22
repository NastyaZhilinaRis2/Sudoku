#include "MainForm.h"
#include <Windows.h>
#include "PartyGame.h"
#include "Game.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace Sudoku; // Название проекта

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    srand(time(0));
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm);

    return 0;

}
extern PartyGame newGame;
System::Void Sudoku::MainForm::button_lightLvl_Click(System::Object^ sender, System::EventArgs^ e)
{
    newGame.setLvl(1, 9);//создание игры легкого уровня с размером поля 9 на 9
    Game^ game = gcnew Game();
    game->Show();
}
System::Void Sudoku::MainForm::button_middleLvl_Click(System::Object^ sender, System::EventArgs^ e)
{
    newGame.setLvl(2, 9);//создание игры среднего уровня с размером поля 9 на 9
    Game^ game = gcnew Game();
    game->Show();
}
System::Void Sudoku::MainForm::button_heavyLvl_Click(System::Object^ sender, System::EventArgs^ e)
{
    newGame.setLvl(3, 9);//создание игры тяжелого уровня с размером поля 9 на 9
    Game^ game = gcnew Game();
    game->Show();
}
System::Void Sudoku::MainForm::button_openSave_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string line, time;
    int lvl, size, errors;
    std::vector<std::vector<int>> matrixSolving;
    std::vector<std::vector<int>> matrixField;
    std::vector<std::vector<int>> maskField;
    std::vector<int> row;
    // Чтение файла
    try
    {
        std::ifstream file("Saved field.txt");
        if (file.is_open())
        {
            if (getline(file, line))
            {
                System::String^ lineCS = gcnew System::String(line.c_str());
                lvl = Convert::ToInt32(lineCS);
                if (getline(file, line))
                {
                    System::String^ lineCS = gcnew System::String(line.c_str());
                    size = Convert::ToInt32(lineCS);
                    if (getline(file, line))
                    {
                        System::String^ lineCS = gcnew System::String(line.c_str());
                        errors = Convert::ToInt32(lineCS);
                        if (getline(file, line))
                        {
                            time = line;
                        }
                    }
                }
            }
            //для матрицы matrixSolving
            for (int i = 0; i < size; i++)
            {
                if (getline(file, line))
                {
                    std::stringstream ss(line);
                    int num;
                    while (ss >> num)
                    {
                        row.push_back(num);
                    }
                    matrixSolving.push_back(row);
                    row.clear();
                }
            } 
            //для матрицы matrixField
            for (int i = 0; i < size; i++)
            {
                if (getline(file, line))
                {
                    std::stringstream ss(line);
                    int num;
                    while (ss >> num)
                    {
                        row.push_back(num);
                    }
                    matrixField.push_back(row);
                    row.clear();
                }
            }
            //для матрицы maskField
            for (int i = 0; i < size; i++)
            {
                if (getline(file, line))
                {
                    std::stringstream ss(line);
                    int num;
                    while (ss >> num)
                    {
                        row.push_back(num);
                    }
                    maskField.push_back(row);
                    row.clear();
                }
            }
            file.close();
        }
        else
        {
            Console::WriteLine("Не удалось открыть файл.");
        }
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка: " + ex->Message);
    }

    newGame.setLvl(lvl, size);//создание игры lvl уровня с размером поля size на size
    newGame.setErrors(errors);
    newGame.setTime(time);
    newGame.insertSaveField(matrixSolving, matrixField, maskField);
    Game^ game = gcnew Game();
    game->Show();
}
