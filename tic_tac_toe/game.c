#include <stdio.h>
#include <stdlib.h>

#define N 9
char *makeGameboard(char *gameBoard);
void printGameBoard(char *gameBoard, int pl1, int pl2);
char switchPlayers(int i);
int declareWinner(char *gameBoard);

int main(void)
{
        // variables
        int i, playerSelect, gamePlay = 0, count = 0, playAgain = 0;
        int pl1 = 0, pl2 = 0;
        
        char gameBoard[N];
        char playerSign;
        char s;

        printf("player 1 : X\n");
        printf("player 2 : O\n");
        printf("start game...?\n(0)yes\n(1)no ");
        scanf("%d", &i);
        if (i != 0)
                exit(1);
        system("cls");
        // create gamesboard array
        makeGameboard(gameBoard);

        do
        {        
                i = 0;
                while (i < 9)
                {      
                        if (declareWinner(gameBoard) != 1)
                        {
                                // print only once in the game
                                if (gamePlay == 0){
                                        printGameBoard(gameBoard, pl1,pl2);
                                        gamePlay = 1;
                                }
                                ////////////// X or O //////////
                                playerSign = switchPlayers(i);
                                scanf("%d", &playerSelect);

                                do
                                {
                                        if (gameBoard[playerSelect] != 'X' && gameBoard[playerSelect] != 'O')
                                        {   
                                                if (playerSelect <= 8 && playerSelect >= 0)
                                                {
                                                        // put the player symbol in the selected index in the array
                                                        gameBoard[playerSelect] = playerSign;
                                                        i++;
                                                }
                                                
                                                {
                                                        while (playerSelect > 8 || playerSelect < 0)
                                                        {
                                                                system("cls");
                                                                printGameBoard(gameBoard, pl1,pl2);
                                                                printf("pick a number between 0 and 8 : ");
                                                                scanf("%d", &playerSelect);
                                                                gameBoard[playerSelect] = playerSign;
                                                        
                                                        }
                                                        i++;
                                                }
                                                count = 1;
                                        }
                                        
                                        {
                                                printGameBoard(gameBoard, pl1,pl2);
                                                printf("select another box: ");
                                                scanf("%d", &playerSelect);
                                                count = 0;
                                        }
                                        
                                } while (count == 0);

                                printGameBoard(gameBoard, pl1,pl2);
                        }
                        
                        {
                                break;
                        }
                }

                printGameBoard(gameBoard, pl1, pl2);
                makeGameboard(gameBoard);

                if (i != 9)
                {
                        if (playerSign == 'X')
                                pl1++;
                        
                                pl2++;
                        
                        printf("%c wins\n", playerSign);
                }
                 
                        printf("nobody wins\n");

                printf("continue game...?\n(0)yes (1)no\n");
                scanf("%d", &playAgain);

                printGameBoard(gameBoard, pl1, pl2);
                i = 0;

        } while (playAgain == 0);
        // system("clr");
        return (0);
}

/* the makeGameboard function takes in the gameboard array loops over it and adds characters to it */
char *makeGameboard(char *gameBoard)
{
        int i;
        for (i = 0; i < 9; i++)
        {
                gameBoard[i] = i + '0';
        }
        return gameBoard;
}

/* printGameBoard prints out the gameboard with the elements in the gameBoard array*/
void printGameBoard(char *gameBoard, int pl1, int pl2)
{
        system("cls");
        printf("----------------------------------\n");
        printf("|          |          |          |\n");
        printf("|    %c     |    %c     |    %c     |\n", gameBoard[0], gameBoard[1], gameBoard[2]);
        printf("|          |          |          |\n");
        printf("----------------------------------\n");
        printf("|          |          |          |\n");
        printf("|    %c     |    %c     |    %c     |   X = %d\n", gameBoard[3], gameBoard[4], gameBoard[5], pl1);
        printf("|          |          |          |   O = %d\n", pl2);
        printf("----------------------------------\n");
        printf("|          |          |          |\n");
        printf("|    %c     |   %c      |   %c      |\n", gameBoard[6], gameBoard[7], gameBoard[8]);
        printf("|          |          |          |\n");
        printf("----------------------------------\n");
}

/* switch players */
char switchPlayers(int i)
{
        if (i % 2 == 0)
        {
                printf("player 1: ");
                return ('X');
        }
        
        {       
                printf("player 2: ");
                return ('O');  
        }
}

/* declareWinner checks if any player has won the the game*/
int declareWinner(char *gameBoard)
{
        if (gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2] && gameBoard[0] == gameBoard[2])
        {
                printf("%c wins\n", gameBoard[0]);
                return 1;
        }
         if (gameBoard[3] == gameBoard[4] && gameBoard[3] == gameBoard[5] && gameBoard[4] == gameBoard[5])
        {
                printf("%c wins\n", gameBoard[3]);
                return 1;
        }
         if (gameBoard[6] == gameBoard[7] && gameBoard[6] == gameBoard[8] && gameBoard[7] == gameBoard[8])
        {
                printf("%c wins\n", gameBoard[6]);
                return 1;
        }
         if (gameBoard[0] == gameBoard[3] && gameBoard[0] == gameBoard[6] && gameBoard[3] == gameBoard[6])
        {
                printf("%c wins\n", gameBoard[0]);
                return 1;
        }
         if (gameBoard[1] == gameBoard[4] && gameBoard[1] == gameBoard[7] && gameBoard[4] == gameBoard[7])
        {
                printf("%c wins\n", gameBoard[1]);
                return 1;
        }
         if (gameBoard[2] == gameBoard[5] && gameBoard[2] == gameBoard[8] && gameBoard[5] == gameBoard[8])
        {
                printf("%c wins\n", gameBoard[2]);
                return 1;
        }
         if (gameBoard[0] == gameBoard[4] && gameBoard[0] == gameBoard[8] && gameBoard[4] == gameBoard[8])
        {
                printf("%c wins\n", gameBoard[0]);
                return 1;
        }
         if (gameBoard[2] == gameBoard[4] && gameBoard[2] == gameBoard[6] && gameBoard[4] == gameBoard[6])
        {
                printf("%c wins\n", gameBoard[2]);
                return 1;
        }
        
        return 0;
}