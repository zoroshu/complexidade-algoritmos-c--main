//
// Created by Victor F on 08/11/2025.
//
#include<algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include "../gerarentradas.h"
#include "../salvararquivos.h"

void particiona(int a[], int esq, int dir, int &i, int &j, int x) {
    i = esq;
    j = dir;
    do {
        while (a[i] < x) ++i;
        while (a[j] > x) --j;
        if (i <= j) {
            std::swap(a[i], a[j]);
            ++i; --j;
        }
    } while (i <= j);
}

void quickSort_v1(int a[], int esq, int dir) {
    while (esq < dir) {
        int i, j;
        int x = a[esq];
        particiona(a, esq, dir, i, j, x);

        if ((j - esq) < (dir - i)) {
            if (esq < j) quickSort_v1(a, esq, j);
            esq = i;
        } else {
            if (i < dir) quickSort_v1(a, i, dir);
            dir = j;
        }
    }
}

void quickSort_v2(int a[], int esq, int dir) {
    if (esq >= dir) return;
    int i, j;
    int x = (a[esq] + a[dir]) / 2;
    particiona(a, esq, dir, i, j, x);
    if (esq < j) quickSort_v2(a, esq, j);
    if (i   < dir) quickSort_v2(a, i, dir);
}

void quickSort_v3(int a[], int esq, int dir) {
    if (esq >= dir) return;

    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    int i, j;
    int p = esq + rand() % (dir - esq + 1);
    int x = a[p];
    particiona(a, esq, dir, i, j, x);
    if (esq < j) quickSort_v3(a, esq, j);
    if (i   < dir) quickSort_v3(a, i, dir);

}
void executarQuickSort(char tipo, int n, int versao) {
    int* vet = new int[n];

    bool crescente   = (tipo == 'c' || tipo == 'C');
    bool decrescente = (tipo == 'd' || tipo == 'D');
    std::string subpasta, prefixo;

    if (crescente) {
        gerarValorCrescente(vet, n);
        subpasta = "Crescente/";
        prefixo  = "Crescente";
    } else if (decrescente) {
        gerarValorDecrescente(vet, n);
        subpasta = "Decrescente/";
        prefixo  = "Decrescente";
    } else {
        gerarValorRandom(vet, n);
        subpasta = "Random/";
        prefixo  = "Random";
    }

    // base de diretório pela versão: v1/, v2/ ou v3/
    string algoritmo = "QuickSort/v" + to_string(versao) + "/";

    // Define caminhos completos
    string diretorioEntrada = algoritmo + "Arquivos de Entrada/" + subpasta +
                              "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = algoritmo + "Arquivos de Saida/"   + subpasta +
                              "Saida"   + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = algoritmo + "Arquivos de Tempo/"   + subpasta +
                              "Tempo"   + prefixo + to_string(n) + ".txt";

    salvarArquivos(diretorioEntrada, vet, n);

    std::cout << "Iniciando Ordenacao... \n";
    auto start = std::chrono::high_resolution_clock::now();

    switch (versao) {
        case 1: quickSort_v1(vet, 0, n - 1); break; // pivô = primeiro elemento
        case 2: quickSort_v2(vet, 0, n - 1); break; // pivô = media
        case 3: quickSort_v3(vet, 0, n - 1); break; // pivô = aleatório
        default:
            std::cout << "Versao invalida! Use 1, 2 ou 3.\n";
            delete[] vet;
            return;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = stop - start;

    std::cout << "Vetor ordenado! \n";

    salvarTempo(diretorioTempo, n, duration.count());
    salvarArquivos(diretorioSaida, vet, n);

    std::cout << "Arquivos Salvos em seus respectivos diretorios! \n";

    delete[] vet;
}


