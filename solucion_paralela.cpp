// IMCOMPDefiniendoNHilos.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

// Inclu�mos las librer�as.

#include <iostream>
#include <omp.h>

//Definimos los valores a utilizar para esta pr�ctica

#define N 1000 //Cantidad de elementos a manejar en los arreglos
#define chunk 100 //Tama�o que tendr�n los arreglos para que cada hilo creado se encargue de esta cantidad de elementos
#define mostrar 10 //Permitir� manejar la cantidad de datos a imprimir

using namespace std;
int tid;

void imprimeArreglo(float* d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo!\n";
	//Enlistamos las 3 variables
	float a[N], b[N], c[N];
	int i;

	// Vamos a estar iterando de 0 a N utilizando i como variable

	for (i = 0; i < N; i++)
	{
		//Asignamos una f�rmula para calcular a y b
		a[i] = i * 80;
		b[i] = (i + 10) * 3.7;
	}
	int pedazos = chunk;

	//paralelizamos la iteraci�n 

#pragma omp parallel for \
	shared (a, b, c, pedazos) private (i) \
	schedule(static, pedazos)
	
	//calculamos C dentro de la paralelizaci�n
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros" << mostrar << "valores del arreglo a:" << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros" << mostrar << "valores del arreglo b:" << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros" << mostrar << "valores del arreglo c:" << std::endl;
	imprimeArreglo(c);
}

void imprimeArreglo(float *d)

{	
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
	
}