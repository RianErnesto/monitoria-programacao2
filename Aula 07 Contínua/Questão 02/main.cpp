/* 
    2. Desenvolva uma função que recebe as seguinte informações de uma
    circunferência e de um retângulo:
    • Circunferência: valores inteiros para o tamanho do raio e das
    coordenadas cartesiana do seu centro.
    • Retângulo: valores inteiros das coordenadas das quatro pontas do
    retângulo.
    Com essas informações, a função deve retornar 1 caso a circunferência
    esteja tocando no retângulo e caso contrário, a função retorna 0. 
*/

#include <iostream>

using namespace std;

typedef struct Circunferencia {
    int raio;
    int x;
    int y;
} Circunferencia;

typedef struct Quadrado {
    int superiorEsquerdo[2];
    int superiorDireito[2];
    int inferiorEsquerdo[2];
    int inferiorDireito[2];
} Quadrado;

bool PontoToca(Circunferencia c, int x, int y) {
    if((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) <= c.raio * c.raio)
        return true;
    return false;
}

bool VerificarSeToca(Circunferencia c, Quadrado q) {
    if(PontoToca(c, q.superiorEsquerdo[0], q.superiorEsquerdo[1]))
        return true;
    if(PontoToca(c, q.superiorDireito[0], q.superiorDireito[1]))
        return true;
    if(PontoToca(c, q.inferiorEsquerdo[0], q.inferiorEsquerdo[1]))
        return true;
    if(PontoToca(c, q.inferiorDireito[0], q.inferiorDireito[1]))
        return true;
    return false;
}

int main() {

    Circunferencia circunferencia;
    Quadrado quadrado;

    cout << "Posição x da circunferencia: ";
    cin >> circunferencia.x;
    cout << "Posição y da circunferencia: ";
    cin >> circunferencia.y;
    cout << "Raio da circunferencia: ";
    cin >> circunferencia.raio;

    cout << "Posição x do Canto superior esquerdo do quadrado: ";
    cin >> quadrado.superiorEsquerdo[0];
    cout << "Posição y do Canto superior esquerdo do quadrado: ";
    cin >> quadrado.superiorEsquerdo[1];

    cout << "Posição x do Canto superior direito do quadrado: ";
    cin >> quadrado.superiorDireito[0];
    cout << "Posição y do Canto superior direito do quadrado: ";
    cin >> quadrado.superiorDireito[1];

    cout << "Posição x do Canto inferior esquerdo do quadrado: ";
    cin >> quadrado.inferiorEsquerdo[0];
    cout << "Posição y do Canto inferior esquerdo do quadrado: ";
    cin >> quadrado.inferiorEsquerdo[1];

    cout << "Posição x do Canto inferior direito do quadrado: ";
    cin >> quadrado.inferiorDireito[0];
    cout << "Posição y do Canto inferior direito do quadrado: ";
    cin >> quadrado.inferiorDireito[1];

    if(VerificarSeToca(circunferencia, quadrado)){
    	cout << "O Quadrado toca/pertence ao círculo";
	}
	else {
		cout << "O Quadrado não toca/pertence ao círculo";
	}

    return 0;
}
