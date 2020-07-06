#include <stdio.h>
#include <cs50.h>

int main(void)

{

    long x;

    do

    {
        x = get_long("Number: ");
    }

    while (x < 0);





    int one = (x % 10);
    int two = ((x % 100) / 10);
    int three = ((x % 1000) / 100);
    int four = ((x % 10000) / 1000);
    int five = ((x % 100000) / 10000);
    int six = ((x % 1000000) / 100000);
    int seven = ((x % 10000000) / 1000000);
    int eight = ((x % 100000000) / 10000000);
    int nine = ((x % 1000000000) / 100000000);
    int ten = ((x % 10000000000) / 1000000000);
    int eleven = ((x % 100000000000) / 10000000000);
    int twelve = ((x % 1000000000000) / 100000000000);
    int thirteen = ((x % 10000000000000) / 1000000000000);
    int fourteen = ((x % 100000000000000) / 10000000000000);
    int fifteen = ((x % 1000000000000000) / 100000000000000);
    int sixteen = ((x % 10000000000000000) / 1000000000000000);

    int product_16 = (sixteen * 2);
    int product_14 = (fourteen * 2);
    int product_12 = (twelve * 2);
    int product_10 = (ten * 2);
    int product_8 = (eight * 2);
    int product_6 = (six * 2);
    int product_4 = (four * 2);
    int product_2 = (two * 2);

    int lund_1 = ((product_16 / 10) + (product_16 % 10) + (product_14 / 10) + (product_14 % 10) + (product_12 / 10) +
        (product_12 % 10) + (product_10 / 10) + (product_10 % 10) + (product_8 / 10) + (product_8 % 10)
        + (product_6 / 10) + (product_6 % 10) + (product_4 / 10) + (product_4 % 10) + (product_2 / 10)
        + (product_2 % 10) + one + three + five + seven + nine + eleven + thirteen + fifteen);





    int start_13 = ((x % 10000000000000) / 1000000000000);
    int start_15 = ((x % 1000000000000000) / 10000000000000);
    int start_16_V = ((x % 10000000000000000) / 1000000000000000);
    int start_16_MC = ((x % 10000000000000000) / 100000000000000);
    int length_13 = (x / 1000000000000);
    int length_15 = (x / 100000000000000);
    int length_16 = (x / 1000000000000000);


    //VISA conditions

    if (((start_13 == 4) || (start_16_V == 4)) && ((10 > length_16 >= 1) || (10 > length_13 >= 1)) && (lund_1 % 10 == 0))

    {

        printf("VISA\n");

    }

    else

    {

        //Mastercard conditions

        if (((start_16_MC == 51) || (start_16_MC == 52) || (start_16_MC == 53) || (start_16_MC == 54) || (start_16_MC == 55))
            && (10 > length_16 >= 1) && (lund_1 % 10 == 0))


        {

            printf("MASTERCARD\n");

        }

        else

        {

            //AMEX conditions

            if (((start_15 == 34) || (start_15 == 37)) && (10 > length_15 >= 1) && (lund_1 % 10 == 0))

            {
                printf("AMEX\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }
    }
}

//If functions are nested to avoid various returns printing eg VISA and INVALID


