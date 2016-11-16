#include <iostream>

using namespace std;

class matrixOperations
{

private:
	matrixOperations(){};

public:

	static matrix sum(matrix &object1, matrix &object2) // Логическое сложение
	{
		matrix object3(object1.getHeight(), object1.getHeight());
		for (int l = 1; l <= object3.getHeight(); l++)
		{
			for (int c = 1; c <= object3.getWidth(); c++)
			{
				bool value = (object1.getCell(l, c) | object2.getCell(l, c));
				object3.setCell(l, c, value);
			}
		}
		return object3;
	}

	static matrix multiplication(matrix &object1, matrix &object2) // Логическое умножение
	{
		matrix object3(object1.getHeight(), object2.getWidth());
		for (int i = 1; i <= object1.getHeight(); i++)
		{
			for (int j = 1; j <= object2.getWidth(); j++)
			{
				object3.setCell(i, j, false);
				for (int k = 1; k <= object1.getWidth(); k++)
				{
					bool value = (object1.getCell(i, k) & object2.getCell(k, j));
					object3.setCell(i, j, value);
				}
			}
		}
		return object3;
	}
};