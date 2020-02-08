#include <iostream>
#include <iterator>
#include "DiccionarioHash.h"
#include "Hash.h"

using namespace std;

typedef struct chocolate
{
	int numPos=0;
	int pos[3];
};

void resuelve(DiccionarioHash<int, chocolate> diccionario)
{
	int sol[3][2];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sol[i][j] = 0;
		}
	}

	DiccionarioHash<int, chocolate>::ConstIterator it = diccionario.cbegin();

	while (it != diccionario.cend()) 
	{
		chocolate temp = it.valor();
		if (temp.numPos == 1)
		{
			sol[temp.pos[0]][0]++;
		}
		else if (temp.numPos == 2)
		{
			if ((temp.pos[0] == 0 || temp.pos[1] == 0) && ((temp.pos[0] == 1) || (temp.pos[1] == 1)))
			{
				sol[2][1]++;
			}
			else if ((temp.pos[0] == 0 || temp.pos[1] == 0) && ((temp.pos[0] == 2) || (temp.pos[1] == 2)))
			{
				sol[1][1]++;
			}
			else
			{
				sol[0][1]++;
			}
		}
		it.next();
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << sol[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	int numCases, numChoc[3]; 
	int temp;
	cin >> numCases;
	for (int i = 0; i < numCases; i++)
	{
		DiccionarioHash<int, chocolate> diccionario;
		cin >> numChoc[0]>> numChoc[1] >> numChoc[2];
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < numChoc[k]; j++)
			{
				cin >> temp;
				DiccionarioHash<int, chocolate>::Iterator it = diccionario.busca(temp);
				if (it != diccionario.end())
				{
					chocolate elem = it.valor();
					if ((elem.numPos == 1 && elem.pos[0] != k) || (elem.numPos == 2 && elem.pos[0] != k && elem.pos[1] != k))
					{
						elem.pos[elem.numPos] = k;
						elem.numPos++;
						it.setVal(elem);
					}
				}
				else
				{
					chocolate newElem;
					newElem.pos[newElem.numPos] = k;
					newElem.numPos++;
					diccionario.inserta(temp, newElem);

				}
			}
		}
		cout << "Case #" << i + 1 << ":\n";
		resuelve(diccionario);
	}
}