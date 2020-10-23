/*
 ============================================================================
 Name        : e_bitmap.c
 Author      : rt-rk
 Version     :
 Copyright   : Your copyright notice
 Description : image processing example
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "imageProcessing.h"

static const int ARG_NUM = 2;

int main(int argc, char* argv[])//argv[0] je naziv programa
{
	int_least32_t err = 0;
	BITMAPFILEHEADER bitmapFileHeader;
	BITMAPINFOHEADER bitmapInfoHeader;
	uint_least8_t* bitmapData;

	if ( argc != ARG_NUM )
	{
		printf("Enter input file path \n");
		return EXIT_FAILURE;
	}
	
	printf("Applying brightness\n");	
	bitmapData = LoadBitmapFile(argv[1],&bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	adjustImageBrightness(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, false, 70);
	err = SaveBitmapFile("out_brightness.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying dark image\n");
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	bwImage(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_bw.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying effect\n");
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	effect(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_effect.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Average:\n");
		bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
		if(!bitmapData)
		{
			printf("Error! Can't open input bitmap file: %s\n", argv[1]);
			return EXIT_FAILURE;
		}

		float RGB[3];
		RGB[0] = 0;
		RGB[1] = 0;
		RGB[2] = 0;
		average(bitmapData, bitmapInfoHeader.biWidth,
			bitmapInfoHeader.biHeight, RGB, RGB+1, RGB+2);
		err = SaveBitmapFile("out_average.bmp", &bitmapFileHeader,
			&bitmapInfoHeader, bitmapData);
		if (err)
		{
			printf("Error trying to save bitmap\n");
		}
		printf("RED = %f\n", RGB[0]);
		printf("GREEN = %f\n", RGB[1]);
		printf("BLUE = %f\n", RGB[2]);
		free(bitmapData);

	return EXIT_SUCCESS;
}
