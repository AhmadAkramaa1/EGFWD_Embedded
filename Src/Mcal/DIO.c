/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
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

#include "DIO.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PinCpy    DIO_PIN_x (x : 0 - 7)
*                    PortCpy   PORTA-PORTF               
* \Parameters (out): None                                                      
* \Return value:   : Level     DIO_HIGH
                     		   DIO_LOW              
*******************************************************************************/
DIO_Level_Type DIO_ReadChannel(DIO_Port_Type PortCpy, DIO_Channel_Type PinCpy)
{
	
	DIO_Level_Type LevelLoc = DIO_LOW;
	
	if(PinCpy<0 || PinCpy>7 || PortCpy<0 || PortCpy>5)
	{
		// Do nothing
		// in case of wrong arguments
	}
	else
	{
		switch(PortCpy)
		{
			case (PORTA) :
			{
				LevelLoc = ((GPIODATA(GPIO_PortA)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTB):
			{
				LevelLoc = ((GPIODATA(GPIO_PortB)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTC):
			{
				LevelLoc = ((GPIODATA(GPIO_PortC)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTD):
			{
				LevelLoc = ((GPIODATA(GPIO_PortD)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTE):
			{
				LevelLoc = ((GPIODATA(GPIO_PortE)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTF):
			{
				LevelLoc = ((GPIODATA(GPIO_PortF)) >> PinCpy) & 0x01;
				break;
			}
			default :
			{
				//do nothing because errors are covered in if condition
				break;
			}
		}
		
	}

	return LevelLoc;
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortCpy	   PORTA-PORTF
*					 PinCpy        DIO_PIN_x (x : 0 - 7)  
*				     LevelCpy      DIO_HIGH, DIO_LOW
*                   					   
* \Parameters (out): None                                                      
* \Return value:   : void                                 
*******************************************************************************/
void DIO_WriteChannel(DIO_Port_Type PortCpy, DIO_Channel_Type PinCpy, DIO_Level_Type LevelCpy)
{
	if( PortCpy<0 || PortCpy>5 || PinCpy<0 || PinCpy>7 || LevelCpy>1 || LevelCpy<0 )
	{
		//Do nothing
		// in case of wrong arguments
	}
	else
	{
		switch(PortCpy)
		{
			case (PORTA) :
			{
				if(LevelCpy == DIO_HIGH)
				{
					GPIODATA(GPIO_PortA) |= (1<<PinCpy) ;
				}
				else
				{
					GPIODATA(GPIO_PortA) &= ((u32)~(1<<PinCpy)) ;
				}
				break;
			}
			case (PORTB):
			{
				if(LevelCpy == DIO_HIGH)
				{
					GPIODATA(GPIO_PortB) |= (1<<PinCpy) ;
				}
				else
				{
					GPIODATA(GPIO_PortB) &= ((u32)~(1<<PinCpy)) ;
				}
				break;
			}
			case (PORTC):
			{
				if(LevelCpy == DIO_HIGH)
				{
					GPIODATA(GPIO_PortC) |= (1<<PinCpy) ;
				}
				else
				{
					GPIODATA(GPIO_PortC) &= ((u32)~(1<<PinCpy)) ;
				}
				break;
			}
			case (PORTD):
			{
	    		if(LevelCpy == DIO_HIGH)
	    		{
	    			GPIODATA(GPIO_PortD) |= (1<<PinCpy) ;
	    		}
	    		else
	    		{
	    			GPIODATA(GPIO_PortD) &= ((u32)~(1<<PinCpy)) ;
	    		}
	    		break;
	    	}
	    	case (PORTE):
	    	{
	    		if(LevelCpy == DIO_HIGH)
	    		{
	    			GPIODATA(GPIO_PortE) |= (1<<PinCpy) ;
	    		}
	    		else
	    		{
	    			GPIODATA(GPIO_PortE) &= ((u32)~(1<<PinCpy)) ;
	    		}
	    		break;
	    	}
	    	case (PORTF):
	    	{
	    		if(LevelCpy == DIO_HIGH)
	    		{
	    			GPIODATA(GPIO_PortF) |= (1<<PinCpy) ;
	    		}
	    		else
	    		{
	    			GPIODATA(GPIO_PortF) &= ((u32)~(1<<PinCpy)) ;
	    		}
	    		break;
	    	}
	    	default :
	    	{
	    		//do nothing because errors are covered in if condition
	    		break;
	    	}
	    }
	
	}
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortCpy                PORTA-PORTF                     
* \Parameters (out): None                                                      
* \Return value:   : DIO_PortLevel_Type  0x00 - 0xFF                        
*******************************************************************************/
DIO_PortLevel_Type DIO_ReadPort(DIO_Port_Type PortCpy)
{
	
	 DIO_PortLevel_Type PortLevelLoc = 0; 
	 if(PortCpy<0 || PortCpy>5)
	{
		//Do nothing
		// in case of wrong arguments
	}
	else
	{
		switch(PortCpy)
		{
			case (PORTA) :
			{
				PortLevelLoc = (u8)GPIODATA(GPIO_PortA);
				break;
			}
			case (PORTB):
			{
				PortLevelLoc = (u8)GPIODATA(GPIO_PortB);
				break;
			}
			case (PORTC):
			{
				PortLevelLoc = (u8)GPIODATA(GPIO_PortC);
				break;
			}
			case (PORTD):
			{
				PortLevelLoc = (u8)GPIODATA(GPIO_PortD);
				break;
			}
			case (PORTE):
			{
				PortLevelLoc = (u8)GPIODATA(GPIO_PortE);
				break;
			}
			case (PORTF):
			{
				PortLevelLoc = (u8)GPIODATA(GPIO_PortF);
				break;
			}
			default :
			{
				//do nothing because errors are covered in if condition
				break;
			}
		}
	}
	

	return PortLevelLoc;
	 
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port         PORTA-PORTF 
                   : PortLevel    0x00 - 0xFF
* \Parameters (out): None                                                      
* \Return value:   : void                                  
*******************************************************************************/
void DIO_WritePort(DIO_Port_Type PortCpy, DIO_PortLevel_Type PortLevelCpy)
{
	
	if(PortCpy<0 || PortCpy>5 ) //we dont check on portlevel because it's a u8
	{
		// Do nothing
		// in case of wrong arguments
	}
	else
	{
		switch(PortCpy)
		{
			case (PORTA) :
			{
				GPIODATA(GPIO_PortA) = PortLevelCpy;
				break;
			}
			case (PORTB):
			{
				GPIODATA(GPIO_PortB) = PortLevelCpy;
				break;
			}
			case (PORTC):
			{
				GPIODATA(GPIO_PortC) = PortLevelCpy;
				break;
			}
			case (PORTD):
			{
				GPIODATA(GPIO_PortD) = PortLevelCpy;
				break;
			}
			case (PORTE):
			{
				GPIODATA(GPIO_PortE) = PortLevelCpy;
				break;
			}
			case (PORTF):
			{
				GPIODATA(GPIO_PortF) = PortLevelCpy;
				break;
			}
			default :
			{
				//do nothing because errors are covered in if condition
				break;
			}
		}
	}
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortCpy         PORTA-PORTF 
					 PinCpy          DIO_PIN_x (x : 0 - 7) PIN number to flip
* \Parameters (out): None                                                      
* \Return value:   : DIO_Level_Type  DIO_LOW
*                                    DIO_HIGH                                  
*******************************************************************************/
DIO_Level_Type DIO_FlipChannel(DIO_Port_Type PortCpy, DIO_Channel_Type PinCpy)
{
	
	DIO_Level_Type LevelLoc = DIO_LOW;
	
	if(PinCpy<0 || PinCpy>7 || PortCpy<0 || PortCpy>5)
	{
		// Do nothing
		// in case of wrong arguments
	}
	else
	{
		switch(PortCpy)
		{
			case (PORTA) :
			{
				(GPIODATA(GPIO_PortA)) ^= (1<<PinCpy);
				LevelLoc = ((GPIODATA(GPIO_PortA)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTB):
			{
				(GPIODATA(GPIO_PortB)) ^= (1<<PinCpy);
				LevelLoc = ((GPIODATA(GPIO_PortB)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTC):
			{
				(GPIODATA(GPIO_PortC)) ^= (1<<PinCpy);
				LevelLoc = ((GPIODATA(GPIO_PortC)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTD):
			{
				(GPIODATA(GPIO_PortD)) ^= (1<<PinCpy);
				LevelLoc = ((GPIODATA(GPIO_PortD)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTE):
			{
				(GPIODATA(GPIO_PortE)) ^= (1<<PinCpy);
				LevelLoc = ((GPIODATA(GPIO_PortE)) >> PinCpy) & 0x01;
				break;
			}
			case (PORTF):
			{
				(GPIODATA(GPIO_PortF)) ^= (1<<PinCpy);
				LevelLoc = ((GPIODATA(GPIO_PortF)) >> PinCpy) & 0x01;
				break;
			}
			default :
			{
				//do nothing because errors are covered in if condition
				break;
			}
		}
	}

	return LevelLoc;
	
}

////////////////////////////////////////////////////







//I made it for testing the project 
void GPIO_VoidInit(void)
{
	RCGCGPIO = 0x00000020;          // enable PortF Clk, bit 5 "0b0010 0000"
	GPIODIR(GPIO_PortF) |= (1<<2);  //cofigure pin 2 in port F as Output/start from Pin 0
	GPIODEN(GPIO_PortF) |= (1<<2);  //enable pin 2 as DIO
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
