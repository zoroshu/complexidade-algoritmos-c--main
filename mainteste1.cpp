//
// Created by Victor F on 17/09/2025.
//

#include <iostream>
#include <ostream>
#include "insertionsort.cpp"
#include "gerarentradas.cpp"
#include "salvararquivos.cpp"
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    int array[] = {22,68,54,21,99,4578,3,2,1,5,4,7,88,66666,854,325,6,4,5,7};
    int n = sizeof(array) / sizeof(array[0]);
    cout << "Array desordenado: \n";
    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }
    auto start = chrono::high_resolution_clock::now();
    insertionSort(array, n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    double tempo = duration.count();
    cout << "Array ordenado: \n";
    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }
    cout << "Tempo gasto " + to_string(tempo) + "ms" << endl;

    return 0;
}