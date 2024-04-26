#include <iostream>
#include <vector>
// #define scanf scanf_s

using namespace std;

class Gobang
{
private:
    vector<vector<int> > map;
    int length;

public:
    Gobang();
    Gobang(int len);

    void start();

private:
    void mainMenu(void);
    void init(void);
    void play(void);
    void printBoard(void);
    bool checkWin(int x, int y);
    void winnerMenu(int flag);
    void clear(void);
};

Gobang::Gobang()
{
    length = 15;
    vector<int> tmp(length);
    map.resize(length, tmp);
}

Gobang::Gobang(int len)
{
    length = len;
    vector<int> tmp(length);
    map.resize(length, tmp);
}

void Gobang::start(void)
{
    mainMenu();
}

void Gobang::mainMenu(void)
{
    int x = 0;
    while (true)
    {
        init();
        clear();
        printf("————————Gobang————————\n");
        printf("1.play game\n");
        printf("2.exit\n");
        printf(":");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            play();
            break;
        case 2:
            return;
        default:
            break;
        }
    }
}

void Gobang::init(void)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            map[i][j] = 0;
        }
    }
}

void Gobang::play(void)
{
    int flagPlayer = 1;
    int round = 1;
    int x = 0, y = 0;
    while (true)
    {
        //Player 1
        flagPlayer = 1;
        clear();
        printBoard();
        printf("Round %d, Player%d's turn\n", round, flagPlayer);
        printf("Please play your piece like \"1 5\" to (1,5):");
        scanf("%d%d", &x, &y);
        map[x][y] = flagPlayer;
        if (checkWin(x, y))
        {
            winnerMenu(flagPlayer);
            return;
        }

        //Player 2
        flagPlayer = 2;
        clear();
        printBoard();
        printf("Round %d, Player%d's turn\n", round, flagPlayer);
        printf("Please play your piece like \"1 5\" to (1,5):");
        scanf("%d%d", &x, &y);
        map[x][y] = flagPlayer;
        if (checkWin(x, y))
        {
            winnerMenu(flagPlayer);
            return;
        }

        round++;
    }
}

void Gobang::printBoard(void)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            switch (map[i][j])
            {
            case 1:
                printf("x");
                break;
            case 2:
                printf("o");
                break;
            default:
                printf("*");
            }
        }
        printf("\n");
    }
}

bool Gobang::checkWin(int x, int y)
{

    int cnt;

    // 横向
    cnt = 1;
    for (int i = 1; i < 5; i++) {
        if (x + i < length && map[x + i][y] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (x - i >= 0 && map[x - i][y] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    if (cnt >= 5) return true;

    // 纵向
    cnt = 1;
    for (int i = 1; i < 5; i++) {
        if (y + i < length && map[x][y + i] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (y - i >= 0 && map[x][y - i] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    if (cnt >= 5) return true;

    // 斜向（左上到右下）
    cnt = 1;
    for (int i = 1; i < 5; i++) {
        if (x + i < length && y + i < length && map[x + i][y + i] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (x - i >= 0 && y - i >= 0 && map[x - i][y - i] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    if (cnt >= 5) return true;

    // 斜向（左下到右上）
    cnt = 1;
    for (int i = 1; i < 5; i++) {
        if (x + i < length && y - i >= 0 && map[x + i][y - i] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (x - i >= 0 && y + i < length && map[x - i][y + i] == map[x][y]) {
            cnt++;
        }
        else {
            break;
        }
    }
    if (cnt >= 5) return true;

    return false;

}

void Gobang::winnerMenu(int flag)
{
    int x = 0;
    clear();
    printf("————————Gobang————————\n");
    printf("The winner is Player%d!\n", flag);
    printf("1.leave to main menu\n");
    printf("2.exit\n");
    printf(":");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        break;
    case 2:
        system("pause");
        break;
    default:
        break;
    }
}

void Gobang::clear(void)
{
    // system("clear");
    system("cls");
}

int main()
{
    Gobang* chess = new Gobang();
    chess->start();
    system("pause");
    return 0;
}