#include <gui/screen1_screen/Screen1View.hpp>
#include <math.h>
#include "stm32h7xx_hal.h"

Screen1View::Screen1View()
{

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
	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_2) == 0x00)
	{
		if(testCNTR < 500){
			customGraph1.addPoint(firstTime+testCNTR*180, 20000+10000*cos(testCNTR*(PI/180.0)));
			testCNTR++;
		}
		else if(testCNTR == 500)
		{
			customGraph1.setLineColor(0xFFFF00);
			customGraph1.setTimeRange(8);
		}
	}

	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_5) == 0x00)
	{
		customGraph1.clearAllData();
		testCNTR = 0;
	}

	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_3) == 0x00)
	{
		customGraph1.setLineColor(0xFF0000);
		customGraph1.setYAxisLabel("Current");
		customGraph1.setTimeRange(24);
	}

	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_6) == 0x00)
	{
		customGraph1.setLineColor(0x00FF00);
		customGraph1.setYAxisLabel("CO2");
		customGraph1.setTimeRange(8);
	}

	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_4) == 0x00)
	{
		customGraph1.setLineColor(0x00FFFF);
		customGraph1.setYAxisLabel("Voltage");
		customGraph1.setTimeRange(1);
	}
}
