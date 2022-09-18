#include <stdio.h>
#include <stdlib.h>

#define R 18
#define C 17
int moves = 0;
char mat2[R][C] = {
    "_________________",
    "#################",
    "#               #",
    "#               #",
    "#   S           #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#               #",
    "#        E      #",
    "#################"};

void printAdjMatrix(char arr[][C])
{
    int i, j;
    printf("\n");
    for (i = 0; i < R; i++)
    {
        // printf("%d: ", i);
        for (j = 0; j < C; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

// ---------------------Functions to Find any character in Matrix----------------------------------

int findRow(char arr[R][C], char a)
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (arr[i][j] == a)
            {
                return i;
            }
        }
    }
}
int findColumn(char arr[R][C], char b)
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (arr[i][j] == b)
            {
                return j;
            }
        }
    }
}

// -----------------------Play Game--------------------------------

int moveDown(char arr[R][C])
{
    moves++;
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    if (arr[r + 1][c] == 'E')
    {
        printf("Congratss!!, Total moves %d", moves);
        moves = 0;
        return 0;
    }

    if (arr[r + 1][c] != '#')
    {
        arr[r][c] = ' ';
        arr[r + 1][c] = 'S';
    }

    printAdjMatrix(arr);
}

int moveUp(char arr[R][C])
{
    moves++;
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    if (arr[r - 1][c] == 'E')
    {
        printf("Congratss!!, Total moves %d", moves);
        moves = 0;
        return 0;
    }

    if (arr[r - 1][c] != '#' && arr[r - 1][c] != '_')
    {
        arr[r][c] = ' ';
        arr[r - 1][c] = 'S';
    }
    printAdjMatrix(arr);
}

int moveRight(char arr[R][C])
{
    moves++;
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    if (arr[r][c + 1] == 'E')
    {
        printf("Congratss!!, Total moves %d", moves);
        moves = 0;
        return 0;
    }

    if (arr[r][c + 1] != '#')
    {
        arr[r][c] = ' ';
        arr[r][c + 1] = 'S';
    }

    printAdjMatrix(arr);
}

int moveLeft(char arr[R][C])
{
    moves++;
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    if (arr[r][c - 1] == 'E')
    {
        printf("Congratss!!, Total moves %d", moves);
        moves = 0;
        return 0;
    }

    if (arr[r][c - 1] != '#')
    {
        arr[r][c] = ' ';
        arr[r][c - 1] = 'S';
    }
    printAdjMatrix(arr);
}

// -------------------------Customize Game------------------------------

void moveDown2(char arr[R][C])
{
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    arr[r][c] = ' ';
    arr[r + 1][c] = 'S';

    printAdjMatrix(arr);
}

void moveUp2(char arr[R][C])
{
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    arr[r][c] = ' ';
    arr[r - 1][c] = 'S';

    printAdjMatrix(arr);
}

void moveRight2(char arr[R][C])
{
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    arr[r][c] = ' ';
    arr[r][c + 1] = 'S';

    printAdjMatrix(arr);
}

void moveLeft2(char arr[R][C])
{
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    arr[r][c] = ' ';
    arr[r][c - 1] = 'S';
    printAdjMatrix(arr);
}

void customMoveCond(char arr[R][C], int r, int c)
{
    if (arr[r][c + 1] != '#')
    {
        arr[r][c + 1] = 'S';
    }
    else if (arr[r + 1][c] != '#')
    {
        arr[r + 1][c] = 'S';
    }
    else if (arr[r][c - 1] != '#')
    {
        arr[r][c - 1] = 'S';
    }
    else if (arr[r - 1][c] != '#')
    {
        arr[r - 1][c] = 'S';
    }
    printAdjMatrix(arr);
}

void throwBlock(char arr[R][C])
{
    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    arr[r][c] = '#';

    customMoveCond(arr, r, c);
}

void throwEnd(char arr[R][C])
{
    int er = findRow(arr, 'E');
    int ec = findColumn(arr, 'E');

    arr[er][ec] = ' ';

    int r = findRow(arr, 'S');
    int c = findColumn(arr, 'S');

    arr[r][c] = 'E';

    customMoveCond(arr, r, c);
}

// ---------------------------*Functions Used in Main*----------------------------
void play(char arr[R][C])
{

    char x = 'O';

    while (x != 'x')
    {
        printf("\nEnter: ");
        scanf("%s", &x);

        if (x == 'w')
        {
            if (moveUp(arr) == 0)
                main();
        }

        if (x == 's')
        {
            if (moveDown(arr) == 0)
                main();
        }
        if (x == 'a')
        {
            if (moveLeft(arr) == 0)
                main();
        }
        if (x == 'd')
        {
            if (moveRight(arr) == 0)
                main();
        }
        if (x == 'x')
        {
            main();
        }
        printf("\t\tMoves: %d", moves);
    }
}

void customize(char arr[R][C])
{
    char x = 'O';
    while (x != 'x')
    {
        printf("\nEnter: ");
        scanf("%s", &x);
        if (x == 'w')
        {
            moveUp2(arr);
        }
        if (x == 's')
        {
            moveDown2(arr);
        }
        if (x == 'a')
        {
            moveLeft2(arr);
        }
        if (x == 'd')
        {
            moveRight2(arr);
        }
        if (x == 'x')
        {
            main();
        }

        if (x == 'g')
        {
            throwBlock(arr);
        }
        if (x == 'h')
        {
            throwEnd(arr);
        }
    }
}

// ------------------------*Main Function*-------------------------------
int main()
{
    char mat1[R][C] = {
        "_________________",
        "#######  S#######",
        "#   #     #     #",
        "# # # ##### # # #",
        "# #   #     # # #",
        "# ### # ##### ###",
        "# #   # #     # #",
        "# ##### ##### # #",
        "#         #   # #",
        "# ####### # # # #",
        "# # #   # # #   #",
        "# # # # ### ### #",
        "#   # #     # # #",
        "### # ##### # # #",
        "# # #     # # # #",
        "# # ##### # # ###",
        "#     #   #     #",
        "#######  E#######"};

    printf("\n\n***Welcome to the MAZE game***\n");
    int a = -1;
    while (a != 0)
    {
        printf("\nPress\n\t1. Play Game\t2. Customize Level\t3. Play Customized Level\n");
        scanf("%d", &a);

        if (a == 1)
        {
            moves = 0;
            printAdjMatrix(mat1);
            printf("\n**Controls**\n'w': Move Up\t's': Move Down\t'a': Move Left\t'd': Move Right\t'x': Exit\n");

            play(mat1);
        }

        if (a == 2)
        {
            printAdjMatrix(mat2);
            printf("\n**Controls**\n'w': Move Up\t's': Move Down\t'a': Move Left\t'd': Move Right\n'g': Throw Block\t'h': throw E (End)\t'x': Save and Exit");

            customize(mat2);
        }

        if (a == 3)
        {
            moves = 0;
            printAdjMatrix(mat2);
            printf("\n**Controls**\n'w': Move Up\t's': Move Down\t'a': Move Left\t'd': Move Right\t'x': Exit\n");
            play(mat2);
        }
    }

    return 0;
}
