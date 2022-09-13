#include <iostream>
#include <string>

using namespace std;

class Carro {
    public:
    int numeroChapa;
    string marca;
    int horaEntrada;
    int horaSaida;

    Carro() {
        this->numeroChapa = 0;
        this->horaEntrada = 0;
        this->horaSaida = 0;
        this->marca = "";
    }

    Carro(int numeroChapa, int horaEntrada, int horaSaida, string marca) {
        this->numeroChapa = numeroChapa;
        this->horaEntrada = horaEntrada;
        this->horaSaida = horaSaida;
        this->marca = marca;
    }

    void Imprimir() {
        cout << "Numero Chapa: " << this->numeroChapa << endl;
        cout << "Marca: " << this->marca << endl;
        cout << "Hora Entrada: " << this->horaEntrada << ":00:00" << endl;
        cout << "Hora Saida: " << this->horaSaida << ":00:00" << endl;
    }

    int Taxa() {
        int taxa = 1;
        int valorCobrado = (this->horaSaida - this->horaEntrada) * taxa;

        return valorCobrado;
    }

    void Relatorio() {
        cout << "###### Relatorio Carro " << this->marca << " - Chapa " << this->numeroChapa << " #########\n\n";
        cout << "Hora Entrada: " << this->horaEntrada << ":00:00" << endl;
        cout << "Hora Saida: " << this->horaSaida << ":00:00" << endl;
        cout << "Taxa: R$" << Taxa() << ",00\n\n";
        cout << "###########################################################" << "\n\n";
    }
};
