/**
 *
 * \file SWC_IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_IoHwAbs
 *
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 *
 *
 */

#include "Rte_SWC_IoHwAbs.h"


/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Speed
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIoGetSpeed_IoGet
 *
 */

void RE_IoHwAbs_ECUGet_Speed (Impl_IoSpeedSensorReadingType* Speed)
{
	/* this runnable will serve the IoGet operation, so, the     *
	 * implenetation should provide speed in the passed pointer. */

	/* applying some logic and assigining the output in the speed pointer */
	/* *Speed = ....;          */
	Std_ReturnType status;
}

