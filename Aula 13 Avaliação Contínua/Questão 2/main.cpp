#include <iostream>
#include <string>
#include "Carro.cpp"

using namespace std;

int main() {
    Carro carro = Carro();
    Carro carro1 = Carro(222, 7, 12, "Ford");


    //Alternativas A, B e C
    cout << "--- Alternativas A, B e C ---\n";
    carro.Imprimir();
    carro1.Imprimir();
    cout << endl;

    //Alternativa D
    cout << "--- Alternativa D ---\n";
    cout << "R$" << carro1.Taxa() << ",00\n";
    cout << endl;

    //Alternativa E
    cout << "--- Alternativa E ---\n";
    Carro carros[5];

    int i;
    for(i = 0; i < 5; i++){
        int numeroChapa;
        string marca;
        int horaEntrada;
        int horaSaida;

        cout << "Carro " << i + 1 << endl;

        cout << "Numero Chapa: ";
        cin >> numeroChapa;

        cout << "Marca: ";
        cin >> marca;

        cout << "Hora Entrada: ";
        cin >> horaEntrada;

        cout << "Hora Saida: ";
        cin >> horaSaida;

        carros[i] = Carro(numeroChapa, horaEntrada, horaSaida, marca);
        cout << "\n\n";
    }

    for(i = 0; i < 5; i++) {
        carros[i].Relatorio();
    }

    return 0;
}