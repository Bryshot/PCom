#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparePairs(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
	if(lhs.first == rhs.first)
	{
		return lhs.second < rhs.second;
	}
	return lhs.first < rhs.first;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	while (numCasos--)
	{
		vector<string> nombres;
		vector<int> valores;
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> m;
		for (int i = 0; i < n; i++)
		{
			string tempString;
			int tempInt;
			cin >> tempString >> tempInt;
			nombres.push_back(tempString);
			valores.push_back(tempInt);
			m.push_back(make_pair(valores[i], i));
		}
		for (int i = 0; i < k; i++)
		{
			auto t = m.begin();
			int first = t->first;
			int second = t->second;
			m.erase(t);
			m.push_back(make_pair(first + valores[second], second));
			cout << first << " "<<nombres[second] << '\n';
			sort(m.begin(), m.end(), comparePairs);
		}

	}
}