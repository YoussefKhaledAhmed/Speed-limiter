/**
 *
 * \file SWC_SpeedSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SpeedSensor
 *
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 *
 *
 */

#include "Rte_SWC_SpeedSensor.h"


/**
 *
 * Runnable RE_SpeedSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSpeedSensor_GetSpeed
 *
 */

void RE_SpeedSensor_GetPosition (Impl_SensorType* Speed)
{
	/* this is the runnable that will serve the GetSpeed operation      *
	 * so, the implenetation should provide speed in the passed pointer */
	
	/* applying some logic and assigining the output in the speed pointer */
	/* *Speed = ....;          */
	Std_ReturnType status;
}


/**
 *
 * Runnable RE_SpeedSensor_GetSpeed
 *
 * Triggered By:
 *
 */

void RE_SpeedSensor_GetSpeed (void)
{
	Std_ReturnType status;
	Impl_IoSpeedSensorReadingType Speed;

	/* Server Call Points */
	/* requsting the "IoGet" operation from the RTE, where the operation is        *
	 * responsible for getting the speed and the implementation of this operation  *
	 * should be in Software component: IoHwAbs_ECUGet_Speed                       */
	status = Rte_Call_rpIoGetSpeed_IoGet(&Speed);
}

