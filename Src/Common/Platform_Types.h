/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Platform_Types.h
 *       Module:  -
 *
 *  Description:  Contains types that dependent on platform - CortexM4     
 *  
 *********************************************************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define WORD_LENGTH_BITS      32u
#define WORD_LENGTH_BYTES     4u
#define MSB_FIRST             0u    /* big endian bit ordering */
#define LSB_FIRST             1u    /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0u    /* big endian byte ordering */
#define LOW_BYTE_FIRST   1u    /* little endian byte ordering */

#ifndef TRUE
   #define TRUE   1u
#endif

#ifndef FALSE
   #define FALSE  0u
#endif

//#define ENABLE    1u
//#define DISABLE   0u

#define CPU_BIT_ORDER    LSB_FIRST        /*little endian bit ordering*/
#define CPU_BYTE_ORDER   LOW_BYTE_FIRST   /*little endian byte ordering*/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef unsigned char         boolean;       /*        TRUE .. FALSE           */


typedef unsigned char      u8;        /*           0 .. 255             */
typedef unsigned short int u16;       /*           0 .. 65535           */
typedef unsigned long int  u32;       /*           0 .. 4294967295      */

typedef signed char        s8;        /*        -128 .. +127            */
typedef signed short int   s16;       /*      -32768 .. +32767          */
typedef signed long int    s32;       /* -2147483648 .. +2147483647     */

typedef float              f32;
typedef double             f64;

#ifdef PLATFORM_SUPPORT_SINT64_UINT64 /*Valid only for gnu and C99 */
typedef signed    long long  s64;     /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  u64;     /*                    0 .. 18446744073709551615     */
#endif



 
#endif  /* PLATFORM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
