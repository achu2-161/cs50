#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)

{

float change;
   
 int quarter, nquarter, rquarter, dime, ndime, rdime, nickel, nnickel, rnickel, ncoins;
    
 

     do
    {
        change = get_float("how much change is owed? ");
        
     
    }

    while (change < 0);
    
          quarter = change*100;
   nquarter = floor(quarter/25);
   rquarter = quarter%25;
   
   ndime = floor(rquarter/10);
   rdime = rquarter%10;

    nnickel = floor(rdime/5);
    rnickel = rdime%5;
    
    ncoins = nquarter + ndime + nnickel + rnickel;

          printf("%.2f\n", change);


     printf("number of coins: %i\n", ncoins);
        
}
   
        
         
         


 