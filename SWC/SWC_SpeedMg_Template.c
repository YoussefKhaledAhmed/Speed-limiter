/**
 *
 * \file SWC_SpeedMg_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SpeedMg
 *
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 *
 *
 */

#include "Rte_SWC_SpeedMg.h"


/**
 *
 * Runnable RE_SpeedMg_AutoSpeed
 *
 * Triggered By:
 *  - SwcModeSwitchEventImpl.MSE_rpSpeedCtrlMode_Mode_Auto_ON_ENTRY
 *  - TimingEventImpl.TE_RE_SpeedMg_AutoSpeed_200ms
 *
 */

void RE_SpeedMg_AutoSpeed (void)
{
	Std_ReturnType status;
	Impl_SensorType Speed;

	/* Server Call Points */
	status = Rte_Call_rpSpeedSensor_GetSpeed(&Speed);
	
}


/**
 *
 * Runnable RE_SpeedMg_SetSpeed
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSpeedCtrlBtns_DE_SpeedBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSpeedCtrlMode_Mode_Manual_ON_ENTRY
 *
 */

void RE_SpeedMg_SetSpeed (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType SpeedBtnState;
	Impl_SpeedMotorType Speed;

	/* Data Receive Points */
	status = Rte_Read_rpSpeedCtrlBtns_SpeedBtnState(&SpeedBtnState);
	
	/* if the API Rte_Read_rpSpeedCtrlBtns_SpeedBtnState returns E_OK then we will  *
	 * proceed.                                                                     */
	if(E_OK == status){
		/* if the received speed button state is 0 then the speed should be limited */
		if(LIMIT_ON == SpeedBtnState){
			/* Server Call Points */
			/* requesting "Limit" operation from the RTE, where this operation is     *
		     * responsible for limiting speed but its implementation should be in the *
			 * Software component: VehicleMotor                                       */
			status = Rte_Call_rpVehicleMotor_Limit(Speed);
		} else{
			/* no limit is set the speed can reach any value according to the mechanical *
			 * limits.                                                                   */
		}
	} else{
		/* Error handling */
	}
	
}