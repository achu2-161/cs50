#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    //declare variables
    
    float change;

    int quarter, nquarter, rquarter, dime, ndime, rdime, nickel, nnickel, rnickel, ncoins, npenny;


    //operators are located inside do-while loops to so user input can be used to calculate
    do
    {
        
        change = get_float("how much change is owed? ");

    }

    while (change < 0);
    
    //convert into cents
    quarter = change * 100;
    
    //calculate how many quarters from change
    nquarter = floor(quarter / 25);
    //calculate how many cents remaining after quarters subtracted
    rquarter = quarter % 25;

    //calculate how many dimes after quarters
    ndime = floor(rquarter / 10);
    //calculate how many cents remaining after dimes subtracted
    rdime = rquarter % 10;

    //calculate how many nickels after quarters
    nnickel = floor(rdime / 5);
    //calculate how many cents remaining after nickels subtracted
    rnickel = rdime % 5;
    
    //calculate how many pennies after nickels
    npenny = floor(rnickel % 1);
    
    //add all denominations
    ncoins = nquarter + ndime + nnickel + npenny;

    printf("%.2f\n", change);


    printf("number of coins: %i\n", ncoins);

}






