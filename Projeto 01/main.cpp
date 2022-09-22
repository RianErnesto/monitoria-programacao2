#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "header.h"

using namespace std;

Door door;
Player player;
Key key;

void Init()
{
    player.character = '&';
    door.character = 'D';
    key.character = '@';
}

void DrawMap()
{
    int i, j;
    for (i = 0; i < currentMapLength; i++)
    {
        for (j = 0; j < currentMapLength; j++)
        {
            if (i == 0)
                map[i][j] = wall;
            else if (i == currentMapLength - 1)
                map[i][j] = wall;
            else if (j == 0)
                map[i][j] = wall;
            else if (j == currentMapLength - 1)
                map[i][j] = wall;
            else
                map[i][j] = emptyChar;
        }
    }
}

void PrintMap()
{
    int i, j;
    for (i = 0; i < currentMapLength; i++)
    {
        for (j = 0; j < currentMapLength; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void AddDoor()
{
    int doorPosition = rand() % (currentMapLength - 2) + 1;
    door.x = currentMapLength - 1;
    door.y = doorPosition;
    map[door.x][door.y] = door.character;
}

void AddPlayer()
{
    int playerPosition = rand() % (currentMapLength - 2) + 1;
    player.x = 1;
    player.y = playerPosition;

    map[player.x][player.y] = player.character;
}

void AddKey()
{
    while (true)
    {
        int keyPositionX = rand() % (currentMapLength - 2) + 1;
        int keyPositionY = rand() % (currentMapLength - 2) + 1;

        if (map[keyPositionX][keyPositionY] != player.character)
        {
            key.x = keyPositionX;
            key.y = keyPositionY;
            map[key.x][key.y] = key.character;
            break;
        }
    }
}

void AddThorn() {
    int i, j;
    for(i = 1; i < currentMapLength - 1; i++){
        for(j = 1; j < currentMapLength - 1; j++) {
            if(map[i][j] == player.character || map[i][j] == key.character || map[i + 1][j] == door.character)
                continue;
            if(rand() % 10 == 1)
                map[i][j] = thorn;
        }
    }
}

void GetAction()
{
    char move = getch();
    switch (move)
    {
    case 'w':
        if (isMoveAvailable(move))
            MovePlayer(move);
        break;
    case 's':
        if (isMoveAvailable(move))
            MovePlayer(move);
        break;
    case 'a':
        if (isMoveAvailable(move))
            MovePlayer(move);
        break;
    case 'd':
        if (isMoveAvailable(move))
            MovePlayer(move);
        break;
    case 'i':

        if (isInteractionAvailable())
            Interact();
        break;
    default:
        cout << "Escolha outra tecla";
        break;
    }
}

bool isMoveAvailable(char direction)
{
    if (direction == 'w')
    {
        if (map[player.x - 1][player.y] == emptyChar || (map[player.x - 1][player.y] == door.character && door.character == '='))
            return true;
    }

    if (direction == 's')
    {
        if (map[player.x + 1][player.y] == emptyChar || (map[player.x + 1][player.y] == door.character && door.character == '='))
            return true;
    }

    if (direction == 'a')
    {
        if (map[player.x][player.y - 1] == emptyChar || (map[player.x][player.y - 1] == door.character && door.character == '='))
            return true;
    }

    if (direction == 'd')
    {
        if (map[player.x][player.y + 1] == emptyChar || (map[player.x][player.y + 1] == door.character && door.character == '='))
            return true;
    }

    return false;
}

bool isInteractionAvailable()
{
    if (map[player.x - 1][player.y] == key.character)
        return true;

    if (map[player.x + 1][player.y] == key.character)
        return true;

    if (map[player.x][player.y - 1] == key.character)
        return true;

    if (map[player.x][player.y + 1] == key.character)
        return true;

    return false;
}

void Interact()
{
    if (map[player.x - 1][player.y] == key.character)
    {
        map[key.x][key.y] = emptyChar;
        door.character = '=';
        map[door.x][door.y] = door.character;
    }

    if (map[player.x + 1][player.y] == key.character)
    {
        map[key.x][key.y] = emptyChar;
        door.character = '=';
        map[door.x][door.y] = door.character;
    }

    if (map[player.x][player.y - 1] == key.character)
    {
        map[key.x][key.y] = emptyChar;
        door.character = '=';
        map[door.x][door.y] = door.character;
    }

    if (map[player.x][player.y + 1] == key.character)
    {
        map[key.x][key.y] = emptyChar;
        door.character = '=';
        map[door.x][door.y] = door.character;
    }
}

void MovePlayer(char direction)
{
    if (direction == 'w')
    {
        map[player.x - 1][player.y] = player.character;
        map[player.x][player.y] = emptyChar;
        player.x--;
    }

    if (direction == 's')
    {
        map[player.x + 1][player.y] = player.character;
        map[player.x][player.y] = emptyChar;
        player.x++;
    }

    if (direction == 'a')
    {
        map[player.x][player.y - 1] = player.character;
        map[player.x][player.y] = emptyChar;
        player.y--;
    }

    if (direction == 'd')
    {
        map[player.x][player.y + 1] = player.character;
        map[player.x][player.y] = emptyChar;
        player.y++;
    }
}

void Level1() {
    DrawMap();
    AddDoor();
    AddPlayer();
    AddKey();
    PrintMap();

    do{
        GetAction();
        system("cls || clear");
        PrintMap();
    }
    while(!Victory());
}

void Level2() {
    DrawMap();
    AddDoor();
    AddPlayer();
    AddKey();
    AddThorn();
    PrintMap();

    do{
        GetAction();
        system("cls || clear");
        PrintMap();
    }
    while(!Victory());
}

void Level3() {
    DrawMap();
    AddDoor();
    AddPlayer();
    AddKey();
    PrintMap();

    do{
        GetAction();
        system("cls || clear");
        PrintMap();
    }
    while(!Victory());
}

bool Victory() {
    if(player.x == currentMapLength - 1) {
        cout << "You've won the Level " << level << endl;
        level++;
        currentMapLength = level * 25;
        return true;
    }

    return false;
}

int main()
{
    srand(time(NULL));

    Init();

    Level2();
}
