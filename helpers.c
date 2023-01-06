#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)

    {
        for (int j = 0; j < width; j++)

        {
            int s = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            float a = round(s / 3.0);

            image[i][j].rgbtBlue = a;
            image[i][j].rgbtGreen = a;
            image[i][j].rgbtRed = a;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)

    {
        for (int j = 0; j < width; j++)

        {
            float s_b = (image[i][j].rgbtBlue * 0.131 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtRed * 0.272);
            float s_g = (image[i][j].rgbtBlue * 0.168 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtRed * 0.349);
            float s_r = (image[i][j].rgbtBlue * 0.189 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtRed * 0.393);

            int s_bi = round(s_b);
            int s_gi = round(s_g);
            int s_ri = round(s_r);

            if (s_bi > 255)

            {
                image[i][j].rgbtBlue = 255;
            }

            else

            {
                image[i][j].rgbtBlue = s_bi;
            }

            if (s_gi > 255)

            {
                image[i][j].rgbtGreen = 255;
            }

            else
            {
                image[i][j].rgbtGreen = s_gi;
            }

            if (s_ri > 255)

            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = s_ri;
            }



        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{



    for (int i = 0; i < width / 2; i++)

    {

        for (int j = 0; j < height; j++)




        {

            int temp_b = image[j][i].rgbtBlue;
            int temp_g = image[j][i].rgbtGreen;
            int temp_r = image[j][i].rgbtRed;

            int i_swap = round(width - i);


            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;

            image[j][width - i - 1].rgbtBlue = temp_b;
            image[j][width - i - 1].rgbtGreen = temp_g;
            image[j][width - i - 1].rgbtRed = temp_r;

        }


    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE duplicate[height][width];

    for (int i = 0; i < width; i++)

    {
        for (int j = 0; j < height; j++)

        {
            duplicate[j][i].rgbtBlue = image[j][i].rgbtBlue;
            duplicate[j][i].rgbtGreen = image[j][i].rgbtGreen;
            duplicate[j][i].rgbtRed = image[j][i].rgbtRed;
        }
    }

    for (int i = 0; i < width; i++)

    {
        for (int j = 0; j < height; j++)

        {

            float avg_blue = 0.0;
            float avg_green = 0.0;
            float avg_red = 0;

            //for the following, abcdefghi is a box represented the pixels around pixel [j][i]. the grid is represented as follows:

            // a b c
            // d e f
            // g h i

            if (j == 0 && i == 0)
                // 1 - efhi (top left corner)

            {
                avg_blue = ((duplicate[j][i].rgbtBlue + duplicate[j][i + 1].rgbtBlue + duplicate[j + 1][i].rgbtBlue
                            + duplicate[j + 1][i + 1].rgbtBlue)/4.0);
                avg_green = ((duplicate[j][i].rgbtGreen + duplicate[j][i + 1].rgbtGreen + duplicate[j + 1][i].rgbtGreen
                            + duplicate[j + 1][i + 1].rgbtGreen)/4.0);
                avg_red = ((duplicate[j][i].rgbtRed + duplicate[j][i + 1].rgbtRed + duplicate[j + 1][i].rgbtRed
                            + duplicate[j + 1][i + 1].rgbtRed)/4.0);

            }


            else if (j == 0 && (0 < i && i < width - 1))
                // 2 - defghi (top row)

            {
                avg_blue = ((duplicate[j][i - 1].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j][i + 1].rgbtBlue
                            + duplicate[j + 1][i - 1].rgbtBlue + duplicate[j + 1][i].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue) / 6.0);
                avg_green = ((duplicate[j][i - 1].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j][i + 1].rgbtGreen
                            + duplicate[j + 1][i - 1].rgbtGreen + duplicate[j + 1][i].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen) / 6.0);
                avg_red = ((duplicate[j][i - 1].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j][i + 1].rgbtRed
                            + duplicate[j + 1][i - 1].rgbtRed + duplicate[j + 1][i].rgbtRed + duplicate[j + 1][i + 1].rgbtRed) / 6.0);

            }

            else if (j == 0 && i == width - 1)
                // 3 - degh (top right corner)

            {
                avg_blue = ((duplicate[j][i - 1].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j + 1][i - 1].rgbtBlue
                            + duplicate[j + 1][i].rgbtBlue)/4.0);
                avg_green = ((duplicate[j][i - 1].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j + 1][i - 1].rgbtGreen
                            + duplicate[j + 1][i].rgbtGreen)/4.0);
                avg_red = ((duplicate[j][i - 1].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j + 1][i - 1].rgbtRed
                            + duplicate[j + 1][i].rgbtRed)/4.0);


            }

            else if ((j > 0 && j < height - 1) && i == 0)
                // 4 - bcefhi (left column)


            {
                avg_blue = ((duplicate[j - 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j][i].rgbtBlue
                            + duplicate[j][i + 1].rgbtBlue + duplicate[j + 1][i].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue) / 6.0);
                avg_green = ((duplicate[j - 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen +duplicate[j][i].rgbtGreen
                            + duplicate[j][i + 1].rgbtGreen + duplicate[j + 1][i].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen) / 6.0);
                avg_red = ((duplicate[j - 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed +duplicate[j][i].rgbtRed
                            + duplicate[j][i + 1].rgbtRed + duplicate[j + 1][i].rgbtRed + duplicate[j + 1][i + 1].rgbtRed) / 6.0);


            }

            else if ((j > 0 && j < height - 1) && i == width - 1)
                // 6 - abdegh (right column)

            {
                avg_blue = ((duplicate[j - 1][i - 1].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j][i - 1].rgbtBlue
                            + duplicate[j][i].rgbtBlue + duplicate[j + 1][i - 1].rgbtBlue + duplicate[j + 1][i].rgbtBlue) / 6.0);
                avg_green = ((duplicate[j - 1][i - 1].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j][i - 1].rgbtGreen
                            + duplicate[j][i].rgbtGreen + duplicate[j + 1][i - 1].rgbtGreen + duplicate[j + 1][i].rgbtGreen) / 6.0);
                avg_red = ((duplicate[j - 1][i - 1].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j][i - 1].rgbtRed
                            + duplicate[j][i].rgbtRed + duplicate[j + 1][i - 1].rgbtRed + duplicate[j + 1][i].rgbtRed) / 6.0);


            }

            else if (j == height - 1 && i == 0)
                // 7 - bcef (bottom left corner)


            {
                avg_blue = ((duplicate[j - 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j][i].rgbtBlue
                            + duplicate[j][i + 1].rgbtBlue) / 4.0);
                avg_green = ((duplicate[j - 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen + duplicate[j][i].rgbtGreen
                            + duplicate[j][i + 1].rgbtGreen) / 4.0);
                avg_red = ((duplicate[j - 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed + duplicate[j][i].rgbtRed
                            + duplicate[j][i + 1].rgbtRed) / 4.0);


            }

            else if (j == height - 1 && (i > 0 && i < width - 1))
                // 8 - abcdef (bottom row)


            {
                avg_blue = ((duplicate[j - 1][i - 1].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue
                            + duplicate[j][i - 1].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j][i + 1].rgbtBlue) / 6.0);
                avg_green = ((duplicate[j - 1][i - 1].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen
                            + duplicate[j][i - 1].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j][i + 1].rgbtGreen) / 6.0);
                avg_red = ((duplicate[j - 1][i - 1].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed
                            + duplicate[j][i - 1].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j][i + 1].rgbtRed) / 6.0);


            }


            else if (j == height - 1 && i == width - 1)
                // 9 - abde (bottom right corner)


            {
                avg_blue = ((duplicate[j - 1][i - 1].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j][i - 1].rgbtBlue
                            + duplicate[j][i].rgbtBlue) / 4.0);
                avg_green = ((duplicate[j - 1][i - 1].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j][i - 1].rgbtGreen
                            + duplicate[j][i].rgbtGreen) / 4.0);
                avg_red = ((duplicate[j - 1][i - 1].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j][i - 1].rgbtRed
                            + duplicate[j][i].rgbtRed) / 4.0);


            }

            else if ((j > 0 && j < height - 1) && (i > 0 && i < width - 1))
                // 5 - abcdefghi (internal pixels)

            {
                avg_blue = ((duplicate[j - 1][i - 1].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue
                            + duplicate[j][i - 1].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j][i + 1].rgbtBlue + duplicate[j + 1][i - 1].rgbtBlue
                            + duplicate[j + 1][i].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue) / 9.0);
                avg_green = ((duplicate[j - 1][i - 1].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen
                            + duplicate[j][i - 1].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j][i + 1].rgbtGreen + duplicate[j + 1][i - 1].rgbtGreen
                            + duplicate[j + 1][i].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen) / 9.0);
                avg_red = ((duplicate[j - 1][i - 1].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed
                            + duplicate[j][i - 1].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j][i + 1].rgbtRed + duplicate[j + 1][i - 1].rgbtRed
                            + duplicate[j + 1][i].rgbtRed + duplicate[j + 1][i + 1].rgbtRed) / 9.0);


            }

            int avg_blue_i = round(avg_blue);
            int avg_green_i = round(avg_green);
            int avg_red_i = round(avg_red);

            image[j][i].rgbtBlue = avg_blue_i;
            image[j][i].rgbtGreen = avg_green_i;
            image[j][i].rgbtRed = avg_red_i;

        }
    }

    return;
}
