#include <vector>
#include <iostream>

using namespace std;




int main()
{
	int dimX, dimY;
	while (cin >> dimX >> dimY)
	{
		vector<vector<int>> matriz(dimX,vector<int> (dimY));
		
		for (int i = 0; i < dimX; i++)
			for (int j = 0; j < dimY; j++)
				cin >> matriz[i][j];

		int numConsultas;
		cin >> numConsultas;
		for (int i = 0; i < numConsultas; i++)
		{

		}
	}
}

