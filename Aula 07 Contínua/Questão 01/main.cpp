/* 
    1. Utilizando a soma de Riemann, desenvolva uma função que calcule e
    retorne o resultado da integral abaixo:
    a
    ∫ (sin(x)+x)dx
    b
    
    A função tem como protótipo float Integral(int a, int b, int n)
    onde:
    • a: limite inferior;
    • b: limite superior;
    • n: quantidade de divisões do espaço. 
*/

#include <iostream>
#include <cmath>

using namespace std;

double CalcularSoma(double limiteSuperior, double limiteInferior, int quantidadeDivisoes) {
    double result = 0.0;
    double base = (limiteSuperior - limiteInferior) / quantidadeDivisoes;

    int i;
    for(i = 0; i < quantidadeDivisoes; i++) {
        result += (sin(limiteInferior + i * base) + (limiteInferior + i * base)) * base;
    }

    return result;
}

int main() {
    double limiteSuperior, limiteInferior;
    int quantidadeDivisoes;
    
    cout << "Limite Superior: ";
    cin >> limiteSuperior;

    cout << "Limite Inferior: ";
    cin >> limiteInferior;

    cout << "Quantidade Divisoes: ";
    cin >> quantidadeDivisoes;

    cout << "O resultado da soma é " << CalcularSoma(limiteSuperior, limiteInferior, quantidadeDivisoes);

    return 0;
}
