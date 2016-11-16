#include <windows.h>
#include <locale>
#include <iostream>
#include <vector>
#include "matrix.h"
#include "matrixOperations.h"

using namespace std;
int matrix::defaultSize = 5;
bool matrixRandomGeneration = true;
vector<reference_wrapper<matrix>> memory;

void main();

void showMatrix(matrix &object)
{
	for (int l = 1; l <= object.getHeight(); l++)
	{
		for (int c = 1; c <= object.getWidth(); c++)
		{
			cout << object.getCell(l, c) << "   ";
		}
		cout << endl;
	}
}

bool existMatrix(unsigned int index)
{
	if (index >= 0 && index < memory.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void operations()
{
	system("cls");
	setlocale(LC_ALL, "Russion");
	int act, m1, m2;
	cout << "�������� � ���������:" << endl << "1. �������������" << endl << "2. �����������" << endl << "3. �������� ������" << endl << "4. ��������� ������" << endl << "5. � �������� ����" << endl << endl;
	cout << "�������� �";
	cin >> act;
	system("cls");
	switch (act)
	{
	case 1:
		cout << "������� ����� ������� ��� ��������������: ";
		cin >> m1;
		m1--;
		if (existMatrix(m1))
		{
			system("cls");
			cout << "���������:" << endl;
			(memory[m1]).get().invert();
			showMatrix(memory[m1]);
			cout << endl;
			system("pause");
			operations();
		}
		else
		{
			operations();
		}
		break;

	case 2:
		cout << "������� ����� ������� ��� ����������: ";
		cin >> m2;
		m2--;
		if (existMatrix(m2))
		{
			system("cls");
			cout << "���������:" << endl;
			(memory[m2]).get().sort();
			showMatrix(memory[m2]);
			cout << endl;
			system("pause");
			operations();
		}
		else
		{
			operations();
		}
		break;

	case 3:
		cout << "������� ����� ������ ������� ��� ��������: ";
		cin >> m1;
		m1--;
		system("cls");
		cout << "������� ����� ������ ������� ��� ��������: ";
		cin >> m2;
		m2--;
		if (existMatrix(m2) && existMatrix(m1))
		{
			system("cls");
			if ((memory[m1]).get().getHeight() == (memory[m2]).get().getHeight() && (memory[m1]).get().getWidth() == (memory[m2]).get().getWidth())
			{
				cout << "���������:" << endl;
				matrix *newMatrix = new matrix(matrixOperations::sum(memory[m1], memory[m2]));
				showMatrix(*newMatrix);
				cout << endl;
				system("pause");
				operations();
			}
			else
			{
				cout << "�������� � ���������." << endl;
				system("pause");
				operations();
			}
		}
		else
		{
			cout << "��������." << endl;
			system("pause");
			operations();
		}
		break;

	case 4:
		cout << "������� ����� ������ ������� ��� ���������: ";
		cin >> m1;
		m1--;
		system("cls");
		cout << "������� ����� ������ ������� ��� ���������: ";
		cin >> m2;
		m2--;
		if (existMatrix(m2) && existMatrix(m1))
		{
			system("cls");
			matrix *newMatrix = new matrix(matrixOperations::multiplication(memory[m1], memory[m2]));
			if ((memory[m1]).get().getWidth() == (memory[m2]).get().getHeight())
			{
				cout << "���������:" << endl;
				showMatrix(*newMatrix);
				cout << endl;
				system("pause");
				operations();
			}
			else
			{
				cout << "�������� � ���������." << endl;
				system("pause");
				operations();
			}
		}
		else
		{
			cout << "��������." << endl;
			system("pause");
			operations();
		}
		break;

	case 5:
		main();
		break;

	default:
		operations();
	}
}

void list()
{
	cout << "������ ������." << endl << endl;
	if (memory.size() == 0)
	{
		cout << "������� ��� �� ���������." << endl << endl;
		Sleep(3000);
	}
	else
	{
		for (unsigned int i = 0; i < memory.size(); i++)
		{
			int n = i + 1;
			cout << "������� �" << n << endl;
			showMatrix(memory[i]);
			cout << endl;
		}
		cout << endl << endl;
		system("pause");
	}
}

void add()
{
	if (matrixRandomGeneration){
		matrix *newMatrix = new matrix;
		newMatrix->random();
		memory.push_back(*newMatrix);
		cout << "������� ������������� � ��������� � ������." << endl << endl;
		system("pause");
	}
	else
	{
		int l, c, input;
		cout << "������� ����� ������� ����������. ������������ ������ 100�100." << endl;
		cout << "������� ������: ";
		cin >> c;
		cout << "������� ������: ";
		cin >> l;
		if (l > 0 && c > 0 && l <= 100 && c <= 100)
		{
			matrix *newMatrix = new matrix(l, c);
			for (int inputLine = 1; inputLine <= l; inputLine++)
			{
				for (int inputColumn = 1; inputColumn <= c; inputColumn++)
				{
					system("cls");
					cout << "������ " << inputLine << "x" << inputColumn << ": ";
					cin >> input;
					newMatrix->setCell(inputLine, inputColumn, input);
					system("cls");
				}
			}
			memory.push_back(*newMatrix);
			cout << "������� ��������� � ������." << endl << endl;
			system("pause");
		}
	}
}

void settings()
{
	cout << "���������." << endl << endl;
	if (matrixRandomGeneration){
		cout << "������� ������������ ��������� �������." << endl;
	}
	else
	{
		cout << "������� ����������� �������." << endl;
	}
	cout << "����������� ������ �������: " << matrix::getDefaultSize() << "." << endl << endl;
	cout << "����������� ����� ���������� ������� 2, � ���� ������ ��������� � ����, �� 1." << endl << endl;
	int input;
	cin >> input;
	if (input == 2)
	{
		if (matrixRandomGeneration)
		{
			matrixRandomGeneration = false;
		}
		else
		{
			matrixRandomGeneration = true;
		}
		system("cls");
		cout << "����� ������." << endl << endl;
		Sleep(1000);
	}
	else
	{
		system("pause");
	}
}

void search()
{
	system("cls");
	cout << "�����." << endl << endl;
	int act;
	cout << "��������:" << endl << "1. � ���������� / ���������� ����������� ������" << endl << "2. � ������ ����������� ����� � ������ ������" << endl << "3. ��������� � ����" << endl << endl;
	cout << "�������� �";
	cin >> act;
	system("cls");
	switch (act)
	{
	case 1:
		if (memory.size() == 0)
		{
			cout << "������� ��� �� ���������." << endl << endl;
			Sleep(3000);
		}
		else
		{
			int bigger = 0, litter = 1000;
			bool bs = false, ls = false;
			for (unsigned int i = 0; i < memory.size(); i++)
			{
				int count = (memory[i]).get().count(1);
				if (count >= bigger)
				{
					bigger = count;
				}
				if (count <= litter)
				{
					litter = count;
				}
			}
			for (unsigned int i = 0; i < memory.size(); i++)
			{
				if ((memory[i]).get().count(1) == bigger && !bs)
				{
					bs = true;
					cout << "���������� ���������� ������:" << endl << endl;
					showMatrix(memory[i]);
				}
				if ((memory[i]).get().count(1) == litter && !ls)
				{
					ls = true;
					cout << "���������� ���������� ������:" << endl << endl;
					showMatrix(memory[i]);
				}
			}
			cout << endl << endl;
			system("pause");
		}
		search();
		break;

	case 2:
		if (memory.size() == 0)
		{
			cout << "������� ��� �� ���������." << endl << endl;
			Sleep(3000);
		}
		else
		{
			for (unsigned int i = 0; i < memory.size(); i++)
			{
				for (unsigned int k = 0; k < memory.size(); k++)
				{
					if ((memory[i]).get().getHeight() == (memory[k]).get().getHeight() && i != k)
					{
						bool show = true;
						for (int l = 1; l <= (memory[k]).get().getHeight(); l++)
						{
							if ((memory[i]).get().count(0, l) != (memory[k]).get().count(0, l) && show == true)
							{
								show = false;
							}
						}
						if (show){
							int t1 = i + 1, t2 = k + 1;
							cout << "� ������� �" << t1 << " ���������� ���������� 0 � ������ ������ � �������� �" << t2 << endl << endl;
						}
					}
				}
			}
			cout << endl << endl;
			system("pause");
		}
		search();
		break;

	case 3:
		main();
		break;

	default:
		search();
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	int act;
	cout << "������ �������." << endl << "���������� ������: " << memory.size() << endl << endl;
	cout << "0. ����� ������" << endl << "1. ������ ������" << endl << "2. �������� �������" << endl << "3. �������� � ���������" << endl << "4. ���������" << endl << endl;
	cout << "��������� �������� �";
	cin >> act;
	system("cls");
	switch (act)
	{
	case 0:
		search();
		main();
		break;

	case 1:
		list();
		main();
		break;

	case 2:
		add();
		main();
		break;

	case 3:
		operations();
		break;

	case 4:
		settings();
		main();
		break;

	default:
		cout << "������ �������� ���..." << endl << endl;
		Sleep(2500);
		main();
	}
}
