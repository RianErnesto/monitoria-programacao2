/*
    3. Utilizando sobrecarga, desenvolva uma função MaiorValor que recebe de 2
    até 4 valores e retorne o maior desses valores.
*/

#include <iostream>

using namespace std;

int MaiorValor(int value1, int value2)
{
    return value1 > value2 ? value1 : value2;
}

int MaiorValor(int value1, int value2, int value3)
{
    int values[3] = {value1, value2, value3};
    int greatestValue = values[0];
    int currentValue;
    for (currentValue = 1; currentValue < 3; currentValue++)
    {
        if (values[currentValue] > greatestValue)
            greatestValue = values[currentValue];
    }
    return greatestValue;
}

int MaiorValor(int value1, int value2, int value3, int value4)
{
    int values[4] = {value1, value2, value3, value4};
    int greatestValue = values[0];
    int currentValue;
    for (currentValue = 1; currentValue < 4; currentValue++)
    {
        if (values[currentValue] > greatestValue)
            greatestValue = values[currentValue];
    }
    return greatestValue;
}

int main()
{
    int quantity;
    int values[4];

Choose:
    int currentNumber = 0;
    cout << "How many values do you wanna check? Between 2 and 4 values: ";
    cin >> quantity;

    switch (quantity)
    {
        {
        case 2:
            for (currentNumber = 0; currentNumber < quantity; currentNumber++)
            {
                cout << "Value " << currentNumber + 1 << ": ";
                cin >> values[currentNumber];
            }

            cout << "Maior valor é: " << MaiorValor(values[0], values[1]);
            break;
        case 3:
            for (currentNumber = 0; currentNumber < quantity; currentNumber++)
            {
                cout << "Value " << currentNumber + 1 << ": ";
                cin >> values[currentNumber];
            }

            cout << "Maior valor é: " << MaiorValor(values[0], values[1], values[2]);
            break;
        case 4:
            for (currentNumber = 0; currentNumber < quantity; currentNumber++)
            {
                cout << "Value " << currentNumber + 1 << ": ";
                cin >> values[currentNumber];
            }

            cout << "Maior valor é: " << MaiorValor(values[0], values[1], values[2], values[3]);
            break;
        default:
            cout << "You chose an invalid quantity !";
            goto Choose;
            break;
        }

        return 0;
    }
}
