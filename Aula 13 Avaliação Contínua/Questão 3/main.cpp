#include <iostream>
#include <string>
#include "Restaurante.cpp"

using namespace std;

int main() {
    Restaurante restaurantes[2][2];

    int i,j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            restaurantes[i][j] = Restaurante();
            string nome;
            string endereco;
            float preco;
            string tipoComida;

            cout << "Nome: ";
            cin >> nome;
			fflush(stdin);

            cout << "Endereco: ";
            cin >> endereco;
			fflush(stdin);

            cout << "Preco: ";
            cin >> preco;
			fflush(stdin);

            cout << "Tipo Comida: ";
            cin >> tipoComida;
			fflush(stdin);
			
            restaurantes[i][j] = Restaurante(nome, endereco, preco, tipoComida);
			
			fflush(stdin);
            cout << endl;
        }
    }

    string tipoComida;

    cout << "Qual o tipo de comida? ";
    cin >> tipoComida;

    cout << "Restaurantes que possuem a comida " << tipoComida << endl;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(restaurantes[i][j].tipoComida == tipoComida) {
                restaurantes[i][j].Imprimir();
            }
        }
    }

    return 0;
}
