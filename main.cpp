//
// Created by Victor Felipe on 13/09/2025.
//
#include <iostream>
#include <chrono>
#include <cstdlib>
#include "InsertionSort/insertionsort.cpp"
#include "gerarentradas.cpp"
#include "salvararquivos.cpp"
#include "SelectionSort/selectionsort.cpp"
#include "BubbleSort/bubblesort.cpp"
#include "ShellSort/shellsort.cpp"

using namespace std;

bool tamanhoValido(int n) {  // funcao que lê a entrada fornecida e compara com os valores pre estabelecidos do algoritmo

    int tamanhos[] = {10,100,1000,10000,100000,1000000};
    for (int i = 0; i < sizeof(tamanhos)/sizeof(tamanhos[0]); i++) {
        if (tamanhos[i] == n) return true;
    }
    return false;
}

int main() {
    int op,tam;
    char escolha = '';
    do {
        cout << "\n                                       ------ M E N U ------ \n";
        cout << "Escolha uma Funcao:\n";
        cout << "1. Insertion Sort \n";
        cout << "2. Selection Sort \n";
        cout << "3. Bubble Sort \n";
        cout << "4. Shell Sort \n";
        cout << "5. Sair\n";

        cin >> op ;

        if (op == 1) {  // Executa o algoritmo Insertion Sort
            cout << "Escolha a forma de entrada que voce deseja ou S para sair: \n";
            cout << "C. Crescente\n";
            cout << "D. Decrescente\n";
            cout << "R. Random\n";
            cin >> escolha;
            escolha = toupper(escolha);

            if (escolha == 'S') {
                cout << "Saindo da Aplicacao..." << endl;
                op = 5;
                break;
            }
            if ( escolha != 'C' && escolha != 'D' && escolha != 'R') {
                cout << "Opcao invalida!\n";
                continue;
            }

            cout << "Digite o tamanho da entrada (10,100,1000,10000,100000,1000000):\n";
            cin >> tam;

            if (!tamanhoValido(tam)) {
                cout << "Tamanho invalido!\n";
                continue;
            }
            executarInsertionSort(escolha, tam);
        }
        else if (op == 2) { // Executa o algoritmo Selection Sort
            cout << "Escolha a forma de entrada que voce deseja ou S para sair: \n";
            cout << "C. Crescente\n";
            cout << "D. Decrescente\n";
            cout << "R. Random\n";
            cin >> escolha;
            escolha = toupper(escolha);

            if (escolha == 'S') {
                cout << "Saindo da Aplicacao..." << endl;
                op = 5;
                break;
            }
            if ( escolha != 'C' && escolha != 'D' && escolha != 'R') {
                cout << "Opcao invalida!\n";
                continue;
            }

            cout << "Digite o tamanho da entrada (10,100,1000,10000,100000,1000000):\n";
            cin >> tam;

            if (!tamanhoValido(tam)) {
                cout << "Tamanho invalido!\n";
                continue;
            }
            executarSelectionSort(escolha, tam);

        }
        else if (op == 3) { // Executa o algoritmo Bubble Sort
            cout << "Escolha a forma de entrada que voce deseja ou S para sair: \n";
            cout << "C. Crescente\n";
            cout << "D. Decrescente\n";
            cout << "R. Random\n";
            cin >> escolha;
            escolha = toupper(escolha);

            if (escolha == 'S') {
                cout << "Saindo da Aplicacao..." << endl;
                op = 5;
                break;
            }
            if ( escolha != 'C' && escolha != 'D' && escolha != 'R') {
                cout << "Opcao invalida!\n";
                continue;
            }

            cout << "Digite o tamanho da entrada (10,100,1000,10000,100000,1000000):\n";
            cin >> tam;

            if (!tamanhoValido(tam)) {
                cout << "Tamanho invalido!\n";
                continue;
            }
            executarBubbleSort(escolha,tam);

        }
        else if (op == 4) { // Executa o algoritmo Shell Sort
            cout << "Escolha a forma de entrada que voce deseja ou S para sair: \n";
            cout << "C. Crescente\n";
            cout << "D. Decrescente\n";
            cout << "R. Random\n";
            cin >> escolha;
            escolha = toupper(escolha);

            if (escolha == 'S') {
                cout << "Saindo da Aplicacao..." << endl;
                op = 5;
                break;
            }
            if ( escolha != 'C' && escolha != 'D' && escolha != 'R') {
                cout << "Opcao invalida!\n";
                continue;
            }

            cout << "Digite o tamanho da entrada (10,100,1000,10000,100000,1000000):\n";
            cin >> tam;

            if (!tamanhoValido(tam)) {
                cout << "Tamanho invalido!\n";
                continue;
            }
            executarShellSort(escolha, tam);
        }
        else{
        cout << "Opcao invalida!\n";
        break;
        }
    }while (op != 5);

    cout << "Programa finalizado!\n";
    return 0;
}



