#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{


    if (argc != 2)

    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if(strlen(argv[1]) != 26)

    {
        printf("Key must contain 26 characters\n");
        return 1;
    }



    int z = 0;

    string key = argv[1];
    char k = key[z];
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



    //


    for (int y = 0; y < strlen(argv[1]); y++)

        {
            if(isalpha(key[y]))

            {
                if(y != strlen(argv[1]))

                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }

            }
        }




    //


    string s = get_string("plaintext: ");
    int l = strlen(s);

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
    return 0;


}