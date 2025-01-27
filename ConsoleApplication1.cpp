#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
    std::cout << "\nSumando Arreglos en Paralelo!\n";

    float a[N], b[N], c[N];
    int i;

    // Generar valores aleatorios para los arreglos
    srand(time(0)); // Semilla para los números aleatorios
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 100; // Números aleatorios entre 0 y 99
        b[i] = rand() % 100;
    }

    int pedazos = chunk;

    // Paralelización con OpenMP
#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    // Imprimir los arreglos para verificar resultados
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}
