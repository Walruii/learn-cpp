#include <iostream>
#include <unistd.h>

void buildarr(char arr[][5]);
void printarr(char arr[][5]);
void loading(char arr[][5]);

int main ()
{
    char arr[5][5];
    buildarr(arr);

    loading(arr);
    system("clear");
   
    return 0;
}


void loading(char arr[][5])
{
    for (int i = 0; i < 5; i++)
    {
        printarr(arr);
        if (i % 2 == 0)
        {
            arr[2][2] = 'X';
        }
        else 
        {
            arr[2][2] = 'O';
        }
        sleep(1);
        system("clear");
    } 
}


void buildarr(char arr[][5])
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            arr[row][col] = '0';
        }
    }
}


void printarr(char arr[][5])
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            std::cout << arr[row][col];
        }
        std::cout << '\n';
    }
}
