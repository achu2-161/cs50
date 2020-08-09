#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])

{
    
    if (argc != 2)
    
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    
    
        int len = strlen(argv[1]);
        int x, y = 0;
        
        for (x = 0; x < len; x++)
        
        {
            if (isdigit(argv[1][x]) > 0)
            
            {
                y++;
                
            }
            
            
        }
        
    
    

    if (argc == 2 && y == len)
    

    
    {
        string s = get_string("plaintext: ");
        string kk = argv[1];

        printf("ciphertext: ");
        int k = atoi(kk);
        int i = 0;  //ticker
        int j = 0;  //moves across string
        int l = strlen(s); //length of string

        for (i = 0; i < l; i++)

        {
            char p = s[j]; //p = plain text character at jth position in string s
            int pi = p;  //pi = ASCII number representing character p
            int ci = pi + k;

            if ((pi >= 65) && (pi <= 90))

            {
                int cir = ((ci - 65) % 26) + 65;
                printf("%c", (char)cir);

            }

            else

            {

                if ((pi >= 97) && (pi <= 122))

                {

                    int cir = ((ci - 97) % 26) + 97;
                    printf("%c", (char)cir);

                }

                else

                {
                    printf("%c", p);

                }

            }

            j++;

        
         }
         
         printf("\n");
         return 0;
    
    }
    
    
    else
    
    
    {

        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    
}

