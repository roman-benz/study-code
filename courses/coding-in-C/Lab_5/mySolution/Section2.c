#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

    for (int i = 0; i < argc; i++)
    {
        char *address = argv[i];
        int length = strlen(argv[i]);
        printf("Argument %d at address ""%p"" has content: %s (length: %d)\n", i, address, argv[i], length);
    }
    

}