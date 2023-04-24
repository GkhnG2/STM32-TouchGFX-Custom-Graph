#include <gui/screen1_screen/Screen1View.hpp>
#include <math.h>
#include "stm32h7xx_hal.h"

uint32_t testCNTR=0;
time_t firstTime = 1681492804;

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
		if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_2) == 0x00)
		{
			HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_12);
			HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_13);
			HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_14);
			HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_15);
		}
	}
	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_2) == 0x00)
	{
		if(testCNTR < 500){
			customGraph1.addPoint(firstTime+testCNTR*180, 2+cos(testCNTR*(PI/180.0)));
			testCNTR++;
		}
		else if(testCNTR == 500)
		{
			customGraph1.setTimeRange(8);
		}
	}

	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_3) == 0x00)
	{
		customGraph1.clearAllData();
		testCNTR = 0;
	}

	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_4) == 0x00)
	{
		customGraph1.setLineColor(0xFF0000);
		customGraph1.setYAxisLabel("Curr");
		customGraph1.setTimeRange(8);
	}
	if(HAL_GPIO_ReadPin(GPIOK, GPIO_PIN_5) == 0x00)
	{
		customGraph1.setLineColor(0x00FF00);
		customGraph1.setYAxisLabel("CO2");
		customGraph1.setTimeRange(24);
	}

	//graph1.setGraphRangeX(0, 60+tickCounter2);
	if(tickCounter2 % 3 == 0)
	{
		//customGraph1.addPoint((sinf(tickCounter2 * 0.07) + 1) * 40 + rand() % 10, (float)tickCounter2);
		//graph1.addDataPoint((int)(sinf(tickCounter2 * 0.07) + 1) * 40 + rand() % 10, tickCounter2);
	}
}

//void Screen1View:
