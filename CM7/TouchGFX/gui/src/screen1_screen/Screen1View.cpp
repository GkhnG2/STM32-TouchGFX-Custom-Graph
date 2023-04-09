#include <gui/screen1_screen/Screen1View.hpp>
#include <math.h>

Screen1View::Screen1View()
{
	tickCounter = 0;
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	tickCounter++;
	if(tickCounter % 3 == 0)
	{
		dynamicGraph1.addDataPoint((int)(sinf(tickCounter * 0.07) + 1) * 40 + rand() % 10);
		customGraph1.addPoint((sinf(tickCounter * 0.07) + 1) * 40 + rand() % 10);
	}
}
