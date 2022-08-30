/* 
    1. Escreva um programa em C++ para contar o número de ocorrências de um
    determinado número em um array de inteiros. 
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int tamanhoVetor = 10;

void preencherVetor(int vetor[]) {
    int i;
    for(i = 0; i < tamanhoVetor; i++) {
        vetor[i] = rand() % 10;
    }
}

void imprimirVetor(int vetor[]) {
    int i;
    for(i = 0; i < tamanhoVetor; i++) {
        cout << vetor[i] << endl;
    }
}

int contarOcorrencias(int vetor[], int numero) {
    int quantidadeOcorrencias = 0;

    int i;
    for(i = 0; i < tamanhoVetor; i++) {
        if(vetor[i] == numero)
            quantidadeOcorrencias++;
    }

    return quantidadeOcorrencias;
}

int main() {
    int numero;
    int vetor[10];
    
    srand(time(0));

    cout << "Preenchendo o vetor com numeros entre 0 e 10..." << endl;
    preencherVetor(vetor);

    cout << "Numero que deseja contar as ocorrencias: ";
    cin >> numero;

    cout << "O numero " << numero << " aparece " << contarOcorrencias(vetor, numero) << " vezes no vetor abaixo: " << endl << endl;

    imprimirVetor(vetor);

    return 0;
}
