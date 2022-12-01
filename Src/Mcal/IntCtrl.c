/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "IntCtrl.h"  /*  enclosed is cfg.h & types.h*/
#include "Mcu_Hw.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	u32 u32PRI_RegLoc=0, u32PRI_BitLoc=0, i = 0;
	
	u32 u32IntrRegLoc=0, u32IntrBitLoc=0;

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
	#if(INTCTRL_GRP_SUBGRP == GRP_3_SUBGRP_0_MODE)
		
		SCB_APINT->Reg = GRP_3_SUBGRP_0_MODE;
	
	#elif(INTCTRL_GRP_SUBGRP == GRP_2_SUBGRP_1_MODE)
		
		SCB_APINT->Reg = GRP_2_SUBGRP_1_MODE;
	
	#elif(INTCTRL_GRP_SUBGRP == GRP_1_SUBGRP_2_MODE)
		
		SCB_APINT->Reg = GRP_1_SUBGRP_2_MODE;
	
	#else // (Default value = GRP_0_SUBGRP_3_MODE)
	
		SCB_APINT->Reg = GRP_0_SUBGRP_3_MODE;
		
    #endif
    

	for(; i<INTCTRL_NB_OF_INTRS; i++)
	{                                                          //timer0 intr nb is 19

		u32PRI_RegLoc = (u32)((AStrCfg[i].NVIC_Intr_Perif)/4u);  // = 4 in our case
		u32PRI_BitLoc = (u32)((AStrCfg[i].NVIC_Intr_Perif)%4u);  // = 3 in our case
		
		u32IntrRegLoc = (u32)((AStrCfg[i].NVIC_Intr_Perif)/32u); // = 0
		u32IntrBitLoc = (u32)((AStrCfg[i].NVIC_Intr_Perif)%32u); // = 19
		
	/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
		
		         // PRI[4]    |= (0 << 29) : 3*8 + 5
		NVIC_PRI -> PRI[u32PRI_RegLoc] |= ( AStrCfg[i].IntCtrl_Grp_SubGrp << ((u32PRI_BitLoc*8u)+5u));
		
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
		
		if(AStrCfg[i].IntCtrl_Status == ENABLED)
		{
			        // EN[0]  = (  1 << 19  )
			NVIC_EN -> EN[u32IntrRegLoc] = ( 1u << u32IntrBitLoc );
		} 
		else
		{
			         // DIS[0]  = (  1 << 19  )
			NVIC_DIS -> DIS[u32IntrRegLoc] = ( 1u << u32IntrBitLoc );
		} 
	}
	
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
