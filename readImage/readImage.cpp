#include <iostream>
#include <fstream>
#include "Magick++.h"

using namespace Magick;
using namespace std;

int main(int argc, char** argv)
{
	Image image;
	try
	{
		InitializeMagick(*argv);
		image.read(argv[1]);
		PixelData pxlsDat(image, argv[2], MagickCore::CharPixel);
		cout << " Bit depth is " << image.depth() << ", memory use is " << pxlsDat.size() << endl;
	}
	catch (Magick::Exception &error_)
	{
		cout << "Caught exception: " << error_.what() << endl; 
		return 1;
	}
	return 0;
}