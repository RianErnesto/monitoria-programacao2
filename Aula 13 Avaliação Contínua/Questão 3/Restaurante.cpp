#include <iostream>
#include <string.h>

using namespace std;

class Restaurante
{
public:
    string nome;
    string endereco;
    float preco;
    string tipoComida;

    Restaurante()
    {
        this->nome = "";
        this->endereco = "";
        this->preco = 0.0;
        this->tipoComida = "";
    }

    Restaurante(string nome, string endereco, float preco, string tipoComida)
    {
        this->nome = nome;
        this->endereco = endereco;
        this->preco = preco;
        this->tipoComida = tipoComida;
    }

    void init(string nome, string endereco, float preco, string tipoComida)
    {
        this->nome = nome;
        this->endereco = endereco;
        this->preco = preco;
        this->tipoComida = tipoComida;
    }

    void Imprimir() {
        cout << "=========================================\n";
        cout << "Nome: " << this->nome << endl;
        cout << "Endereco: " << this->endereco << endl;
        cout << "TipoComida: " << this->tipoComida << endl;
        cout << "Preco: " << this->preco << endl;
        cout << "==========================================\n\n";
    }
};
