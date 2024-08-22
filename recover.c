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
    string filename = 000;

    //while there is still data on memory card, keep reading card

    while (fread(buffer, BUFFER_SIZE, 1, card) == 512)

    {
        //check if the first blocks represent a jpeg sequence
        for (int i = 0; i < 1000; i++)
        {

            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)

            {
                sprintf(filename, "%03i.jpg", i++);
                FILE *img = fopen(filename, "w");

                fwrite(buffer, BUFFER_SIZE, 1, img);
                fclose(img);
            }

            else
            {
                FILE *img = fopen(filename, "w");
                fwrite(buffer, BUFFER_SIZE, 1, img);
                fclose(img);

            }
        }

        fclose(card);
    }

    //copy data block to buffer
    //write data to new file ###.jpg, where ### is the name of the file

}
