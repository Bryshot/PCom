#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool>visited;
vector<int> parent;
vector<vector<int>> cap;
int INF = 1e9;
vector<vector<int>> adj;
int numNodos, numConexion;

void bfs(int s, int t)
{
	queue<int> q;
	visited = vector<bool>(numNodos, false);
	q.push(s);
	parent[s] = -1; visited[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (!visited[v] && (cap[u][v] > 0)) {
				parent[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int sendFlow(int s, int t) {
	// Intentamos llegar de s a t
	bfs(s, t);
	if (!visited[t])
		return 0; // No pudimos
		// Buscamos capacidad m´as peque˜na en el camino
	int flow = INF, v = t;
	while (v != s) {
		flow = min(cap[parent[v]][v], flow);
		v = parent[v];
	}
	// Mandamos flujo
	v = t;
	while (v != s) {
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow; // INVERSA
		v = parent[v];
	}
	return flow;
}

int edmonKarps(int s, int t) {
	int ret = 0;
	int flow = 0;
	do {
		flow = sendFlow(s, t);
		ret += flow;
	} while (flow > 0);
	return ret;
}

bool posValida(int i, int j, int x, int y)
{
	return (i >= 0 && j >= 0 && i < x && j < y);
}


void creaGrafo(int i, int j, int i2, int j2, int x , int y, vector<vector<int>> idNodo, vector<vector<char>> matriz)
{
	if (posValida(i2, j2, x, y))
	{
		int id = idNodo[i][j];
		int id2 = idNodo[i2][j2];
		if (matriz[i][j] == '*' || matriz[i][j] == '.')
		{
			if (matriz[i2][j2] != '~' && matriz[i2][j2] != '*' )
			{
				cap[id][id2] = 1;
				adj[id].push_back(id2);
			}
		}
		else if (matriz[i][j] == '@' || matriz[i][j] == '#')
		{
			if ( matriz[i2][j2] != '~' && matriz[i2][j2] != '*')
			{
				cap[id][id2] = INF;
				adj[id].push_back(id2);
			}
		}
	}
}

int main()
{
	int x, y, p;
	cin >> x;
	while (x != EOF)
	{
		cin >> y >> p;
		int s = 0, t = 0;
		vector<vector<char>> matriz(x, vector<char>(y));
		vector<vector<int>> idNodo(x, vector<int>(y));
		numNodos = 2;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> matriz[i][j];
				idNodo[i][j] = numNodos;
				numNodos++;
			}
		}
		cap = vector<vector<int>>(numNodos, vector<int>(numNodos, 0));
		adj = vector<vector<int>>(numNodos);
		parent = vector<int>(numNodos);
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				int id = idNodo[i][j];
				if (matriz[i][j] == '*')
				{
					cap[0][id] = 1;
					adj[0].push_back(id);
				//	cap[id][0] = 1;
				//	adj[id].push_back(0);
				}
				else if (matriz[i][j] == '#')
				{
					cap[id][1] = p;
					adj[id].push_back(1);
				//	cap[1][id] = p;
				//	adj[1].push_back(id);
				}
				creaGrafo(i, j, i + 1, j, x, y, idNodo, matriz);
				creaGrafo(i, j, i, j + 1, x, y, idNodo, matriz);
				creaGrafo(i, j, i - 1, j, x, y, idNodo, matriz);
				creaGrafo(i, j, i, j - 1, x, y, idNodo, matriz);
			}
		}

		cout << edmonKarps(0, 1) << '\n';
		cin >> x;
	}
}