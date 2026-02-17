#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define timesteps 5
#define array_size 10

int array[array_size];

int main(int argc, char **argv){

    srand((unsigned)time(NULL));

    //Partikel setzen
    array[2] = 1;    
    array[4] = 1;
    array[6] = 1;

    int *ptrarray = &array[0];

    int temp[array_size];                       //temp deklarieren
    for (int i = 0; i < array_size; i++)        //temp array initialisieren
    {
        temp[i] = 0;
    }
    
    int *ptrtemp = &temp[0];

    //Schleife für jeden Zeitschritt
    for (int k = 0; k < timesteps; k++)
    {
        //Ausgabe
        printf("Time %2d: ", k+1);
        for (int m = 0; m < array_size; m++)
        {
           printf("%-2d", *(ptrarray + m));
        }
        printf("\n");

        //Schleife für jeden Array Element
        for (int i = 0; i < array_size; i++)
        {

          if (*(ptrarray + i) == 1)        //Wenn Partikel da ist
            {
                
                int r = rand() % 2;     

                if(r == 0){         //Entscheiden mit random Zahl ob +1 oder -1 Position

                    if ((i-1) >= 0)     //Check ob i im array liegt
                    {

                        if (*(ptrtemp + i - 1) == 1)     //Wenn bei -1 bereits Partikel ist dann Kollision -> i-1 = 0
                        {
                            *(ptrtemp + i - 1) = 0;
                            printf("\nCollision on Index %d", i-1);
                        }

                        else{                       // Wenn bei -1 kein Partikel ist dann i-1 = 1
                            *(ptrtemp + i - 1) = 1;
                        }

                    }
                    else{
                        *(ptrtemp + i) = *(ptrarray + i);     //Wenn Partikel am Rand dann soll es am Rand bleiben
                    }
                    
                }
                else{

                    if ( (i + 1) < array_size)  //Check ob i im array liegt
                    {

                        if (*(ptrtemp + i + 1) == 1)     //Wenn bei +1 bereits Partikel ist dann Kollision -> i+1 = 0
                        {
                            *(ptrtemp + i + 1) = 0;
                            printf("\nCollision on Index %d", i+1);
                        }

                        else{                   // Wenn bei +1 kein Partikel ist dann i+1 = 1      
                            *(ptrtemp + i + 1) = 1;
                        }

                    }
                    else{
                        *(ptrtemp + i) = *(ptrarray + i);     //Wenn Partikel am Rand dann soll es am Rand bleiben
                    }
                }
            }  
            //Ende innere Array-Schleife
        } 
        
        //Array temp auf Array array kopieren
        for (int j = 0; j < array_size; j++)
        {
            *(ptrarray + j) = *(ptrtemp + j);
            
        }
        printf("\n\n");
        //Temp Array nullen
        for (int i = 0; i < array_size; i++)
        {
            *(ptrtemp + i) = 0;
        }
        
    }   
}