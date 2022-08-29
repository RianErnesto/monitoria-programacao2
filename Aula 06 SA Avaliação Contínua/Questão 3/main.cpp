/*
    3. Utilizando sobrecarga, desenvolva uma função MaiorValor que recebe de 2
    até 4 valores e retorne o maior desses valores.
*/

#include <iostream>

using namespace std;

int MaiorValor(int valor1, int valor2)
{
    return valor1 > valor2 ? valor1 : valor2;
}

int MaiorValor(int valor1, int valor2, int value3)
{
    int valores[3] = {valor1, valor2, value3};
    int maiorValor = valores[0];
    int valorAtual;
    for (valorAtual = 1; valorAtual < 3; valorAtual++)
    {
        if (valores[valorAtual] > maiorValor)
            maiorValor = valores[valorAtual];
    }
    return maiorValor;
}

int MaiorValor(int valor1, int valor2, int value3, int value4)
{
    int valores[4] = {valor1, valor2, value3, value4};
    int maiorValor = valores[0];
    int valorAtual;
    for (valorAtual = 1; valorAtual < 4; valorAtual++)
    {
        if (valores[valorAtual] > maiorValor)
            maiorValor = valores[valorAtual];
    }
    return maiorValor;
}

int main()
{
    int quantidade;
    int valores[4];

Escolha:
    int numeroAtual = 0;
    cout << "Quantos valores você deseja verificar? Entre 2 e 4 valores: ";
    cin >> quantidade;

    switch (quantidade)
    {
        {
        case 2:
            for (numeroAtual = 0; numeroAtual < quantidade; numeroAtual++)
            {
                cout << "Value " << numeroAtual + 1 << ": ";
                cin >> valores[numeroAtual];
            }

            cout << "Maior valor é: " << MaiorValor(valores[0], valores[1]);
            break;
        case 3:
            for (numeroAtual = 0; numeroAtual < quantidade; numeroAtual++)
            {
                cout << "Valor " << numeroAtual + 1 << ": ";
                cin >> valores[numeroAtual];
            }

            cout << "Maior valor é: " << MaiorValor(valores[0], valores[1], valores[2]);
            break;
        case 4:
            for (numeroAtual = 0; numeroAtual < quantidade; numeroAtual++)
            {
                cout << "Valor " << numeroAtual + 1 << ": ";
                cin >> valores[numeroAtual];
            }

            cout << "Maior valor é: " << MaiorValor(valores[0], valores[1], valores[2], valores[3]);
            break;
        default:
            cout << "Voce escolheu uma quantidade invalida !";
            goto Escolha;
            break;
        }

        return 0;
    }
}
