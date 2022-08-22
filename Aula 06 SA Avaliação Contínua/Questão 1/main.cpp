/*
    1. Utilizando sobrecarga, desenvolva uma função Perimetro que receba como
    parâmetro de entrada os valores dos lados de um triângulo, quadrado ou
    pentágono e retorne seu perímetro.
*/

#include <iostream>

using namespace std;

int CalculatePerimeter(int sideValue)
{
    return sideValue * 4;
}

int CalculatePerimeter(int sideValue1, int sideValue2, int sideValue3)
{
    return sideValue1 + sideValue2 + sideValue3;
}

int CalculatePerimeter(int sideValue1, int sideValue2, int sideValue3, int sideValue4, int sideValue5)
{
    return sideValue1 + sideValue2 + sideValue3 + sideValue4 + sideValue5;
}

int main()
{
    int polygonType;
    int currentSide = 0;

Choose:
    cout << "Wish Polygon do you want to calculate the perimeter?:\n1 - Triangle\n2 - Square\n3 - Pentagon\nR:";
    cin >> polygonType;

    switch (polygonType)
    {
    case 1:
        int sidesTriangle[3];
		currentSide = 0;
		
        while (currentSide < 3)
        {
            cout << "Side " << currentSide << ": ";
            cin >> sidesTriangle[currentSide];
            currentSide++;
        }

        cout << CalculatePerimeter(sidesTriangle[0], sidesTriangle[1], sidesTriangle[2]);
        break;
        
    case 2:
        int sideValue;
        cout << "Side value: ";
        cin >> sideValue;

        cout << CalculatePerimeter(sideValue);
        break;
        
    case 3:
        int sidesPentagon[5];
        currentSide = 0;

        while (currentSide < 5)
        {
            cout << "Side " << currentSide << ": ";
            cin >> sidesPentagon[currentSide];
            currentSide++;
        }

        cout << CalculatePerimeter(sidesPentagon[0], sidesPentagon[1], sidesPentagon[2], sidesPentagon[3], sidesPentagon[4]);
        break;
    default:
        cout << "You chose an invalid polygon type!" << endl;
        goto Choose;
        break;
    }

    return 0;
}
