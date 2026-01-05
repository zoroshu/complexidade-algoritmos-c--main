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
#include "HeapSort/heapsort.cpp"

using namespace std;

int main() {
    int op, tam;
    char escolha;
    bool menu = true;

    do {
        cout << "\n                                       ------ M E N U ------ \n";
        cout << "Escolha uma Funcao:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Shell Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Heap Sort (com arquivos)\n";
        cout << "8. Heap (modo interativo / fila de prioridade)\n";
        cout << "9. Sair\n";

        cin >> op;

        if (op == 1) {  // Insertion Sort
            if (lerParametros(escolha, tam)) {
                executarInsertionSort(escolha, tam);
            }

        } else if (op == 2) { // Selection Sort
            if (lerParametros(escolha, tam)) {
                executarSelectionSort(escolha, tam);
            }

        } else if (op == 3) { // Bubble Sort
            if (lerParametros(escolha, tam)) {
                executarBubbleSort(escolha, tam);
            }

        } else if (op == 4) { // Shell Sort
            if (lerParametros(escolha, tam)) {
                executarShellSort(escolha, tam);
            }

        } else if (op == 5) { // Merge Sort
            if (lerParametros(escolha, tam)) {
                executarMergeSort(escolha, tam);
            }

        } else if (op == 6) { // Quick Sort (3 versões)
            int versao = 0;
            cout << "Escolha a versao do Quick Sort que deseja:\n";
            cout << "1. Quick Sort V1 - Pivo no primeiro elemento\n";
            cout << "2. Quick Sort V2 - Pivo utilizando media\n";
            cout << "3. Quick Sort V3 - Pivo aleatorio\n";
            cin >> versao;

            if (versao != 1 && versao != 2 && versao != 3) {
                cout << "Erro: versao do Quick Sort invalida.\n";
                continue;
            }

            if (lerParametros(escolha, tam)) {
                executarQuickSort(escolha, tam, versao);
            }

        } else if (op == 7) {
            if (lerParametros(escolha, tam)) {
                executarHeapSort(escolha, tam);
            }

        } else if (op == 8) {
            const int CAP = 100;
            int heap[CAP];
            int heapSize = 0;

            cout << "\n--- MODO INTERATIVO DE MIN-HEAP ---\n";
            cout << "Digite o tamanho inicial do heap (<= " << CAP << "): ";
            cin >> heapSize;

            if (heapSize < 0 || heapSize > CAP) {
                cout << "Tamanho invalido!\n";
                continue;
            }

            cout << "Digite " << heapSize << " valores inteiros:\n";
            for (int i = 0; i < heapSize; ++i) {
                cin >> heap[i];
            }

            BUILD_MIN_HEAP(heap, heapSize);

            int opHeap;
            do {
                cout << "\n------ M E N U   H E A P ------\n";
                cout << "1. Imprimir heap (vetor)\n";
                cout << "2. HEAP_MINIMUM\n";
                cout << "3. HEAP_EXTRACT_MIN\n";
                cout << "4. MIN_HEAP_INSERT\n";
                cout << "0. Voltar ao menu principal\n";
                cout << "Escolha uma opcao: ";
                cin >> opHeap;

                if (opHeap == 1) {
                    cout << "Heap atual (como vetor): ";
                    for (int i = 0; i < heapSize; ++i) {
                        cout << heap[i] << " ";
                    }
                    cout << "\n";

                } else if (opHeap == 2) {
                    int minimo = HEAP_MINIMUM(heap, heapSize);
                    if (heapSize > 0)
                        cout << "HEAP_MINIMUM = " << minimo << "\n";
                    else
                        cout << "Heap vazio.\n";

                } else if (opHeap == 3) {
                    if (heapSize == 0) {
                        cout << "Heap vazio, nao ha o que extrair.\n";
                    } else {
                        int extraido = HEAP_EXTRACT_MIN(heap, heapSize);
                        cout << "HEAP_EXTRACT_MIN = " << extraido << "\n";
                    }

                } else if (opHeap == 4) {
                    if (heapSize == CAP) {
                        cout << "Heap cheio, nao e possivel inserir.\n";
                    } else {
                        int valor;
                        cout << "Digite o valor a ser inserido: ";
                        cin >> valor;
                        MIN_HEAP_INSERT(heap, heapSize, CAP, valor);
                        cout << "Valor " << valor << " inserido no heap.\n";
                    }

                } else if (opHeap == 0) {
                    cout << "Retornando ao menu principal...\n";

                } else {
                    cout << "Opcao invalida no menu do heap!\n";
                }

            } while (opHeap != 0);

        } else if (op == 9) {
            cout << "Saindo do programa...\n";
            menu = false;

        } else {
            cout << "Opcao invalida!\n";
        }

    } while (menu);

    cout << "Programa finalizado!\n";
    return 0;
}