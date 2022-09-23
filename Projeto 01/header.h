#include <string.h>
#include <iostream>

int currentMapLength = 25;
char map[75][75];

int level = 3;

int chance = 1;

typedef struct Player {
    char character;
    int x;
    int y;
    int initialX;
    int initialY;
} Player;

typedef struct Door {
    char character;
    int x;
    int y;
} Door;

typedef struct Key {
    char character;
    int x;
    int y;
    int initialX;
    int initialY;
} Key;

typedef struct Button {
    char character;
    int x;
    int y;
} Button;

typedef struct Teletransporter {
    char character;
    int firstX;
    int firstY;
    int secondX;
    int secondY;
} Teletransporter;

char thorn = '#';
char emptyChar = ' ';
char wall = '*';

void Init();
void DrawMap();
void PrintMap();

void AddDoor();
void AddPlayer();
void AddKey();
void AddButton();
void AddThorn();
void AddTeletransport();

void GetMove();
void MovePlayer(char direction);

bool isMoveAvailable(char direction);
bool isInteractionAvailable();
bool isNextMoveButton(char direction);
bool isNextMoveThorn(char direction);
bool isNextMoveTeletransporter(char direction);

void Hurt();
void Interact();
void ReplaceKey();
void RestartLevel();

void MainMenu();
void Tutorial();
void Leave();

void Level1();
void Level2();
void Level3();

bool Victory();
bool Lose();
