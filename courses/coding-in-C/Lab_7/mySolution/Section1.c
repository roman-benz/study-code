#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int userinput;
    printf("Bitte int N eingeben: ");
    scanf("%d", &userinput);
    int *ptr = (int*)calloc(userinput, sizeof userinput);

    for (int i = 0; i < userinput; i++)
    {
        *(ptr + i) = i*i;
    }

    int *newaddress = (int*)realloc(ptr, (sizeof userinput) * 2);

    printf("Array: ");
    for (int i = 0; i < userinput*2; i++)
    {
        *(newaddress + i) = i*i;
        printf("%-3d ", *(newaddress+i));
    }
    free(newaddress);

    //Malloc ist fuer die Deklarierung einzelner Objekte gedacht und initalisiert den Speicherbereich nicht.
    //Calloc ist fuer die Deklarierung von Arrays gedacht und fuellt die Speicherelemente mit Null-Bits auf.
    
}