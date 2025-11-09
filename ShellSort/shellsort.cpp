//
// Created by Victor F on 21/09/2025.
//
void shellSort (int vet[], int n) {                   // Ordena 'vet' (tamanho n) por Shell Sort
    for (int gap = n / 2; gap > 0; gap /= 2) {        // Define sequência de gaps (n/2, n/4, ..., 1)

        // Percorremos os elementos a partir do índice "gap"
        // Cada sub-sequência separada pelo gap será ordenada como no Insertion Sort
        for (int i = gap; i < n; i++) {               // Para cada elemento na janela deslocada por 'gap'...
            int aux = vet[i];                         // ...salva o valor atual
            int j;                                    // ...índice para varrer para trás por passos de 'gap'

            // Move elementos que estão distantes "gap" posições, enquanto forem maiores que aux
            for (j = i; j >= gap && vet[j - gap] > aux; j -= gap) {
                vet[j] = vet[j - gap];                // Desloca o elemento maior 'gap' posições à frente
            }
            vet[j] = aux;                             // Insere 'aux' na posição correta dentro da subsequência h-espaçada
        }
    }
}                                                     // Fim da função

void executarShellSort(char tipo, int n) {
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

    string algoritmo = "ShellSort/"; // caminho para salvar arquivo

    string diretorioEntrada = algoritmo + "Arquivos de Entrada/" + subpasta +
                              "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = algoritmo + "Arquivos de Saida/"   + subpasta +
                              "Saida" + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = algoritmo + "Arquivos de Tempo/"   + subpasta +
                              "Tempo" + prefixo + to_string(n) + ".txt";

    salvarArquivos(diretorioEntrada, vet, n);

    auto start = chrono::high_resolution_clock::now();
    cout << "Iniciando Ordenacao... \n";
    shellSort(vet, n);
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;
    cout << "Vetor ordenado! \n";
    salvarTempo(diretorioTempo, n, duration.count());
    salvarArquivos(diretorioSaida, vet, n);
    cout << "Arquivos Salvos em seus respectivos diretorios! \n";
    delete[] vet;
}



