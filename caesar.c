#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])

{

    if (argc != 2)  //assesses whether there are 2 arguments

    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    int len = strlen(argv[1]);  //assesses whether argv[] argument is numerical len is variable to assess lenth of string
    int x, y = 0;  // x is a ticker, y increases everytime a character in the string array is a number

    for (x = 0; x < len; x++)  // argc and argv are assessed separately because the test for argv assumes there the user is imputting a value in argv. If nothing is input it leads in a segmentation ettot
                                // when argc is assessed first, it kills the program as soon as there is not 2 arguments (including no argv argument) before the chance for segmentation error
    {
        if (isdigit(argv[1][x]) > 0)  //2D array - isdigit is a function that detects numerical values for each character. for loop analyses each character one by one

        {
            y++;  //y increases everytime a numerical value is found


        }


    }


    if (argc == 2 && y == len)  //  if function to determine if argv meets requirements. if y and len are the same it means that all characters in argv are numbers (therefore meet requirements)
                                //  if y is less than len, then not all characters in argv were numerical, therefore do not meet requirements of argv
                                //  argv = 2 is redundant here as it has already been done earlier (line 11)

    {
        string s = get_string("plaintext: ");  // requesting user input for the string
        string kk = argv[1];                    // declaring a variable kk  for the key instead of writing argv[1] all the time for the key

        printf("ciphertext: ");
        int k = atoi(kk);               // converting string kk to an integer so that it can be used in mathematical operations
        int i = 0;  //ticker
        int j = 0;  //moves across string. j probably needed as i and j increase toether
        int l = strlen(s); //length of string   //  calculates length of string - already done above but redundant because code was rewritten

        for (i = 0; i < l; i++)   // loop to analyse and print each character of string

        {
            char p = s[j]; //p = plain text character at jth position in string s
            int pi = p;  //pi = plain text (integer) ASCII number representing character p (integer format)
            int ci = pi + k;  // ci = ciphertext (integer) ASCII number representing character ci (integer format). key added to create cipher

            // evaulating uppercases

            if ((pi >= 65) && (pi <= 90))   // determining whether characters are uppercase

            {
                int cir = ((ci - 65) % 26) + 65;   // formula to wrap letters around when they pass Z
                printf("%c", (char)cir);   //print character. for loop will make each character print side by side. (char) casts ASCII integer to character.

            }

            else

            {
                //evaluating lower cases. Part of same for loop to upper and lower cases print on same line

                if ((pi >= 97) && (pi <= 122))  //determining characters are lowercase

                {

                    int cir = ((ci - 97) % 26) + 97;  // formula to wrap letters around when they pass Z
                    printf("%c", (char)cir);  //print character. for loop will make each character print side by side. (char) casts ASCII integer to character.

                }

                else

                {
                    printf("%c", p);  //print original characters which are not upper or lower characters

                }

            }

            j++;  // after a character is analysed and printed, j increases move to next character


        }

        printf("\n");  // print new line
        return 0;

    }


    else


    {

        printf("Usage: ./caesar key\n");  // error message from else statement following line 38
        return 1;
    }


}

