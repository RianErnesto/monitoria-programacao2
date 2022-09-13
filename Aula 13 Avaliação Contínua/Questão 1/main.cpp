#include <iostream>
#include "Tempo.cpp"

using namespace std;

int main() {
    Tempo tempo1 = Tempo(2, 35, 57);
    Tempo tempo2 = Tempo(1, 27, 22);
    Tempo tempo3 = Tempo(0, 42,10);
    Tempo tempo = Tempo();

    // Alternativas A, B e D
    cout << "--- Alternativas A, B e D ---" << endl;
    tempo.Imprimir();
    tempo1.Imprimir();
    tempo2.Imprimir();
    tempo3.Imprimir();
    cout << endl;

    //Alternativa C
    cout << "--- Alternativa C ---" << endl;
    tempo1.Imprimir();
    tempo1.init(3, 8, 46);
    tempo1.Imprimir();
    cout << endl;

    //Alternativa E
    cout << "--- Alternativa E ---" << endl;
    tempo.Soma(tempo1, tempo2);
    tempo.Imprimir();
    cout << endl;

    //Alternativa F
    cout << "--- Alternativa F ---" << endl;
    Tempo novoTempo = tempo1.Soma(tempo2);
    novoTempo.Imprimir();
    cout << endl;

    //Alternativa G
    cout << "--- Alternativa G ---" << endl;
    cout << tempo.Subtrair(tempo1, tempo2) << endl;

    return 0;
}
