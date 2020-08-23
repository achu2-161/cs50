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
            string k1 = argv[1];                    // declaring a variable kk  for the key instead of writing argv[1] all the time for the key

            printf("ciphertext: ");
            
            int i = 0;  //ticker
            int j = 0;  //moves across string. j probably needed as i and j increase toether
            int l = strlen(s); //length of string   //  calculates length of string - already done above but redundant because code was rewritten
            
            string alpha = "abcdefghijklmnopqrstuvwxyz";
            string ALPHA2 = "ABCEDFGHIJKLMNOPQRSTUVWXYZ";
            
            for(i = 0; i < l; i++)
            
            {
            
            
                char p0 = k1[i];  //p0 = key text character at ith position in string k1
                char p1 = s[i]; //p = plain text character at ith position in string s
                char p2 = alpha[i];  //p2 = original alphabet at the ith position in string alpha
                char p3 = ALPHA2[i];  //p3 = original alphabet at the ith position in string ALPHA
                int k = p0;   //k = plain texy (integer) ASCII number representing character p0
                int pi = p1;  //pi = plain text (integer) ASCII number representing character p1 (integer format)
                int pii = p2;  //pii = plain tect (integer) ASCII number representing character p2
                int piii = p3; //piii = plain text (integer_ ASCII number representing character p3)
                int ci; // ASCII code representing deciphered code
                
                if ((pi >= 65) && (pi <= 90))   // determining whether characters are uppercase
                
                {
                    ci = (pi + (piii - k) % 26) + 65; //
                    printf("%c", (char)ci);
                }
                
                else
                
                {
                     if ((pi >= 97) && (pi <= 122))  //determining characters are lowercase
                     
                     {
                        ci = (pi + (pii - k) % 26) + 97; //
                        printf("%c", (char)ci);
                     }
                     
                      else
                      
                      {
                      
                      printf("%c", p1);  //print original characters which are not upper or lower characters

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

        
