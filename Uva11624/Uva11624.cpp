#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

int columnas[] = { 0,1, 0 ,-1 };
int filas[] = { 1,0,-1,0 };

bool correcto(int i, int j, int r , int c)
{
	return i < r && 0 <= i && j < c && 0 <= j;
}

void fuego(vector<pair<int, int>> vectorPair, int  r, int c, vector<vector<int>>& dist, vector<vector<bool>> visitadosJuan)
{
	
	pair<int, int> x;
	vector<vector<bool>> visitados = visitadosJuan;
	queue<pair<int, int>> q;

	for (pair<int, int> p : vectorPair)
	{
		visitados[p.first][p.second] = true;
		dist[p.first][p.second] = 0; 
		q.push(p);
	}
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int puntoy = x.second + filas[i];
			int puntox = x.first + columnas[i];
			if (correcto(puntox, puntoy,r,c) && !visitados[puntox][puntoy])
			{
				visitados[puntox][puntoy] = 1;
				dist[puntox][puntoy] = min(dist[x.first][x.second] + 1, dist[puntox][puntoy]);
				q.push(make_pair(puntox, puntoy));
			}
		}
	}
	return;
}



int bfs(pair<int, int> p, int  r, int c, vector<vector<int>> dF, vector<vector<bool>> visitadosJuan)
{
	vector<vector<int>> d(r, vector<int>(c));

	pair<int, int> punto;
	queue<pair<int, int>> q;
	punto = p;
	d[p.first][p.second] = 0; visitadosJuan[p.first][p.second] = true;
	q.push(punto);
	while (!q.empty())
	{
		punto = q.front(); q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int py = punto.second + filas[i];
			int px = punto.first + columnas[i];
			if (px == -1 || px == r || py == -1 || py == c)
			{
				return d[punto.first][punto.second] + 1;
			}
			if (!visitadosJuan[px][py])
			{
				d[px][py] = d[punto.first][punto.second] + 1;
				if (d[px][py] < dF[px][py]) 
				{
					visitadosJuan[px][py] = true;
					q.push(make_pair(px, py));
				}
			}
		}
	}
	return -1;
}

int main() {
	int casos;

	cin >> casos;
	for (int i= 0; i<casos; i++)
	{
		int r, c;
		cin >> r >> c;
		vector<vector<bool>>  visitadosJuan;
		visitadosJuan = vector<vector<bool>> (r, vector<bool>(c, false));
		vector<pair<int, int>> vf = vector<pair<int, int>>();
		pair<int, int> posF;
		pair<int, int> posJ;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				char temp;
				cin >> temp;
				if (temp == '#') 
				{
					visitadosJuan[i][j] = true;
				}
				
				else if (temp == 'J')
				{
					posJ = make_pair(i, j);
				}
				else if (temp == 'F')
				{
					posF = make_pair(i, j);
					vf.push_back(posF);
					visitadosJuan[i][j] = true;
				}
				 
			}
		}
		vector<vector<int>> dF(r, vector<int>(c, 1e9));

		fuego(vf, r, c, dF, visitadosJuan);

		int distancia= bfs(posJ, r, c, dF, visitadosJuan);
		
		if (distancia == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << distancia << "\n";
		}
	}
}