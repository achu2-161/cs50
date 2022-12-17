

#include <stdio.h>
#include <cs50.h>

int main(void)


{
    int height;

do
    {
    height = get_int ("height of the pyramid: ");
    }

    while ((height < 1) || (height > 8));

for (int row = 0; row < height; row++)
    {


    for (int column = 0; column <= row; column++)
        {

            printf("#");
        }
        printf("\n");
    }
}
