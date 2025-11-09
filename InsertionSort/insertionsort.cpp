//
// Created by Victor Felipe on 13/09/2025.
//

#include "insertionsort.h"
#include <iostream>
#include "../gerarentradas.h"
#include <ctime>
#include <chrono>
#include <string.h>
#include "../salvararquivos.h"

using namespace std;

void insertionSort(int arr[], int n) {
    for (int j = 1; j < n; j++) {
        int chave = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > chave) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = chave;
    }
}

void executarInsertionSort(char tipo, int n) {
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

    string algoritmo = "InsertionSort/"; // caminho para salvar arquivo

    string diretorioEntrada = algoritmo + "Arquivos de Entrada/" + subpasta +
                              "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = algoritmo + "Arquivos de Saida/"   + subpasta +
                              "Saida" + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = algoritmo + "Arquivos de Tempo/"   + subpasta +
                              "Tempo" + prefixo + to_string(n) + ".txt";

    salvarArquivos(diretorioEntrada, vet, n);

    auto start = chrono::high_resolution_clock::now();
    cout << "Iniciando Ordenacao... \n";
    insertionSort(vet, n);
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;
    cout << "Vetor ordenado! \n";
    salvarTempo(diretorioTempo, n, duration.count());
    salvarArquivos(diretorioSaida, vet, n);
    cout << "Arquivos Salvos em seus respectivos diretorios! \n";
    delete[] vet;
}

