#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h> 
#include <bitset>

using namespace std;

const int MAX_PRIME = 1000001;

bitset<MAX_PRIME + 1> bs; // #include <bitset>
vector<unsigned int> primes; // unsigned int

bool isPrime(unsigned long long n) {
	if (n <= 1e9)
		return bs[n];
	for (unsigned int i = 0;
		primes[i] * primes[i] <= n; ++i) {
		if (!(n % primes[i]))
			return false;
	}
	return true;
}

void sieve() {
	bs.set(); // De momento, todos son primos
	bs[0] = bs[1] = 0; // El 0 y el 1 no lo son.
	for (unsigned int i = 2; i <= MAX_PRIME; ++i) {
		if (bs[i]) {
			// El actual es primo. Tiramos sus m´ultiplos
			for (unsigned int j = i * i; j <= MAX_PRIME; j += i)
				bs[j] = 0;
			primes.push_back(i);
		} // if es primo
	} // for
} // sieve


int main()
{
	sieve();
	int ini, fin;
	while (cin >> ini >> fin)
	{
		int vlejano1, vlejano2, vcerca1, vcerca2, anterior = -1, cercano = 1e9, lejano = -cercano;
		bool pareja=true;
		long long int valor;
		for (int i = ini; i <= fin; i++)
		{
			if (isPrime(i))
			{
				if (anterior != -1)
				{
					if (i - anterior > lejano)
					{
						lejano = i - anterior;
						vlejano1 = anterior; vlejano2 = i;
					}
					if (i - anterior < cercano)
					{
						cercano = i - anterior;
						vcerca1 = anterior; vcerca2 = i;
					}
					pareja = false;
				}
				anterior = i;
			}
		}

		if (pareja) cout << "There are no adjacent primes.";
		else cout << vcerca1 << " " << vcerca2 << " are closest, " << vlejano1 << " " << vlejano2 << " are most distant.\n";
	}
}