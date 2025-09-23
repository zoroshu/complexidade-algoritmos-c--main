//
// Created by Victor F on 21/09/2025.
//

void selectionSort(int vet[], int n){
    int index_minimo,aux;

    for ( int i = 0; i < n - 1; i++ ){
    index_minimo = i;
    for ( int j = i + 1; j < n; j++ ){
    if ( vet[j] < vet[index_minimo] ){
        index_minimo = j;
       }
     }
     if (index_minimo != i){
     aux = vet[i];
     vet[i] = vet[index_minimo];
     vet[index_minimo] = aux;
      }
    }
}

void executarSelectionSort(char tipo, int n) {
    int* vet = new int[n]; // inicializa o vetor de acordo com o tamanho de entrada fornecido

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

    // Caminhos completos para os arquivos
    string diretorioEntrada = "SelectionSort/Arquivos de Entrada/" + subpasta + "Entrada" + prefixo + to_string(n) + ".txt";
    string diretorioSaida   = "SelectionSort/Arquivos de Saida/"   + subpasta + "Saida"   + prefixo + to_string(n) + ".txt";
    string diretorioTempo   = "SelectionSort/Arquivos de Tempo/"   + subpasta + "Tempo"   + prefixo + to_string(n) + ".txt";

    // salva arquivo de entrada de acordo com prefixo já estabelecido
    salvarArquivos(diretorioEntrada,vet,n);

    cout << "Iniciando Ordenacao...\n";

    auto start = chrono::high_resolution_clock::now(); // inicia a contagem de tempo
    SelectionSort(vet, n); // realiza a ordenação
    cout<< "Vetor ordenado!" << endl;
    cout << "Salvando valores em seus respectivos arquivos..." << endl;
    auto stop = chrono::high_resolution_clock::now(); // finaliza a contagem de tempo
    chrono::duration<double> duration = stop - start;// calcula a duração da função de inserção em s
    salvarTempo(diretorioTempo,n,duration.count()); // salva a duração em um arquivo
    salvarArquivos(diretorioSaida,vet,n); // salva o arquivo de saida com vetor já ordenado

    delete[] vet; // deleta o vetor instanciado
}