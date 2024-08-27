#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer to store data blocks
    uint8_t buffer[BUFFER_SIZE];
    FILE *img = NULL;
    char filename[8];  // To hold the filename ###.jpg
    int file_count = 0;

    // Read the card file until the end
    while (fread(buffer, sizeof(uint8_t), BUFFER_SIZE, card) == BUFFER_SIZE)
    {
        // Check if the block indicates the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a previous JPEG file is open, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            file_count++;
        }

        // If a JPEG file is open, write to it
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BUFFER_SIZE, img);
        }
    }

    // Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
