#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

using namespace std;

vector<int> C; int numSets;

bool comparator(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b)
{
	return a.first < b.first;
}

void init(int n) {
	C.assign(n, 0); numSets = n;
	for (int i = 0; i < n; ++i) C[i] = i;
}
int find(int x) {
	return (C[x] == x) ? x : C[x] = find(C[x]);
}
void merge(int x, int y) { // find(x) != find(y)
	C[find(x)] = find(y);
	--numSets;
}
int main()
{
	int numCases;
	cin >> numCases;
	while (numCases--)
	{
		int numSatelites , numPuntos;
		cin >> numSatelites >> numPuntos;
		vector<pair<int, int>> puntos = vector<pair<int, int>>(numPuntos); 
		for(int i = 0; i< numPuntos ;i++)
		{
			int temp1, temp2;
			cin >> temp1>> temp2;
			puntos[i] = make_pair(temp1, temp2);
		}
		vector<pair<double, pair<int, int>>> distancias = vector<pair<double, pair<int, int>>>();
		for (int i = 0; i < numPuntos; i++)
		{
			for(int j = i; j <numPuntos; j++)
			{
				double distancia = sqrt(pow(puntos[i].second - puntos[j].second, 2) + pow(puntos[i].first - puntos[j].first, 2));
				distancias.push_back(make_pair(distancia, make_pair(i, j)));
			}
		}
		init(numPuntos);
		sort(distancias.begin(), distancias.end());
		double out = 0;
		for (int i = 0; i < distancias.size(); i++) 
		{
			
			if (find(distancias[i].second.second) != find(distancias[i].second.first))
			{
				merge(distancias[i].second.first, distancias[i].second.second);
				out = distancias[i].first;
			}
			if (numSatelites == numSets)
				break;
		}
		cout << fixed << setprecision(2) << out << '\n';
	}
}
