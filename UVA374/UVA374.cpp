#include <iostream>
#include <fstream>
using namespace std;

long long int BigMod(long long int  base, long long  int  potencia, long long int  modulo)
{
	
	if (potencia % 2 == 1) return (base % modulo * BigMod(base, potencia - 1, modulo) % modulo) % modulo;
	if (potencia == 0) return 1;

	long long int  valor = BigMod(base, potencia / 2, modulo) % modulo;
	return (valor * valor) % modulo;
}

int main()
{
	ofstream fout;
	fout.open("outPut.txt");
	long long int  base, potencia, modulo;
	cin >> base;
	while (base != 0)
	{
		cin >> potencia >> modulo;
		fout <<BigMod(base, potencia, modulo) << '\n';
		cin >> base;
	}
}
