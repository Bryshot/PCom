#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main() {
	int C, N, A;
	while (cin >> C )
	{
		//siguiente guarda la siguiente vez que aparece el elemento de esa posicion del vector o el final+1 si no existe
		cin >> N >> A;
		int elemsEnCache = 0, accesos = 0;
		vector<int> entrada(A), ultimo(N,A), siguiente(A);
		vector<bool> enCache(N, false);

		for (int i = 0; i < A; ++i) cin >> entrada[i];

		for (int i = A - 1; i >= 0; --i)
		{
			siguiente[i] = ultimo[entrada[i]];
			ultimo[entrada[i]] = i;
		}

		map<int, int> Q;

		for (int i = 0; i < A; ++i)
		{
			int x = entrada[i];

			if (!enCache[x]) 
			{
				++accesos;
				enCache[x] = true;

				if (elemsEnCache >= C)
				{
					enCache[Q.begin()->second] = false;
					Q.erase(Q.begin());
				}
				else ++elemsEnCache;
			}

			Q.insert(make_pair(siguiente[i],x));
		}
		cout << accesos<< '\n';
	}
}