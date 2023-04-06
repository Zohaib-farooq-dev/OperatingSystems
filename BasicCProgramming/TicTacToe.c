#include <stdio.h>
#include <stdlib.h>

int i=0,player;
char mark = 'X';
int win =0;
char board[3][3] = {{'1','2','3'},
                   {'4','5','6'},
                   {'7','8','9'}};
void checkWin();
void drawBoard();
int main()
{
    int player=0,choice;

    do{
         drawBoard();
         player = (i%2)==0?1:2;
         mark = (player ==1)?'X':'O';
         printf("Player %d Choose your option \n",player);
         scanf("%d",&choice);
         if(choice == 1 && board[0][0] == '1'){
             board[0][0] = mark;
         }else if (choice ==2 && board[0][1] =='2'){
             board[0][1] = mark;
         }else if (choice ==3 && board[0][2] =='3'){
             board[0][2] = mark;
         }else if (choice ==4 && board[1][0] =='4'){
             board[1][0] = mark;
         }else if (choice ==5 && board[1][1] =='5'){
             board[1][1] = mark;
         }else if (choice ==6 && board[1][2] =='6'){
             board[1][2] = mark;
         }else if (choice ==7 && board[2][0] =='7'){
             board[2][0] = mark;
         }else if (choice ==8 && board[2][1] =='8'){
             board[2][1] = mark;
         }else if (choice ==9 && board[2][2] =='9'){
             board[2][2] = mark;
         }
         checkWin();
    }while(win==-1);
    drawBoard();
    if(win==1){
        printf("\n Player %d  wins  \n\n ",player);
    }else{
        printf("\n Game Draw \n\n");
    }

    return 0;
}
void checkWin(){

   i++;
   if(board[0][0] == mark && board[0][1] == mark && board[0][2] == mark ){
    win =1;
   }else if(board[1][0] == mark && board[1][1] == mark && board[1][2] == mark){
    win=1;
   }else if(board[2][0] == mark && board[2][1] == mark && board[2][2] == mark){
    win=1;
   }else if(board[0][0] == mark && board[1][0] == mark && board[2][0] == mark){
    win=1;
   }else if(board[0][1] == mark && board[1][1] == mark && board[2][1] == mark){
    win=1;
   }else if(board[0][2] == mark && board[1][2] == mark && board[2][2] == mark){
    win=1;
   }else if(board[0][0] == mark && board[1][1] == mark && board[2][2] == mark){
    win=1;
   }else if(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark){
    win=1;
   }else if(i==9){
    win=0;
   }else{
    win =-1;
   }
}

void drawBoard(){

system("clear");
printf("\n\n  Tic Tac Toe \n");
printf("Player 1(X) -- Player 2(O)  \n\n");
printf("      |       |     \n");
printf(" %c    |  %c    |   %c  \n ", board[0][0],board[0][1],board[0][2]);
printf("_____|_______|______\n");
printf("      |       |     \n");
printf(" %c    |  %c    |   %c  \n ", board[1][0],board[1][1],board[1][2]);
printf("_____|_______|______\n");
printf("      |       |     \n");
printf(" %c    |  %c    |   %c \n ", board[2][0],board[2][1],board[2][2]);
printf("     |       |     \n");
}

