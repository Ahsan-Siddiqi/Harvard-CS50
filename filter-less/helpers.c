#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* pixel = &image[i][j];
            int avg = (pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue + 1) / 3;
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

            int originalRed = pixel->rgbtRed;
            int originalGreen = pixel->rgbtGreen;
            int originalBlue = pixel->rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;
            if (sepiaBlue > 255) sepiaBlue = 255;

            pixel->rgbtRed = sepiaRed;
            pixel->rgbtGreen = sepiaGreen;
            pixel->rgbtBlue = sepiaBlue;
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
    RGBTRIPLE zero;
    zero.rgbtRed = 0;
    zero.rgbtBlue = 0;
    zero.rgbtGreen = 0;

    RGBTRIPLE* p1 = &zero;
    RGBTRIPLE* p2 = &zero;
    RGBTRIPLE* p3 = &zero;
    RGBTRIPLE* p4 = &zero;
    RGBTRIPLE* p5 = &zero;
    RGBTRIPLE* p6 = &zero;
    RGBTRIPLE* p7 = &zero;
    RGBTRIPLE* p8 = &zero;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE* pixel = &image[i][j];
            RGBTRIPLE* blurredPixel = &blurred[i][j];

            if (i != 0) {
                p2 = &image[i-1][j];

                if (j != 0) {p1 = &image[i-1][j-1];};
                if (j != width - 1) {p3 = &image[i-1][j+1];};
            }
            if (i != height - 1) {
                if (j != 0) {p6 = &image[i+1][j-1];};
                if (j != width - 1) {p8 = &image[i+1][j+1];};
                p7 = &image[i+1][j];
            }
            if (j != height - 1 || j != 0) {
                if (j != 0) {p4 = &image[i][j-1];};
                if (j != width - 1) {p5 = &image[i][j+1];};
            }


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
