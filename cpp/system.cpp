#include <iostream>
#include <unistd.h>
#define WIDTH 30
#define HEIGHT 10

void buildarr(char arr[][WIDTH]);
void printarr(char arr[][WIDTH]);
void loading(char arr[][WIDTH]);
int main ()
{
    system("clear");
    char arr[HEIGHT][WIDTH];
    buildarr(arr);

    loading(arr);
    system("clear");
   
    return 0;
}


void loading(char arr[][WIDTH])
{
    for (int i = 0; i < 5; i++)
    {
        printarr(arr);
        if (i % 2 == 0)
        {
            arr[HEIGHT/2][WIDTH/2] = 'X';
        }
        else 
        {
            arr[HEIGHT/2][WIDTH/2] = 'O';
        }
        sleep(1);
        system("clear");
    } 
}


void buildarr(char arr[][WIDTH])
{
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            arr[row][col] = '0';
        }
    }
}


void printarr(char arr[][WIDTH])
{
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            std::cout << arr[row][col];
        }
        std::cout << '\n';
    }
}
