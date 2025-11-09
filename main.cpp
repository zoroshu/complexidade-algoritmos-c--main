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
#include "MergeSort/mergesort.h"
#include "MergeSort/mergesort.cpp"
#include "ShellSort/shellsort.cpp"
#include "QuickSort/quicksort.h"
#include "QuickSort/quicksort.cpp"

using namespace std;

int main() {
    int op,tam,menu;
    menu = 1;
    char escolha;
    do {
        cout << "\n                                       ------ M E N U ------ \n";
        cout << "Escolha uma Funcao:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Shell Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Sair\n";

       cin >> op ;

        if (op == 1) {  // Executa o algoritmo Insertion Sort
            if (lerParametros(escolha, tam)){
                executarInsertionSort(escolha, tam);
            }
        }
        else if (op == 2) { // Executa o algoritmo Selection Sort
             if (lerParametros(escolha, tam)){
                executarSelectionSort(escolha, tam);
            }
        }
        else if (op == 3) { // Executa o algoritmo Bubble Sort
        if (lerParametros(escolha, tam)){
            executarBubbleSort(escolha, tam);
            }
        }
        else if (op == 4) { // Executa o algoritmo Shell Sort
           if (lerParametros(escolha, tam)){
               executarShellSort(escolha, tam);
           }
        }else if (op == 5) { // Executa o algoritmo Merge Sort
            if (lerParametros(escolha, tam)) {
                executarMergeSort(escolha, tam);
            }
        }
        else if (op == 6) {
            int versao =0;
            cout << "Escolha a versao do Quick Sort que deseja:\n";
            cout << "1. Quick Sort V1 - Pivo no primeiro elemento\n";
            cout << "2. Quick Sort V2 - Pivo utilizando media\n";
            cout << "3. Quick Sort V3 - Pivo aleatorio\n";
            cin >> versao;
            if (versao != 1 && versao != 2 && versao != 3) {
                cout << "Erro versao do Quick Sort\n";
                break;
            }
          if (lerParametros(escolha, tam)) {
              executarQuickSort(escolha, tam,versao);
          }
        }
        else if (op == 7) {
            cout << "Saindo do programa...\n";
            menu = 0;
        }
        else{
        cout << "Opcao invalida!\n";
            break;
        }
    }while (menu);
    cout << "Programa finalizado!\n";
        return 0;
}
