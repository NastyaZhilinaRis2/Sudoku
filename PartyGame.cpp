#include "PartyGame.h"
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Game.h"

PartyGame newGame;
PartyGame::PartyGame()
{
	errors = 0;
}
void PartyGame::setTime()
{
	time = "";
}
void PartyGame::setTime(std::string time)
{
	this->time = time;
}
std::string PartyGame::getTime()
{
	return time;
}
bool PartyGame::haveFullField()
{
	if (matrixSolving.size() > 0) return true;
	else return false;
}
void PartyGame::setLvl(int difficultyLvl, int size)
{
	this->difficultyLvl = difficultyLvl;
	this->size = size;
}
int PartyGame::getLvl()
{
	return difficultyLvl;
}
System::String^ PartyGame::getLvlName()
{
	switch (getLvl())
	{
	case 1: return "�����"; break;
	case 2: return "�������"; break;
	case 3: return "������"; break;
	}
}
void PartyGame::setCurrent�ell(int row, int col)
{
	current�ell.first = row;
	current�ell.second = col;
}
std::pair<int, int> PartyGame::getCurrent�ell()
{
	return current�ell;
}
int PartyGame::getCellValue(int row, int col)
{
	return matrixSolving[row][col];
}
void PartyGame::setCellValue(int row, int col, int value)
{
	matrixSolving[row][col] = matrixField[row][col] = value;
	maskField[row][col] = 1;
}
void PartyGame::setErrors()
{
	this->errors += 1;
}
void PartyGame::setErrors(int err)
{
	this->errors = err;
}
int PartyGame::getErrors()
{
	return errors;
}
int PartyGame::getSize()
{
	return size;
}
bool PartyGame::haveEmptyCells()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (maskField[i][j] == 0) return true;
		}
	}
	return false;
}
void PartyGame::insertSaveField(std::vector<std::vector<int>> matrixSolving, std::vector<std::vector<int>> matrixField, std::vector<std::vector<int>> maskField)
{
	this->matrixSolving = matrixSolving;
	this->matrixField = matrixField;
	this->maskField = maskField;
}
void PartyGame::deleteField()
{
	difficultyLvl = 0;
	size = 0;
	errors = 0;
	current�ell.first = -1; current�ell.second = -1;
	matrixSolving.clear();
	matrixField.clear();
	maskField.clear();
}
std::vector<std::vector<int>> PartyGame::getMatrixSolving()
{
	return matrixSolving;
}
std::vector<std::vector<int>> PartyGame::getMatrixField()
{
	return matrixField;
}
std::vector<std::vector<int>> PartyGame::getMaskField()
{
	return maskField;
}
void PartyGame::generatingTasks(System::Windows::Forms::Panel^ panel_game, System::Windows::Forms::Form^ form)
{
	setTime();
	generatingField();
	int NumberPermutations = 5;//���������� ������������ � �����
	for (int i = 0; i < NumberPermutations; i++)
	{
		int Exchanging = randomNumber(1, 5);//����� ������ ������������

		int index1, index2, bord1 = 0, bord2 = size - 1;
		if (Exchanging != 1) 
		{
			//���� ������������ 2 ��� 3
			if (Exchanging == 2 || Exchanging == 3)
			{
				index1 = randomNumber(bord1, bord2);
				bord2 = index1 / 3 * 3 + sqrt(size) - 1;
				bord1 = bord2 - sqrt(size) + 1;
				do
				{
					index2 = randomNumber(bord1, bord2);
				} while (index1 == index2);
			}
			//���� ������������ 4 ��� 5
			else if (Exchanging == 4 || Exchanging == 5)
			{
				bord2 = sqrt(size) - 1;
				index1 = randomNumber(bord1, bord2);
				do
				{
					index2 = randomNumber(bord1, bord2);
				} while (index1 == index2);
			}
		}
		switch (Exchanging)
		{
		case 1:
			transposition();
			break;
		case 2:
			exchangingTwoLines(index1, index2);
			break;
		case 3:
			exchangingTwoColumns(index1, index2);
			break;
		case 4:
			exchangingTwoDistrictsHorizontally(index1, index2);
			break;
		case 5:
			exchangingTwoDistrictsVertically(index1, index2);
			break;
		}
	}
	matrixSolving = matrixField;
	deleteCell();
	printFieldStart(panel_game);
}
void PartyGame::generatingField()
{
	matrixField.clear();
	for (int i = 1; i <= size; i++)
	{
		std::vector<int> Temp;
		switch (i)
		{
		case 1:
		{
			for (int j = 1; j <= size; j++) Temp.push_back(j);
			break;
		}
		case 2:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 3 <= 9) Temp.push_back(j + 3);
				else Temp.push_back(j + 3 - 9);
			}
			break;
		}
		case 3:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 6 <= 9) Temp.push_back(j + 6);
				else Temp.push_back(j + 6 - 9);
			}
			break;
		}
		case 4:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 1 <= 9) Temp.push_back(j + 1);
				else Temp.push_back(j + 1 - 9);
			}
			break;
		}
		case 5:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 4 <= 9) Temp.push_back(j + 4);
				else Temp.push_back(j + 4 - 9);
			}
			break;
		}
		case 6:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 7 <= 9) Temp.push_back(j + 7);
				else Temp.push_back(j + 7 - 9);
			}
			break;
		}
		case 7:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 2 <= 9) Temp.push_back(j + 2);
				else Temp.push_back(j + 2 - 9);
			}
			break;
		}
		case 8:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 5 <= 9) Temp.push_back(j + 5);
				else Temp.push_back(j + 5 - 9);
			}
			break;
		}
		case 9:
		{
			for (int j = 1; j <= size; j++) {
				if (j + 8 <= 9) Temp.push_back(j + 8);
				else Temp.push_back(j + 8 - 9);
			}
			break;
		}
		}
		matrixField.push_back(Temp);
		Temp.clear();
	}
}
void PartyGame::transposition()
{
	std::vector<std::vector<int>> transposedMatrix(size, std::vector<int>(size, 0)); // ������� ������ ������� ��� ������ ����������������� �������
	// ���������������� �������
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			std::swap(matrixField[i][j], matrixField[j][i]);
		}
	}
}
void PartyGame::exchangingTwoLines(int row1, int row2)
{
	std::swap(matrixField[row1], matrixField[row2]);
}
void PartyGame::exchangingTwoColumns(int column1, int column2)
{
	for (int i = 0; i < size; i++)
	{
		std::swap(matrixField[i][column1], matrixField[i][column2]);
	}
}
void PartyGame::exchangingTwoDistrictsHorizontally(int district1, int district2)
{
	for (int i = 0; i < sqrt(size); i++)
	{
		exchangingTwoLines(district1 * sqrt(size) + i, district2 * sqrt(size) + i);
	}
}
void PartyGame::exchangingTwoDistrictsVertically(int district1, int district2)
{
	for (int i = 0; i < sqrt(size); i++)
	{
		exchangingTwoColumns(district1 * sqrt(size) + i, district2 * sqrt(size) + i);
	}
}
void PartyGame::deleteCell()
{
	int countEmptyCells, temp;
	int randIndex1, randIndex2;

	switch (difficultyLvl)
	{
	case 1: countEmptyCells = 25; break;
	case 2: countEmptyCells = 30; break;
	case 3: countEmptyCells = 35; break;
	}
	maskField = std::vector<std::vector<int>>(size, std::vector<int>(size, 1)); // ��������� �����
	for (int i = 0; i < countEmptyCells; i++)
	{
		do
		{
			randIndex1 = randomNumber(0, size - 1);
			randIndex2 = randomNumber(0, size - 1);
		} while (maskField[randIndex1][randIndex2] == 0);
		
		
		matrixField[randIndex1][randIndex2] = 0;//�������� ������ "��������� ����������� �������"
		maskField[randIndex1][randIndex2] = 0;//�������� ������ �����
		if (solve() > 1)//���� ������� �����
		{
			matrixField[randIndex1][randIndex2] = matrixSolving[randIndex1][randIndex2];//������� ����������
			maskField[randIndex1][randIndex2] = 1;
			i--;
		}
	}
}
void PartyGame::printFieldStart(System::Windows::Forms::Panel^ panel_game)
{
	for each (System::Windows::Forms::Control ^ control in panel_game->Controls) //��� ���� ��������� ������
	{
		System::Windows::Forms::TextBox^ tbCell = dynamic_cast<System::Windows::Forms::TextBox^>(control);
		if (tbCell != nullptr)
		{
			int i, j;
			System::Int32::TryParse(tbCell->Name[0].ToString(), i);
			System::Int32::TryParse(tbCell->Name[1].ToString(), j);
			if (matrixField[i][j] != 0) {
				tbCell->Text = matrixField[i][j].ToString();
				tbCell->Enabled = false;
			}
			else {
				tbCell->Text = "";
				tbCell->Enabled = true;
				tbCell->ReadOnly = true;
			}
		}
	}
}
static int randomNumber(int border1, int border2)
{
	border2 = border2 - border1 + 1;
	return rand() % border2 + border1;
}
std::vector<int> PartyGame::isValid(int col, int row)
{
	//0 - ���� �� ���, -1 - ���� ����
	std::vector<int> Temp = std::vector<int>(size, 0);;
	//�������� ������ � �������
	for (int i = 0; i < size; i++)
	{
		if(maskField[i][row] != 0)
			Temp[matrixField[i][row] - 1] = -1;
		if (maskField[col][i] != 0)
			Temp[matrixField[col][i] - 1] = -1;
	}
	//�������� �����������
	int miniSize = sqrt(size); // ������ �����������
	int startCol = (col / miniSize) * miniSize; // ��������� ������� �����������
	int startRow = (row / miniSize) * miniSize; // ��������� ������ �����������

	for (int i = startCol; i < startCol + miniSize; i++)
	{
		for (int j = startRow; j < startRow + miniSize; j++)
		{
			if (maskField[i][j] != 0)
			{
				Temp[matrixField[i][j] - 1] = -1;
			}
		}
	}
	for (int i = 0; i < Temp.size(); i++)
	{
		if (Temp[i] == 0)
		{
			Temp[i] = i + 1;
		}
	}
	Temp.erase(std::remove(Temp.begin(), Temp.end(), -1), Temp.end());
	return Temp;
}
int PartyGame::solve()
{
	sumSolush = 0;
	std::vector<int> valid;
	bool f = false;
	//������� �����
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//���� ����������� ������ - ������
			if (maskField[i][j] == 0)
			{
				f = true;
				valid = isValid(i, j);
				//�������� ��������� �������� ���� ������
				for (int k = 0; k < valid.size(); k++)
				{
					matrixField[i][j] = valid[k];
					maskField[i][j] = 1;
					solve();
				}
				maskField[i][j] = 0; // ���������� ������ � �������� ��������� ����� �������
				matrixField[i][j] = 0;
				return sumSolush;
			}
		}
	}
	if (!f) // ���� ��� ������ ������, �� ����� �������
	{
		sumSolush += 1; // ����������� ������� �������
		return sumSolush;
	}
	return sumSolush;
}