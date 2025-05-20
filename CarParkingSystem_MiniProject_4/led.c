/************************************************************************************************************************************
 Module      : LED
 Name        : led.c
 Author      : Salma Hamdy
 Description : Source file for the ATmega32 LED driver
 ************************************************************************************************************************************/

#include "common_macros.h" /* For GET_BIT Macro */
#include "led.h"
#include "gpio.h"

void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);

#if(LED_RED_LOGIC == POSITIVE_LOGIC)
	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
#elif(LED_RED_LOGIC == Negative_LOGIC)
	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_HIGH);
#endif

#if(LED_GREEN_LOGIC == POSITIVE_LOGIC)
	GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
#elif(LED_GREEN_LOGIC == Negative_LOGIC)
	GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_HIGH);
#endif

#if(LED_BLUE_LOGIC == POSITIVE_LOGIC)
	GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
#elif(LED_BLUE_LOGIC == Negative_LOGIC)
	GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_HIGH);
#endif

}

void LED_on(LED_ID id)
{
	if(id == LED_RED)
	{
	#if(LED_RED_LOGIC == POSITIVE_LOGIC)
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_HIGH);
	#elif(LED_RED_LOGIC == Negative_LOGIC)
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
	#endif
	}

	else if(id == LED_GREEN)
	{
	#if(LED_GREEN_LOGIC == POSITIVE_LOGIC)
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_HIGH);
	#elif(LED_GREEN_LOGIC == Negative_LOGIC)
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
	#endif
	}

	else if(id == LED_BLUE)
	{
	#if(LED_BLUE_LOGIC == POSITIVE_LOGIC)
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_HIGH);
	#elif(LED_BLUE_LOGIC == Negative_LOGIC)
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
	#endif
	}
}

void LED_off(LED_ID id)
{
	if(id == LED_RED)
	{
	#if(LED_RED_LOGIC == POSITIVE_LOGIC)
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
	#elif(LED_RED_LOGIC == Negative_LOGIC)
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_HIGH);
	#endif
	}

	else if(id == LED_GREEN)
	{
	#if(LED_GREEN_LOGIC == POSITIVE_LOGIC)
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
	#elif(LED_GREEN_LOGIC == Negative_LOGIC)
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_HIGH);
	#endif
	}

	else if(id == LED_BLUE)
	{
	#if(LED_BLUE_LOGIC == POSITIVE_LOGIC)
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
	#elif(LED_BLUE_LOGIC == Negative_LOGIC)
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_HIGH);
	#endif
	}
}
