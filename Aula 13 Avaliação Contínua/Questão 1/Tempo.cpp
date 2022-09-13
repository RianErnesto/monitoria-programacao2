#include <iostream>
#include <math.h>

using namespace std;

class Tempo
{
public:
    int horas;
    int mins;
    int segs;

    Tempo()
    {
        this->horas = 0;
        this->mins = 0;
        this->segs = 0;
    }

    Tempo(int horas, int mins, int segs)
    {
        this->horas = horas;
        this->mins = mins;
        this->segs = segs;
    }

    void init(int horas, int mins, int segs)
    {
        this->horas = horas;
        this->mins = mins;
        this->segs = segs;
    }

    void Imprimir() {
        cout << this->horas << ":" << this->mins << ":" << this->segs << endl;
    }

    void Soma(Tempo tempo1, Tempo tempo2) {
        int segundosTempo1 = PassarParaSegundos(tempo1);
        int segundosTempo2 = PassarParaSegundos(tempo2);
        int segundosTotal = segundosTempo1 + segundosTempo2;

        int horas = floor((segundosTotal / 60) / 60);
        int minutos = floor((segundosTotal % 3600) / 60);
        int segundos = segundosTotal % 60;

        this->horas = horas;
        this->mins = minutos;
        this->segs = segundos;
    }

    Tempo Soma(Tempo tempo) {
        int segundosTempo1 = PassarParaSegundos(tempo);
        int segundosTempo2 = PassarParaSegundos(Tempo(this->horas, this->mins, this->segs));
        int segundosTotal = segundosTempo1 + segundosTempo2;

        int horas = floor((segundosTotal / 60) / 60);
        int minutos = floor((segundosTotal % 3600) / 60);
        int segundos = segundosTotal % 60;

        Tempo novoTempo = Tempo(horas, minutos, segundos);

        return novoTempo;
    }

    int Subtrair(Tempo tempo1, Tempo tempo2) {
        int segundosTempo1 = PassarParaSegundos(tempo1);
        int segundosTempo2 = PassarParaSegundos(tempo2);
        int diferenca = segundosTempo1 - segundosTempo2;

        return diferenca;
    }

    int PassarParaSegundos(Tempo tempo) {
        int segundos = (tempo.horas * 60 * 60) + (tempo.mins * 60) + tempo.segs;
        return segundos;
    }
};
