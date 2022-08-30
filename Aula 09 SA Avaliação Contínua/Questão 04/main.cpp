/*
    4. Criar um algoritmo que entre com valores inteiros para uma matriz m 3 x 3 e
    imprimir a matriz final, conforme mostrado a seguir (a matriz gira 90°):

    [1 2 3
    4 5 6
    7 8 9]
    ⇒
    [7 4 1
    8 5 2
    9 6 3]
 */

#include <iostream>

using namespace std;

int tamanhoMatriz = 3;

void preencherMatriz(int matriz[][3])
{
    int i, j;
    for (i = 0; i < tamanhoMatriz; i++)
    {
        for (j = 0; j < tamanhoMatriz; j++)
        {
            cout << "Posicao [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void imprimirMatriz(int matriz[][3]) {
    int i, j;
    for(i = 0; i < tamanhoMatriz; i++) {
        for(j = 0; j < tamanhoMatriz; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void girarMatriz90(int matriz[][3])
{
    int matriz90[3][3];

    int i, j;
    for (i = 0; i < tamanhoMatriz; i++)
    {
        for (j = 0; j < tamanhoMatriz; j++)
        {
            matriz90[j][tamanhoMatriz - 1 - i] = matriz[i][j];
        }
    }

    for(i = 0; i < tamanhoMatriz; i++)
    {
        for(j = 0; j < tamanhoMatriz; j++){
            matriz[i][j] = matriz90[i][j];
        }
    }
}

int main()
{
    int matriz[3][3];

    preencherMatriz(matriz);

    cout << "Antes da troca: " << endl;
    imprimirMatriz(matriz);

    cout << "Invertendo a matriz ..." << endl;
    girarMatriz90(matriz);

    cout << "Após a inversão: " << endl;
    imprimirMatriz(matriz);

    return 0;
}
