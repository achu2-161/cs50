#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BUFFER_SIZE 512                         //define buffer size to 512 bytes
#define FILENAME_SIZE 8                         //define size of string to 8 bytes

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

    uint8_t buffer[BUFFER_SIZE];                    //ceate an unsigned integer for the buffer
    char filename[FILENAME_SIZE];                   //create an array of characters to store name of file
    int i = 0;                                      //create an integer to keep track of number of files

    FILE *img = NULL;                               //*img is a pointer that points to a file. initialised to point at nothing

    //while there is still data on memory card, keep reading card. once there are no more 512byte blocks, it's reached the end of the card

    while (fread(buffer, 1, BUFFER_SIZE, card) == BUFFER_SIZE)

    {

        //check that the first block has the header of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)

            {

            if (img != NULL)                //check if file is already open

            {
                fclose(img);                //if file is open, close file (not sure why necessary!)

            }

            sprintf(filename, "%03i.jpg", i);           //create a file with name xxx.jpg based on the value of i
            img = fopen(filename, "w");                 //open the file with current file name (based on i)
            i++;                                        //increase the value of i for the next file

            }

        //if the header is not a jpg signature, start writing to file

        //check if file is already open

        if(img != NULL)

        {
            fwrite(buffer, 1, BUFFER_SIZE, img);        //if file is already open, start writing to file from buffer
        }

    }                                                   //close while loop when card at the end

    if (img != NULL)                                    //if any images are still open, close them

    {
        fclose(img);
    }

    fclose(card);                                       //close card
    return 0;

    }                                                   //end main function




    //copy data block to buffer
    //write data to new file ###.jpg, where ### is the name of the file


