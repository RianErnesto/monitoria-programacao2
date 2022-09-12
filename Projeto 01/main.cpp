#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "header.h"

using namespace std;

int tamanhoMapa = 25;
int levelAtual = 1;
int quantidadeTentativas = 1;

void DesenharMapa(char mapa[25][25])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (i == 0)
            {
                mapa[i][j] = '*';
            }
            else if (j == 0)
            {
                mapa[i][j] = '*';
            }
            else if (j == tamanhoMapa - 1)
            {
                mapa[i][j] = '*';
            }
            else if (i == tamanhoMapa - 1)
            {
                mapa[i][j] = '*';
            }
            else
            {
                mapa[i][j] = ' ';
            }
        }
    }

    int posicaoJogadorX = PosicaoXJogador();
    int posicaoJogadorY = PosicaoYJogador();

    mapa[posicaoJogadorX][posicaoJogadorY] = '&';

    int posicaoPortaX = PosicaoXPorta();

    mapa[posicaoPortaX][tamanhoMapa - 1] = 'D';

    int posicaoChaveX = PosicaoXChave();
    int posicaoChaveY = PosicaoYChave();

    mapa[posicaoChaveX][posicaoChaveY] = '@';
}

void DesenharMapa(char mapa[50][50])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (i == 0)
            {
                mapa[i][j] = '*';
            }
            else if (j == 0)
            {
                mapa[i][j] = '*';
            }
            else if (j == tamanhoMapa - 1)
            {
                mapa[i][j] = '*';
            }
            else if (i == tamanhoMapa - 1)
            {
                mapa[i][j] = '*';
            }
            else
            {
                mapa[i][j] = ' ';
            }
        }
    }

    int posicaoJogadorX = PosicaoXJogador();
    int posicaoJogadorY = PosicaoYJogador();

    mapa[posicaoJogadorX][posicaoJogadorY] = '&';

    int posicaoPortaX = PosicaoXPorta();

    mapa[posicaoPortaX][tamanhoMapa - 1] = 'D';

    int posicaoChaveX = PosicaoXChave();
    int posicaoChaveY = PosicaoYChave();

    mapa[posicaoChaveX][posicaoChaveY] = '@';
}

void DesenharMapa(char mapa[75][75])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (i == 0)
            {
                mapa[i][j] = '*';
            }
            else if (j == 0)
            {
                mapa[i][j] = '*';
            }
            else if (j == tamanhoMapa - 1)
            {
                mapa[i][j] = '*';
            }
            else if (i == tamanhoMapa - 1)
            {
                mapa[i][j] = '*';
            }
            else
            {
                mapa[i][j] = ' ';
            }
        }
    }

    int posicaoJogadorX = PosicaoXJogador();
    int posicaoJogadorY = PosicaoYJogador();

    mapa[posicaoJogadorX][posicaoJogadorY] = '&';

    int posicaoPortaX = PosicaoXPorta();

    mapa[posicaoPortaX][tamanhoMapa - 1] = 'D';

    int posicaoChaveX = PosicaoXChave();
    int posicaoChaveY = PosicaoYChave();

    mapa[posicaoChaveX][posicaoChaveY] = '@';
}

void ImprimirMapa(char mapa[25][25])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

void ImprimirMapa(char mapa[50][50])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

void ImprimirMapa(char mapa[75][75])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

void ImprimirMenu(int *escolha)
{
    cout << "--------- Rian Game Puzzle Game ---------\n\n";
    cout << "1 - Jogar Level " << levelAtual << "\n";
    cout << "2 - Tutorial\n";
    cout << "3 - Sair\n";
    cout << "Escolha: ";
    cin >> *escolha;
}

void ImprimirTutorial()
{
    system("cls || clear");
    cout << "Um jogo de aventura � um g�nero de videogame no qual o jogador assume o papel de protagonista em uma hist�ria interativa impulsionada pela explora��o e/ou resolu��o de quebra-cabe�as (Rollings & Adams 2003, p. 43). O foco do g�nero na hist�ria permite que ele se baseie fortemente em outras m�dias, literatura e filmes. Muitos jogos de aventura (texto e gr�fico) s�o projetados para um �nico jogador, j� que essa �nfase na hist�ria e no personagem dificulta o design multijogador (Hitchens 2002, p. 258). Colossal Cave Adventure � identificado (\" The Colossal Cave Adventure page \". rickadams.org. Retrieved 31 July 2020.) como o primeiro jogo de aventura, lan�ado pela primeira vez em 1976, enquanto outras s�ries de jogos de aventura not�veis incluem Zork, King's Quest, The Secret of Monkey Island e Myst.";
    cout << "O jogo � do estilo aventura/puzzle onde o objetivo � o jogador conseguir passar de tr�s fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.\n";
    cout << "O jogador possui os seguintes comando:\n";
    cout << "\tW: O jogador movimenta uma unidade para cima;\n";
    cout << "\tA: O jogador movimenta uma unidade para esquerda;\n";
    cout << "\tS: O jogador movimenta uma unidade para baixo;\n";
    cout << "\tD: O jogador movimenta uma unidade para direita;\n";
    cout << "\tI: O jogador interage com o objeto que ele estar em cima.\n";
    cout << "  O jogo possui os seguintes elementos nas fases:\n";
    cout << "\t&: Simbolo que representa o jogador.\n";
    cout << "\t*: Simbolo que representa uma parede, o jogador ao se movimentar n�o pode passar pela parede.\n";
    cout << "\t@: Simbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\n";
    cout << "\tD: Simbolo que representa a porta fechada.\n";
    cout << "\t=: Simbolo que representa a porta aberta quando o jogador interagiu com a chave.\n";
    cout << "\tO: Simbolo que representa um bot�o que o usu�rio pode interagir, o bot�o fica no ch�o e o jogador deve ficar em cima dele para poder interagir.\n";
    cout << "\t#: Simbolo que representa um espinho. A fase � reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada tr�s vezes, o jogo volta para o menu principal.\n";
    cout << "\t>: Simbolo que representa um teletransporte. O teletransporte sempre deve vir em par, quando o jogador toca em um ele � transportado para o outro e vice-versa.\n";
    cout << "O jogo possui um total de 8 telas:\n";
    cout << "\tMenu Principal: Menu com com tr�s escolhas para o usu�rio (Jogar, Tutorial, Sair);\n";
    cout << "\tTutorial: Texto ensinando o jogador a jogar o jogo;\n";
    cout << "\tSair: Texto de despedida e encerramento do programa;\n";
    cout << "\tFase 1: A Fase 1 � inicializada quando o jogador seleciona a op��o Jogar no Menu Principal;\n";
    cout << "\tFase 2: A Fase 2 � inicializada quando o jogador termina a Fase 1;\n";
    cout << "\tFase 3: A Fase 3 � inicializada quando o jogador termina a Fase 2;\n";
    cout << "\tVit�ria: Texto elogiando o jogador por ter conseguido terminar o jogo, depois dessa tela o jogador volta para o Menu Principal. Essa tela s� pode ser acessada se o jogador finalizar a Fase 3;\n";
    cout << "\tDerrota: Texto ca�oando o jogador, depois dessa tela o jogador volta para o Menu Principal. Essa tela s� pode ser acessada quando o jogador perde em uma fase.\n";
    cout << "Cada fase deve possuir as seguintes caracter�sticas:\n";
    cout << "\tFase 1: Essa fase possui uma dimens�o de 25x25 e possui os seguintes elementos: jogador, parede, chave e porta;\n";
    cout << "\tFase 2: Essa fase possui uma dimens�o de 50x50 e possui os seguintes elementos: todos da Fase 1, bot�o e espinhos;\n";
    cout << "\tFase 3: Essa fase possui uma dimens�o de 75x75 e possui os seguintes elementos: todos da Fase 2 e teletransporte.\n";
}

void ImprimirSair()
{
    system("cls || clear");
    cout << "Voce desistiu do jogo. At� mais !";
}

int PosicaoXJogador()
{
    return (rand() % (tamanhoMapa - 2)) + 1;
}

int PosicaoYJogador()
{
    return (rand() % (tamanhoMapa - 2)) + 1;
}

int PegarPosicaoXJogador(char mapa[25][25])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == '&')
            {
                return i;
            }
        }
    }
}

int PegarPosicaoXJogador(char mapa[50][50])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == '&')
            {
                return i;
            }
        }
    }
}

int PegarPosicaoXJogador(char mapa[75][75])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == '&')
            {
                return i;
            }
        }
    }
}

int PegarPosicaoYJogador(char mapa[25][25])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == '&')
            {
                return j;
            }
        }
    }
}

int PegarPosicaoYJogador(char mapa[50][50])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == '&')
            {
                return j;
            }
        }
    }
}

int PegarPosicaoYJogador(char mapa[75][75])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == '&')
            {
                return j;
            }
        }
    }
}

int PosicaoXPorta()
{
    return (rand() % (tamanhoMapa - 2)) + 1;
}

int PegarPosicaoXPorta(char mapa[25][25])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == 'D')
                return i;
        }
    }
}

int PegarPosicaoXPorta(char mapa[50][50])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == 'D')
                return i;
        }
    }
}

int PegarPosicaoXPorta(char mapa[75][75])
{
    int i, j;
    for (i = 0; i < tamanhoMapa; i++)
    {
        for (j = 0; j < tamanhoMapa; j++)
        {
            if (mapa[i][j] == 'D')
                return i;
        }
    }
}

int PosicaoXChave()
{
    return (rand() % (tamanhoMapa - 2)) + 1;
}

int PosicaoYChave()
{
    return (rand() % (tamanhoMapa - 2)) + 1;
}

bool VerificarSePodeInserir(char mapaPosicao, char insercao)
{
    if (mapaPosicao == ' ')
    {
        return true;
    }
    return false;
}

void JogarFase1(char mapa[25][25])
{
    DesenharMapa(mapa);
    int posicaoJogadorX = PegarPosicaoXJogador(mapa);
    int posicaoJogadorY = PegarPosicaoYJogador(mapa);
    int posicaoPortaX = PegarPosicaoXPorta(mapa);

    while (true)
    {
        system("cls || clear");
        ImprimirMapa(mapa);
        char movimentacao;
        cout << "Movimento: ";
        cin >> movimentacao;

        switch (movimentacao)
        {
        case 'W':
            if (posicaoJogadorX - 1 >= 1)
            {
                if (IrParaCima(mapa[posicaoJogadorX - 1][posicaoJogadorY]))
                {
                    mapa[posicaoJogadorX - 1][posicaoJogadorY] = '&';
                    mapa[posicaoJogadorX][posicaoJogadorY] = ' ';

                    posicaoJogadorX--;
                }
            }
            break;
        case 'A':
            if (posicaoJogadorY - 1 >= 1)
            {
                if (IrParaEsquerda(mapa[posicaoJogadorX][posicaoJogadorY - 1]))
                {
                    mapa[posicaoJogadorX][posicaoJogadorY - 1] = '&';
                    mapa[posicaoJogadorX][posicaoJogadorY] = ' ';

                    posicaoJogadorY--;
                }
            }
            break;
        case 'S':
            if (posicaoJogadorX + 1 < tamanhoMapa - 1)
            {
                if (IrParaBaixo(mapa[posicaoJogadorX + 1][posicaoJogadorY]))
                {
                    mapa[posicaoJogadorX + 1][posicaoJogadorY] = '&';
                    mapa[posicaoJogadorX][posicaoJogadorY] = ' ';

                    posicaoJogadorX++;
                }
            }
            break;
        case 'D':
            if (posicaoJogadorY + 1 <= tamanhoMapa - 1)
            {
                if (IrParaDireita(mapa[posicaoJogadorX][posicaoJogadorY + 1]))
                {
                    mapa[posicaoJogadorX][posicaoJogadorY + 1] = '&';
                    mapa[posicaoJogadorX][posicaoJogadorY] = ' ';

                    posicaoJogadorY++;
                }
            }
            break;
        case 'I':
            if (Interagir(mapa, posicaoJogadorX, posicaoJogadorY))
            {
                mapa[posicaoPortaX][tamanhoMapa - 1] = '=';
            }
            break;

        default:
            break;
        }

        if (Vitoria(posicaoJogadorY))
        {
            break;
        }
    }
}

void JogarFase2(char mapa[50][50])
{
    while (true)
    {
        system("cls || clear");
        char movimentacao;
        cout << "Movimento: ";
        cin >> movimentacao;

        switch (movimentacao)
        {
        case 'W':
            break;
        case 'A':
            break;
        case 'S':
            break;
        case 'D':
            break;
        case 'I':
            break;

        default:
            break;
        }
    }
}

void JogarFase3(char mapa[75][75])
{
    while (true)
    {
        system("cls || clear");
        char movimentacao;
        cout << "Movimento: ";
        cin >> movimentacao;

        switch (movimentacao)
        {
        case 'W':
            break;
        case 'A':
            break;
        case 'S':
            break;
        case 'D':
            break;
        case 'I':
            break;

        default:
            break;
        }
    }
}

bool IrParaCima(char proximoChar)
{
    if (proximoChar == ' ')
    {
        return true;
    }
    return false;
}

bool IrParaBaixo(char proximoChar)
{
    if (proximoChar == ' ')
    {
        return true;
    }
    return false;
}

bool IrParaDireita(char proximoChar)
{
    if (proximoChar == ' ' || proximoChar == '=')
    {
        return true;
    }
    return false;
}

bool IrParaEsquerda(char proximoChar)
{
    if (proximoChar == ' ')
    {
        return true;
    }
    return false;
}

bool Interagir(char mapa[25][25], int posicaoJogadorX, int posicaoJogadorY)
{
    if (posicaoJogadorX - 1 >= 1)
    {
        if (mapa[posicaoJogadorX - 1][posicaoJogadorY] == '@')
            return true;
    }
    if (posicaoJogadorX + 1 < tamanhoMapa - 1)
    {
        if (mapa[posicaoJogadorX + 1][posicaoJogadorY] == '@')
            return true;
    }
    if (posicaoJogadorY - 1 >= 1)
    {
        if (mapa[posicaoJogadorX][posicaoJogadorY - 1] == '@')
            return true;
    }
    if (posicaoJogadorY + 1 < tamanhoMapa - 1)
    {
        if (mapa[posicaoJogadorX][posicaoJogadorY + 1] == '@')
            return true;
    }

    return false;
}

bool Interagir(char mapa[50][50], int posicaoJogadorX, int posicaoJogadorY)
{
    if (posicaoJogadorX - 1 >= 1)
    {
        if (mapa[posicaoJogadorX - 1][posicaoJogadorY] == '@')
            return true;
    }
    if (posicaoJogadorX + 1 < tamanhoMapa - 1)
    {
        if (mapa[posicaoJogadorX + 1][posicaoJogadorY] == '@')
            return true;
    }
    if (posicaoJogadorY - 1 >= 1)
    {
        if (mapa[posicaoJogadorX][posicaoJogadorY - 1] == '@')
            return true;
    }
    if (posicaoJogadorY + 1 < tamanhoMapa - 1)
    {
        if (mapa[posicaoJogadorX][posicaoJogadorY + 1] == '@')
            return true;
    }

    return false;
}

bool Interagir(char mapa[75][75], int posicaoJogadorX, int posicaoJogadorY)
{
    if (posicaoJogadorX - 1 >= 1)
    {
        if (mapa[posicaoJogadorX - 1][posicaoJogadorY] == '@')
            return true;
    }
    if (posicaoJogadorX + 1 < tamanhoMapa - 1)
    {
        if (mapa[posicaoJogadorX + 1][posicaoJogadorY] == '@')
            return true;
    }
    if (posicaoJogadorY - 1 >= 1)
    {
        if (mapa[posicaoJogadorX][posicaoJogadorY - 1] == '@')
            return true;
    }
    if (posicaoJogadorY + 1 < tamanhoMapa - 1)
    {
        if (mapa[posicaoJogadorX][posicaoJogadorY + 1] == '@')
            return true;
    }

    return false;
}

bool Vitoria(int posicaoJogadorY)
{
    if (posicaoJogadorY == tamanhoMapa - 1)
    {
        ProximoLevel();
        cout << "Você Venceu !!\n\n";
        return true;
    }
    return false;
}

void ProximoLevel()
{
    levelAtual++;
    tamanhoMapa += 25;
}

int main()
{
    srand(time(NULL));

    char mapaFase1[25][25];
    char mapaFase2[50][50];
    char mapaFase3[75][75];

    int escolha;

    do
    {
        ImprimirMenu(&escolha);
        switch (escolha)
        {
        case 1:
            switch (levelAtual)
            {
            case 1:
                JogarFase1(mapaFase1);
                break;
            case 2:
                JogarFase2(mapaFase2);
                break;
            case 3:
                JogarFase3(mapaFase3);
                break;
            default:
                break;
            }
            break;
        case 2:
            ImprimirTutorial();
            break;
        case 3:
            ImprimirSair();
            break;
        default:
            break;
        }
    } while (escolha != 3);

    return 0;
}
