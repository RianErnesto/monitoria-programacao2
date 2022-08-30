/* 
    3. Crie um algoritmo onde o usuário vai inserir os valores para três vetores
    (A, B e C) de 10 elementos. O algoritmo deve somar os elementos de
    mesma posição do vetor A e B e depois dividir pelo elemento do vetor C.
    Escrever na tela o resultado de cada um. 
*/

#include <iostream>

using namespace std;

int tamanhoVetor = 10;

void preencherVetor(int vetor[]) {
    int i;
    for(i = 0; i < tamanhoVetor; i++) {
        cout << "Posicao " << i + 1 << ": ";
        cin >> vetor[i];
    }
}

void calcular(int vetorA[], int vetorB[], int vetorC[]) {
    int i;
    for(i = 0; i < tamanhoVetor; i++) {
        float resultado = (vetorA[i] + vetorB[i]) / (float)vetorC[i];
        cout << "Posicao " << i + 1 << ": " << resultado << endl;
    }
}

int main() {
    int vetorA[10], vetorB[10], vetorC[10];

    cout << "----- Vetor A ------\n";
    preencherVetor(vetorA);

    cout << "----- Vetor B ------\n";
    preencherVetor(vetorB);

    cout << "----- Vetor C ------\n";
    preencherVetor(vetorC);

    cout << "Calculando..." << endl << endl;

    calcular(vetorA, vetorB, vetorC);

    return 0;
}
