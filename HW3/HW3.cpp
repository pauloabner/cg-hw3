// HW3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <FreeImage.h>
#include <iostream>
#include <string>



void saveScreenshot(BYTE * pixels, int w, int h, std::string fname)
{
	FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, w, h, w * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, true);

	std::cout << "Saving screenshot: " << fname << "\n";

	FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);
}


int main()
{
	FreeImage_Initialise();
	int w = 640, h = 480;
	BYTE pixels[921600]; // 3 * w * h

	saveScreenshot(pixels, w, h, "output.png");

	FreeImage_DeInitialise();
    return 0;
}

