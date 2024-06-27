#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE pixel = image[height][width];
            int avg = (pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3;
            image[height][width].rgbtRed = avg;
            image[height][width].rgbtBlue = avg;
            image[height][width].rgbtGreen = avg;
        }
    }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
