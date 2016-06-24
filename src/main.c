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

#define BIT26 0x4000000; //configuracion como salida naranja
#define BIT24 0X1000000; //configuracion como salida verde
#define BIT28 0X10000000; //configuracion como salida verde
#define BIT30 0X40000000; //configuracion como salida verde

#define BIT13 0X2000; //pin del led naranja
#define BIT12 0X1000; //pin del led verde
#define BIT14 0X4000; //pin del led rojo
#define BIT15 0X8000; //pin del led azul

void delay(uint16_t delay);

void main(void) {
	//configuracion
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; //configuracion del clock del bus del gpio D
	GPIOD->MODER |= BIT26; //configura pin de led como salida
	GPIOD->MODER |= BIT24;
	GPIOD->MODER |= BIT28;
	GPIOD->MODER |= BIT30;

	for (;;) {
		//aplicacion
		delay(5000);
		GPIOD->ODR ^= BIT13; //prendo led naranja
		GPIOD->ODR ^= BIT12; //prendo led verde
		GPIOD->ODR ^= BIT14; //prendo led rojo
		GPIOD->ODR ^= BIT15; //prendo led azul
	}
}

void delay(uint16_t delay) {
	uint8_t i;
	while (delay-- > 0) {
		for (i = 100; i > 0; i++)
			asm ("nop");
		//instruccion de asembler NOP
	}
}
