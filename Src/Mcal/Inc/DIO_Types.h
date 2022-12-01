/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_Types
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	DIO_PIN_0 = 0,
	DIO_PIN_1 ,
	DIO_PIN_2 ,
	DIO_PIN_3 ,
	DIO_PIN_4 ,
	DIO_PIN_5 ,
	DIO_PIN_6 ,
	DIO_PIN_7 
	
}DIO_Channel_Type;

typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH
	
}DIO_Level_Type;

typedef enum
{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF

}DIO_Port_Type;


typedef u8 DIO_PortLevel_Type;

///////////////////////////////////////





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_Types.h
 *********************************************************************************************************************/