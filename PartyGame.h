#pragma once
#ifndef PARTYGAME_H
#define PARTYGAME_H
#include <vector>
#include <iostream>
class PartyGame
{
private:
	int difficultyLvl;//уровень сложности
	int size;//размер поля
	int sumSolush;
	int errors;
	std::string time;
	std::pair<int, int> currentСell;
	std::vector<std::vector<int>> matrixSolving;//матрица поля (решенная)
	std::vector<std::vector<int>> matrixField;//матрица поля
	std::vector<std::vector<int>> maskField;//маска поля
public:
	PartyGame();
	/*ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ*/
	void setTime();
	void setTime(std::string time);
	std::string getTime();
	bool haveFullField();
	void setLvl(int difficultyLvl, int size);
	int getLvl();
	System::String^ getLvlName();
	void setCurrentСell(int row, int col);
	std::pair<int, int> getCurrentСell();
	int getCellValue(int row, int col);
	void setCellValue(int row, int col, int value);
	void setErrors();
	void setErrors(int err);
	int getErrors();
	int getSize();
	bool haveEmptyCells();
	void insertSaveField(std::vector<std::vector<int>> matrixSolving, std::vector<std::vector<int>> matrixField, std::vector<std::vector<int>> maskField);
	std::vector<std::vector<int>> getMatrixSolving();
	std::vector<std::vector<int>> getMatrixField();
	std::vector<std::vector<int>> getMaskField();
	void deleteField();

	/*ГЕНЕРАЦИЯ ЗАДАНИЯ*/
	void generatingTasks(System::Windows::Forms::Panel^ panel_game, System::Windows::Forms::Form^ form);//генерация в целом задания
	void generatingField();//изначальная генерация поля

	/////РАЗНООБРАЗИЕ ПЕРЕСТАНОВОК СТРОК(СТОЛБЦОВ) ПОЛЯ/////
	void transposition();//транспонирование поля (матрицы)
	void exchangingTwoLines(int row1, int row2);//обмен двух строк поля (матрицы)
	void exchangingTwoColumns(int column1, int column2);//обмен двух столбцов поля (матрицы)
	void exchangingTwoDistrictsHorizontally(int district1, int district2);//обмен двух районов по горизонтали поля (матрицы)
	void exchangingTwoDistrictsVertically(int district1, int district2);//обмен двух районов по вертикали поля (матрицы)
	/////УДАЛЕНИЕ ЯЧЕЕК ПОЛЯ/////
	void deleteCell();

	/*РАЗМЕЩЕНИЕ ИГРОВОГО ПОЛЯ*/
	void printFieldStart(System::Windows::Forms::Panel^ panel_game);

	/*РЕШЕНИЕ СУДОКУ*/
	int solve();
	std::vector<int> isValid(int col, int row);
};
static int randomNumber(int border1, int border2);
#endif