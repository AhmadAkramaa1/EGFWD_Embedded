

#include "Std_Types.h"
#include "Bit_Math.h"

#include "IntCtrl.h"
#include "DIO.h"
#include "SysTick.h"

#include "Led.h"


volatile u8 ontime =4;
volatile u8 offtime =1;

void Intr_Func(void)
{
	static u8 diffsetup=0;
	static u8 count=0;
	count++;
	/***** to make one full cycle ****/
	if(count == ontime )
	{
		LedOff();
	}
	else if(count == (ontime+offtime) )
	{
		LedOn();
		count = 0;
		diffsetup++;
		
	}
	/***** to make different setup for the led ****/
	if(diffsetup == 3)   //after 3times, change
	{
		ontime  =1;
		offtime =1;
	}
	if(diffsetup >= 5) //after 4 times next, change
	{
		ontime  =4;
		offtime =1;
		diffsetup = 0;
	}
}
int main(void)
{
	IntCrtl_Init();
	GPIO_VoidInit();             //enable portF clk - configure bit 2 as output - enable it as dio
	Systick_VoidInit();          //select system clk and enable interrupt
	Systick_VoidCallBack(Intr_Func);  //set call back func
	DIO_WriteChannel(PORTF, DIO_PIN_2, DIO_HIGH); //set pin2 in portf
	Systick_VoidStartTimer(15999999); //delay one second 
	
	while(1)
	{
		
	}
	return 0;
}
