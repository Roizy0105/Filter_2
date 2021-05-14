#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through rows
    for (int i = 0; i < height; i++)
    {
        //iterate through columns
        for (int j = 0; j < width; j++)
        {
            double sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            double avrage = round(sum / 3);
            //get the abvrage of the rgb and aggaign that to the pixel
            image[i][j].rgbtBlue = avrage;
            image[i][j].rgbtGreen = avrage;
            image[i][j].rgbtRed = avrage;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through the rows
    for (int i = 0; i < height; i++)
    {
        //itarate through the height
        for (int j = 0; j < width; j++)
        {
            //apply a formula to the red green and blue then asign the new value to the pixel
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            //make sure no number is greater then 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //assighn new values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //itarate through the rows
    for (int i = 0; i < height; i++)
    {
        //iterate through the columns
        int counter = 0;
        for (int j = width - 1; j > counter; j--)
        {
            //swap the first value with the last value
            RGBTRIPLE temp = image[i][counter];
            image[i][counter] = image[i][j];
            image[i][j] = temp;
            counter++;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    //iterate through the rows of the image
    for (int i = 0; i < height; i++)
    {
        //iterate therough the columes in the image
        for (int j = 0; j < width; j++)
        {
            int blurRed = 0;
            int blurGreen = 0;
            int blurBlue = 0;

            //if this pixel is at the top left of the image
            if (i == 0 && j == 0)
            {
                //sum of red
                double sumRed = image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                //sum of green
                double sumGreen = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                //sum of blue
                double sumBlue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is at the top right of the image
            else if (i == 0 && j == width - 1)
            {

                double sumRed = image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed;

                double sumGreen = image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen;

                double sumBlue = image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is at the bottom left of the screen
            else if (i == height - 1 && j == 0)
            {

                double sumRed = image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j].rgbtRed + image[i][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is at the bottom right of the image
            else if (i == height - 1 && j == width - 1)
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 4);
                double avrageGreen = round(sumGreen / 4);
                double avrageBlue = round(sumBlue / 4);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is on the top row of the image
            else if (i == 0 && j > 0 && j < width - 1)
            {

                double sumRed = image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                double sumGreen = image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                double sumBlue = image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is on the bottom row of the image
            else if (i == height - 1 && j > 0 && j < width - 1)
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is in the first column
            else if (j == 0 && i > 0 && i < height - 1)
            {

                double sumRed = image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }


            //if the pixel is in the last column
            else if (j == width - 1 && i > 0 && i < height - 1)
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 6);
                double avrageGreen = round(sumGreen / 6);
                double avrageBlue = round(sumBlue / 6);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }

            //if the pixel is anyware else in the image
            else
            {

                double sumRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                double sumGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                  image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                double sumBlue = image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                 image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;


                //avrage
                double avrageRed = round(sumRed / 9);
                double avrageGreen = round(sumGreen / 9);
                double avrageBlue = round(sumBlue / 9);

                blurRed = avrageRed;
                blurGreen = avrageGreen;
                blurBlue = avrageBlue;
            }
            //assign new values to rgb
            copy[i][j].rgbtRed = blurRed;
            copy[i][j].rgbtGreen = blurGreen;
            copy[i][j].rgbtBlue = blurBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
