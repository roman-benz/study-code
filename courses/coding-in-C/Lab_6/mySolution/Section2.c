#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    float fuel_level;
    float max_fuel_level;
    char model[50];
}Car;

void refuel(Car *myCar, float fuelToAdd);

int main(void) {
    Car einAuto;
    einAuto.fuel_level = 15.2;
    einAuto.max_fuel_level= 66;
    char meinModell[50] = "Mercedes-Benz";
    strcpy(einAuto.model, meinModell);
    refuel(&einAuto, 40);
}

void refuel(Car *myCar, float fuelToAdd){
    if ((myCar->fuel_level + fuelToAdd) > myCar->max_fuel_level)
    {
        printf("Too much fuel added!");
    }
    else{
        myCar->fuel_level = myCar->fuel_level + fuelToAdd;
        printf("Fuel has been added. New fuel level: %-5f", myCar->fuel_level);
    }

}