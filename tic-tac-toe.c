#include <stdio.h>
void print_board();
int even_odd(int);
int CheckWin();
char board[9];

int main(void)
{
    char ch;
    char ch2;
    int choice, i = 0, eee;

    for(int j = 0; j < 9; j++)
        board[j] = '-';

    printf("\nWhat you want to take X or O(player 1): ");
    scanf("%c",&ch);

    if(ch == 'X')
        ch2 = 'O';
    else
        ch2 = 'X';

    while(i != 9 && CheckWin() == 45)
    {
        eee = even_odd(i);
        printf("\n");
        print_board();
        printf("Player %d (1-9) : ", eee);
        scanf("%d", &choice);
        
        if(board[choice-1] == '-' && eee == 1)
            board[choice-1] = ch;
        else if(board[choice-1] == '-' && eee == 2)
            board[choice-1] = ch2;
        else
        {
            printf("\nPlace is already filled !\n");
            i--;
        }
        if(CheckWin() == 88)
        {
            printf("\nFinal results : \n\n");
            print_board();
            printf("X wins the game\n\n");
            return 0;
        }
        else if(CheckWin() == 79)
        {
            printf("\nFinal results : \n\n");
            print_board();
            printf("O wins the game\n\n");
            return 0;
        }
        
        i++;
    }

    printf("\nFinal results : \n\n");
    print_board();
    printf("Game draw !\n\n");
    return 0;
}

int even_odd(int num)
{
    if(num % 2 == 0)
        return 1;
    else
        return 2;
}

void print_board()
{
    printf("|  %c  |  %c  |  %c  |\n",board[0], board[1], board[2]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",board[3], board[4], board[5]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",board[6], board[7], board[8]);
    printf("\n");
}

int CheckWin()
{
    int winner;
    if(board[0] == board[1] && board[0] == board[2])
        winner = board[0];
    else if(board[3] == board[4] && board[3] == board[5])
        winner = board[3];
    else if(board[6] == board[7] && board[6] == board[8])
        winner = board[6];
    else if(board[0] == board[3] && board[0] == board[6])
        winner = board[0];
    else if(board[1] == board[4] && board[1] == board[7])
        winner = board[1];
    else if(board[2] == board[5] && board[2] == board[8])
        winner = board[2];
    else if(board[0] == board[4] && board[0] == board[8])
        winner = board[0];
    else if(board[2] == board[4] && board[2] == board[6])
        winner = board[2];
    else
        winner = 45;

    return winner;
}