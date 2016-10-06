#include "setWallPaper.h"

using namespace std;

void SetWallPaper()
{
	CImage earth;
	earth.Load("C:\\earth.png");
	earth.Save("C:\\earth.bmp");

	SystemParametersInfo(SPI_SETDESKWALLPAPER,0, "C:\\earth.bmp", SPIF_SENDCHANGE);
}
