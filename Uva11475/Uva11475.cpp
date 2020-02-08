#include <iostream>
#include <vector>
#include <string>

using namespace std;


string T, P;
vector<int> b; // back table
int n, m; // n = length of T, m = length of P

void kmpPreprocess() { // before calling kmpSearch
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		++i; ++j;
		b[i] = j;
	}
}

void kmpSearch() {
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j])
			j = b[j]; // different reset j using b
		++i; ++j; // same, advance both pointers
		if (j == m) {
			printf("P is found at index %d in T\n", i - j);
			j = b[j];
		}
	}
}

int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
