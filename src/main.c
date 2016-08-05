/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void delay(uint16_t delay);

#define LED_NARANJA GPIO_PIN_13
#define LED_VERDE GPIO_PIN_12
#define LED_ROJO GPIO_PIN_14
#define LED_AZUL GPIO_PIN_15

#define LEDS_PORT GPIOD
//Pulsador PUERTO y PIN
#define BUTTONS_PORT GPIOA
#define BUTTONS_PIN GPIO_PIN_0

uint8_t rotacion;

int main(void) {

	__GPIOD_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FAST;
	GPIO_Init.Pin = LED_AZUL | LED_ROJO | LED_NARANJA | LED_VERDE;

	HAL_GPIO_Init(LEDS_PORT, &GPIO_Init);


	__GPIOA_CLK_ENABLE(); //enciendo el reloj del bus del puerto A
		//configuracion
	GPIO_InitTypeDef GPIO_Buttons;
	GPIO_Buttons.Mode = GPIO_MODE_INPUT;
	GPIO_Buttons.Pull = GPIO_PULLDOWN;
	GPIO_Buttons.Speed = GPIO_SPEED_LOW;
	GPIO_Buttons.Pin = BUTTONS_PIN;
		//inicializacion
	HAL_GPIO_Init(BUTTONS_PORT, &GPIO_Buttons);


	while (1) {
		if (HAL_GPIO_ReadPin(BUTTONS_PORT, BUTTONS_PIN)){
			rotacion ^= 1;
		}

		HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);


		if (rotacion) {
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_SET);
			delay(0xFFFF);
		} else {

			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_SET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);

		}

	}
}

void delay(uint16_t delay) {
	uint16_t i = 0xFFFF;
	while (i) {
		while (delay)
			delay--;
		i--;
	}
}
