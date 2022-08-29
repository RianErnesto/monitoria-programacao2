/*
    1. Utilizando sobrecarga, desenvolva uma função Perimetro que receba como
    parâmetro de entrada os valores dos lados de um triângulo, quadrado ou
    pentágono e retorne seu perímetro.
*/

#include <iostream>

using namespace std;

int CalcularPerimetro(int valorLado)
{
    return valorLado * 4;
}

int CalcularPerimetro(int valorLado1, int valorLado2, int valorLado3)
{
    return valorLado1 + valorLado2 + valorLado3;
}

int CalcularPerimetro(int valorLado1, int valorLado2, int valorLado3, int valorLado4, int valorLado5)
{
    return valorLado1 + valorLado2 + valorLado3 + valorLado4 + valorLado5;
}

int main()
{
    int tipoPoligono;
    int ladoAtual = 0;

Escolha:
    cout << "Qual poligono você gostaria de calcular o perimetro?:\n1 - Triangulo\n2 - Quadrado\n3 - Pentagono\nR:";
    cin >> tipoPoligono;

    switch (tipoPoligono)
    {
    case 1:
        int ladosTriangulo[3];
		ladoAtual = 0;
		
        while (ladoAtual < 3)
        {
            cout << "Lado " << ladoAtual + 1 << ": ";
            cin >> ladosTriangulo[ladoAtual];
            ladoAtual++;
        }

        cout << CalcularPerimetro(ladosTriangulo[0], ladosTriangulo[1], ladosTriangulo[2]);
        break;
        
    case 2:
        int valorLado;
        cout << "Valor do Lado: ";
        cin >> valorLado;

        cout << CalcularPerimetro(valorLado);
        break;
        
    case 3:
        int ladosPentagono[5];
        ladoAtual = 0;

        while (ladoAtual < 5)
        {
            cout << "Lado " << ladoAtual + 1 << ": ";
            cin >> ladosPentagono[ladoAtual];
            ladoAtual++;
        }

        cout << CalcularPerimetro(ladosPentagono[0], ladosPentagono[1], ladosPentagono[2], ladosPentagono[3], ladosPentagono[4]);
        break;
    default:
        cout << "Você escolheu um tipo invalido!" << endl;
        goto Escolha;
        break;
    }

    return 0;
}
