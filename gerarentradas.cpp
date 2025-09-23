//
// Created by Victor Felipe on 14/09/2025.
//

#include <iostream>
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
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10);
    }
}



