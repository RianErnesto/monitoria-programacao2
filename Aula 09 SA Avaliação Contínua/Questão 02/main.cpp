/* 
    2. Criar um algoritmo que leia os elementos de um vetor com 20 posições e
    escreva-os. Em seguida, troque o primeiro elemento pelo último, o
    segundo pelo penúltimo, o terceiro pelo antepenúltimo, e assim
    sucessivamente. Mostre o vetor depois da troca. 
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int tamanhoVetor = 20;

void preencherVetor(int vetor[]) {
    int i;
    for(i = 0; i < tamanhoVetor; i++) {
        vetor[i] = rand() % 10;
    }
}

void imprimirVetor(int vetor[]) {
    int i;
    for(i = 0; i < tamanhoVetor; i++) {
        cout << "Posicao " << i + 1 << ": " << vetor[i] << endl;
    }
}

void trocarPosicoes(int vetor[]) {
    int i, j;
    for(i = 0, j = tamanhoVetor - 1; i < j; i++, j--) {
        int numeroSalvo = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = numeroSalvo;
    }
}

int main() {
    srand(time(0));

    int vetor[20];

    cout << "Preenchendo o vetor com numeros entre 0 e 10..." << endl;
    preencherVetor(vetor);

    cout << "Vetor antes da troca: " << endl;
    imprimirVetor(vetor);

    trocarPosicoes(vetor);

    cout << "Vetor depois da troca: " << endl;
    imprimirVetor(vetor);


    return 0;
}
