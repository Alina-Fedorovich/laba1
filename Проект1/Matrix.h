#include <iostream>
#include <ctime>
using namespace std;

class matrix
{

	static int defaultSize;

private:
	const bool defalutValue = 0;
	int height;
	int width;
	bool **content = NULL;

	void generateMatrix(int lines, int columns) // ����������� ������� ��� �������� ������� 
	{
		this->content = new bool *[lines];

		// �������� ������������ �������
		for (int i = 0; i < lines; i++)
		{
			content[i] = new bool[columns];
		}

		// ��������� ����������� ��������
		for (int l = 0; l < lines; l++)
		{
			for (int c = 0; c < columns; c++)
			{
				setCell(l, c, defalutValue);
			}
		}

		this->setSize(lines, columns);
	}

	void generateMatrix() // �� ������, ���� ���������� ������� ������� ����������� ��������
	{
		generateMatrix(this->defaultSize, this->defaultSize);
	}

	void setSize(int lines, int columns) // ��������� �������� �� ���������
	{
		this->height = lines;
		this->width = columns;
	}

	bool correctCell(int line, int columns) // �������� �� ������������� ������
	{
		return (line <= this->getHeight() && line > 0 && columns <= this->getWidth() && columns > 0);
	}



public:

	// GET || SET

	static int getDefaultSize()
	{
		return defaultSize;
	}

	int getWidth()
	{
		return width;
	}

	int getHeight()
	{
		return height;
	}

	bool getCell(int line, int column) // ���������� ������
	{
		if (this->correctCell(line, column)){
			line--;
			column--;
			return content[line][column];
		}
		else
		{
			return false;
		}
	}

	void setCell(int line, int column, int value) // ������������� �������� ������
	{
		if (this->correctCell(line, column)){
			bool newValue;
			if (value >= 1)
			{
				newValue = true;
			}
			else
			{
				newValue = false;
			}
			setCell(line, column, newValue);
		}
	}

	void setCell(int line, int column, bool value) // ������������� �������� ������
	{
		if (this->correctCell(line, column)){
			line--;
			column--;
			content[line][column] = value;
		}
	}

	// ��������

	void invert() // �������������� �������
	{
		for (int l = 1; l <= this->getHeight(); l++)
		{
			for (int c = 1; c <= this->getWidth(); c++)
			{
				this->setCell(l, c, !this->getCell(l, c));
			}
		}
	}

	void random() // ���������� ������� ���������� ����������
	{
		for (int l = 1; l <= this->getHeight(); l++)
		{
			for (int c = 1; c <= this->getWidth(); c++)
			{
				int value = rand() % 2;
				this->setCell(l, c, value);
			}
		}
	}

	int count(bool target) // ���������� ���������
	{
		int counter = 0;
		for (int l = 1; l <= this->getHeight(); l++)
		{
			for (int c = 1; c <= this->getWidth(); c++)
			{
				if (this->getCell(l, c) == target)
				{
					counter++;
				}
			}
		}
		return counter;
	}

	int count(bool target, int line) // ���������� ���������
	{
		int counter = 0;
		for (int c = 1; c <= this->getWidth(); c++)
		{
			if (this->getCell(line, c) == target)
			{
				counter++;
			}
		}
		return counter;
	}

	void sort() // ���������� � ������������������ �������
	{

		for (int l = 1; l <= this->getHeight(); l++)
		{
			int count = this->count(0, l);
			for (int c = 1; c <= this->getWidth(); c++)
			{
				if (count > 0)
				{
					this->setCell(l, c, 0);
					count--;
				}
				else
				{
					this->setCell(l, c, 1);
				}
			}
		}
	}

	// ������������

	matrix() // ��������� ��� ��������� ��������
	{
		this->generateMatrix();
	}

	matrix(int lines, int columns) // ��������� � �������� ��������
	{
		this->generateMatrix(lines, columns);
	}

	matrix(matrix &object) // �����������
	{
		this->generateMatrix(object.getHeight(), object.getWidth());
		for (int l = 1; l <= object.getHeight(); l++)
		{
			for (int c = 1; c <= object.getWidth(); c++)
			{
				this->setCell(l, c, object.getCell(l, c));
			}
		}
	}

	~matrix() // ��������
	{
		for (int i = 0; i < getHeight(); i++) {
			delete[] content[i];
		}
		delete[] content;
	}
};

