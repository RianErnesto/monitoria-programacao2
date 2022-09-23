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
Button button;
Teletransporter teletransporter;

void Init()
{
    player.character = '&';
    door.character = 'D';
    key.character = '@';
    button.character = 'O';
    teletransporter.character = '>';
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
    player.initialX = 1;
    player.initialY = playerPosition;

    map[player.x][player.y] = player.character;
}

void AddKey()
{
    while (true)
    {
        int keyPositionX = rand() % (currentMapLength - 2) + 1;
        int keyPositionY = rand() % (currentMapLength - 2) + 1;

        if (map[keyPositionX][keyPositionY] == emptyChar)
        {
            key.x = keyPositionX;
            key.y = keyPositionY;
            key.initialX = keyPositionX;
            key.initialY = keyPositionY;
            map[key.x][key.y] = key.character;
            break;
        }
    }
}

void AddButton()
{
    while (true)
    {
        int buttonPositionX = rand() % (currentMapLength - 2) + 1;
        int buttonPositionY = rand() % (currentMapLength - 2) + 1;

        if (map[buttonPositionX][buttonPositionY] == emptyChar)
        {
            button.x = buttonPositionX;
            button.y = buttonPositionY;
            map[button.x][button.y] = button.character;
            break;
        }
    }
}

void AddThorn()
{
    int i, j;
    for (i = 1; i < currentMapLength - 1; i++)
    {
        for (j = 1; j < currentMapLength - 1; j++)
        {
            if (map[i][j] != emptyChar)
                continue;
            if (rand() % 100 < 7)
                map[i][j] = thorn;
        }
    }
}

void AddTeletransport()
{
    int firstLineOfKeyTeletransport;
    int lastLineOfKeyTeletransport;

    if (key.x - 1 == 0)
        firstLineOfKeyTeletransport = 1;
    else
        firstLineOfKeyTeletransport = key.x - 1;

    if (key.x + 1 == currentMapLength - 1)
        lastLineOfKeyTeletransport = currentMapLength - 2;
    else
        lastLineOfKeyTeletransport = key.x + 1;

    while (true)
    {
        int firstTeletransportX = rand() % (lastLineOfKeyTeletransport - firstLineOfKeyTeletransport + 1) + firstLineOfKeyTeletransport;
        int firstTeletransportY = rand() % (currentMapLength - 2) + 1;

        if (map[firstTeletransportX][firstTeletransportY] == emptyChar)
        {
            teletransporter.firstX = firstTeletransportX;
            teletransporter.firstY = firstTeletransportY;
            map[teletransporter.firstX][teletransporter.firstY] = teletransporter.character;
            break;
        }
    }

    int firstLineOfDoorTeletransport = currentMapLength - 4;
    while (true)
    {
        int secondTeletransportX = rand() % 3 + firstLineOfDoorTeletransport;
        int secondTeletransportY = rand() % (currentMapLength - 2) + 1;

        if (map[secondTeletransportX][secondTeletransportY] == emptyChar)
        {
            teletransporter.secondX = secondTeletransportX;
            teletransporter.secondY = secondTeletransportY;
            map[teletransporter.secondX][teletransporter.secondY] = teletransporter.character;
            break;
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
        if (map[player.x - 1][player.y] == emptyChar ||
            (map[player.x - 1][player.y] == door.character && door.character == '=') ||
            map[player.x - 1][player.y] == button.character ||
            map[player.x - 1][player.y] == thorn)
            return true;
    }

    if (direction == 's')
    {
        if (map[player.x + 1][player.y] == emptyChar ||
            (map[player.x + 1][player.y] == door.character && door.character == '=') ||
            map[player.x + 1][player.y] == button.character ||
            map[player.x + 1][player.y] == thorn)
            return true;
    }

    if (direction == 'a')
    {
        if (map[player.x][player.y - 1] == emptyChar ||
            (map[player.x][player.y - 1] == door.character && door.character == '=') ||
            map[player.x][player.y - 1] == button.character ||
            map[player.x][player.y - 1] == thorn)
            return true;
    }

    if (direction == 'd')
    {
        if (map[player.x][player.y + 1] == emptyChar ||
            (map[player.x][player.y + 1] == door.character && door.character == '=') ||
            map[player.x][player.y + 1] == button.character ||
            map[player.x][player.y + 1] == thorn)
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

bool isNextMoveButton(char direction)
{
    if (direction == 'w')
    {
        if (map[player.x - 1][player.y] == button.character)
            return true;
    }

    if (direction == 's')
    {
        if (map[player.x + 1][player.y] == button.character)
            return true;
    }

    if (direction == 'a')
    {
        if (map[player.x][player.y - 1] == button.character)
            return true;
    }

    if (direction == 'd')
    {
        if (map[player.x][player.y + 1] == button.character)
            return true;
    }

    return false;
}

bool isNextMoveThorn(char direction)
{
    if (direction == 'w')
    {
        if (map[player.x - 1][player.y] == thorn)
            return true;
    }

    if (direction == 's')
    {
        if (map[player.x + 1][player.y] == thorn)
            return true;
    }

    if (direction == 'a')
    {
        if (map[player.x][player.y - 1] == thorn)
            return true;
    }

    if (direction == 'd')
    {
        if (map[player.x][player.y + 1] == thorn)
            return true;
    }

    return false;
}

bool isNextMoveTeletransporter(char direction)
{
    if (direction == 'w')
    {
        if (map[player.x - 1][player.y] == teletransporter.character)
            return true;
    }

    if (direction == 's')
    {
        if (map[player.x + 1][player.y] == teletransporter.character)
            return true;
    }

    if (direction == 'a')
    {
        if (map[player.x][player.y - 1] == teletransporter.character)
            return true;
    }

    if (direction == 'd')
    {
        if (map[player.x][player.y + 1] == teletransporter.character)
            return true;
    }

    return false;
}

void Teletransport() {

}

void Hurt()
{
    chance += 1;
    cout << "You are Walking on Thorns, have you got Crazy?!" << endl;
    RestartLevel();
}

void RestartLevel()
{
    map[player.x][player.y] = emptyChar;
    map[player.initialX][player.initialY] = player.character;
    player.x = player.initialX;
    player.y = player.initialY;
    map[key.x][key.y] = emptyChar;
    map[key.initialX][key.initialY] = key.character;
    key.x = key.initialX;
    key.y = key.initialY;
    map[door.x][door.y] = 'D';
    door.character = 'D';

    if (level == 2)
    {
        map[button.x][button.y] = button.character;
    }
}

void ReplaceKey()
{
    if (door.character == 'D')
    {
        while (true)
        {
            int keyPositionX = rand() % (currentMapLength - 2) + 1;
            int keyPositionY = rand() % (currentMapLength - 2) + 1;

            if (map[keyPositionX][keyPositionY] == emptyChar)
            {
                map[key.x][key.y] = emptyChar;
                key.x = keyPositionX;
                key.y = keyPositionY;
                map[key.x][key.y] = key.character;
                break;
            }
        }
    }
}

void MovePlayer(char direction)
{
    bool backButton = false;
    bool backTeletransport = false;

    if (isNextMoveButton(direction))
        ReplaceKey();
    else
        backButton = true;

    if (isNextMoveThorn(direction))
    {
        Hurt();
        return;
    }

    if(isNextMoveTeletransporter(direction)) {

    }

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

    if (backButton)
        map[button.x][button.y] = button.character;
}

void Level1()
{
    DrawMap();
    AddDoor();
    AddPlayer();
    AddKey();
    AddButton();
    PrintMap();

    do
    {
        GetAction();
        system("cls || clear");
        PrintMap();
    } while (!Victory());
}

void Level2()
{
    DrawMap();
    AddDoor();
    AddPlayer();
    AddKey();
    AddButton();
    AddThorn();
    PrintMap();

    do
    {
        GetAction();
        system("cls || clear");
        PrintMap();
    } while (!Victory() && !Lose());
}

void Level3()
{
    DrawMap();
    AddDoor();
    AddPlayer();
    AddKey();
    AddButton();
    AddTeletransport();
    AddThorn();
    PrintMap();

    do
    {
        GetAction();
        system("cls || clear");
        PrintMap();
    } while (!Victory() && !Lose());
}

bool Victory()
{
    if (player.x == currentMapLength - 1)
    {
        cout << "You've won the Level " << level << endl;
        level++;
        currentMapLength = level * 25;
        return true;
    }

    return false;
}

bool Lose()
{
    if (chance == 4)
    {
        cout << "You've walked on Thorns 3 times and lost the came, what a pitty !" << endl;
        return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));

    Init();

    Level3();
}
