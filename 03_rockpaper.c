#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <math.h>


int game(char you, char computer){
    if (you == computer)
    {
        return -1; 
    }
    //  player winning code
    else if (you == 'p' && computer == 'r')
    {
        return 0;
    }
    else if (you == 's' && computer == 'p')
    {
        return 0;
    }
    else if (you == 'r' && computer == 's')
    {
        return 0;
    }
    //Computer winning code
    else if (you == 's' && computer == 'r')
    {
        return 1;
    }
    else if (you == 'p' && computer == 's')
    {  
        return 1;
    }
    else if (you == 'r' && computer == 'p')
    {
        return 1;
    }
    //here is draw code
    else if (you == 'r' && computer =='r')
    {
        return -1;
    }
    else if (you == 'p' && computer == 'p')
    {
        return -1;
    }
    else if (you == 's' && computer == 's')
    {
        return -1;
    }
}
int main()
{
    int n;
    char you,comuter,result;


    srand(time(NULL));

    n = rand() % 100;
    if (n<33)
    {
        comuter = 'r';
    }
    else if (n>33 && n<66)
    {
        comuter = 'p';
    }
    else if (n>66 && n<100)
    {
        comuter = 's';
    }
    printf("\n\nEnter 'r' for Rock and 'p' for paper and 's' for  scissor\n");
    scanf("%c",&you);
    
result = game(you,comuter);
if (result == 1)
{
    printf("\n You have Lost the game\n");
}
else if (result == 0)
{
    printf("\n You have Won the game \n");
}
else if (result == -1)
{
    printf("\n Draw \n");
}
printf("you choose %c and computer choose %c \n",you, comuter);
    return 0;
}