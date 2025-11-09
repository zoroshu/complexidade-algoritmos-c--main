//
// Created by Victor F on 23/10/2025.
//

#include <iostream>
#include <chrono>
#include "../gerarentradas.h"
#include "../salvararquivos.h"

using namespace std;

void merge(int arr[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int* E = new int[n1];
    int* D = new int[n2];

    for (int i = 0; i < n1; i++)
        E[i] = arr[esquerda + i];
    for (int j = 0; j < n2; j++)
        D[j] = arr[meio + 1 + j];

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            arr[k] = E[i];
            i++;
        } else {
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = E[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = D[j];
        j++;
        k++;
    }

    delete[] E;
    delete[] D;
}

void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda >= direita) {
        return;
    }

    int meio = esquerda + (direita - esquerda) / 2;
    mergeSort(arr, esquerda, meio);
    mergeSort(arr, meio + 1, direita);
    merge(arr, esquerda, meio, direita);
}


void executarMergeSort(char tipo, int n) {
    int* vet = new int[n];

    bool crescente = (tipo == 'c' || tipo == 'C');
    bool decrescente = (tipo == 'd' || tipo == 'D');
    string subpasta, prefixo;

    if (crescente) {
        gerarValorCrescente(vet, n);
        subpasta = "Crescente/";
        prefixo = "Crescente";
    } else if (decrescente) {
        gerarValorDecrescente(vet, n);
        subpasta = "Decrescente/";
        prefixo = "Decrescente";
    } else {
        gerarValorRandom(vet, n);
        subpasta = "Random/";
        prefixo = "Random";
    }

    string algoritmo = "MergeSort/";
    string diretorioEntrada = algoritmo + "Arquivos de Entrada/" + subpasta +
                              "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = algoritmo + "Arquivos de Saida/"   + subpasta +
                              "Saida" + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = algoritmo + "Arquivos de Tempo/"   + subpasta +
                              "Tempo" + prefixo + to_string(n) + ".txt";

    salvarArquivos(diretorioEntrada, vet, n);

    auto start = chrono::high_resolution_clock::now();
    cout << "Iniciando Ordenacao... \n";
    mergeSort(vet, 0, n - 1);                    // <-- use 'n' aqui
    auto stop = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = stop - start;
    cout << "Vetor ordenado! \n";

    salvarTempo(diretorioTempo, n, duration.count());
    salvarArquivos(diretorioSaida, vet, n);

    cout << "Arquivos Salvos em seus respectivos diretorios! \n";
    delete[] vet;
}
