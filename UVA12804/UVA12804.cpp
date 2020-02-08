#include <vector>
#include <iostream>

using namespace std;

enum barco{TOCADO,HUNDIDO,LIBRE};

bool dfs(int u, vector<barco> & estado, vector<vector<int>> adj)
{
	estado[u] = TOCADO;
	for (int i = 0; i < adj[u].size(); ++i) 
	{
		int v = adj[u][i];
		if (estado[v] == TOCADO)
			return true;
		else if (dfs(v,estado,adj))
			return true;
	}
	estado[u] = HUNDIDO;
	return false;
}

int main()
{
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++)
	{
		int numIntr;
		cin >> numIntr;
		vector<vector<int>> matriz(numIntr);
		for (int j = 0; j < numIntr; j++)
		{
			char c; 
			cin >> c;
			if (c == 'A')
			{
				matriz[j].push_back(j + 1);
			}
			else if (c == 'J')
			{
				int a;
				cin >> a;
				matriz[j].push_back(a - 1);
			}
			else
			{
				int a;
				cin >> a;
				matriz[j].push_back(a - 1);
				matriz[j].push_back(j + 1);
			}
		}
		
		vector<barco> usado(numIntr+1,LIBRE);

		bool ciclo  = dfs(0, usado, matriz);

		if (!ciclo)
		{
			cout << "ALWAYS" << '\n';
		}
		else if (usado[numIntr] == TOCADO || usado[numIntr] == HUNDIDO)
		{
			cout << "SOMETIMES" << '\n';
		}
		else
		{
			cout << "NEVER" << '\n';
		}

	}
}