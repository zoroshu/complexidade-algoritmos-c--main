#include <algorithm>
#include <climits>
#include <chrono>
#include <iostream>
#include <string>
#include "../gerarentradas.h"
#include "../salvararquivos.h"
#include "heapsort.h"

using namespace std;


void MIN_HEAPIFY(int a[], int heapSize, int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if (l < heapSize && a[l] < a[s]) s = l;
        if (r < heapSize && a[r] < a[s]) s = r;

        if (s == i) break;

        swap(a[i], a[s]);
        i = s;
    }
}

void BUILD_MIN_HEAP(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        MIN_HEAPIFY(a, n, i);
}

int HEAP_MINIMUM(const int a[], int heapSize) {
    return (heapSize > 0) ? a[0] : INT_MAX;
}

int HEAP_EXTRACT_MIN(int a[], int &heapSize) {
    if (heapSize <= 0) return INT_MAX;

    int minvalue = a[0];
    a[0] = a[heapSize - 1];
    --heapSize;
    MIN_HEAPIFY(a, heapSize, 0);
    return minvalue;
}

void HEAP_DECREASE_KEY(int a[], int i, int newKey) {
    if (newKey > a[i]) return;
    a[i] = newKey;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (a[p] <= a[i]) break;
        swap(a[p], a[i]);
        i = p;
    }
}

void MIN_HEAP_INSERT(int a[], int &heapSize, int n, int newKey) {
    if (heapSize >= n) return;

    a[heapSize] = INT_MAX;
    ++heapSize;
    HEAP_DECREASE_KEY(a, heapSize - 1, newKey);
}


void heapsortMin(int a[], int n) {
    BUILD_MIN_HEAP(a, n);
    int heapSize = n;

    for (int i = n - 1; i >= 1; --i) {
        swap(a[0], a[i]);
        --heapSize;
        MIN_HEAPIFY(a, heapSize, 0);
    }

    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        swap(a[i], a[j]);
    }
}

void executarHeapSort(char tipo, int n) {
    int* vet = new int[n];

    string subpasta, prefixo;

    if (tipo == 'C' || tipo == 'c') {
        gerarValorCrescente(vet, n);
        subpasta = "Crescente/";
        prefixo  = "Crescente";
    } else if (tipo == 'D' || tipo == 'd') {
        gerarValorDecrescente(vet, n);
        subpasta = "Decrescente/";
        prefixo  = "Decrescente";
    } else {
        gerarValorRandom(vet, n);
        subpasta = "Random/";
        prefixo  = "Random";
    }

    string algoritmo = "HeapSort/";

    string diretorioEntrada = algoritmo + string("Arquivos de Entrada/") + subpasta +
                              "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = algoritmo + string("Arquivos de Saida/")   + subpasta +
                              "Saida"   + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = algoritmo + string("Arquivos de Tempo/")   + subpasta +
                              "Tempo"   + prefixo + to_string(n) + ".txt";

    salvarArquivos(diretorioEntrada, vet, n);

    cout << "Iniciando HeapSort (min-heap)...\n";
    auto start = chrono::high_resolution_clock::now();

    heapsortMin(vet, n);

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;
    cout << "Vetor ordenado!\n";

    salvarTempo(diretorioTempo, n, duration.count());
    salvarArquivos(diretorioSaida, vet, n);

    cout << "Arquivos salvos em: " << algoritmo << "\n";

    delete[] vet;
}
