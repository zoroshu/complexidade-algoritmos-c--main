//
// Created by Victor Felipe on 14/09/2025.
//

#include <iostream>
#include <bits/stdc++.h>
#include "gerarentradas.h"
#include <ctime>

void gerarValorCrescente(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void gerarValorDecrescente(int vet[], int n) {
    int val = n;
    for (int i = 0; i < n; i++) {
        vet[i] = val;
        val--;
    }
}

void gerarValorRandom(int arr[], int n) {
    random_device rd;  // Inicializa com um valor aleatório do sistema
    mt19937 gen(rd()); // Mersenne Twister
    uniform_int_distribution<> dist(0, n * 10);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
}

bool tamanhoValido(int n) {  // funcao que lê a entrada fornecida e compara com os valores pre estabelecidos do algoritmo

    int tamanhos[] = {10,100,1000,10000,100000,1000000};
    for (int i = 0; i < sizeof(tamanhos)/sizeof(tamanhos[0]); i++) {
        if (tamanhos[i] == n) return true;
    }
    return false;
}

bool lerParametros(char &escolha, int &tam) { // função para padronizar as entradas dos algoritmos
            cout << "Escolha a forma de entrada que voce deseja ou S para sair: \n";
            cout << "C. Crescente\n";
            cout << "D. Decrescente\n";
            cout << "R. Random\n";
            cin >> escolha;
            escolha = toupper(escolha);

            if (escolha == 'S') {
                cout << "Saindo da Aplicacao..." << endl;
                return false;
            }
            if ( escolha != 'C' && escolha != 'D' && escolha != 'R') {
                cout << "Opcao invalida!\n";
                return false;
            }

            cout << "Digite o tamanho da entrada (10,100,1000,10000,100000,1000000):\n";
            cin >> tam;

            if (!tamanhoValido(tam)) {
                cout << "Tamanho invalido!\n";
                return false;
            }
            return true;
}


