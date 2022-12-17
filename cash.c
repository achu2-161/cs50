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
    quarter = round(change * 100);

    //calculate how many quarters from change
    nquarter = round(quarter / 25);
    //calculate how many cents remaining after quarters subtracted
    rquarter = round(quarter % 25);

    //calculate how many dimes after quarters
    ndime = round(rquarter / 10);
    //calculate how many cents remaining after dimes subtracted
    rdime = round(rquarter % 10);

    //calculate how many nickels after quarters
    nnickel = round(rdime / 5);
    //calculate how many cents remaining after nickels subtracted
    rnickel = round(rdime % 5);

    //calculate how many pennies after nickels
    npenny = quarter - (nquarter * 25) - (ndime * 10) - (nnickel * 5);

    //add all denominations
    ncoins = nquarter + ndime + nnickel + npenny;

    printf("%.2f\n", change);

    printf("%i\n", quarter);
    printf("number of coins: %i\n", ncoins);

}






