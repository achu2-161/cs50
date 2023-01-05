#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])                                       //definition of function grayscale taking arguments int height, int width and datatype RGBTRIPLE array image (array defined by height and width)
{
    for (int i = 0; i < height; i++)                                                                        //2 loops to cycle through every pixel of the image. Outer loop cycles through the various rows

    {
        for (int j = 0; j < width; j++)                                                                     //inner loop cycles through all the columns

        {
            int s = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;                     //declaration of int variable s which stores the average of the r, g and b values of each pixel [i][j]
            float a = round(s/3);                                                                             //declaration of int variable a which rounds the value of s

            image[i][j].rgbtBlue = a;                                                                       //set the value of the blue pixel [i][j] to a
            image[i][j].rgbtGreen = a;                                                                      //set the value of the green pixel [i][j] to a
            image[i][j].rgbtRed = a;                                                                        //set the value of the red pixel [i][j] to a
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])                                                                   //definition of function sepia taking arguments int height, int width and datatype RGBTRILE array image (array defined by height and width)
{
    for (int i = 0; i < height; i++)                                                                                                //2 loops to cycle through every pixel of the image

    {                                                                                                                               //outer loop cycles through the various rows
        for (int j = 0; j < width; j++)                                                                                             //inner loop cycles through the various columns

        {
            float s_b = round(image[i][j].rgbtBlue * 0.131 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtRed * 0.272);            //declaration of int variable s_b to convert any original blue value of a pixel according to this sepia algorithm
            float s_g = round(image[i][j].rgbtBlue * 0.168 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtRed * 0.349);            //declaration of int variable s_g to convert any original green value of a pixel according to this sepia algorithm
            float s_r = round(image[i][j].rgbtBlue * 0.189 + image[i][j].rgbtGreen * 0.729 + image[i][j].rgbtRed * 0.393);            //declaration of int variable s_r to convert any original red value of a pixel according to this sepia algorithm

            if (s_b > 255)                                                                                                          //check if s_b is more than 255 (white)

            {
                s_b = 255;                                                                                                          //if s_b is greater than 255, define s_b as 255
            }

            else if (s_g > 255)                                                                                                     //check if s_g is more than 255 (white)

            {
                s_g = 255;                                                                                                          //if s_g is greater than 255, define s_g as 255
            }

            else if (s_r > 255)                                                                                                     //check if s_r is more than 255 (white)

            {
                s_g = 255;                                                                                                          //if s_r is greater than 255, define s_r as 255
            }

            else                                                                                                                    //after all the checks have been made

            image[i][j].rgbtBlue = s_b;                                                                                             //set blue value of pixel [i][j] as s_b
            image[i][j].rgbtGreen = s_g;                                                                                            //set green value of pixel[i][j] as s_g
            image[i][j].rgbtRed = s_r;                                                                                              //set red value of pixel [i][j] as s_r
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])                                                                 //definition of function reflect taking arguments int height, int width and datatype RGBTRILE array image (array defined by height and width)
{



    for (int i = 0; i < width/2; i++)                                                                                                //2 loops to cycle through every pixel of the image

    {                                                                                                                               //outer loop cycles through the various rows

        for (int j = 0; j < height; j++)                                                                                             //inner loop cycles through the various columns

                                                                                                                                    //to swap 2 values eg a and b, a third temporary variable is needed
                                                                                                                                    //steps are: STEP 1: temporary is assigned value of a, STEP 2: a is assigned value of b, and STEP 3: b is assigned temperary value
                                                                                                                                    //in this function a is image[j][i], b is image[j][width - i] and temporary is temp_
        {

            int temp_b = image[j][i].rgbtBlue;                                                                                      //this block (lines 85 - 87) assigns the value of a to temp_ for each pixel [j][i] (STEP 1)
            int temp_g = image[j][i].rgbtGreen;                                                                                     //a separate temporary variable is created for each of the r, g and b values of each pixel
            int temp_r = image[j][i].rgbtRed;

            int i_swap = round(width - i);                                                                                          //declaration of int variable i_swap as width - i (used to reference the the reflected position at any position i) - ended up being unused


            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;                                                                    //this block (lines 92 - 94) assigns the value of b to a to a for each of pixel [j][i] (STEP 2)
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;                                                                  //this step is repeated for each of the r, g and b values of each pixel
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;

            image[j][width - i - 1].rgbtBlue = temp_b;                                                                                  //this block (lines 96 - 98) assigns the value of temp_ to b for each of the pixel [j][i] (STEP 3)
            image[j][width - i - 1].rgbtGreen = temp_g;                                                                                 //this step is repeated for each of the r, g and b values of each pixel
            image[j][width - i - 1].rgbtRed = temp_r;

        }


    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])                                            //definition of function blur taking arguments int height, int width and datatype RGBTRILE array image (array defined by height and width)
{

    RGBTRIPLE duplicate[height][width];                                                                     //creation of another array called duplicate of type RGBTRIPLE. This array will duplicate any image being processed

    for (int i = 0; i < width; i++)                                                                        //2 nested loops to cycle through all the pixels
                                                                                                            //outer loop to cycle through rows using i as counter
    {
        for (int j = 0; j < height; j++)                                                                     //inner loop to cycle through columns using j as counter

        {
            duplicate[j][i].rgbtBlue = image[j][i].rgbtBlue;                                                //r, g and b values of each pixel [i][j] of image are mapped to dupolicate
            duplicate[j][i].rgbtGreen = image[j][i].rgbtGreen;
            duplicate[j][i].rgbtRed = image[j][i].rgbtRed;
        }
    }

    for (int i = 0; i < width; i++)

    {
        for (int j = 0; j < height; j++)

        {

            int avg_blue = 0;
            int avg_green = 0;
            int avg_red = 0;

            if (i - 1 < 0 || j - 1 < 0)

            {
                avg_blue = round((duplicate[j][i].rgbtBlue + duplicate[j + 1][i].rgbtBlue + duplicate[j][i + 1].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue)/4);
                avg_green = round((duplicate[j][i].rgbtGreen + duplicate[j + 1][i].rgbtGreen + duplicate[j][i + 1].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen)/4);
                avg_red = round((duplicate[j][i].rgbtRed + duplicate[j + 1][i].rgbtRed + duplicate[j][i + 1].rgbtRed + duplicate[j + 1][i + 1].rgbtRed)/4);


            }

            else if (i - 1 < 0 || 0 < j < width)

            {
                avg_blue = round((duplicate[j - 1][i].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j + 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j][i + 1].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue)/6);
                avg_green = round((duplicate[j - 1][i].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j + 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen + duplicate[j][i + 1].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen)/6);
                avg_red = round((duplicate[j - 1][i].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j + 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed + duplicate[j][i + 1].rgbtRed + duplicate[j + 1][i + 1].rgbtRed)/6);


            }

            else if (i - 1 < 0 || j + 1 > width)

            {
                avg_blue = round((duplicate[j - 1][i].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j][i + 1].rgbtBlue)/4);
                avg_green = round((duplicate[j - 1][i].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen + duplicate[j][i + 1].rgbtGreen)/4);
                avg_red = round(((duplicate[j - 1][i].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed + duplicate[j][i + 1].rgbtRed))/4);


            }

            else if (0 < i < width || j - 1 < 0)

            {
                avg_blue = round((duplicate[j][i].rgbtBlue + duplicate[j + 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue)/4);
                avg_green = round((duplicate[j][i].rgbtGreen + duplicate[j + 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen)/4);
                avg_red = round((duplicate[j][i].rgbtRed + duplicate[j + 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed + duplicate[j + 1][i + 1].rgbtRed)/4);


            }

            else if (0 < i < width || j + 1 > width)

            {
                avg_blue = round((duplicate[j - 1][i - 1].rgbtBlue + duplicate[j][i - 1].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j][i + 1].rgbtBlue)/6);
                avg_green = round((duplicate[j - 1][i - 1].rgbtGreen + duplicate[j][i - 1].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen + duplicate[j][i + 1].rgbtGreen)/6);
                avg_red = round((duplicate[j - 1][i - 1].rgbtRed + duplicate[j][i - 1].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed + duplicate[j][i + 1].rgbtRed)/6);



            }

            else if (i + 1 > height || j - 1 < 0)

            {
                avg_blue = round((duplicate[j][i].rgbtBlue + duplicate[j + 1][i].rgbtBlue + duplicate[j][i + 1].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue)/4);
                avg_green = round((duplicate[j][i].rgbtGreen + duplicate[j + 1][i].rgbtGreen + duplicate[j][i + 1].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen)/4);
                avg_red = round((duplicate[j][i].rgbtRed + duplicate[j + 1][i].rgbtRed + duplicate[j][i + 1].rgbtRed + duplicate[j + 1][i + 1].rgbtRed)/4);



            }

            else if (i + 1 > height || 0 < j < width)


            {
                avg_blue = round((duplicate[j - 1][i - 1].rgbtBlue + duplicate[j][i - 1].rgbtBlue + duplicate[j + 1][i - 1].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j + 1][i].rgbtBlue)/6);
                avg_green = round((duplicate[j - 1][i - 1].rgbtGreen + duplicate[j][i - 1].rgbtGreen + duplicate[j + 1][i - 1].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j + 1][i].rgbtGreen)/6);
                avg_red = round((duplicate[j - 1][i - 1].rgbtRed + duplicate[j][i - 1].rgbtRed + duplicate[j + 1][i - 1].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j + 1][i].rgbtRed)/6);



            }

            else if (i + 1 > height || i + 1 > width)

            {
                avg_blue = round((duplicate[j - 1][i].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j][i + 1].rgbtBlue)/4);
                avg_green = round((duplicate[j - 1][i].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen + duplicate[j][i + 1].rgbtGreen)/4);
                avg_red = round((duplicate[j - 1][i].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed + duplicate[j][i + 1].rgbtRed)/4);



            }

            else

            {
                avg_blue = round((duplicate[j - 1][i - 1].rgbtBlue + duplicate[j][i - 1].rgbtBlue + duplicate[j + 1][i - 1].rgbtBlue + duplicate[j - 1][i].rgbtBlue + duplicate[j][i].rgbtBlue + duplicate[j + 1][i].rgbtBlue + duplicate[j - 1][i + 1].rgbtBlue + duplicate[j][i + 1].rgbtBlue + duplicate[j + 1][i + 1].rgbtBlue)/9);
                avg_green = round((duplicate[j - 1][i - 1].rgbtGreen + duplicate[j][i - 1].rgbtGreen + duplicate[j + 1][i - 1].rgbtGreen + duplicate[j - 1][i].rgbtGreen + duplicate[j][i].rgbtGreen + duplicate[j + 1][i].rgbtGreen + duplicate[j - 1][i + 1].rgbtGreen + duplicate[j][i + 1].rgbtGreen + duplicate[j + 1][i + 1].rgbtGreen)/9);
                avg_red = round((duplicate[j - 1][i - 1].rgbtRed + duplicate[j][i - 1].rgbtRed + duplicate[j + 1][i - 1].rgbtRed + duplicate[j - 1][i].rgbtRed + duplicate[j][i].rgbtRed + duplicate[j + 1][i].rgbtRed + duplicate[j - 1][i + 1].rgbtRed + duplicate[j][i + 1].rgbtRed + duplicate[j + 1][i + 1].rgbtRed)/9);

            }

            image[j][i].rgbtBlue = avg_blue;
            image[j][i].rgbtGreen = avg_green;
            image[j][i].rgbtRed = avg_red;


        }
    }

     return;
}
