/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* if these macros are changed after IntCtrl.c is build, undefined behavior would occur*/

#define INTCTRL_NB_OF_INTRS   1                     /* max no. of configured interrupts  */

/** options for INTCTRL_GRP_SUBGRP = GRP_3_SUBGRP_0_MODE
* 								 	 GRP_2_SUBGRP_1_MODE
* 								 	 GRP_1_SUBGRP_2_MODE
* 								 	 GRP_0_SUBGRP_3_MODE
*/
#define INTCTRL_GRP_SUBGRP    GRP_0_SUBGRP_3_MODE   /* 0 & 3 specifies no. of bits       */



 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
