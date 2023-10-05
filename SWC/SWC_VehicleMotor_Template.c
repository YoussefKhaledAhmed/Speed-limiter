/**
 *
 * \file SWC_VehicleMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_VehicleMotor
 *
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 *
 *
 */

#include "Rte_SWC_VehicleMotor.h"


/**
 *
 * Runnable RE_VehicleMotor_Limit
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppVehicleMotor_Limit
 *
 */

void RE_VehicleMotor_Limit (Impl_SpeedMotorType Speed)
{
	/* this runnable serves the "Limit" operation where the implementaion *
	 * should be to limit the speed of the motor.                         */
	Std_ReturnType status;
}

