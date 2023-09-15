#include "sl.h"
#include <iostream>

using namespace std;


int main()
{

	const int width = 800;
	const int height = 400;

	slWindow(width, height, "BreakOut", false);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
			 
		slSetBackColor(0, 0, 0);

		slSetForeColor(1, 0, 1, 1);
		slRectangleFill(width * 0.5, height * 0.05, 130, 15);

		slRender();
	}

	slClose();

	return 0;
}