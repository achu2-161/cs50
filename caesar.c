#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string input_arg);
char rotate(char input, int key);

int main(int argc, string argv[])

{
    string plaintext;

    if (argc != 2)

    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else

    {


    bool n = only_digits(argv[argc-1]);

    if (n == 0)

    {
        plaintext = get_string("plaintext: ");

    }

    else

    {
        return 0;
    }


    printf("ciphertext: ");

    for (int j = 0; j < strlen(plaintext); j++)

    {
        char c = rotate(plaintext[j], atoi(argv[1]));
        printf("%c", c);

    }

    printf("\n");

    }
}



bool only_digits(string input_arg)

{
    int key = atoi(input_arg);

    int l = strlen(input_arg);

    int a = 0;

    for (int i = 0; i < l; i++)

    {

        if (isdigit(input_arg[0]))

        {

            a++;
        }

        else

        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }


        if (a == l)

        {

            return 0;
        }

        else

        {
            printf("Usage: ./caesar key\n");
            return 1;
        }


}

char rotate(char input, int key)

{
    int asc = (int) input;
    int casc = 0;
    //printf("key is: %i\n", key);

    if (isupper(input))

    {
        casc = (asc + key - 65) % 26;
        //printf("casc is: %i\n", casc);
        return (char) (casc + 65);
    }

    else if (islower(input))

    {
        casc = (asc + key - 97) % 26;
        return (char) (casc +97);
    }

    else

    {
        return input;
    }
}