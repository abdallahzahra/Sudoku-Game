#include <stdio.h>
#include<stdlib.h>
#include <windows.h>

#define RAW_need 9
#define COL_need 9
const int sudovalid [][9]= {
  { 5, 3, 4,         6, 7, 8,    9, 1, 2 } ,
  { 6, 7, 2,         1, 9, 5,    3, 4, 8 } ,
  { 1, 9, 8,         3, 4, 2,    5, 6, 7 } ,

  { 8, 5, 9,         7, 6, 1,    4, 2, 3 } ,
  { 4, 2, 6,         8, 5, 3,    7, 9, 1 } ,
  { 7, 1, 3,         9, 2, 4,    8, 5, 6 } ,

  { 9, 6, 1,         5, 3, 7,    2, 8, 4 } ,
  { 2, 8, 7,         4, 1, 9,    6, 3, 5 } ,
  { 3, 4, 5,         2, 8, 6,    1, 7, 9 }
};

void print_game(int arr[][9], int raw ,int col)
{
    system("cls");
    int i,j;

     for (i=0;i<raw;i++)
     {
         if (3==i || 6==i || 9==i )
            printf("----------------------------------------------------------------------------- \n");
         for (j=0;j<col;j++)
         {
             if (3==j || 6==j || 9==j )
                printf("  |");
            if (0==arr[i][j])
                {
                    printf("\x1b[34m");
//                    arr[i][j]='*';
//                    printf("\t  %c",arr[i][j]);
                    printf(" \t   ");
                    printf("\x1b[0m");
                }
            else
                printf("\t  %d",arr[i][j]);
         }
         printf("\n");
         printf("\n");
     }
}
int check_ele(int arr[][9], int raw ,int col , int *val )
{
    int i, j;
    for(i=0;i<RAW_need;i++){
        if (arr[raw][i]==*val && 0 !=*val )
            return 1 ;

    }
    for(j=0;j<COL_need;j++){
        if (arr[j][col]==*val && 0 !=*val)
            return 1;
    }
    return 0 ;
}

void GetELE(int arr[][9] )
{
    print_game( arr, 9 , 9);
    int raw , col;
    printf("enter raw u need :");
    scanf("%d",&raw);
    printf("enter col u need :");
    scanf("%d",&col);
    if ((raw==0&&col==0)||(raw==0&&col==1)||(raw==1&&col==5)||(raw==2&&col==1)
        ||(raw==2&&col==2)||(raw==2&&col==8)||(raw==3&&col==6)||(raw==3&&col==8)||
        (raw==6&&col==1)||(raw==8&&col==1)||(raw==8&&col==2))
    {
       get_ele:
           {
        int  x;
        printf("enter ur number if u want clear enter zero -0- :");
        fflush(stdin);
        scanf("%d",&x);
        if (x>=0 && x<=9)
        {
            int  f= check_ele(arr,raw,col,&x);
           if (f)
               MessageBox(0, "You number is repeted ", "WARNING" ,MB_ICONWARNING  );
           else{
            arr[raw][col]=x;
           }
        }
        else
        {

            printf("\x1b[31m");
             MessageBox(0, "You should enter number from 1 to 9 ", "ERROR" ,MB_ICONERROR );
            printf("wrong number  \n");
            printf("\x1b[0m");
            goto get_ele;

        }
    }
    }
    else
    {
        printf("\x1b[31m");
        printf("wrong place \n");
        printf("\x1b[0m");
	    MessageBox(0, "wrong place ", "ERROR" ,MB_ICONERROR );
        printf("Enter q to quit or any char  to continue : ");
        char option;
        fflush(stdin);
        option = getchar();
        if ((option=='q')||(option=='Q'))
            exit(0);
        else
            GetELE(arr);
    }
    print_game( arr, 9 , 9);

}

int isvalidgame(int arr[][9], int raw ,int col)
{
    int i ,j ;
    for (i=0;i<raw;i++)
    {
      for (j=0;j<col;j++)
      {
          if(sudovalid[i][j]!=arr[i][j])
            return 0 ;
      }
    }
    return 1;
}
