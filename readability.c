#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)


{

    string s = get_string("Text: ");

    int characters = strlen(s);

    //printf("length of string is %i\n", characters);


    int i;       //i is the number of characters in the string s - i increases everytime the for loop loops until i = characters
    int j = 0;   //j is the number is spaces in the string s - j increases everytime the for loops finds a space until i = character
    int jj = 0;  //jj is the number of punctuations in the string s - not needed after all
    int k = 0;   //k is the number of sentences in the string s - k increases everytime the for loop finds . ! or ? until i = character
    int l = 0;   //l is the number of letters in string s - l increases everytime loops finds a letter (bu using ASCII codes)

    for (i = 0; i < characters; i++)   //i++ is used to go through each character of the string one by one

    {

        if (s[i] == ' ')   //s[i] is used to index individual characters within a string

        {

            j++;
        }


    }


    for (i = 0; i < characters; i++)

    {

        if (((s[i] > (int) 64) && (s[i] < (int) 90)) || ((s[i] > (int) 96) && (s[i] < (int) 123)))

        {

            l++;

        }

    }



    //int letters = characters - jj - j; - this was flawed as it was difficult to capture all punctiations so jj was inaccurate
    int words = j + 1;
    int letters = l

    for (i = 0; i < characters; i++)

    {
        if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))

        {
            k++;

        }

    }

    int sentences = k


    //printf("Number of letters is %i\n", letters);   //print number of letters

    //printf("Number of words is %i\n", words);   //print number of words

    //printf("Number of sentences is %i\n", k);   //print number of sentences



    //Coleman-Liau Index
    //Index = 0.588 * L - 0.296 * S - 15.8
    // L = number of letters / 100 words
    // S = number of sentences / 100 words

    float L = (100 * ((float) letters / (float) words));   //integers previously declared are cast as floats to preserve precision of division
    float S = (100 * ((float) sentences / (float) words));

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
        if (Index > 16)

        {

            printf("Grade 16+\n");

        }


        else

        {

            printf("Grade %.0f\n", Index);
        }

    }

}