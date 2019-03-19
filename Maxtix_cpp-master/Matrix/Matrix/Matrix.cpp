#include "stdafx.h"
#include <iostream>

using namespace std;


class Matrix {
public:
	int row;
	int col;
	int ** matrix;
	Matrix() {
		cout << "Please input row and col: ";
		cin >> row >> col;
		matrix = new int *[row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new int[col];
		}
	}
	void crtMatrix(int ** pointer) {
		cout << "Input first matrix" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << "a(" << i << "," << j << "): ";
				cin >> pointer[i][j];
			}
		}
		cout << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << pointer[i][j] << " ";
			}
			cout << endl;
		}
	}
	void deleteMatrix(int ** pointer) {
		for (int i = 0; i < col; i++)
		{
			delete[] pointer[i];
		}
		delete[] pointer;
	};

	void addMatrix(Matrix second) 
	{
		if (row == second.row && col == second.col)
		{
			int ** result = new int *[row];
			for (int i = 0; i < row; i++)
			{
				result[i] = new int[col];
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					result[i][j] = matrix[i][j] + second.matrix[i][j];
				}
			};

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << result[i][j] << " ";
				}
				cout << endl;
			}

		}
		else
			cout << "Error!\n Try again.";
	}

	void subMatrix(Matrix second) {
		if (col == second.col && row == second.row)
		{
			int ** result = new int *[row];
			for (int i = 0; i < row; i++)
			{
				result[i] = new int[col];
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					result[i][j] = matrix[i][j] - second.matrix[i][j];
				}
			};

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << result[i][j] << " ";
				}
				cout << endl;
			}

		}
		else
			cout << "Error!";
	}
	void multMatrix(Matrix second) {
		if (col == second.row) {
			int ** result = new int *[row];
			for (int i = 0; i < row; i++)
			{
				result[i] = new int[second.col];
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < second.col; j++)
				{
					result[i][j] = 0;
				}
			}

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < second.col; j++)
				{
					for (int n = 0; n < second.row; i++)
					{
						result[i][j] += matrix[i][n] * second.matrix[n][j];
					}
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < second.col; j++)
				{
					cout << result[i][j] << " ";
				}
				cout << endl;
			}
		}
		else 
			cout << "Error" << endl;
		}
};

int main()
{
	cout << " It's a matrix calculator!" << endl << " What go you need to do?" << endl;
	cout << " 1 - for addition\n 2 - for subtraction\n 3 - for multiplication\n";
	int i;
	cin >> i;
	switch (i) {
	case 1:
	{
		Matrix first;
		first.crtMatrix(first.matrix);
		Matrix second;
		second.crtMatrix(second.matrix);
		cout << endl;
		first.addMatrix(second);
		first.deleteMatrix(first.matrix);
		second.deleteMatrix(second.matrix);
		return 0; 
	}

	case 2:
	{
		Matrix first;
		first.crtMatrix(first.matrix);
		Matrix second;
		second.crtMatrix(second.matrix);
		cout << endl;
		first.subMatrix(second);
		first.deleteMatrix(first.matrix);
		second.deleteMatrix(second.matrix);
		return 0;
	}
	case 3:
	{
		Matrix first;
		first.crtMatrix(first.matrix);
		Matrix second;
		second.crtMatrix(second.matrix);
		cout << endl;
		first.multMatrix(second);
		first.deleteMatrix(first.matrix);
		second.deleteMatrix(second.matrix);

		return 0;
	}
	default:
		break;
	}
}