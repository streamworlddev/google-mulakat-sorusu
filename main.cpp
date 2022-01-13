#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int>> Matrix;

vector<vector<int>> islandCoordinates;


bool CheckCoordinate(int y,int x)
{

	for (size_t i = 0; i < islandCoordinates.size(); i++)
	{
		if (y == islandCoordinates.at(i).at(0) && x == islandCoordinates.at(i).at(1))
			return true;
		
	}
	return false;
}

void FindPath(int y, int x, Matrix m)
{
	if (CheckCoordinate(y, x))
	{
		return;
	}

	islandCoordinates.push_back({ y,x });

	for (int ky = -1; ky < 2; ky++)
	{
		for (int kx = -1; kx < 2; kx++)
		{
			if (((kx == 0 && ky == 0) ||
				(kx != 0 && ky != 0) ||
				(x == 0 && kx == -1) ||
				(x == static_cast<int>(m.at(y).size()) - 1 && kx == 1) ||
				(y == 0 && ky == -1) ||
				(y == static_cast<int>(m.size()) -1 && ky == 1))
				)

			{
				continue;
			}
			
			if (m.at(y + ky).at(x + kx) == 1)
			{
				FindPath(y + ky, x + kx, m);
			}
			
		}
	}
}

int main()
{
	Matrix matrix = 
	{ 
		{1,0,0,0,1,0,1},
		{0,1,0,1,1,1,1},
		{0,0,1,1,1,0,0},
		{1,1,0,0,1,0,1},
		{1,0,1,1,0,0,1},
		{1,0,0,0,0,1,0},
		{1,0,0,0,1,1,1},
	};

	//ÝLK OLARAK BAÞLANGIÇ DEÐERLERÝNÝ YAZDIR
	cout << "BEFORE : " << endl;
	for (int y = 0; y < size(matrix); y++)
	{
		for (int x = 0; x < size(matrix[0]); x++)
		{
			cout << matrix[y][x] << " ";
		}
		cout << endl;
	}

	//SINIRA KOMÞU OLAN 1'LERÝ BUL
	for (int y = 0; y < size(matrix); y++)
	{
		for (int x = 0; x < size(matrix[0]); x++)
		{
			// Sýnýrda olan 1'e denk gelinirse;
			if ((y == 0 || y == size(matrix) - 1 || x == 0 || x == size(matrix[0]) - 1) &&
				 (matrix.at(y).at(x) == 1))
			{
				FindPath(y,x, matrix);
			}
		}
	}

	//BULUNAN KORDÝNATLAR HARÝCÝNDEKÝ 1'LERÝ 0'A ÇEVÝR
	for (int y = 0; y < size(matrix); y++)
	{
		for (int x = 0; x < size(matrix[0]); x++)
		{
			if (!CheckCoordinate(y, x))
				matrix.at(y).at(x) = 0;
		}
	}

	//SON DEÐERLERÝNÝ YAZDIR
	cout << "AFTER : " << endl;
	for (int y = 0; y < size(matrix); y++)
	{
		for (int x = 0; x < size(matrix[0]); x++)
		{
			cout << matrix[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}