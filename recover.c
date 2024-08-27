#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#define BUFFER_SIZE 512
#define FILENAME_SIZE 4

int main(int argc, char *argv[])
{
    //accept single command-line argument
    //message user and return 1 (terminate main) if single command-line argument is not provided
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    //open file from memory card in read mode

    FILE *card = fopen(argv[1], "r");               //*card is a pointer that points to the file card.raw

    //create a buffer for a block of data

    uint8_t buffer[BUFFER_SIZE];
    string filename = NULL;
    int i = 0;

    FILE *img = NULL;                               //*img is a pointer that points to a file. initialised to point at nothing

    //while there is still data on memory card, keep reading card

    while (fread(buffer, BUFFER_SIZE, 1, card) == BUFFER_SIZE)

    {

        //check that the first block has the header of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)

            {
            //check that a file is already open

            if (img != NULL)

            {
                fclose(img);

            }

            sprintf(filename, "%03i.jpg", i);           //create a file with name xxx.jpg
            img = fopen(filename, "w");
            i++;

            }

        //if the header is not a jpg signature, start writing to file

        //check if file is already open

        if(img != NULL)

        {
            fwrite(buffer, BUFFER_SIZE, 1, img);
        }

    }

    if (img != NULL)

    {
        fclose(img);
    }

    fclose(card);
    return 0;

    }




    //copy data block to buffer
    //write data to new file ###.jpg, where ### is the name of the file


