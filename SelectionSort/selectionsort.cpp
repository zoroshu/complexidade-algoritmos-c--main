//
// Created by Victor F on 21/09/2025.
//

void selectionSort(int vet[], int n){                 // Ordena 'vet' (tamanho n) por Selection Sort
    int index_minimo, aux;                            // index_minimo: índice do menor na região não ordenada; aux: temporário

    for ( int i = 0; i < n - 1; i++ ){                // Para cada posição i (exceto a última)...
        index_minimo = i;                             // ...supõe que o menor está em i

        for ( int j = i + 1; j < n; j++ ){            // Varre o restante do vetor (da zona não ordenada)
            if ( vet[j] < vet[index_minimo] ){        // Se achar elemento menor que o atual mínimo...
                index_minimo = j;                     // ...atualiza o índice do menor
            }
        }
        if (index_minimo != i){                       // Se o menor não está em i...
            aux = vet[i];                             // ...guarda vet[i]
            vet[i] = vet[index_minimo];               // ...traz o menor para a posição i
            vet[index_minimo] = aux;                  // ...coloca o antigo vet[i] na posição do menor
        }                                             // Ao final, vet[i] fica na posição correta
    }
}                                                     // Fim da função

void executarSelectionSort(char tipo, int n) {
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

    string algoritmo = "SelectionSort/"; // caminho para salvar arquivo

    string diretorioEntrada = algoritmo + "Arquivos de Entrada/" + subpasta +
                              "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = algoritmo + "Arquivos de Saida/"   + subpasta +
                              "Saida" + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = algoritmo + "Arquivos de Tempo/"   + subpasta +
                              "Tempo" + prefixo + to_string(n) + ".txt";

    salvarArquivos(diretorioEntrada, vet, n);

    auto start = chrono::high_resolution_clock::now();
    cout << "Iniciando Ordenacao... \n";
    selectionSort(vet, n);
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;
    cout << "Vetor ordenado! \n";
    salvarTempo(diretorioTempo, n, duration.count());
    salvarArquivos(diretorioSaida, vet, n);
    cout << "Arquivos Salvos em seus respectivos diretorios! \n";
    delete[] vet;
}
