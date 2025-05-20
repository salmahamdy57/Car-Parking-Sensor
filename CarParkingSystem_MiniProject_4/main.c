/************************************************************************************************************************************
 Module      : Main
 Name        : main.c
 Author      : Salma Hamdy
 Description : Car Parking Sensor Using ATmega32, Ultrasonic Sensor, LCD Display, LEDs, and Buzzer.
 ***********************************************************************************************************************************/

#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "ultrasonic_sensor.h"
#include <util/delay.h>


int main(void)
{
	uint16 distance;

	LCD_init();
	LEDS_init();
	Buzzer_init();
	Ultrasonic_init();

	while(1)
	{
		distance = Ultrasonic_readDistance();

		/************************************************ LCD Display ************************************************************/

		LCD_moveCursor(0,2);
		LCD_displayString("Distance= ");
		LCD_intgerToString(distance);
		LCD_displayString("cm ");

		if(distance <= 5)
		{
			LCD_moveCursor(1,6);
			LCD_displayString("STOP!");
		}
		else
		{
			LCD_moveCursor(1,6);
			LCD_displayString("     ");
		}

		/*************************************** Distance to LED and Buzzer Mapping ************************************************/

		if(distance <= 5)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
			Buzzer_on();

			_delay_ms(500);

			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			Buzzer_off();

			_delay_ms(500);
		}
		else if(distance >= 6 && distance <= 10)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
			Buzzer_off();
		}
		else if(distance >= 11 && distance <= 15)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
			Buzzer_off();
		}
		else if(distance >= 16 && distance <= 20)
		{
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			Buzzer_off();
		}
		else if(distance > 20)
		{
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			Buzzer_off();
		}
	}

	return 0;
}
