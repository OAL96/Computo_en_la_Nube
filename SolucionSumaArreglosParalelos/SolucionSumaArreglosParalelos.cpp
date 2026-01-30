// SolucionSumaArreglosParalelos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

using namespace std;

void imprimeArreglo(float* d);

int main()
{
    cout << "Sumando Arrgles en Paralelo!\n";
    float a[N], b[N], c[N], d[N];
    int i;

    for (i = 0; i < N; i++)
    {
        a[i] = i * 67;
        b[i] = (i + 6) * 9.9;
        c[i] = (i * 8) + 12;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, d, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++)
        d[i] = a[i] + b[i] + c[i];

    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << endl;
    imprimeArreglo(a);
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << endl;
    imprimeArreglo(b);
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << endl;
    imprimeArreglo(c);
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo d: " << endl;
    imprimeArreglo(d);
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        cout << d[x] << " | ";
    cout << endl;
}