#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE temp;
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            temp = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = temp;
            image[i][j].rgbtRed = temp;
            image[i][j].rgbtGreen = temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
   int realwidth = width - 1;
   void swap(BYTE *a, BYTE *b);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            swap(&image[i][realwidth - j].rgbtRed, &image[i][j].rgbtRed);
            swap(&image[i][realwidth - j].rgbtGreen, &image[i][j].rgbtGreen);
            swap(&image[i][realwidth - j].rgbtBlue, &image[i][j].rgbtBlue);
    }
    }
    return;
}

void swap(BYTE *a, BYTE *b)
{
    BYTE tempB = *a;
    *a = *b;
    *b = tempB;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float tempRed;
    float tempGreen;
    float tempBlue;
    int realheight = height - 1;
    int realwidth = width -1;
    RGBTRIPLE imageCopy[height][width];

    //making copy of original image
    for (int k = 0; k < height; k++)
	{
		for (int l = 0; l < width; l++)
		{
			imageCopy[k][l].rgbtRed = image[k][l].rgbtRed;
			imageCopy[k][l].rgbtGreen = image[k][l].rgbtGreen;
			imageCopy[k][l].rgbtBlue = image[k][l].rgbtBlue;
		}
	}

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            //top left corner
            if (i == 0 && j == 0) {

                tempRed = (float)(imageCopy[i+1][j].rgbtRed + imageCopy[i+1][j +1].rgbtRed + imageCopy[i][j+1].rgbtRed + imageCopy[i][j].rgbtRed)/4;
                tempGreen = (float)(imageCopy[i+1][j].rgbtGreen + imageCopy[i+1][j +1].rgbtGreen + imageCopy[i][j+1].rgbtGreen + imageCopy[i][j].rgbtGreen)/4;
                tempBlue = (float)(imageCopy[i+1][j].rgbtBlue + imageCopy[i+1][j +1].rgbtBlue + imageCopy[i][j+1].rgbtBlue + imageCopy[i][j].rgbtBlue)/4;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
            }
            //top edge
            else if (i == 0 && (j > 0 &&  j < realwidth)) {
                tempRed = (float)(imageCopy[i][j].rgbtRed + imageCopy[i][j-1].rgbtRed + imageCopy[i+1][j-1].rgbtRed + imageCopy[i][j+1].rgbtRed +imageCopy[i+1][j].rgbtRed + imageCopy[i+1][j+1].rgbtRed)/6;
                tempGreen = (float)(imageCopy[i][j].rgbtGreen + imageCopy[i][j-1].rgbtGreen + imageCopy[i+1][j-1].rgbtGreen + imageCopy[i][j+1].rgbtGreen +imageCopy[i+1][j].rgbtGreen + imageCopy[i+1][j+1].rgbtGreen)/6;
                tempBlue = (float)(imageCopy[i][j].rgbtBlue + imageCopy[i][j-1].rgbtBlue + imageCopy[i+1][j-1].rgbtBlue + imageCopy[i][j+1].rgbtBlue +imageCopy[i+1][j].rgbtBlue + imageCopy[i+1][j+1].rgbtBlue)/6;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
            }
            //top right corner
           else if (i == 0 && j == realwidth) {
                tempRed = (float)(imageCopy[i+1][j].rgbtRed + imageCopy[i+1][j-1].rgbtRed + imageCopy[i][j-1].rgbtRed + imageCopy[i][j].rgbtRed)/4;
                tempGreen = (float)(imageCopy[i+1][j].rgbtGreen + imageCopy[i+1][j-1].rgbtGreen + imageCopy[i][j-1].rgbtGreen + imageCopy[i][j].rgbtGreen)/4;
                tempBlue = (float)(imageCopy[i+1][j].rgbtBlue + imageCopy[i+1][j-1].rgbtBlue + imageCopy[i][j-1].rgbtBlue + imageCopy[i][j].rgbtBlue)/4;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;

            }
            //right edge
            else if (j == realwidth && (i > 0 && i < realheight)) {
                tempRed = (float)(imageCopy[i][j].rgbtRed + imageCopy[i][j-1].rgbtRed + imageCopy[i+1][j-1].rgbtRed + imageCopy[i-1][j].rgbtRed +imageCopy[i+1][j].rgbtRed + imageCopy[i-1][j-1].rgbtRed)/6;
                tempGreen = (float)(imageCopy[i][j].rgbtGreen + imageCopy[i][j-1].rgbtGreen + imageCopy[i+1][j-1].rgbtGreen + imageCopy[i-1][j].rgbtGreen +imageCopy[i+1][j].rgbtGreen + imageCopy[i-1][j-1].rgbtGreen)/6;
                tempBlue = (float)(imageCopy[i][j].rgbtBlue + imageCopy[i][j-1].rgbtBlue + imageCopy[i+1][j-1].rgbtBlue + imageCopy[i-1][j].rgbtBlue +imageCopy[i+1][j].rgbtBlue + imageCopy[i-1][j-1].rgbtBlue)/6;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
            }
            //bottom right corner
            else if (i == realheight && j == realwidth) {
                tempRed = (float)(imageCopy[i-1][j].rgbtRed + imageCopy[i-1][j-1].rgbtRed + imageCopy[i][j-1].rgbtRed + imageCopy[i][j].rgbtRed)/4;
                tempGreen = (float)(imageCopy[i-1][j].rgbtGreen + imageCopy[i-1][j-1].rgbtGreen + imageCopy[i][j-1].rgbtGreen + imageCopy[i][j].rgbtGreen)/4;
                tempBlue = (float)(imageCopy[i-1][j].rgbtBlue + imageCopy[i-1][j-1].rgbtBlue + imageCopy[i][j-1].rgbtBlue + imageCopy[i][j].rgbtBlue)/4;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
            }
            //bottom edge
            else if (i == realheight && (j > 0 && j < realwidth)) {
                tempRed = (float)(imageCopy[i][j].rgbtRed + imageCopy[i][j-1].rgbtRed + imageCopy[i-1][j+1].rgbtRed + imageCopy[i][j+1].rgbtRed +imageCopy[i-1][j].rgbtRed + imageCopy[i-1][j-1].rgbtRed)/6;
                tempGreen = (float)(imageCopy[i][j].rgbtGreen + imageCopy[i][j-1].rgbtGreen + imageCopy[i-1][j+1].rgbtGreen + imageCopy[i][j+1].rgbtGreen +imageCopy[i-1][j].rgbtGreen + imageCopy[i-1][j-1].rgbtGreen)/6;
                tempBlue = (float)(imageCopy[i][j].rgbtBlue + imageCopy[i][j-1].rgbtBlue + imageCopy[i-1][j+1].rgbtBlue + imageCopy[i][j+1].rgbtBlue +imageCopy[i-1][j].rgbtBlue + imageCopy[i-1][j-1].rgbtBlue)/6;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
        }
        //bottom left corner
        else if (i == realheight && j == 0) {
                tempRed = (float)(imageCopy[i-1][j].rgbtRed + imageCopy[i-1][j +1].rgbtRed + imageCopy[i][j+1].rgbtRed + imageCopy[i][j].rgbtRed)/4;
                tempGreen = (float)(imageCopy[i-1][j].rgbtGreen + imageCopy[i-1][j +1].rgbtGreen + imageCopy[i][j+1].rgbtGreen + imageCopy[i][j].rgbtGreen)/4;
                tempBlue = (float)(imageCopy[i-1][j].rgbtBlue + imageCopy[i-1][j +1].rgbtBlue + imageCopy[i][j+1].rgbtBlue + imageCopy[i][j].rgbtBlue)/4;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
        }
        //left edge
        else if (j == 0 && (i> 0 && i < realheight)) {
                tempRed = (float)(imageCopy[i][j].rgbtRed + imageCopy[i][j+1].rgbtRed + imageCopy[i-1][j+1].rgbtRed + imageCopy[i-1][j].rgbtRed +imageCopy[i+1][j].rgbtRed + imageCopy[i+1][j+1].rgbtRed)/6;
                tempGreen = (float)(imageCopy[i][j].rgbtGreen + imageCopy[i][j+1].rgbtGreen + imageCopy[i-1][j+1].rgbtGreen + imageCopy[i-1][j].rgbtGreen +imageCopy[i+1][j].rgbtGreen + imageCopy[i+1][j+1].rgbtGreen)/6;
                tempBlue = (float)(imageCopy[i][j].rgbtBlue + imageCopy[i][j+1].rgbtBlue + imageCopy[i-1][j+1].rgbtBlue + imageCopy[i-1][j].rgbtBlue +imageCopy[i+1][j].rgbtBlue + imageCopy[i+1][j+1].rgbtBlue)/6;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
        }
        else {
                tempRed = (float)(imageCopy[i][j].rgbtRed + imageCopy[i][j+1].rgbtRed + imageCopy[i-1][j+1].rgbtRed + imageCopy[i-1][j].rgbtRed +imageCopy[i+1][j].rgbtRed + imageCopy[i+1][j+1].rgbtRed + imageCopy[i][j-1].rgbtRed + imageCopy[i-1][j-1].rgbtRed + imageCopy[i+1][j-1].rgbtRed)/9;
                tempGreen = (float)(imageCopy[i][j].rgbtGreen + imageCopy[i][j+1].rgbtGreen + imageCopy[i-1][j+1].rgbtGreen + imageCopy[i-1][j].rgbtGreen +imageCopy[i+1][j].rgbtGreen + imageCopy[i+1][j+1].rgbtGreen + imageCopy[i][j-1].rgbtGreen + imageCopy[i-1][j-1].rgbtGreen + imageCopy[i+1][j-1].rgbtGreen)/9;
                tempBlue = (float)(imageCopy[i][j].rgbtBlue + imageCopy[i][j+1].rgbtBlue + imageCopy[i-1][j+1].rgbtBlue + imageCopy[i-1][j].rgbtBlue +imageCopy[i+1][j].rgbtBlue + imageCopy[i+1][j+1].rgbtBlue + imageCopy[i][j-1].rgbtBlue + imageCopy[i-1][j-1].rgbtBlue + imageCopy[i+1][j-1].rgbtBlue)/9;

                tempRed = round(tempRed);
                tempGreen = round(tempGreen);
                tempBlue = round(tempBlue);

                image[i][j].rgbtRed = tempRed;
				image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtBlue = tempBlue;
        }
    }
}
return;
}

// Detect edges (Note: Effect works well, but some pixel values are not matching up with check50)
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int realheight = height - 1;
    int realwidth = width -1;
    RGBTRIPLE imageCopy[height][width];
    int value;

    //making copy of original image
    for (int k = 0; k < height; k++)
	{
		for (int l = 0; l < width; l++)
		{
			imageCopy[k][l].rgbtRed = image[k][l].rgbtRed;
			imageCopy[k][l].rgbtGreen = image[k][l].rgbtGreen;
			imageCopy[k][l].rgbtBlue = image[k][l].rgbtBlue;
		}
	}
	int gx[3][3] = {{ -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 }};
    int gy[3][3] = {{ -1, -2, -1 }, { 0, 0, 0 }, { 1, 2, 1 }};
    int gxrvals[9];
    int gxgvals[9];
    int gxbvals[9];
    DWORD sumrgx = 0;
    DWORD sumggx = 0;
    DWORD sumbgx = 0;

    int gyrvals[9];
    int gygvals[9];
    int gybvals[9];
    DWORD sumrgy = 0;
    DWORD sumggy = 0;
    DWORD sumbgy = 0;

     for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //for the same 9 pixel possibilities as blur function, I multiply the pixels with the Gx and Gy kernels, find the sums, and implement the Sobel operator

            //top left corner
            if (i == 0 && j == 0) {
                gxrvals[0] = imageCopy[i+1][j].rgbtRed * gx[1][0];
                gxrvals[1] = imageCopy[i+1][j +1].rgbtRed * gx[1][1];
                gxrvals[2] = imageCopy[i][j+1].rgbtRed * gx[0][1];
                gxrvals[3] = imageCopy[i][j].rgbtRed * gx[0][0];

                gxgvals[0] = imageCopy[i+1][j].rgbtGreen * gx[1][0];
                gxgvals[1] = imageCopy[i+1][j +1].rgbtGreen * gx[1][1];
                gxgvals[2] = imageCopy[i][j+1].rgbtGreen *gx[0][1];
                gxgvals[3] = imageCopy[i][j].rgbtGreen * gx[0][0];

                gxbvals[0] = imageCopy[i+1][j].rgbtBlue * gx[1][0];
                gxbvals[1] = imageCopy[i+1][j +1].rgbtBlue * gx[1][1];
                gxbvals[2] = imageCopy[i][j+1].rgbtBlue * gx[0][1];
                gxbvals[3] = imageCopy[i][j].rgbtBlue * gx[0][0];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i+1][j].rgbtRed * gy[1][0];
                gyrvals[1] = imageCopy[i+1][j +1].rgbtRed * gy[1][1];
                gyrvals[2] = imageCopy[i][j+1].rgbtRed * gy[0][1];
                gyrvals[3] = imageCopy[i][j].rgbtRed * gy[0][0];

                gygvals[0] = imageCopy[i+1][j].rgbtGreen * gy[1][0];
                gygvals[1] = imageCopy[i+1][j +1].rgbtGreen * gy[1][1];
                gygvals[2] = imageCopy[i][j+1].rgbtGreen *gy[0][1];
                gygvals[3] = imageCopy[i][j].rgbtGreen * gy[0][0];

                gybvals[0] = imageCopy[i+1][j].rgbtBlue * gy[1][0];
                gybvals[1] = imageCopy[i+1][j +1].rgbtBlue * gy[1][1];
                gybvals[2] = imageCopy[i][j+1].rgbtBlue * gy[0][1];
                gybvals[3] = imageCopy[i][j].rgbtBlue * gy[0][0];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
            }
            //top edge
            else if (i == 0 && (j > 0 &&  j < realwidth)) {
                gxrvals[0] = imageCopy[i][j].rgbtRed * gx[0][1];
                gxrvals[1] = imageCopy[i][j-1].rgbtRed * gx[0][0];
                gxrvals[2] = imageCopy[i+1][j-1].rgbtRed * gx[1][0];
                gxrvals[3] = imageCopy[i][j+1].rgbtRed * gx[0][2];
                gxrvals[4] = imageCopy[i+1][j].rgbtRed * gx[1][1];
                gxrvals[5] = imageCopy[i+1][j+1].rgbtRed * gx[1][2];

                gxgvals[0] = imageCopy[i][j].rgbtGreen * gx[0][1];
                gxgvals[1] = imageCopy[i][j-1].rgbtGreen * gx[0][0];
                gxgvals[2] = imageCopy[i+1][j-1].rgbtGreen * gx[1][0];
                gxgvals[3] = imageCopy[i][j+1].rgbtGreen * gx[0][2];
                gxgvals[4] = imageCopy[i+1][j].rgbtGreen * gx[1][1];
                gxgvals[5] = imageCopy[i+1][j+1].rgbtGreen * gx[1][2];

                gxbvals[0] = imageCopy[i][j].rgbtBlue * gx[0][1];
                gxbvals[1] = imageCopy[i][j-1].rgbtBlue * gx[0][0];
                gxbvals[2] = imageCopy[i+1][j-1].rgbtBlue * gx[1][0];
                gxbvals[3] = imageCopy[i][j+1].rgbtBlue * gx[0][2];
                gxbvals[4] = imageCopy[i+1][j].rgbtBlue * gx[1][1];
                gxbvals[5] = imageCopy[i+1][j+1].rgbtBlue * gx[1][2];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i][j].rgbtRed * gy[0][1];
                gyrvals[1] = imageCopy[i][j-1].rgbtRed * gy[0][0];
                gyrvals[2] = imageCopy[i+1][j-1].rgbtRed * gy[1][0];
                gyrvals[3] = imageCopy[i][j+1].rgbtRed * gy[0][2];
                gyrvals[4] = imageCopy[i+1][j].rgbtRed * gy[1][1];
                gyrvals[5] = imageCopy[i+1][j+1].rgbtRed * gy[1][2];

                gygvals[0] = imageCopy[i][j].rgbtGreen * gy[0][1];
                gygvals[1] = imageCopy[i][j-1].rgbtGreen * gy[0][0];
                gygvals[2] = imageCopy[i+1][j-1].rgbtGreen * gy[1][0];
                gygvals[3] = imageCopy[i][j+1].rgbtGreen * gy[0][2];
                gygvals[4] = imageCopy[i+1][j].rgbtGreen * gy[1][1];
                gygvals[5] = imageCopy[i+1][j+1].rgbtGreen * gy[1][2];

                gybvals[0] = imageCopy[i][j].rgbtBlue * gy[0][1];
                gybvals[1] = imageCopy[i][j-1].rgbtBlue * gy[0][0];
                gybvals[2] = imageCopy[i+1][j-1].rgbtBlue * gy[1][0];
                gybvals[3] = imageCopy[i][j+1].rgbtBlue * gy[0][2];
                gybvals[4] = imageCopy[i+1][j].rgbtBlue * gy[1][1];
                gybvals[5] = imageCopy[i+1][j+1].rgbtBlue * gy[1][2];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));
                image[i][j].rgbtRed = value;

                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
            }
            //top right corner
           else if (i == 0 && j == realwidth) {
                gxrvals[0] = imageCopy[i+1][j].rgbtRed * gx[1][2];
                gxrvals[1] = imageCopy[i+1][j-1].rgbtRed * gx[1][1];
                gxrvals[2] = imageCopy[i][j-1].rgbtRed * gx[0][1];
                gxrvals[3] = imageCopy[i][j].rgbtRed * gx[0][2];

                gxgvals[0] = imageCopy[i+1][j].rgbtGreen * gx[1][2];
                gxgvals[1] = imageCopy[i+1][j-1].rgbtGreen * gx[1][1];
                gxgvals[2] = imageCopy[i][j-1].rgbtGreen * gx[0][1];
                gxgvals[3] = imageCopy[i][j].rgbtGreen * gx[0][2];

                gxbvals[0] = imageCopy[i+1][j].rgbtBlue * gx[1][2];
                gxbvals[1] = imageCopy[i+1][j-1].rgbtBlue * gx[1][1];
                gxbvals[2] = imageCopy[i][j-1].rgbtBlue * gx[0][1];
                gxbvals[3] = imageCopy[i][j].rgbtBlue * gx[0][2];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i+1][j].rgbtRed * gy[1][2];
                gyrvals[1] = imageCopy[i+1][j-1].rgbtRed * gy[1][1];
                gyrvals[2] = imageCopy[i][j-1].rgbtRed * gy[0][1];
                gyrvals[3] = imageCopy[i][j].rgbtRed * gy[0][2];

                gygvals[0] = imageCopy[i+1][j].rgbtGreen * gy[1][2];
                gygvals[1] = imageCopy[i+1][j-1].rgbtGreen * gy[1][1];
                gygvals[2] = imageCopy[i][j-1].rgbtGreen * gy[0][1];
                gygvals[3] = imageCopy[i][j].rgbtGreen * gy[0][2];

                gybvals[0] = imageCopy[i+1][j].rgbtBlue * gy[1][2];
                gybvals[1] = imageCopy[i+1][j-1].rgbtBlue * gy[1][1];
                gybvals[2] = imageCopy[i][j-1].rgbtBlue * gy[0][1];
                gybvals[3] = imageCopy[i][j].rgbtBlue * gy[0][2];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
            }
            //right edge
            else if (j == realwidth && (i > 0 && i < realheight)) {
                gxrvals[0] = imageCopy[i][j].rgbtRed * gx[1][2];
                gxrvals[1] = imageCopy[i][j-1].rgbtRed * gx[1][1];
                gxrvals[2] = imageCopy[i+1][j-1].rgbtRed * gx[2][1];
                gxrvals[3] = imageCopy[i-1][j].rgbtRed * gx[0][2];
                gxrvals[4] = imageCopy[i+1][j].rgbtRed * gx[2][2];
                gxrvals[5] = imageCopy[i-1][j-1].rgbtRed * gx[0][1];

                gxgvals[0] = imageCopy[i][j].rgbtGreen * gx[1][2];
                gxgvals[1] = imageCopy[i][j-1].rgbtGreen * gx[1][1];
                gxgvals[2] = imageCopy[i+1][j-1].rgbtGreen * gx[2][1];
                gxgvals[3] = imageCopy[i-1][j].rgbtGreen * gx[0][2];
                gxgvals[4] = imageCopy[i+1][j].rgbtGreen * gx[2][2];
                gxgvals[5] = imageCopy[i-1][j-1].rgbtGreen * gx[0][1];

                gxbvals[0] = imageCopy[i][j].rgbtBlue * gx[1][2];
                gxbvals[1] = imageCopy[i][j-1].rgbtBlue * gx[1][1];
                gxbvals[2] = imageCopy[i+1][j-1].rgbtBlue * gx[2][1];
                gxbvals[3] = imageCopy[i-1][j].rgbtBlue * gx[0][2];
                gxbvals[4] = imageCopy[i+1][j].rgbtBlue * gx[2][2];
                gxbvals[5] = imageCopy[i-1][j-1].rgbtBlue * gx[0][1];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i][j].rgbtRed * gy[1][2];
                gyrvals[1] = imageCopy[i][j-1].rgbtRed * gy[1][1];
                gyrvals[2] = imageCopy[i+1][j-1].rgbtRed * gy[2][1];
                gyrvals[3] = imageCopy[i-1][j].rgbtRed * gy[0][2];
                gyrvals[4] = imageCopy[i+1][j].rgbtRed * gy[2][2];
                gyrvals[5] = imageCopy[i-1][j-1].rgbtRed * gy[0][1];

                gygvals[0] = imageCopy[i][j].rgbtGreen * gy[1][2];
                gygvals[1] = imageCopy[i][j-1].rgbtGreen * gy[1][1];
                gygvals[2] = imageCopy[i+1][j-1].rgbtGreen * gy[2][1];
                gygvals[3] = imageCopy[i-1][j].rgbtGreen * gy[0][2];
                gygvals[4] = imageCopy[i+1][j].rgbtGreen * gy[2][2];
                gygvals[5] = imageCopy[i-1][j-1].rgbtGreen * gy[0][1];

                gybvals[0] = imageCopy[i][j].rgbtBlue * gy[1][2];
                gybvals[1] = imageCopy[i][j-1].rgbtBlue * gy[1][1];
                gybvals[2] = imageCopy[i+1][j-1].rgbtBlue * gy[2][1];
                gybvals[3] = imageCopy[i-1][j].rgbtBlue * gy[0][2];
                gybvals[4] = imageCopy[i+1][j].rgbtBlue * gy[2][2];
                gybvals[5] = imageCopy[i-1][j-1].rgbtBlue * gy[0][1];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
            }
            //bottom right corner
            else if (i == realheight && j == realwidth) {
                gxrvals[0] = imageCopy[i-1][j].rgbtRed * gx[1][2];
                gxrvals[1] = imageCopy[i-1][j-1].rgbtRed * gx[1][1];
                gxrvals[2] = imageCopy[i][j-1].rgbtRed * gx[2][1];
                gxrvals[3] = imageCopy[i][j].rgbtRed * gx[2][2];

                gxgvals[0] = imageCopy[i-1][j].rgbtGreen * gx[1][2];
                gxgvals[1] = imageCopy[i-1][j-1].rgbtGreen * gx[1][1];
                gxgvals[2] = imageCopy[i][j-1].rgbtGreen * gx[2][1];
                gxgvals[3] = imageCopy[i][j].rgbtGreen * gx[2][2];

                gxbvals[0] = imageCopy[i-1][j].rgbtBlue * gx[1][2];
                gxbvals[1] = imageCopy[i-1][j-1].rgbtBlue * gx[1][1];
                gxbvals[2] = imageCopy[i][j-1].rgbtBlue * gx[2][1];
                gxbvals[3] = imageCopy[i][j].rgbtBlue * gx[2][2];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i-1][j].rgbtRed * gy[1][2];
                gyrvals[1] = imageCopy[i-1][j-1].rgbtRed * gy[1][1];
                gyrvals[2] = imageCopy[i][j-1].rgbtRed * gy[2][1];
                gyrvals[3] = imageCopy[i][j].rgbtRed * gy[2][2];

                gygvals[0] = imageCopy[i-1][j].rgbtGreen * gy[1][2];
                gygvals[1] = imageCopy[i-1][j-1].rgbtGreen * gy[1][1];
                gygvals[2] = imageCopy[i][j-1].rgbtGreen * gy[2][1];
                gygvals[3] = imageCopy[i][j].rgbtGreen * gy[2][2];

                gybvals[0] = imageCopy[i-1][j].rgbtBlue * gy[1][2];
                gybvals[1] = imageCopy[i-1][j-1].rgbtBlue * gy[1][1];
                gybvals[2] = imageCopy[i][j-1].rgbtBlue * gy[2][1];
                gybvals[3] = imageCopy[i][j].rgbtBlue * gy[2][2];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
            }
            //bottom edge
            else if (i == realheight && (j > 0 && j < realwidth)) {
                gxrvals[0] = imageCopy[i][j].rgbtRed * gx[2][1];
                gxrvals[1] = imageCopy[i][j-1].rgbtRed * gx[2][0];
                gxrvals[2] = imageCopy[i-1][j+1].rgbtRed * gx[1][2];
                gxrvals[3] = imageCopy[i][j+1].rgbtRed * gx[2][2];
                gxrvals[4] = imageCopy[i-1][j].rgbtRed * gx[1][1];
                gxrvals[5] = imageCopy[i-1][j-1].rgbtRed * gx[1][0];

                gxgvals[0] = imageCopy[i][j].rgbtGreen * gx[2][1];
                gxgvals[1] = imageCopy[i][j-1].rgbtGreen * gx[2][0];
                gxgvals[2] = imageCopy[i-1][j+1].rgbtGreen * gx[1][2];
                gxgvals[3] = imageCopy[i][j+1].rgbtGreen * gx[2][2];
                gxgvals[4] = imageCopy[i-1][j].rgbtGreen * gx[1][1];
                gxgvals[5] = imageCopy[i-1][j-1].rgbtGreen * gx[1][0];

                gxbvals[0] = imageCopy[i][j].rgbtBlue * gx[2][1];
                gxbvals[1] = imageCopy[i][j-1].rgbtBlue * gx[2][0];
                gxbvals[2] = imageCopy[i-1][j+1].rgbtBlue * gx[1][2];
                gxbvals[3] = imageCopy[i][j+1].rgbtBlue * gx[2][2];
                gxbvals[4] = imageCopy[i-1][j].rgbtBlue * gx[1][1];
                gxbvals[5] = imageCopy[i-1][j-1].rgbtBlue * gx[1][0];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i][j].rgbtRed * gy[2][1];
                gyrvals[1] = imageCopy[i][j-1].rgbtRed * gy[2][0];
                gyrvals[2] = imageCopy[i-1][j+1].rgbtRed * gy[1][2];
                gyrvals[3] = imageCopy[i][j+1].rgbtRed * gy[2][2];
                gyrvals[4] = imageCopy[i-1][j].rgbtRed * gy[1][1];
                gyrvals[5] = imageCopy[i-1][j-1].rgbtRed * gy[1][0];

                gygvals[0] = imageCopy[i][j].rgbtGreen * gy[2][1];
                gygvals[1] = imageCopy[i][j-1].rgbtGreen * gy[2][0];
                gygvals[2] = imageCopy[i-1][j+1].rgbtGreen * gy[1][2];
                gygvals[3] = imageCopy[i][j+1].rgbtGreen * gy[2][2];
                gygvals[4] = imageCopy[i-1][j].rgbtGreen * gy[1][1];
                gygvals[5] = imageCopy[i-1][j-1].rgbtGreen * gy[1][0];

                gybvals[0] = imageCopy[i][j].rgbtBlue * gy[2][1];
                gybvals[1] = imageCopy[i][j-1].rgbtBlue * gy[2][0];
                gybvals[2] = imageCopy[i-1][j+1].rgbtBlue * gy[1][2];
                gybvals[3] = imageCopy[i][j+1].rgbtBlue * gy[2][2];
                gybvals[4] = imageCopy[i-1][j].rgbtBlue * gy[1][1];
                gybvals[5] = imageCopy[i-1][j-1].rgbtBlue * gy[1][0];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
        }
        //bottom left corner
        else if (i == realheight && j == 0) {
                gxrvals[0] = imageCopy[i-1][j].rgbtRed * gx[1][0];
                gxrvals[1] = imageCopy[i-1][j +1].rgbtRed * gx[1][1];
                gxrvals[2] = imageCopy[i][j+1].rgbtRed * gx[2][1];
                gxrvals[3] = imageCopy[i][j].rgbtRed * gx[2][0];

                gxgvals[0] = imageCopy[i-1][j].rgbtGreen * gx[1][0];
                gxgvals[1] = imageCopy[i-1][j +1].rgbtGreen * gx[1][1];
                gxgvals[2] = imageCopy[i][j+1].rgbtGreen * gx[2][1];
                gxgvals[3] = imageCopy[i][j].rgbtGreen * gx[2][0];

                gxbvals[0] = imageCopy[i-1][j].rgbtBlue * gx[1][0];
                gxbvals[1] = imageCopy[i-1][j +1].rgbtBlue * gx[1][1];
                gxbvals[2] = imageCopy[i][j+1].rgbtBlue * gx[2][1];
                gxbvals[3] = imageCopy[i][j].rgbtBlue * gx[2][0];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i-1][j].rgbtRed * gy[1][0];
                gyrvals[1] = imageCopy[i-1][j +1].rgbtRed * gy[1][1];
                gyrvals[2] = imageCopy[i][j+1].rgbtRed * gy[2][1];
                gyrvals[3] = imageCopy[i][j].rgbtRed * gy[2][0];

                gygvals[0] = imageCopy[i-1][j].rgbtGreen * gy[1][0];
                gygvals[1] = imageCopy[i-1][j +1].rgbtGreen * gy[1][1];
                gygvals[2] = imageCopy[i][j+1].rgbtGreen * gy[2][1];
                gygvals[3] = imageCopy[i][j].rgbtGreen * gy[2][0];

                gybvals[0] = imageCopy[i-1][j].rgbtBlue * gy[1][0];
                gybvals[1] = imageCopy[i-1][j +1].rgbtBlue * gy[1][1];
                gybvals[2] = imageCopy[i][j+1].rgbtBlue * gy[2][1];
                gybvals[3] = imageCopy[i][j].rgbtBlue * gy[2][0];

                for (int x = 0; x < 4 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
        }
        //left edge
        else if (j == 0 && (i> 0 && i < realheight)) {
                gxrvals[0] = imageCopy[i][j].rgbtRed * gx[1][0];
                gxrvals[1] = imageCopy[i][j+1].rgbtRed * gx[1][1];
                gxrvals[2] = imageCopy[i-1][j+1].rgbtRed * gx[0][1];
                gxrvals[3] = imageCopy[i-1][j].rgbtRed * gx[0][0];
                gxrvals[4] = imageCopy[i+1][j].rgbtRed * gx[2][0];
                gxrvals[5] = imageCopy[i+1][j+1].rgbtRed * gx[2][1];

                gxgvals[0] = imageCopy[i][j].rgbtGreen * gx[1][0];
                gxgvals[1] =  imageCopy[i][j+1].rgbtGreen * gx[1][1];
                gxgvals[2] =  imageCopy[i-1][j+1].rgbtGreen * gx[0][1];
                gxgvals[3] = imageCopy[i-1][j].rgbtGreen * gx[0][0];
                gxgvals[4] = imageCopy[i+1][j].rgbtGreen * gx[2][0];
                gxgvals[5] = imageCopy[i+1][j+1].rgbtGreen * gx[2][1];

                gxbvals[0] = imageCopy[i][j].rgbtBlue * gx[1][0];
                gxbvals[1] = imageCopy[i][j+1].rgbtBlue * gx[1][1];
                gxbvals[2] = imageCopy[i-1][j+1].rgbtBlue * gx[0][1];
                gxbvals[3] = imageCopy[i-1][j].rgbtBlue * gx[0][0];
                gxbvals[4] = imageCopy[i+1][j].rgbtBlue * gx[2][0];
                gxbvals[5] = imageCopy[i+1][j+1].rgbtBlue * gx[2][1];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i][j].rgbtRed * gy[1][0];
                gyrvals[1] = imageCopy[i][j+1].rgbtRed * gy[1][1];
                gyrvals[2] = imageCopy[i-1][j+1].rgbtRed * gy[0][1];
                gyrvals[3] = imageCopy[i-1][j].rgbtRed * gy[0][0];
                gyrvals[4] = imageCopy[i+1][j].rgbtRed * gy[2][0];
                gyrvals[5] = imageCopy[i+1][j+1].rgbtRed * gy[2][1];

                gygvals[0] = imageCopy[i][j].rgbtGreen * gy[1][0];
                gygvals[1] =  imageCopy[i][j+1].rgbtGreen * gy[1][1];
                gygvals[2] =  imageCopy[i-1][j+1].rgbtGreen * gy[0][1];
                gygvals[3] = imageCopy[i-1][j].rgbtGreen * gy[0][0];
                gygvals[4] = imageCopy[i+1][j].rgbtGreen * gy[2][0];
                gygvals[5] = imageCopy[i+1][j+1].rgbtGreen * gy[2][1];

                gybvals[0] = imageCopy[i][j].rgbtBlue * gy[1][0];
                gybvals[1] = imageCopy[i][j+1].rgbtBlue * gy[1][1];
                gybvals[2] = imageCopy[i-1][j+1].rgbtBlue * gy[0][1];
                gybvals[3] = imageCopy[i-1][j].rgbtBlue * gy[0][0];
                gybvals[4] = imageCopy[i+1][j].rgbtBlue * gy[2][0];
                gybvals[5] = imageCopy[i+1][j+1].rgbtBlue * gy[2][1];

                for (int x = 0; x < 6 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
        }
        else {
                gxrvals[0] = imageCopy[i][j].rgbtRed * gx[1][1];
                gxrvals[1] = imageCopy[i][j+1].rgbtRed * gx[1][2];
                gxrvals[2] = imageCopy[i-1][j+1].rgbtRed * gx[0][2];
                gxrvals[3] = imageCopy[i-1][j].rgbtRed * gx[0][1];
                gxrvals[4] = imageCopy[i+1][j].rgbtRed * gx[2][1];
                gxrvals[5] = imageCopy[i+1][j+1].rgbtRed * gx[2][2];
                gxrvals[6] = imageCopy[i][j-1].rgbtRed * gx[1][0];
                gxrvals[7] = imageCopy[i-1][j-1].rgbtRed * gx[0][0];
                gxrvals[8] = imageCopy[i+1][j-1].rgbtRed * gx[2][0];

                gxgvals[0] = imageCopy[i][j].rgbtGreen * gx[1][1];
                gxgvals[1] = imageCopy[i][j+1].rgbtGreen * gx[1][2];
                gxgvals[2] = imageCopy[i-1][j+1].rgbtGreen * gx[0][2];
                gxgvals[3] = imageCopy[i-1][j].rgbtGreen * gx[0][1];
                gxgvals[4] = imageCopy[i+1][j].rgbtGreen * gx[2][1];
                gxgvals[5] = imageCopy[i+1][j+1].rgbtGreen * gx[2][2];
                gxgvals[6] = imageCopy[i][j-1].rgbtGreen * gx[1][0];
                gxgvals[7] = imageCopy[i-1][j-1].rgbtGreen* gx[0][0];
                gxgvals[8] = imageCopy[i+1][j-1].rgbtGreen * gx[2][0];

                gxbvals[0] = imageCopy[i][j].rgbtBlue * gx[1][1];
                gxbvals[1] = imageCopy[i][j+1].rgbtBlue * gx[1][2];
                gxbvals[2] = imageCopy[i-1][j+1].rgbtBlue * gx[0][2];
                gxbvals[3] = imageCopy[i-1][j].rgbtBlue * gx[0][1];
                gxbvals[4] = imageCopy[i+1][j].rgbtBlue * gx[2][1];
                gxbvals[5] = imageCopy[i+1][j+1].rgbtBlue * gx[2][2];
                gxbvals[6] = imageCopy[i][j-1].rgbtBlue * gx[1][0];
                gxbvals[7] = imageCopy[i-1][j-1].rgbtBlue* gx[0][0];
                gxbvals[8] = imageCopy[i+1][j-1].rgbtBlue * gx[2][0];

                for (int x = 0; x < 9 ; x++ ) {
                    sumrgx = sumrgx + gxrvals[x];
                    sumggx = sumggx + gxgvals[x];
                    sumbgx = sumbgx + gxbvals[x];
                }

                gyrvals[0] = imageCopy[i][j].rgbtRed * gy[1][1];
                gyrvals[1] = imageCopy[i][j+1].rgbtRed * gy[1][2];
                gyrvals[2] = imageCopy[i-1][j+1].rgbtRed * gy[0][2];
                gyrvals[3] = imageCopy[i-1][j].rgbtRed * gy[0][1];
                gyrvals[4] = imageCopy[i+1][j].rgbtRed * gy[2][1];
                gyrvals[5] = imageCopy[i+1][j+1].rgbtRed * gy[2][2];
                gyrvals[6] = imageCopy[i][j-1].rgbtRed * gy[1][0];
                gyrvals[7] = imageCopy[i-1][j-1].rgbtRed * gy[0][0];
                gyrvals[8] = imageCopy[i+1][j-1].rgbtRed * gy[2][0];

                gygvals[0] = imageCopy[i][j].rgbtGreen * gy[1][1];
                gygvals[1] = imageCopy[i][j+1].rgbtGreen * gy[1][2];
                gygvals[2] = imageCopy[i-1][j+1].rgbtGreen * gy[0][2];
                gygvals[3] = imageCopy[i-1][j].rgbtGreen * gy[0][1];
                gygvals[4] = imageCopy[i+1][j].rgbtGreen * gy[2][1];
                gygvals[5] = imageCopy[i+1][j+1].rgbtGreen * gy[2][2];
                gygvals[6] = imageCopy[i][j-1].rgbtGreen * gy[1][0];
                gygvals[7] = imageCopy[i-1][j-1].rgbtGreen* gy[0][0];
                gygvals[8] = imageCopy[i+1][j-1].rgbtGreen * gy[2][0];

                gybvals[0] = imageCopy[i][j].rgbtBlue * gy[1][1];
                gybvals[1] = imageCopy[i][j+1].rgbtBlue * gy[1][2];
                gybvals[2] = imageCopy[i-1][j+1].rgbtBlue * gy[0][2];
                gybvals[3] = imageCopy[i-1][j].rgbtBlue * gy[0][1];
                gybvals[4] = imageCopy[i+1][j].rgbtBlue * gy[2][1];
                gybvals[5] = imageCopy[i+1][j+1].rgbtBlue * gy[2][2];
                gybvals[6] = imageCopy[i][j-1].rgbtBlue * gy[1][0];
                gybvals[7] = imageCopy[i-1][j-1].rgbtBlue* gy[0][0];
                gybvals[8] = imageCopy[i+1][j-1].rgbtBlue * gy[2][0];

                for (int x = 0; x < 9 ; x++ ) {
                    sumrgy = sumrgy + gyrvals[x];
                    sumggy = sumggy + gygvals[x];
                    sumbgy = sumbgy + gybvals[x];
                }

                value = round(fmin(255,sqrt(sumrgx * sumrgx + sumrgy * sumrgy)));

                image[i][j].rgbtRed = value;
                value = round(fmin(255,sqrt(sumggx * sumggx + sumggy* sumggy)));

                image[i][j].rgbtGreen = value;
                value = round(fmin(255,sqrt(sumbgx * sumbgx + sumbgy * sumbgy)));

                image[i][j].rgbtBlue = value;

                sumrgx = 0;
                sumggx = 0;
                sumbgx = 0;
                sumrgy = 0;
                sumggy = 0;
                sumbgy = 0;
            }
        }
    }
    return;
}