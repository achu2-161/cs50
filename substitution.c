#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


bool check_key_length(string u);
bool check_arg_count(int argc);
bool check_key_characters(string u);
char rotate_letter(string s);
bool check_duplicates(string u);

int main(int argc, string argv[])
{

    string key = argv[1];

    if(check_arg_count(argc) == 1)

    {

        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else if(check_key_length(argv[1]) == 1)

    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (check_key_characters(argv[1]) == 1)

    {
        printf("Usage: ./substitution key\n");
        return 1;

    }

    else if(check_duplicates(argv[1]) == 1)

    {
        printf("Usage: ./substitution key\n");
        return 1;

    }

    int z = 0;


    char k = key[z];
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


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

//

}

bool check_key_length(string u)

{
    if (strlen(u) != 26)

    {
        return 1;
    }

    return 0;

}

bool check_arg_count(int argc)

{
    if(argc != 2)

    {
        return 1;
    }

    return 0;
}

bool check_key_characters(string u)

{

    int x = 0;
    int z = 0;

    for(x = 0; isalpha(u[x]); x++)

    {
        z++;
    }

    if (z != strlen(u))

    {
        return 1;
    }

    return 0;

}

bool check_duplicates(string u)

{
    int counter = 0;

    for (int i = 0; i < strlen(u); i++)

    {
        for(int j = i + 1; j < strlen(u); j++)

        {
            if(u[i] == u[j])

            {
                counter++;
            }
        }
    }

    if (counter > 0)

    {
        return 1;
    }

    return 0;
}