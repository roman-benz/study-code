#include <stdio.h>
#include <string.h>

int main(void) {
    int flag = 0;
    char word[25];
    printf("Enter a word: ");
    scanf("%24s", word);

    size_t elements_in_word = strlen(word);

    for (size_t i = 0; i < elements_in_word / 2; i++)
    {
        if (word[i] != word[elements_in_word - 1 - i])
        {
           flag = 1;
        }
    }

    if (flag == 1)
    {
        printf("Das Wort ist kein Palindrom");
    }
    else{
        printf("Das Wort ist ein Palindrom");
    }
    
    
}