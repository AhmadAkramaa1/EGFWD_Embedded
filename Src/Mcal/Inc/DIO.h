/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_Types.h"


 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
DIO_Level_Type DIO_ReadChannel(DIO_Port_Type PortCpy, DIO_Channel_Type PinCpy);



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
void DIO_WriteChannel(DIO_Port_Type PortCpy, DIO_Channel_Type PinCpy, DIO_Level_Type LevelCpy);



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
DIO_PortLevel_Type DIO_ReadPort(DIO_Port_Type PortCpy);



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
void DIO_WritePort(DIO_Port_Type PortCpy, DIO_PortLevel_Type PortLevelCpy);



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
DIO_Level_Type DIO_FlipChannel(DIO_Port_Type PortCpy, DIO_Channel_Type PinCpy);
 
 
 
 
 ////////////////////////////////////////////////////////
 
 
 
 
 
 
 
 
 
 
 
 
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
void GPIO_VoidInit(void);
 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
