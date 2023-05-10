#include <cstdlib>
#include <iostream>

void resetboard(char board[][3]);
void menu(char board[][3]);
void printboard(char board[][3]);
void Players(std::string *p1, std::string *p2);
void choose();
void tutorial(char board[][3]);
void playerMove(char board[][3]);
void computerMove(char board[][3]);
char checkWinner(char board[][3]);
char player1;
char player2;
char computer;

int main ()
{
    char board[3][3];
    char winner = ' ';
    int mode;
    std::string player1Name;
    std::string player2Name;
    srand(time(NULL));
    resetboard(board);
    menu(board);
    choose();
    std::cout << "You are \'" << player1 << "\' and Computer is \'" << computer << "\'.\n";
    printboard(board);
    while (winner == ' ')
    {
        playerMove(board);
        winner = checkWinner(board);
        if (winner != ' ')
        {
            break;
        }
        computerMove(board);
        winner = checkWinner(board);
        if (winner != ' ')
        {
            break;
        }
    }
    if (winner == player1)
    {
        std::cout << "\nYou WIN!!";
    }
    else
    {
        std::cout << "\nYou LOSE!";
    }
    return 0;
}


void menu(char board[0][3])
{
    int menu = 0;
    while (menu != 4 && menu != 2)
    {

        std::cout << "***********Welcome to TicTacToe!**********\n";
        std::cout << "1. Tutorial\n";
        std::cout << "2. Play Computer vs Player\n";
        std::cout << "X. Play Player vs Player (coming soon)\n";
        std::cout << "4. Quit\n";
        std::cout << "******************************************\n";
        std::cin >> menu;
        if (std::cin.fail())
        {
            std::cout << "\nERROR -- You did not enter an number\n";
            // get rid of failure state
            std::cin.clear(); 
            std::cin.ignore();
        }
        if (menu == 1)
        {
            tutorial(board);
        }
        else if (menu == 2)
        {
            std::cout << "\nReady Set Go!\n";
            break;
        }
        else if (menu == 3)
        {
            std::cout << "\nCOMING SOON\n";
        }
        else if (menu == 4)
        {
            exit(0);
        }
    }
}


void Players()
{
    
}


void resetboard(char board[][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            board[row][column] = ' ';
        }
    }
}


void printboard(char board[][3])
{
    std::cout << '\n';
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
    std::cout << '\n';
}


void tutorial(char board[][3])
{
    std::cout << "You Play by inputing the block number you want to place in your move in\n";
    printboard(board);
    std::cout << "For example to play in the first field you would input \"1 1\"\n";
    std::cout << "The first input being the row and the second being the column\n";
    board[0][0] = 'X';
    printboard(board);
    resetboard(board);
}


void choose()
{
    int temp = 0;
    while (temp != 1 && temp != 2)
    {
        std::cout << "Choose your sign by pressing 1 or 2\n1: X\n2: O\n";
        std::cin >> temp;

        if (std::cin.fail())
        {
            std::cout << "\nERROR -- You did not enter an number\n";
            // get rid of failure state
            std::cin.clear(); 
            std::cin.ignore();
        }
        if (temp == 1)
        {
            player1 = 'X';
            computer = 'O';
        }
        else if (temp == 2)
        {
            player1 = 'O';
            computer = 'X';
        }
        else
        {
            std::cout << "Invalid Input\n\n";
        }
    }
}


void playerMove(char board[][3])
{
    int row = 0;
    int column = 0;
    bool move = false;


    while (move != true) 
    {
        std::cout << "Your move: ";
        std::cin >> row >> column;
        if (std::cin.fail())
        {
            std::cout << "\nERROR -- You did not enter an number\n";
            // get rid of failure state
            std::cin.clear(); 
            std::cin.ignore();
        }
        if (board[row-1][column-1] == ' ')
        {
            board[row-1][column-1] = player1;
            move = true;
        }
        else
        {
            std::cout << "Invalid move\n";
        }
    }
    printboard(board);
}


void computerMove(char board[][3])
{
    int row = rand() % 3;
    int column = rand() % 3;
    bool move = false;
    while (move != true)
    {
        row = rand() % 3;
        column = rand() % 3;
        if (board[row][column] == ' ')
        {
            board[row][column] = computer;
            move = true;
        }
    }
    printboard(board);
}


char checkWinner(char board[][3])
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
    {
        return board[0][0];
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
    {
        return board[1][0];
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
    {
        return board[2][0];
    }
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
    {
        return board[0][0];
    }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
    {
        return board[0][1];
    }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
    {
        return board[0][2];
    }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }
    else
    {
        return ' ';
    }
}
