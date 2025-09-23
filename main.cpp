//
// Created by Victor Felipe on 13/09/2025.
//
#include <iostream>
#include <chrono>
#include <cstdlib>
#include "InsertionSort/insertionsort.cpp"
#include "gerarentradas.cpp"
#include "salvararquivos.cpp"


using namespace std;

bool tamanhoValido(int n) {  // funcao que lê a entrada fornecida e compara com os valores pre estabelecidos do algoritmo

    int tamanhos[] = {10,100,1000,10000,100000,1000000};
    for (int i = 0; i < sizeof(tamanhos)/sizeof(tamanhos[0]); i++) {
        if (tamanhos[i] == n) return true;
    }
    return false;
}

int main() {
    int op;
    do {
        cout << "\n                                       ------ M E N U ------ \n";
        cout << "Escolha uma Funcao:\n";
        cout << "1. Insertion Sort \n";
        cout << "2. Selection Sort \n";
        cout << "3. Bubble Sort \n";
        cout << "4. Shell Sort \n";
        cout << "2. Sair\n";

        cin >> op;

        if (op == 1) {
            char escolha;
            int n;
            cout << "Escolha a forma de entrada que voce deseja ou S para sair: \n";
            cout << "C. Crescente\n";
            cout << "D. Decrescente\n";
            cout << "R. Random\n";
            cin >> escolha;
            escolha = toupper(escolha);

            if (escolha == 'S') {
                cout << "Saindo da Aplicacao..." << endl;
                op = 2;
                break;
            }
            if ( escolha != 'C' && escolha != 'D' && escolha != 'R') {
                cout << "Opcao invalida!\n";
                continue;
            }

            cout << "Digite o tamanho da entrada (10,100,1000,10000,100000,1000000):\n";
            cin >> n;

            if (!tamanhoValido(n)) {
                cout << "Tamanho invalido!\n";
                continue;
            }
            executarInsertionSort(escolha, n);
        }
        else if (op == 2) {

        }
        else if (op == 3) {

        }
        else if (op == 4) {

        }
        else{
        cout << "Opcao invalida!\n";
        break;
        }
    }while (op != 2);

    cout << "Programa finalizado!\n";
    return 0;
}



