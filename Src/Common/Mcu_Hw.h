/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef union 
{
    u32 Reg;
	struct 
	{
		u32 B0  :1;
		u32 B1  :1;
		u32 B2  :1;
		u32 B3  :1;
		u32 B4  :1;
		u32 B5  :1;
		u32 B6  :1;
		u32 B7  :1;
		u32 B8  :1;
		u32 B9  :1;
		u32 B10 :1;
		u32 B11 :1;
		u32 B12 :1;
		u32 B13 :1;
		u32 B14 :1;
		u32 B15 :1;
		u32 B16 :1;
		u32 B17 :1;
		u32 B18 :1;
		u32 B19 :1;
		u32 B20 :1;
		u32 B21 :1;
		u32 B22 :1;
		u32 B23 :1;
		u32 B24 :1;
		u32 B25 :1;
		u32 B26 :1;
		u32 B27 :1;
		u32 B28 :1;
		u32 B29 :1;
		u32 B30 :1;
		u32 B31 :1;		
	};
}U32_Type; 

typedef union 
{
    u8 Reg;
	struct 
	{
		u32 B0  :1;
		u32 B1  :1;
		u32 B2  :1;
		u32 B3  :1;
		u32 B4  :1;
		u32 B5  :1;
		u32 B6  :1;
		u32 B7  :1;		
	};
}U8_Type;

typedef struct
{
	u32 EN[5];
}NVIC_EN_Type;

typedef struct
{
	u32 DIS[5];
}NVIC_DIS_Type;

typedef struct
{
	u32 PEND[5];
}NVIC_PEND_Type;

typedef struct
{
	u32 UNPEND[5];
}NVIC_UNPEND_Type;

typedef struct
{
	u32 ACTIVE[5];
}NVIC_ACTIVE_Type;

typedef struct
{
	u32 PRI[35];
}NVIC_PRI_Type;


typedef union 
{
    u32 Reg;
	struct 
	{
		u32 VECTRESET       :1;
		u32 VECTCLRACT      :1;
		u32 SYSRESREQ       :1;
		u32                 :5;
		u32 PRIGROUP        :3;
		u32                 :4;
		u32 ENDIANESS       :1;		        
		u32 VECTKEY         :16;
	};
}SCB_APINT_Type;

typedef union 
{
    u32 Reg;
	struct 
	{
		u32 VECACT   :8;
		u32          :3;
		u32 RETBASE  :1;
		u32 VECPEND  :8;
		u32          :2;
		u32 ISRPEND  :1;
		u32 ISRPRE   :1;
		
		u32          :1;
		u32 PENDSTCLR:1;
		u32 PENDSTSET:1;
		u32 UNPENDSV :1;
		u32 PENDSV   :1;
		u32          :2;
		u32 NMISET   :1; 

	};
}SCB_INTCTRL_Type;

typedef union
{
	u32 Reg;
	struct
	{
		u32 ENABLE  :1;
		u32 INTEN   :1;
		u32 CLK_SRC :1;
		u32         :13;
		u32 COUNT   :1;
		u32         :15;
	};
}SYSTICK_STCTRL_Type;
typedef union
{
	u32 Reg;
	struct
	{
		u32 RELOAD  :24;
		u32         :8;
	};
}SYSTICK_STRELOAD_Type;
typedef union
{
	u32 Reg;
	struct
	{
		u32 CURRENT :24;
		u32         :8;
	};
}SYSTICK_STCURRENT_Type;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEXM4_PERIF_BASE_ADDRESS             0xE000E000
 
 /******************************************
 *  SYSTICK REGISTERS
 ******************************************/

#define SYSTICK_STCTRL        ((volatile SYSTICK_STCTRL_Type *)   (CORTEXM4_PERIF_BASE_ADDRESS+0x010))
#define SYSTICK_STRELOAD      ((volatile SYSTICK_STRELOAD_Type *) (CORTEXM4_PERIF_BASE_ADDRESS+0x014))
#define SYSTICK_STCURRENT     ((volatile SYSTICK_STCURRENT_Type *)(CORTEXM4_PERIF_BASE_ADDRESS+0x018))

 /******************************************
 *  INTERRUPT REGISTERS
 ******************************************/
 
#define NVIC_EN               ((volatile NVIC_EN_Type *)      (CORTEXM4_PERIF_BASE_ADDRESS+0x100))
#define NVIC_DIS              ((volatile NVIC_DIS_Type *)     (CORTEXM4_PERIF_BASE_ADDRESS+0x180))
#define NVIC_PEND             ((volatile NVIC_PEND_Type *)    (CORTEXM4_PERIF_BASE_ADDRESS+0x200))
#define NVIC_UNPEND           ((volatile NVIC_UNPEND_Type *)  (CORTEXM4_PERIF_BASE_ADDRESS+0x280))
#define NVIC_ACTIVE           ((volatile NVIC_ACTIVE_Type *)  (CORTEXM4_PERIF_BASE_ADDRESS+0x300))
#define NVIC_PRI              ((volatile NVIC_PRI_Type *)     (CORTEXM4_PERIF_BASE_ADDRESS+0x400))

#define NVIC_SWTRIG           ((volatile U32_Type *)          (CORTEXM4_PERIF_BASE_ADDRESS+0xF00))
														      
#define SCB_APINT             ((volatile SCB_APINT_Type *)    (CORTEXM4_PERIF_BASE_ADDRESS+0xD0C))
#define SCB_INTCTRL           ((volatile SCB_INTCTRL_Type *)  (CORTEXM4_PERIF_BASE_ADDRESS+0xD04))






/*******************************************
 *  GPIO REGISTERS
 ******************************************/
// #define GPIO_PortA  ( 0x40058000 ) //AHB
// #define GPIO_PortB  ( 0x40059000 )
// #define GPIO_PortC  ( 0x4005A000 )  Future Work : make configurations to use both AHB &APB
// #define GPIO_PortD  ( 0x4005B000 )
// #define GPIO_PortE  ( 0x4005C000 )
// #define GPIO_PortF  ( 0x4005D000 )
                           




						   
#define GPIO_PortA  ( 0x40004000 )  //APB
#define GPIO_PortB  ( 0x40005000 )
#define GPIO_PortC  ( 0x40006000 )
#define GPIO_PortD  ( 0x40007000 )
#define GPIO_PortE  ( 0x40024000 )
#define GPIO_PortF  ( 0x40025000 )

//	PORT can be the base address of any port
//  UNMask all 8 bits by doing & with 3FC

#define GPIODATA(PORT)          (*((volatile u32 *)( (PORT) + 0x3FC )))
#define GPIODIR(PORT)           (*((volatile u32 *)( (PORT) + 0x400 )))
#define GPIOIS(PORT)            (*((volatile u32 *)( (PORT) + 0x404 )))
#define GPIOIBE(PORT)           (*((volatile u32 *)( (PORT) + 0x408 )))
#define GPIOIEV(PORT)           (*((volatile u32 *)( (PORT) + 0x40C )))
#define GPIOIM(PORT)            (*((volatile u32 *)( (PORT) + 0x410 )))
#define GPIORIS(PORT)           (*((volatile u32 *)( (PORT) + 0x414 )))
#define GPIOMIS(PORT)           (*((volatile u32 *)( (PORT) + 0x418 )))
#define GPIOICR(PORT)           (*((volatile u32 *)( (PORT) + 0x41C )))
#define GPIOAFSEL(PORT)         (*((volatile u32 *)( (PORT) + 0x420 )))
#define GPIODR2R(PORT)          (*((volatile u32 *)( (PORT) + 0x500 )))
#define GPIODR4R(PORT)          (*((volatile u32 *)( (PORT) + 0x504 )))        
#define GPIODR8R(PORT)          (*((volatile u32 *)( (PORT) + 0x508 )))
#define GPIOODR(PORT)           (*((volatile u32 *)( (PORT) + 0x50C )))
#define GPIOPUR(PORT)           (*((volatile u32 *)( (PORT) + 0x510 )))
#define GPIOPDR(PORT)           (*((volatile u32 *)( (PORT) + 0x514 )))
#define GPIOSLR(PORT)           (*((volatile u32 *)( (PORT) + 0x518 )))
#define GPIODEN(PORT)           (*((volatile u32 *)( (PORT) + 0x51C )))
#define GPIOLOCK(PORT)          (*((volatile u32 *)( (PORT) + 0x520 )))
#define GPIOCR(PORT)            (*((volatile u32 *)( (PORT) + 0x524 )))
#define GPIOAMSEL(PORT)         (*((volatile u32 *)( (PORT) + 0x528 )))
#define GPIOPCTL(PORT)          (*((volatile u32 *)( (PORT) + 0x52C )))
#define GPIOADCCTL(PORT)        (*((volatile u32 *)( (PORT) + 0x530 )))
#define GPIODMACTL(PORT)        (*((volatile u32 *)( (PORT) + 0x534 )))
#define GPIOPeriphID4(PORT)     (*((volatile u32 *)( (PORT) + 0xFD0 )))
#define GPIOPeriphID5(PORT)     (*((volatile u32 *)( (PORT) + 0xFD4 )))
#define GPIOPeriphID6(PORT)     (*((volatile u32 *)( (PORT) + 0xFD8 )))
#define GPIOPeriphID7(PORT)     (*((volatile u32 *)( (PORT) + 0xFDC )))
#define GPIOPeriphID0(PORT)     (*((volatile u32 *)( (PORT) + 0xFE0 )))
#define GPIOPeriphID1(PORT)     (*((volatile u32 *)( (PORT) + 0xFE4 )))
#define GPIOPeriphID2(PORT)     (*((volatile u32 *)( (PORT) + 0xFE8 )))
#define GPIOPeriphID3(PORT)     (*((volatile u32 *)( (PORT) + 0xFEC )))
#define GPIOPCellID0(PORT)      (*((volatile u32 *)( (PORT) + 0xFF0 )))
#define GPIOPCellID1(PORT)      (*((volatile u32 *)( (PORT) + 0xFF4 )))
#define GPIOPCellID2(PORT)      (*((volatile u32 *)( (PORT) + 0xFF8 )))
#define GPIOPCellID3(PORT)      (*((volatile u32 *)( (PORT) + 0xFFC )))


#define RCGCGPIO     (*((volatile u32 *)( 0x400FE608 )))
#define GPIOHBCTL    (*((volatile u32 *)( 0x400FE06C )))  //default value is APB. donot change for now

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
