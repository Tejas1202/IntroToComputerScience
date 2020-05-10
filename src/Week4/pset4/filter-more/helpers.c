#include "helpers.h"
#include <math.h>

BYTE kernel_average(float g_of_x, float g_of_y);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE grey = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = grey;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            BYTE blue = image[i][j].rgbtBlue;
            BYTE green = image[i][j].rgbtGreen;
            BYTE red = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = blue;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtRed = red;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int sum_blue = 0;
    int sum_green = 0;
    int sum_red = 0;
    float counter = 0;

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            sum_blue = sum_green = sum_red = 0;
            counter = 0;

            for (int h = -1; h < 2; h++)
            {
                //skip iteration if pixel going out of the edges vertically
                if (i + h < 0 || i + h > height - 1)
                {
                    continue;
                }

                for (int w = -1; w < 2; w++)
                {
                    //skip iteration if pixel going out of the edges horizontally
                    if (w + j < 0 || w + j > width - 1)
                    {
                        continue;
                    }

                    sum_blue += image[i + h][w + j].rgbtBlue;
                    sum_green += image[i + h][w + j].rgbtGreen;
                    sum_red += image[i + h][w + j].rgbtRed;
                    counter++;
                }
            }
            temp[i][j].rgbtBlue = round(sum_blue / counter);
            temp[i][j].rgbtGreen = round(sum_green / counter);
            temp[i][j].rgbtRed = round(sum_red / counter);
        }
    }

    //copy pixels from temp array to original image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
//   Kernel matrix taken:
//     Gx       Gy
//   -1 0 1  -1 -2 -1
//   -2 0 2   0  0  0
//   -1 0 1   1  2  1
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    float sum_blue_x;
    float sum_green_x;
    float sum_red_x;
    float sum_blue_y;
    float sum_green_y;
    float sum_red_y;
    int multiplication_factor_x;
    int multiplication_factor_y;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sum_blue_x = sum_green_x = sum_red_x = 0;
            sum_blue_y = sum_green_y = sum_red_y = 0;

            for (int h = -1; h < 2; h++)
            {
                //skip iteration if pixel going out of the edges vertically
                if (j + h < 0 || j + h > height - 1)
                {
                    continue;
                }

                for (int w = -1; w < 2; w++)
                {
                    //skip iteration if pixel going out of the edges horizontally
                    if (i + w < 0 || i + w > width - 1)
                    {
                        continue;
                    }
                    multiplication_factor_x = h == 0 ? w * 2 : w;
                    multiplication_factor_y = w == 0 ? h * 2 : h;
                    sum_blue_x += image[j + h][i + w].rgbtBlue * multiplication_factor_x;
                    sum_green_x += image[j + h][i + w].rgbtGreen * multiplication_factor_x;
                    sum_red_x += image[j + h][i + w].rgbtRed * multiplication_factor_x;
                    sum_blue_y += image[j + h][i + w].rgbtBlue * multiplication_factor_y;
                    sum_green_y += image[j + h][i + w].rgbtGreen * multiplication_factor_y;
                    sum_red_y += image[j + h][i + w].rgbtRed * multiplication_factor_y;
                }
            }

            temp[j][i].rgbtBlue = kernel_average(sum_blue_x, sum_blue_y);
            temp[j][i].rgbtGreen = kernel_average(sum_green_x, sum_green_y);
            temp[j][i].rgbtRed = kernel_average(sum_red_x, sum_red_y);
        }
    }

    //copy pixels from temp array to original image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

//calculates average kernel of Gx and Gy with upper limit of 255
BYTE kernel_average(float g_of_x, float g_of_y)
{
    int sqaure_root_of_xy = round(sqrt((g_of_x * g_of_x) + (g_of_y * g_of_y)));

    return sqaure_root_of_xy > 255 ? 255 : (BYTE)sqaure_root_of_xy;
}
