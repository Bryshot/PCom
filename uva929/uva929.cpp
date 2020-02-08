// uva929.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<pair<int, int>>;
using vvii = vector<vii>;
const int MAX = 200;
vvii adjList;
vi dist;
bool visited[1000000];
int INF = 1e9, V, E;


bool isPosValida(int x, int y, int maxY, int maxX)
{
	return x >= 0 && y >= 0 && y < maxY && x < maxX;
}

void dijkstra(int s, vi& dist) {
	dist.assign(adjList.size(), INF);
	dist[s] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (auto a : adjList[u]) {
			if (dist[u] + a.first < dist[a.second]) {
				dist[a.second] = dist[u] + a.first;
				pq.push({ dist[a.second], a.second });
			}
		}
	}
}



int main()
{
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	int numCases;
	cin >> numCases;
	while (numCases--)
	{
		int numRows, numColumns;
		cin >> numRows >> numColumns;
		vector<vector<int>> matriz= vector<vector<int>> (numRows,vector<int>(numColumns));
		vvii adjList = vvii(numRows);
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numColumns; j++)
			{
				int dist;
				cin >> matriz[i][j];
			}
		}
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numColumns; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (isPosValida(i + dx[k], j + dy[k], numRows, numColumns))
					{
						adjList[i+j*numColumns].push_back(make_pair(i + dx[k]+ (j + dy[k])* numColumns, matriz[i + dx[k]][j + dy[k]]));
					}
				}
			}
		}
		vector <int > dist;
		dijkstra(0, dist);
		cout << dist[dist.size()]+adjList[adjList.size()][0].first;

	}
}
