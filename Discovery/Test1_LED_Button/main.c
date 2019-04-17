/**
  *****************************************************************************
  * @title   main.c
  * @author  lolo13
  * @date    13 Dec 2012
  * @brief   This example describes how to toggle the GPIO pins connected on
  *          AHB bus.
  *
  *          PD12, PD13, PD14 and PD15 (configured in output push
  *          pull mode) toggles in a forever loop.
  *           - Set PD12, PD13, PD14 a
  *          nd PD15 by setting corresponding bits in BSRRL register
  *           - Rese
  *          t PD12, PD13, PD14 and PD15  by setting corresponding bits in BS
  *          RRH register
  *
  *          In this example, HCLK is configured at 168 MHz.

  *

  *            - IO_Toggle/stm32f4xx_conf.h    Library Configuration file

  *
  - IO_Toggle/stm32f4xx_it.c      Interrupt handlers
  *            - IO_To
  *          ggle/stm32f4xx_it.h      Interrupt handlers header file
  *            - IO_
  *          Toggle/main.c              Main program
  *            - IO_Toggle/system_st
  *          m32f4xx.c  STM32F4xx system source file
  *
  *            - This example runs
  *           on STM32F4xx Devices Revision A.
  *
  *            - This example has been t
  *          ested with STM32F4-Discovery (MB997) RevB and can be
  *              easily
  *           tailored to any other development board
  *
  *            - STM32F4-Discover
  *          y
  *              - LED4, LED3, LED5 and LED6 are connected respectively to
  *           PD.12, PD.13, PD.14 and PD.15.
  *******************************************************************************
  */
////// The above comment is automatically generated by CoIDE ///////////////////


#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>

GPIO_InitTypeDef  GPIO_InitStructure;

void msDelay(unsigned long msTime);

int main(void)
{
	SystemInit();

	// Configure PA0 with
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// Configure PD12, PD13, PD14 and PD15 in output pushpull mode
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	//Wait until PushButton is pressed PA0=1
	while(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)); //wait when PA0=0

	//loop forever
    while(1)
    {
    	 // PD12 to be toggled
    	 GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

    	 // Insert delay 0.5s
    	 msDelay(500);
    }
}

void msDelay(unsigned long msTime)
{
	unsigned long i,j, nCount=0x1310;
	for(i=0;i<msTime;i++)
		for(j=0;j<nCount;j++);
}
