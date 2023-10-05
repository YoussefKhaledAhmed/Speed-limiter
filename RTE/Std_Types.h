/**
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 * 
 * \brief: header file for standard types
 * \date: 10/3/2023
 */


#ifndef STD_TYPES_H
#define STD_TYPES_H


/* Platform Types */
typedef signed char         sint8;
typedef unsigned char       uint8;
typedef signed short        sint16;
typedef unsigned short      uint16;
typedef signed long         sint32;
typedef unsigned long       uint32;
typedef float               float32;
typedef double              float64;
typedef unsigned char       boolean;

/* AUTOSAR Types */
typedef uint8               Std_ReturnType;

/* AUTOSAR Defines */
#define TRUE      			(1U)
#define FALSE     			(0U)
#define E_NOT_OK    		(1U)
#define E_OK      			(0U)
#define STD_HIGH    		(1U)
#define STD_LOW     		(0U)
#define E_OK			    (0U)
#define E_NOK			    (1U)


#endif