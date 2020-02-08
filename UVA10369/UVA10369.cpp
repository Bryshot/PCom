#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

int N, S, P;
vector<pair<int, int>> coordenadas;

vector<int> C; int numSets;

using arista = pair<double, pair<int, int>>; // < coste, extremos >
vector<arista> aristas;


class comp {
public:
	bool operator ()(arista a, arista b) {
		return (a.first < b.first);
	}
};

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

int main() {
	ofstream out("salida.txt");

	cin >> N;
	while (N--) {

		cin >> S >> P;
		for (int i = 0; i < P; i++) {

			int x, y;
			cin >> x >> y;
			coordenadas.push_back({ x, y });

		}

		// generar aristas y guardarlas en el vector
		for (int i = 0; i < P; i++)
			for (int j = 0; j < P; j++) {
				if (i < j) {
					double dist = sqrt(pow(coordenadas[i].first - coordenadas[j].first, 2) + pow(coordenadas[i].second - coordenadas[j].second, 2));
					aristas.push_back({ dist, {i, j} });
				}
			}

		// ordenamos las aristas de menor a mayor
		sort(aristas.begin(), aristas.end());
		init(P);

		// Kruskal
		//init(V);
		double D = 0;
		for (arista ar : aristas) {
			if (numSets == S)
				break;
			if (find(ar.second.first) != find(ar.second.second)) {
				merge(ar.second.first, ar.second.second);
				D = ar.first;
			}
		}

		cout << fixed << setprecision(2) << D << '\n';

		aristas.clear();
		coordenadas.clear();
	}

	return 0;

}