#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void print_game(int arr[][9], int row ,int col);
void GetELE(int arr[][9] );
int isvalidgame(int arr[][9], int raw ,int col);


int main()
{
int sudoARR [][9]=  {{ 0, 0, 4,         6, 7, 8,    9, 1, 2 } ,
                     { 6, 7, 2,         1, 9, 0,    3, 4, 8 } ,
                     { 1, 0, 0,         3, 4, 2,    5, 6, 0 } ,

                     { 8, 5, 9,         7, 6, 1,    0, 2, 0 } ,
                     { 4, 2, 6,         8, 5, 3,    7, 9, 1 } ,
                     { 7, 1, 3,         9, 2, 4,    8, 5, 6 } ,

                     { 9, 0, 1,         5, 3, 7,    2, 8, 4 } ,
                     { 2, 8, 7,         4, 1, 9,    6, 3, 5 } ,
                     { 3, 0, 0,         2, 8, 6,    1, 7, 9 }
};

while(1)
{
     GetELE( sudoARR );
     int val= isvalidgame(sudoARR,9,9);
     if (val)
     {
       printf("\x1b[32m \n");
       printf("you win bro\n ");
	   MessageBox(0, "winner winner chicken dinner ", "congratulation" ,MB_ICONINFORMATION  );
       printf("\033[0;m");
       exit(0);
     }
}
    return 0;
}
