#include "stdafx.h"

using namespace std;

#define MAINPROGRAM
#include "variables.h"
#include "readfile.h"

void saveScreenshot(BYTE * pixels, int w, int h, string fname)
{
	FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, w, h, w * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, true);

	std::cout << "Saving screenshot: " << fname << "\n";

	FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);
}


int main(int argc, char* argv[])
{
	string fname = readfile(argv[1]);

	FreeImage_Initialise();
	const int m = 3 * w * h;
	BYTE pixels[m]; 
	saveScreenshot(pixels, w, h, fname);
	FreeImage_DeInitialise();
    return 0;
}

