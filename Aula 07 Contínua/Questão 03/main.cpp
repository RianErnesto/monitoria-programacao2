/* 
    3. Desenvolva uma função que desenhe um trapézio retângulo, para isso a
    função precisa receber o valor da base maior e da base menor. 
*/

#include <iostream>

using namespace std;

void DesenharTrapezio(int ladoMenor, int ladoMaior) {
    int quantidadeEspacos = ladoMaior - ladoMenor;

    int i, j;
    for(i = 0; i < quantidadeEspacos; i++){
        if(i == 0) {
            for(j = 0; j < ladoMenor; j++){
                cout << "-";
            }
            cout << endl;
            continue;
        }

        if(i == quantidadeEspacos - 1) {
            for(j = 0; j < ladoMaior; j++){
                cout << "-";
            }
            cout << endl;
            continue;
        }

        for(j = 0; j <= ladoMenor + i; j++){
            if(j == 0) {
                cout << "|";
                continue;
            }

            if(j == ladoMenor + i) {
                cout << "\\";
                continue;
            }

            cout << ' ';
        }
        cout << endl;
    }
}

int main() {

    int ladoMenor, ladoMaior;

    cout << "Lado Maior: ";
    cin >> ladoMaior;

    cout << "Lado Menor: ";
    cin >> ladoMenor;

    DesenharTrapezio(ladoMenor, ladoMaior);

    return 0;
}