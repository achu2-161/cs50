#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)


{

    string s = get_string("Text: ");

    int characters = strlen (s);

    //printf("length of string is %i\n", characters);


    int i;       //i is the ith character in the string s
    int j = 0;   //j is the jth space in the string s
    int jj = 0;  //jj is the number of punctuations in the string s
    int k = 0;   //k is the kth end of sentence of string s

    for(i = 0; i < characters; i++)

    {

        if(s[i] == ' ')

        {

            j++;
        }


    }
        
        
    for(i = 0; i < characters; i++)
    
    {
        
        if((s[i] == ',') || (s[i] == ';') || (s[i] == ':') || (s[i] == '"'))
        
        {
            
            jj++;
            
        }
        
    }
    
    
    
        int letters = characters - jj;
        int words = j+1;


    for(i = 0; i < characters; i++)

    {
        if((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))

        {
            k++;

        }

    }




    //printf("Number of letters is %i\n", letters);   //print number of letters

    //printf("Number of words is %i\n", words);   //print number of words

    //printf("Number of sentences is %i\n", k);   //print number of sentences



    //Coleman-Liau Index
    //Index = 0.588 * L - 0.296 * S - 15.8
    // L = number of letters / 100 words
    // S = number of sentences / 100 words

    float L = (100 * ((float) letters / (float) words));
    float S = (100 * ((float) k / (float) words));

    float Index = ((0.0588 * L) - (0.296 * S) - 15.8);
    
    
    //printf("L: %.4f\n", L);
    //printf("S: %.4f\n", S);
    //printf("Index: %.4f\n", Index);
    
    if (Index < 1)

    {
        
        printf("Before Grade 1\n");
        
    }

    
    else

    {
        if(Index > 16)

        {
            
            printf("Grade 16+\n");
            
        }

        
        else

        {
            
            printf("Grade %.0f\n", Index);
        }
        
    }

}