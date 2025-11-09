//
// Created by Victor F on 21/09/2025.
//

void bubbleSort(int* vet, int n){                    // Função que ordena 'vet' (tamanho n) por Bubble Sort

    int i,j, aux;                                     // i e j: índices; aux: variável temporária para troca
    int trocado;  // flag para detectar se houve troca na passada
    for( i = 0 ; i < n - 1; i++){                     // Passa n-1 vezes pelo vetor (cada passada coloca 1 elemento no lugar)
        trocado = 0;                                  // Assume que ainda não houve troca nesta passada

        for (j = 0 ; j < n - i - 1; j++){             // Varre até o último elemento “não fixado” (n - i - 1)
            if (vet[j] > vet[j + 1]) {                // Se dois adjacentes estão fora de ordem...
                aux = vet[j];                         // ...guarda vet[j] em aux
                vet[j] = vet[j + 1];                  // ...move o menor para a esquerda
                vet[j + 1] = aux;                     // ...coloca o maior à direita
                trocado = 1;                          // Marca que houve ao menos uma troca nesta passada
            }
        }
        if (!trocado){                                // Se nenhuma troca ocorreu, o vetor já está ordenado
            break;                                    // Sai cedo (otimização do melhor caso)
        }
    }
}                                                     // Fim da função

void executarBubbleSort(char tipo, int n) {
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

    string algoritmo = "BubbleSort/"; // caminho para salvar arquivo

    string diretorioEntrada = algoritmo + "Arquivos de Entrada/" + subpasta +
                              "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = algoritmo + "Arquivos de Saida/"   + subpasta +
                              "Saida" + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = algoritmo + "Arquivos de Tempo/"   + subpasta +
                              "Tempo" + prefixo + to_string(n) + ".txt";

    salvarArquivos(diretorioEntrada, vet, n);

    auto start = chrono::high_resolution_clock::now();
    cout << "Iniciando Ordenacao... \n";
    bubbleSort(vet, n);
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;
    cout << "Vetor ordenado! \n";
    salvarTempo(diretorioTempo, n, duration.count());
    salvarArquivos(diretorioSaida, vet, n);
    cout << "Arquivos Salvos em seus respectivos diretorios! \n";
    delete[] vet;
}


