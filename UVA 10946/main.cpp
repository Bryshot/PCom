#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dfs(vector<vector<char>> &mapa, int x, int y, char elem)
{
	
	mapa[x][y] = '.';
	int hoyo = 1;
	if (x == 0 && y == 0)
	{
		if(mapa[x+1][y]== elem)
				hoyo += dfs(mapa, x+1, y,elem);
		if(mapa[x ][y + 1] == elem)
				hoyo += dfs(mapa, x, y+1,elem);
	}
	else if (x == 0)
	{
		if (y != mapa[0].size()-1)
			if (mapa[x][y + 1] == elem) hoyo += dfs(mapa, x, y + 1, elem);
		
		if (mapa[x + 1][y] == elem)
			hoyo += dfs(mapa, x + 1, y, elem);
		if (mapa[x][y -1] == elem)
			hoyo += dfs(mapa, x, y-1,elem);
	}
	else if (y == 0)
	{

		if (x != mapa.size()-1)
			if (mapa[x+1][y] == elem) hoyo += dfs(mapa, x+1, y , elem);

		if (mapa[x-1][y] == elem)
			hoyo += dfs(mapa, x-1, y,elem);
		if (mapa[x][y + 1] == elem)
			hoyo += dfs(mapa, x, y+1,elem);
	}
	else if(x == mapa.size()-1 && y == mapa[0].size()-1)
	{ 
		if (mapa[x][y-1] == elem)
			hoyo += dfs(mapa, x, y-1,elem);
		if (mapa[x - 1][y] == elem)
			hoyo += dfs(mapa, x-1, y,elem);
	}
	else if (x == mapa.size()-1)
	{
		if (y != 0)
			if (mapa[x][y - 1] == elem)
				hoyo += dfs(mapa, x, y - 1, elem);
		if (mapa[x-1][y] == elem)
			hoyo += dfs(mapa, x-1, y,elem);
		if (mapa[x][y + 1] == elem)
			hoyo += dfs(mapa, x, y+1,elem);
		
	}
	else if (y == mapa[0].size()-1)
	{
		if (x != 0)
			if (mapa[x-1][y] == elem)
				hoyo += dfs(mapa, x-1, y, elem);
		if (mapa[x+1][y] == elem)
			hoyo += dfs(mapa, x+1, y,elem);
		if (mapa[x][y - 1] == elem)
			hoyo += dfs(mapa, x, y-1,elem);
	}
	else
	{
		if (mapa[x - 1][y] == elem)
			hoyo += dfs(mapa, x-1, y,elem);
		if (mapa[x + 1][y] == elem)
			hoyo += dfs(mapa, x+1, y,elem);
		if (mapa[x][y - 1] == elem)
			hoyo += dfs(mapa, x, y-1,elem);
		if (mapa[x][y + 1] == elem)
			hoyo += dfs(mapa, x, y+1,elem);
	}

	return hoyo;
}


bool compare(const pair<int, char>& h1, const pair<int, char>& h2)
{
	if (h1.first > h2.first||(h1.first == h2.first && h1.second < h2.second))
		return true;

	return false;
}
int main()
{
	int dimX, dimY; int caso = 1;
	cin >> dimX >> dimY;
	while (dimX != 0 || dimY != 0)
	{
		vector<vector<char>> mapa(dimX, vector<char>(dimY));
		vector<pair<int, char>> sol;

		for (int i = 0; i < dimX; i++)
		{
			for (int j = 0; j < dimY; j++)
			{
				cin >> mapa[i][j];
			}
		}

		for (int i = 0; i < dimX; i++)
		{
			for (int j = 0; j < dimY; j++)
			{
				char elem = mapa[i][j];
				if (mapa[i][j] != '.') sol.push_back(make_pair(dfs(mapa, i, j, elem), elem ));
			}
		}

		sort(sol.begin(), sol.end(), compare);

		cout << "Problem " << caso++ << ":" << endl;
		for (int i = 0; i < sol.size(); ++i)
			cout << sol[i].second << " " << sol[i].first << '\n';

		cin >> dimX >> dimY;
	}
}
