#include <gui/screen1_screen/Screen1View.hpp>
#include <math.h>

Screen1View::Screen1View()
{
	tickCounter  = 0;
	tickCounter2 = 0;
	Counter = 0;
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
	tickCounter2++;
	if(tickCounter == 10){
		tickCounter= 0;
		//tickCounter2++;
	}

	//graph1.setGraphRangeX(0, 60+tickCounter2);
	if(tickCounter2 % 3 == 0)
	{
		//customGraph1.addPoint((sinf(tickCounter2 * 0.07) + 1) * 40 + rand() % 10, (float)tickCounter2);
		//graph1.addDataPoint((int)(sinf(tickCounter2 * 0.07) + 1) * 40 + rand() % 10, tickCounter2);
	}
}

//void Screen1View:
