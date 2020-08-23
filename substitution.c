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



    int len = strlen(argv[1]);  //assesses whether argv[] argument is numerical len is variable to assess lenth of string

    if (len != 26)

    {
        printf("Key must be 26 characters\n");
        return 1;
    }

    //int len = strlen(argv[1]);  //assesses whether argv[] argument is numerical len is variable to assess lenth of string
    int x, y = 0;  // x is a ticker, y increases everytime a character in the string array is a number

    for (x = 0; x < len; x++)  // argc and argv are assessed separately because the test for argv assumes there the user is imputting a value in argv. If nothing is input it leads in a segmentation ettot
                                // when argc is assessed first, it kills the program as soon as there is not 2 arguments (including no argv argument) before the chance for segmentation error
    {
        if (isupper(argv[1][x]) > 0 || islower(argv[1][x]) > 0)  //2D array - isdigit is a function that detects alphabetical values for each character. for loop analyses each character one by one

        {
            y++;  //y increases everytime a numerical value is found


        }


    }


    if (argc == 2 && y == 26)  //  if function to determine if argv meets requirements. if y and len are the same it means that all characters in argv are numbers (therefore meet requirements)
                                //  if y is less than len, then not all characters in argv were numerical, therefore do not meet requirements of argv
                                //  argv = 2 is redundant here as it has already been done earlier (line 11)

        {
            string s = get_string("plaintext: ");  // requesting user input for the string
            string k = argv[1];                    // declaring a variable kk  for the key instead of writing argv[1] all the time for the key

            printf("ciphertext: ");

            int i = 0;  //ticker
            int j = 0;  //moves across string. j probably needed as i and j increase toether
            int l = strlen(s); //length of string   //  calculates length of string - already done above but redundant because code was rewritten




            for(i = 0; i < l; i++)

            {


                char p = s[i];
                int p1 = p;
                char cu = k[p1 - 65];
                char cl = k[p1 - 97];


                if ((p1 >= 65) && (p1 <= 90))   // determining whether characters are uppercase

                {
                    char m = toupper(cl);
                    printf("%c", n);
                }

                else

                {
                     if ((p1 >= 97) && (p1 <= 122))  //determining characters are lowercase

                     {
                        char n = tolower(cl);
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
            printf("Usage: ./substitution key\n");  // error message from else statement following line 38
            return 1;

        }


}


