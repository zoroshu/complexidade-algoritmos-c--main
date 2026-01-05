//
// Created by Victor F on 22/11/2025.
//

#ifndef COMPLEXIDADE_ALGORITMOS_C_MAIN_HEAPSORT_H
#define COMPLEXIDADE_ALGORITMOS_C_MAIN_HEAPSORT_H
void MIN_HEAPIFY(int a[], int heapSize, int i);
void BUILD_MIN_HEAP(int a[], int n);
int HEAP_MINIMUM(const int a[], int heapSize);
int HEAP_EXTRACT_MIN(int a[], int &heapSize);
void HEAP_DECREASE_KEY(int a[], int i, int newKey);
void MIN_HEAP_INSERT(int a[], int &heapSize, int n, int newKey);
void heapsortMin(int a[], int n);
void executarHeapSortMin(char tipo, int n);

#endif //COMPLEXIDADE_ALGORITMOS_C_MAIN_HEAPSORT_H