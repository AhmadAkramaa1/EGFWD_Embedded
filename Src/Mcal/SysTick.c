/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "SysTick.h"

#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

volatile PF PFCallBackAdd = NULL;



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Systick_VoidInit(void)
{
	if(SysStrCfg.SysTick_ClkSrc == SYSTEM_CLK)
	{
		SYSTICK_STCTRL->CLK_SRC = 1;
	}
	else
	{
		//default clk src is (internal oscillator)/4
		SYSTICK_STCTRL->CLK_SRC = 0;
	}
	
	if(SysStrCfg.SysTick_INTR == INTR_ENABLED)
	{
		SYSTICK_STCTRL->INTEN = 1;
	}
	else
	{
		//defualt is interrupt disabled
		SYSTICK_STCTRL->INTEN = 0;
	}
		           
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ValueCpy ( 1 - 16777215 )                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Systick_VoidStartTimer(Timer_Value_Type ValueCpy)
{
	
	if(ValueCpy<=0 || ValueCpy >16777215)
	{
		//do nothing and return
	}
	else
	{
		SYSTICK_STCURRENT->CURRENT = 0;
		
		SYSTICK_STRELOAD->RELOAD = ValueCpy;
		SYSTICK_STCTRL->ENABLE = 1;            //enable timer to start counting
	}
	
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : FuncNameCpy (function name from the APP Layer)                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Systick_VoidCallBack(PF FuncNameCpy)
{
	PFCallBackAdd = FuncNameCpy;
}


void SysTick_Handler (void)
{
	
	if(PFCallBackAdd != NULL)
	{
		PFCallBackAdd();
	}
	else
	{
		//Do nothing
	}
	
}
/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
