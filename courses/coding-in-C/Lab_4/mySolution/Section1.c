#include <stdio.h>
#include <stdlib.h>
void myFunction(char einString[]);

int main(void)
{

    //Early Bird - Teil
    char meinString[] = "Curly bird catches the worm";
    char *p_meinString = meinString;

    printf("%s\n", meinString);
    printf("%c\n", *p_meinString);

    *p_meinString = 'E';
    p_meinString = p_meinString + 1;
    *p_meinString = 'a';

    printf("%s\n", meinString);
    printf("%c", *p_meinString);
    
    printf("\n\n\n");

    //myFuntion-Teil

    char spruch[] = "AAtions speak louder than words";
    myFunction(spruch);
}

void myFunction(char einString[]){
    char *p_einString = einString;
    p_einString = p_einString + 1;
    *p_einString = 'c';
    printf("%s", einString);
}