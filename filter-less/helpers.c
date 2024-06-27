#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* pixel = &image[i][j];
            int avg = (pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue) / 3;
            pixel->rgbtRed = avg;
            pixel->rgbtBlue = avg;
            pixel->rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* pixel = &image[i][j];
            pixel->rgbtRed = .393 * pixel->rgbtRed + .769 * pixel->rgbtGreen + .189 * pixel->rgbtBlue;
            pixel->rgbtBlue = .272 * pixel->rgbtRed + .534 * pixel->rgbtGreen + .131 * pixel->rgbtBlue;
            pixel->rgbtGreen = .349 * pixel->rgbtRed + .686 * pixel->rgbtGreen + .168 * pixel->rgbtBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE flipped[height][width];

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* revPixel = &image[i][width - j];
            RGBTRIPLE* flippedPixel = &flipped[i][j];
            flippedPixel->rgbtRed = revPixel->rgbtRed;
            flippedPixel->rgbtBlue = revPixel->rgbtBlue;
            flippedPixel->rgbtGreen = revPixel->rgbtGreen;
        }
    }

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* pixel = &image[i][j];
            RGBTRIPLE* flippedPixel = &flipped[i][j];
            pixel->rgbtRed = flippedPixel->rgbtRed;
            pixel->rgbtBlue = flippedPixel->rgbtBlue;
            pixel->rgbtGreen = flippedPixel->rgbtGreen;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE blurred[height][width];

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* pixel = &image[i][j];
            RGBTRIPLE* blurredPixel = &blurred[i][j];

            if (j == height - 1 || j == height )
            RGBTRIPLE* p1 = &image[i-1][j-1];
            RGBTRIPLE* p2 = &image[i-1][j];
            RGBTRIPLE* p3 = &image[i-1][j+1];

            RGBTRIPLE* p4 = &image[i][j-1];
            RGBTRIPLE* p5 = &image[i][j+1];

            RGBTRIPLE* p6 = &image[i+1][j-1];
            RGBTRIPLE* p7 = &image[i+1][j];
            RGBTRIPLE* p8 = &image[i+1][j+1];

            int avgRed = (p1->rgbtRed + p2->rgbtRed + p3->rgbtRed + p4->rgbtRed + p5->rgbtRed + p6->rgbtRed + p7->rgbtRed + p8->rgbtRed) / 8;
            int avgBlue = (p1->rgbtBlue + p2->rgbtBlue + p3->rgbtBlue + p4->rgbtBlue + p5->rgbtBlue + p6->rgbtBlue + p7->rgbtBlue + p8->rgbtBlue) / 8;
            int avgGreen = (p1->rgbtGreen + p2->rgbtGreen + p3->rgbtGreen + p4->rgbtGreen + p5->rgbtGreen + p6->rgbtGreen + p7->rgbtGreen + p8->rgbtGreen) / 8;

            blurredPixel->rgbtRed = avgRed;
            blurredPixel->rgbtBlue = avgBlue;
            blurredPixel->rgbtGreen = avgGreen;
        }
    }

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* pixel = &image[i][j];
            RGBTRIPLE* blurredPixel = &blurred[i][j];
            pixel->rgbtRed = blurredPixel->rgbtRed;
            pixel->rgbtBlue = blurredPixel->rgbtBlue;
            pixel->rgbtGreen = blurredPixel->rgbtGreen;
        }
    }

    return;
}
