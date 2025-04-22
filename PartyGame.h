#pragma once
#ifndef PARTYGAME_H
#define PARTYGAME_H
#include <vector>
#include <iostream>
class PartyGame
{
private:
	int difficultyLvl;//������� ���������
	int size;//������ ����
	int sumSolush;
	int errors;
	std::string time;
	std::pair<int, int> current�ell;
	std::vector<std::vector<int>> matrixSolving;//������� ���� (��������)
	std::vector<std::vector<int>> matrixField;//������� ����
	std::vector<std::vector<int>> maskField;//����� ����
public:
	PartyGame();
	/*��������������� ������*/
	void setTime();
	void setTime(std::string time);
	std::string getTime();
	bool haveFullField();
	void setLvl(int difficultyLvl, int size);
	int getLvl();
	System::String^ getLvlName();
	void setCurrent�ell(int row, int col);
	std::pair<int, int> getCurrent�ell();
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

	/*��������� �������*/
	void generatingTasks(System::Windows::Forms::Panel^ panel_game, System::Windows::Forms::Form^ form);//��������� � ����� �������
	void generatingField();//����������� ��������� ����

	/////������������ ������������ �����(��������) ����/////
	void transposition();//���������������� ���� (�������)
	void exchangingTwoLines(int row1, int row2);//����� ���� ����� ���� (�������)
	void exchangingTwoColumns(int column1, int column2);//����� ���� �������� ���� (�������)
	void exchangingTwoDistrictsHorizontally(int district1, int district2);//����� ���� ������� �� ����������� ���� (�������)
	void exchangingTwoDistrictsVertically(int district1, int district2);//����� ���� ������� �� ��������� ���� (�������)
	/////�������� ����� ����/////
	void deleteCell();

	/*���������� �������� ����*/
	void printFieldStart(System::Windows::Forms::Panel^ panel_game);

	/*������� ������*/
	int solve();
	std::vector<int> isValid(int col, int row);
};
static int randomNumber(int border1, int border2);
#endif