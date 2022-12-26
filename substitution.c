#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])

{

    if (argc != 2)  //assesses whether there are 2 arguments

    {
        printf("Usage: ./substitution key\n");
        return 1;
    }



    int len = strlen(argv[1]);  //assesses length of the key

    if (len != 26)  // assesses that the length = 26

    {
        printf("Key must be 26 characters\n");
        return 1;
    }


    int x, y = 0;  // x is a ticker, y increases everytime a character in the string array is a number

    for (x = 0; x < len; x++)

        // argc and argv are assessed separately because the test for argv assumes there the user is imputting a value in argv. If nothing is input it leads in a segmentation ettot
        // when argc is assessed first, it kills the program as soon as there is not 2 arguments (including no argv argument) before the chance for segmentation error
    {
        if (isupper(argv[1][x]) > 0 || islower(argv[1][x]) > 0)

            //2D array - isupper is a function that detects upper caps for each character. is lower is a function that detects lower caps for each character.  for loop analyses each character one by one

        {
            y++;  //y increases everytime an upper case or lower case is found

        }

    }

    int ww = 0, xx, yy;  //nested looops to compare combinations of xx and yy to find duplicates - , the o


    for (xx = 0; xx < len; xx++)  //outside loops goes to the next character and everytime inside loops completes

    {
        for (yy = xx + 1; yy < len; yy++)  // inside loop runs through the string first
        {
            char ii = argv[1][xx];
            char jj = argv[1][yy];
            if (toupper(ii) == toupper(jj))  // toupper converts all characters to upper - otherwise duplicates are missed between upper and lower letters

            {
                ww++;  // everytime duplicates are found, ww increased by 1

            }
        }
    }



    if (argc == 2 && y == 26 && ww == 0)

        //  if function to determine if argv meets requirements.
        //  if argc == 2 means there are only 2 arguments in the command line
        //  if y == 26 means there are only 26 letters
        //  ww == 0 means there are no duplicates

    {
        string s = get_string("plaintext: ");  // requesting user input for the string
        string k = argv[1];                    // declaring a variable k for the key instead of writing argv[1] all the time for the key

        printf("ciphertext: ");

        int i = 0;  //ticker
        int j = 0;  //moves across string. j probably needed as i and j increase toether
        int l = strlen(s);


        for (i = 0; i < l; i++)

        {


            char p = s[i];           //p is a character at the ith position in string s (plaintext)
            int p1 = p;              //p1 is the ASCII number corresponsing to character p
            char cu = k[p1 - 65];   //cu is upper case ciphertext character - [p1 - 65] is to reset ASCII A to 0
            char cl = k[p1 - 97];    //cl is lower case ciphertext character - [p1 - 65] to to reset ASCII a to 0


            if ((p1 >= 65) && (p1 <= 90))   // determining whether characters are uppercase

            {
                char m = toupper(cu);  //toupper necessary to ensure upeprcap plaintext is cipheres in uppercap
                printf("%c", m);
            }

            else

            {
                if ((p1 >= 97) && (p1 <= 122))  //determining characters are lowercase

                {
                    char n = tolower(cl);  //tolower necessary to ensure lowercap plaintext is cipheres in lowercap
                    printf("%c", n);
                }

                else
                {
                    printf("%c", p);  //print original characters which are not upper or lower characters


                }

            }

        }



        printf("\n");  // print new line
        return 0;


    }

    else

    {

        printf("Usage: ./substitution key !\n");  // error message from else statement following line 69
        return 1;



    }


}