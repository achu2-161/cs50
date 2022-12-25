#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{


    int z = 0;

    string key = argv[1];
    char k = key[z];
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string s = get_string("plaintext: ");



    int l = strlen(s);

    //


    for (int y = 0; y < strlen(argv[1]); y++)

        {
            if((isalpha(key[y])) == 1)

            {
                printf("Usage: ./substitution key\n");
            }
        }

    if ((argc != 0) || strlen(argv[1]) != 26)

    {
        printf("Usage: ./substitution key\n");
    }

    else

    {



    //


    printf("ciphertext: ");

    for (int i = 0; i < l; i++)

    {
        if(isalpha(s[i]) == 0)

        {
            printf("%c", s[i]);
        }

        for (int j = 0; j < 26; j++)

        {

            if(islower(s[i]))

            {
                if ((int)(s[i]) == (int)(lower_alphabet[j]))

                {
                    char lower_k = tolower(key[j]);
                    printf("%c", lower_k);
                }


            }

            else if (isupper(s[i]))

            {

                if ((int)(s[i]) == (int)(upper_alphabet[j]))

                {
                    char upper_k = toupper(key[j]);
                    printf("%c", upper_k);
                }


            }


        }


    }

    printf("\n");

    }
}