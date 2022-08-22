/*
    2. Utilizando sobrecarga, desenvolva uma função CalculoRaiz que tem como
    objetivo calcular as raízes de um polinômio. Essa função receba como
    argumentos os coeficientes do polinômio e as variáveis que os resultados
    serão armazenadas. (Trabalhe somente com polinômios de 1° e 2° grau)
*/

#include <iostream>
#include <math.h>

using namespace std;

CalcularRaiz(float a, float b, float c) {
    float delta = pow(b, 2) - 4 * a * c;
    float x1, x2;

    if(delta < 0) 
        cout << "O polinômio não possui raízes reais.";
    else if(delta == 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        cout << "O polinômio possui apenas a raíz: " << x1;
    }
    else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        cout << "As raízes do polinômio são: x1 = " << x1 << " e " << "x2 = " << x2;
    }
}

CalcularRaiz(float a, float b) {
    cout << "A Raíz é: " << -b / a;
}

int main()
{
    int grauPolinomio;
Escolha:
    cout << "Qual o grau do seu polinômio?\n1 - Segundo Grau\n2 - Primeiro Grau\nR: ";
    cin >> grauPolinomio;

    switch (grauPolinomio)
    {
        {
        case 1:
            float a2, b2, c2;
            cout << "a = ";
            cin >> a2;

            cout << "b = ";
            cin >> b2;

            cout << "c = ";
            cin >> c2;
            
            CalcularRaiz(a2, b2, c2);
            break;
        case 2:
            float a1, b1;
            cout << "a = ";
            cin >> a1;

            cout << "b = ";
            cin >> b1;

            CalcularRaiz(a1, b1);
            break;
        default:
            cout << "Você escolheu um grau fora do determinado !";
            goto Escolha;
            break;
        }
    }

    return 0;
}