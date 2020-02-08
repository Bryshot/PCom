#include <iostream>
#include "pila.h"

using namespace std;

int main()
{
	Pila<int> pila, int temp;

	cin >> temp;
	if (temp != EOF)
	{
		while (temp != '\n')
		{
			int valor;
			cin >> valor;
			if (valor > 0)
			{
				if (valor == (temp * -1))
				{
					temp == pila.cima();
					pila.desapila;
				}
			}
			else
			{
				pila.apila(temp);
				temp = valor;
			}
			
		}
	}
}