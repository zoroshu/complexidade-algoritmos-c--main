//
// Created by Victor Felipe on 15/09/2025.
//

#include<iostream>
#include<fstream>
#include <iomanip>
#include "salvararquivos.h"

using namespace std;

void salvarArquivos(const string &arquivo, int arr[], int n) {
    ofstream arq(arquivo);
    if (!arq) {
        cout<<"Erro ao criar arquivo "<< arquivo  << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        arq << arr[i] << "\n";
    }
    arq.close();
}

void salvarTempo(const string &arquivo, int n, double duracao) {
    ofstream arq(arquivo);
    if (!arq) {
        cout << "Erro ao criar arquivo " << arquivo << endl;
    }
    arq << "Tamanho:" << n << endl;
    arq << "Tempo:" << std::fixed << std::setprecision(6) << duracao << "s" << endl;
}
