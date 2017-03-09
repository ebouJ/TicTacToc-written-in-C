// Tic-Tac-Toe Game for 2 users

        // Function Prototypes
char displayBoard(char[3][3]);
int selectLocation(int user,int insertion, char board[3][3]);
void setTurn(int insertion, int row, int column, int user, char board[3][3]);
int checkForWin(char board[3][3], int line, int user, int goodGame);
#include <stdio.h>
#include <stdlib.h>
int main()
{
    static char board[3][3] =
    {
      {'1','2','3'},
      {'4','5','6'},
      {'7','8','9'}
    };
    int i = 0;
    int user = 0;
    int insertion = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    int goodGame = 0;

// Main loop of the program.
 do{
        displayBoard(board);
        user = i%2 + 1;
        insertion = selectLocation(user, insertion, board);
        setTurn( insertion, row, column, user, board);
        goodGame = checkForWin(board, line, user, goodGame);
        i++;
    }while (goodGame != user);


 if(goodGame == 0)
      printf("\nCATS GAME!");
   else
      printf("\nCongratulations, user %d, YOU ARE THE WINNER!\n", goodGame);


return 0;
}
// function showing and updating the board.
char displayBoard(char board[3][3])
{
    printf("\n\n");
      printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}
// function selecting a specific point on the board to place X or O.
int selectLocation(int user,int insertion, char board[3][3])
{
    printf("\nuser %d, Where you want to place your %c: ", user,(user==1)?'X':'O');
    scanf("%d",&insertion);
return insertion;
}
// Required function to actually set the X or O on the board.
void setTurn(int insertion, int row, int column, int user, char board[3][3])
{
    row = --insertion/3;
    column = insertion%3;
    board[row][column] = (user == 1) ? 'X' : 'O';
}
// function to check for a winner. Winner works but other validation is
int checkForWin(char board[3][3], int line, int user, int goodGame)
{
     if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
         (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
          goodGame = user;

     else
        for(line = 0; line <= 2; line ++)
            if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
            (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                goodGame = user;

    if (goodGame != user)
        goodGame == 0;
return goodGame;
}

















