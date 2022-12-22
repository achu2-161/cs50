#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //index - 0.0588 * L - 0.296 * s - 15.8

    string text = get_string("Text: ");

    int l = strlen(text);

    //

    int number_letters = count_letters(text);

    //printf("%i letters\n", number_letters);

    //

    int number_words = count_words(text) + 1;
    //printf("%i words\n", number_words);

    //

    int number_sentences = count_sentences(text);
    //printf("%i sentences\n", number_sentences);

    float L = 100 * number_letters / (number_words);
    float s = 100 * number_sentences / (number_words);

    int index = round(0.0588 * L - 0.296 * s - 15.8);


    if (index < 0)

    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)

    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }


}


int count_letters(string text)

{

    int i = 0;
    int a = 0;



    for (i = 0; i < strlen(text); i++)

    {
        if ((isupper(text[i])) || (islower(text[i])))

        {
            a++;
        }


    }

    //printf("number of letters is %i\n", a);

    return a;

}

int count_words(string text)

{

    int j = 0;
    int b = 0;

    for (j = 0; j < strlen(text); j++)

    {
        if (isspace(text[j]))

        {
            b++;
        }
    }

    return b;
}

int count_sentences(string text)

{

    int k = 0;
    int c = 0;

    for (k = 0; k < strlen(text); k++)

    {
        if ((text[k] == 33) || (text[k] == 46) || (text[k] == 63))

        {
            c++;
        }

    }

    return c;
}