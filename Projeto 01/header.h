#include <string.h>
#include <iostream>

int currentMapLength = 25;
int maxMapLength = 75;
int level = 1;

char map[75][75];

typedef struct Player {
    char character;
    int x;
    int y;
} Player;

typedef struct Door {
    char character;
    int x;
    int y;
} Door;

typedef struct key {
    char character;
    int x;
    int y;
} Key;

char button = 'O';
char teletransporter = '>';

char thorn = '#';
char emptyChar = ' ';
char wall = '*';


void Init();
void DrawMap();
void PrintMap();

void AddDoor();
void AddPlayer();
void AddKey();
void AddThorn();

void GetMove();
bool isMoveAvailable(char direction);
bool isInteractionAvailable();
void MovePlayer(char direction);
void Interact();

void MainMenu();
void Tutorial();
void Leave();

void Level1();
void Level2();
void Level3();

bool Victory();
bool Lose();
