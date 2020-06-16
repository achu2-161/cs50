//

#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int height, row, column, space;  //declaration of variables used

    do
    {
        height = get_int("height of the pyramid: ");  //prompts the user for an input
    }

    while ((height < 1) || (height > 8));  //conditions that causes the program to keep asking is number entered is < 1 or > 8


    for (row = 0; row < height; row++)  //loop that increases row. Will only increase row when nested loop meets condition
    {
        for (space = 0; space < height - row - 1;
             space++)  //loop that increases spaces. This loop and the next one are not nested. When condition is met, program proceeds to next loop.
        {
            printf(" ");
        }

        for (column = 0; column <= row; column++)  //loop that increases columns
        {

            printf("#");
     
            
          
        }
        
            printf("  ");  //prints double space between 2 pyramids
        
                for(column = 0; column <= row; column++)  //loop to print the left aligned pyramid
            
                {
                    printf("#");
                }
        
            printf("\n");


    }  //all this is nested inside the first loop so it all gets printed before row increases.
}

