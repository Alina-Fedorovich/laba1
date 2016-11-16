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
	cout << "Операции с матрицами:" << endl << "1. Инвертировать" << endl << "2. Сортировать" << endl << "3. Сложение матриц" << endl << "4. Умножение матриц" << endl << "5. В основное меню" << endl << endl;
	cout << "Действие №";
	cin >> act;
	system("cls");
	switch (act)
	{
	case 1:
		cout << "Введите номер матрицы для инвертирования: ";
		cin >> m1;
		m1--;
		if (existMatrix(m1))
		{
			system("cls");
			cout << "Результат:" << endl;
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
		cout << "Введите номер матрицы для сортировки: ";
		cin >> m2;
		m2--;
		if (existMatrix(m2))
		{
			system("cls");
			cout << "Результат:" << endl;
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
		cout << "Введите номер первой матрицы для сложения: ";
		cin >> m1;
		m1--;
		system("cls");
		cout << "Введите номер второй матрицы для сложения: ";
		cin >> m2;
		m2--;
		if (existMatrix(m2) && existMatrix(m1))
		{
			system("cls");
			if ((memory[m1]).get().getHeight() == (memory[m2]).get().getHeight() && (memory[m1]).get().getWidth() == (memory[m2]).get().getWidth())
			{
				cout << "Результат:" << endl;
				matrix *newMatrix = new matrix(matrixOperations::sum(memory[m1], memory[m2]));
				showMatrix(*newMatrix);
				cout << endl;
				system("pause");
				operations();
			}
			else
			{
				cout << "Ошибочка с размерами." << endl;
				system("pause");
				operations();
			}
		}
		else
		{
			cout << "Ошибочка." << endl;
			system("pause");
			operations();
		}
		break;

	case 4:
		cout << "Введите номер первой матрицы для умножения: ";
		cin >> m1;
		m1--;
		system("cls");
		cout << "Введите номер второй матрицы для умножения: ";
		cin >> m2;
		m2--;
		if (existMatrix(m2) && existMatrix(m1))
		{
			system("cls");
			matrix *newMatrix = new matrix(matrixOperations::multiplication(memory[m1], memory[m2]));
			if ((memory[m1]).get().getWidth() == (memory[m2]).get().getHeight())
			{
				cout << "Результат:" << endl;
				showMatrix(*newMatrix);
				cout << endl;
				system("pause");
				operations();
			}
			else
			{
				cout << "Ошибочка с размерами." << endl;
				system("pause");
				operations();
			}
		}
		else
		{
			cout << "Ошибочка." << endl;
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
	cout << "Список матриц." << endl << endl;
	if (memory.size() == 0)
	{
		cout << "Матрицы ещё не добавлены." << endl << endl;
		Sleep(3000);
	}
	else
	{
		for (unsigned int i = 0; i < memory.size(); i++)
		{
			int n = i + 1;
			cout << "Матрица №" << n << endl;
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
		cout << "Матрица сгенерирована и добавлена в список." << endl << endl;
		system("pause");
	}
	else
	{
		int l, c, input;
		cout << "Включен режим ручного добавления. Максимальный размер 100х100." << endl;
		cout << "Введите ширину: ";
		cin >> c;
		cout << "Введите высоту: ";
		cin >> l;
		if (l > 0 && c > 0 && l <= 100 && c <= 100)
		{
			matrix *newMatrix = new matrix(l, c);
			for (int inputLine = 1; inputLine <= l; inputLine++)
			{
				for (int inputColumn = 1; inputColumn <= c; inputColumn++)
				{
					system("cls");
					cout << "Ячейка " << inputLine << "x" << inputColumn << ": ";
					cin >> input;
					newMatrix->setCell(inputLine, inputColumn, input);
					system("cls");
				}
			}
			memory.push_back(*newMatrix);
			cout << "Матрица добавлена в список." << endl << endl;
			system("pause");
		}
	}
}

void settings()
{
	cout << "Настройки." << endl << endl;
	if (matrixRandomGeneration){
		cout << "Матрицы генерируются случайным образом." << endl;
	}
	else
	{
		cout << "Матрицы заполняются вручную." << endl;
	}
	cout << "Стандартный размер матрицы: " << matrix::getDefaultSize() << "." << endl << endl;
	cout << "Переключить режим заполнения введите 2, а если хотите вернуться в меню, то 1." << endl << endl;
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
		cout << "Режим изменён." << endl << endl;
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
	cout << "Поиск." << endl << endl;
	int act;
	cout << "Критерии:" << endl << "1. С наибольшим / наименьшим количеством единиц" << endl << "2. С равным количеством нулей в каждой строке" << endl << "3. Вернуться в меню" << endl << endl;
	cout << "Действие №";
	cin >> act;
	system("cls");
	switch (act)
	{
	case 1:
		if (memory.size() == 0)
		{
			cout << "Матрицы ещё не добавлены." << endl << endl;
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
					cout << "Наибольшее количество единиц:" << endl << endl;
					showMatrix(memory[i]);
				}
				if ((memory[i]).get().count(1) == litter && !ls)
				{
					ls = true;
					cout << "Наименьшее количество единиц:" << endl << endl;
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
			cout << "Матрицы ещё не добавлены." << endl << endl;
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
							cout << "В матрице №" << t1 << " одинаковое количество 0 в каждой строке с матрицей №" << t2 << endl << endl;
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
	cout << "Булевы матрицы." << endl << "Количество матриц: " << memory.size() << endl << endl;
	cout << "0. Поиск матриц" << endl << "1. Список матриц" << endl << "2. Добавить матрицу" << endl << "3. Операции с матрицами" << endl << "4. Настройки" << endl << endl;
	cout << "Выполнить действие №";
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
		cout << "Такого действия нет..." << endl << endl;
		Sleep(2500);
		main();
	}
}
