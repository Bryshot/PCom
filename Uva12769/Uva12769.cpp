#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
	vector<int> ft;
	public:
	FenwickTree(int n) { ft.assign(n + 1, 0); }
	int getSum(int b) {
		int ret = 0;
		while (b) {
			ret += ft[b]; b -= (b & -b);
		}
		return ret;
	}
	void add(int pos, int val) {
		while (pos < ft.size()) {
			ft[pos] += val; pos += (pos & -pos);
		}
	}
	int getValue(int pos) {
		return getSum(pos);
	}
};
int main()
{
	int numInst;
	cin >> numInst;
	while (numInst != 0)
	{
		FenwickTree tree = FenwickTree(100000);
		for (int i = 0; i < numInst; i++)
		{
			char opcion;
			cin >> opcion;
			if (opcion == 'B')
			{
				int temp1, temp2, temp3;
				cin >> temp1 >> temp2 >> temp3;
				tree.add(temp1, temp3);
				tree.add(temp2 + 1, -temp3);  
			}
			else
			{
				int num;
				cin >> num;
				cout << tree.getValue(num)<< '\n';
			}
		}
		cin >> numInst;
	}
}

