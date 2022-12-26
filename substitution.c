#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


bool check_key_length(string u);        //declaration of function to calculate length of key
bool check_arg_count(int argc);         //declaration of function to calculate how many arguments
bool check_key_characters(string u);    //declaration of function to determine is string characters are only alphabetical
char rotate_letter(string s);           //declaration of function to rotate letters based on keys
bool check_duplicates(string u);        //declatation of function to identify duplicates

int main(int argc, string argv[])
{

    string key = argv[1];               //store key in a string variable

    if (check_arg_count(argc) == 1)     //call funtion to count arguments

    {

        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else if (check_key_length(argv[1]) == 1)        //call function to calculate key length. function defined to return 1 if key length is not 26

    {
        printf("Usage: ./substitution key\n");      //if function returns 1, print error message and return 1 to end main
        return 1;
    }

    else if (check_key_characters(argv[1]) == 1)    //call function to determine is characters in key are all alphabetical. function defined to return 1 is not all characters i key are alphabetical

    {
        printf("Usage: ./substitution key\n");      //if function returns 1, print error message and return 1 to end main
        return 1;

    }

    else if (check_duplicates(argv[1]) == 1)        //call functin to check duplicates. function defined to return 1 if duplicates are found.

    {
        printf("Usage: ./substitution key\n");      //if function returns 1, print error message and return 1 to end main
        return 1;

    }

    int z = 0;                                                  //initialise variable z to store zth character (unsused variable)


    char k = key[z];                                            //array to identify individual characters in the key
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";       //defined variable containing lower case alphabet
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";       //defined variable containing upper case alphabet


    string s = get_string("plaintext: ");                       //prompting user to enter plaintext. stored in string variable s
    int l = strlen(s);                                          //length of plaintext stored in variable l

    printf("ciphertext: ");

    for (int i = 0; i < l; i++)                                 //loop to cycle through every character of the plaintext

    {
        if (isalpha(s[i]) == 0)                                 //check if ith character is alphabetical
        {
            printf("%c", s[i]);                                 //if ith character is not alphabetical (==1), function prints the character unchanged
        }

        for (int j = 0; j < 26; j++)                            //loop to cycle through alphabet to compare ith key character against position of jth alphabet character

        {

            if (islower(s[i]))                                  //check is ith character is lower case

            {
                if ((int)(s[i]) == (int)(lower_alphabet[j]))    //when ith plaintext character matches jth lower alphabet character,

                {
                    char lower_k = tolower(key[j]);             //force key character at position j to a lower case
                    printf("%c", lower_k);                      //print lowercase key character at jth position
                }


            }

            else if (isupper(s[i]))                             //check is ith character is upper case

            {

                if ((int)(s[i]) == (int)(upper_alphabet[j]))    //when ith plaintext character matches jth upper alphabet character,

                {
                    char upper_k = toupper(key[j]);             //force key character at position j to a upper case
                    printf("%c", upper_k);                      //print upper key character at jth position
                }


            }


        }


    }

    printf("\n");                                               //after all i characters from plaintext s have been matched, print new line
    return 0;

//

}

bool check_key_length(string u)                             //definition of function to check length of string. string argv[1] is passed as variable u

{
    if (strlen(u) != 26)                                    //if length of u is not 26

    {
        return 1;                                           //function returns 1
    }

    return 0;                                               //otherwise function returns 0

}

bool check_arg_count(int argc)                              //definition of function to check number of arguments. int argc is passed as variable argc

{
    if (argc != 2)                                          //if number of arguments is not 2

    {
        return 1;                                           //return 1
    }

    return 0;                                               ///return 0
}

bool check_key_characters(string u)                         //definition of function to check that all characters are alphabetical

{

    int x = 0;                                              //initialise variable x as 0. x will be used as the counter to count alphabetical characters
    int z = 0;                                              //initialise variable z as 0. z will be used to store length of key. not necessary to use variable for this

    for (x = 0; x < strlen(u); x++)                         //loop to cycle through all the characters inside key. when condition is met (ie when character at xth position is alphabetical), increase counter

    {
        if(isalpha(u[x]))

        {
            z++;
        }
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
        for (int j = i + 1; j < strlen(u); j++)

        {
            if (u[i] == u[j])

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