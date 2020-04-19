#include "helpers.h"
#include <math.h>

int round_bytes(float bytes);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average_of_pixels;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average_of_pixels = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average_of_pixels;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        float sepiaRed = 0;
        float sepiaGreen = 0;
        float sepiaBlue = 0;
        for (int j = 0; j < width; j++)
        {
            sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            image[i][j].rgbtRed = round_bytes(sepiaRed);
            image[i][j].rgbtGreen = round_bytes(sepiaGreen);
            image[i][j].rgbtBlue = round_bytes(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, n = round(width / 2); j < n; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Creating temp array to not alter the existing pixels
    RGBTRIPLE temp[height][width];
    int sum_blue = 0;
    int sum_green = 0;
    int sum_red = 0;
    float counter = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sum_blue = sum_green = sum_red = 0;
            counter = 0;
            for (int h = -1; h < 2; h++)
            {
                if (j + h < 0 || j + h > height - 1)
                {
                    continue;
                }

                for (int w = -1; w < 2; w++)
                {
                    if (w + i < 0 || w + i > width - 1)
                    {
                        continue;
                    }
                    sum_blue += image[j + h][i + w].rgbtBlue;
                    sum_green += image[j + h][i + w].rgbtGreen;
                    sum_red += image[j + h][i + w].rgbtRed;
                    counter++;
                }
            }

            temp[j][i].rgbtBlue = round(sum_blue / counter);
            temp[j][i].rgbtGreen = round(sum_green / counter);
            temp[j][i].rgbtRed = round(sum_red / counter);
        }
    }

    //Copying from temp array to original one
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

//Rounds bytes to nearest integer, will return 255 if the number is > 255,
//as one pixel's RGB cannot exceed that limit
int round_bytes(float bytes)
{
    return round(bytes) > 255 ? 255 : round(bytes);
}