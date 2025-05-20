/************************************************************************************************************************************
 Module      : LED
 Name        : led.h
 Author      : Salma Hamdy
 Description : Header file for the ATmega32 LED driver
 ************************************************************************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Enumeration for the LED IDs */
typedef enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE
} LED_ID;


/* LED HW Ports and Pins Ids */
#define POSITIVE_LOGIC                  1
#define NEGATIVE_LOGIC                  0

#define LED_RED_PORT_ID                 PORTC_ID
#define LED_RED_PIN_ID                  PIN0_ID
#define LED_RED_LOGIC                   POSITIVE_LOGIC

#define LED_GREEN_PORT_ID               PORTC_ID
#define LED_GREEN_PIN_ID                PIN1_ID
#define LED_GREEN_LOGIC                 POSITIVE_LOGIC

#define LED_BLUE_PORT_ID                PORTC_ID
#define LED_BLUE_PIN_ID                 PIN2_ID
#define LED_BLUE_LOGIC                  POSITIVE_LOGIC



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * 1. Initializes all Leds (red, green, blue) pins direction.
 * 2. Turn off all the Leds
 */
void LEDS_init(void);

/*
 * Description :
 * Turn on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Description :
 * Turn off the specified LED.
 */
void LED_off(LED_ID id);


#endif /* LED_H_ */
