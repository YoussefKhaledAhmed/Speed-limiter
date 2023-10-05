/**
 *
 * \file SWC_Driver_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_Driver
 *
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 *
 *
 */

#include "Rte_SWC_Driver.h"

/**
 *
 * Runnable RE_DriverInput_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_DriverInput_MainFunction_100ms
 *
 */

void RE_DriverInput_MainFunction (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType SpeedBtnState;
	Impl_SpeedType Speed;

	/* Data Receive Points */
	/* Speed received from another ECU */
	status = Rte_Read_rpSpeedCtrlData_Speed(&Speed);

	/* Data Send Points */
	/* State of Speed button where if + -> 0 (speed is limited by the value received 
	                                          from the other ECU) 
									  - -> 1 (Speed limiter is released and you can 
									          reach any speed)*/
	status = Rte_Write_ppSpeedCtrlBtns_SpeedBtnState(SpeedBtnState);

}


/**
 *
 * Runnable RE_DriverInput_SpeedModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSpeedModeBtn_SpeedModeBtn
 *
 */

void RE_DriverInput_SpeedModeChanged (void)
{
	Std_ReturnType status;
	Impl_SpeedModeBtnType SpeedModeBtn;
	uint8 SpeedCtrlMode = RTE_MODE_SpeedCtrlMode_INIT;

	/* Data Receive Points */
	/* here is the access point of this runnable where it receives SpeedModeBtn *
	 * and according to the received value it will change the mode.             */
	status = Rte_Read_rpSpeedModeBtn_SpeedModeBtn(&SpeedModeBtn);
	
	/* if the received mode button is 0 -> manual then assining the SpeedCtrlMode    *
	 * with a value that indicates the manual mode, also, checking the status of the *
	 * Api: Rte_Read_rpSpeedModeBtn_SpeedModeBtn.                                    */
	if(E_OK == status && MANAUL_MODE == SpeedModeBtn){
		SpeedCtrlMode = RTE_MODE_SpeedCtrlMode_MANUAL;
	}
	/* if the received mode button is 1 -> auto then assigning the SpeedCtrlMode *
	 * with a value that indicates the auto mode.                                */ 
	else if(E_OK == status && AUTO_MODE == SpeedModeBtn){
		SpeedCtrlMode = RTE_MODE_SpeedCtrlMode_AUTO;
	}
	else if(E_OK == status){
		/* the received value of the SpeedModeBtn is not of the configured values *
		 * then this is an error that should be handled.                          */
	}
	else{
		/* Error handling as the Api: Rte_Read_rpSpeedModeBtn_SpeedModeBtn failed. */
	}

	/* Mode Switch Points */
	/* checking if the SpeedCtrlMode is changed or not. */
	if(RTE_MODE_SpeedCtrlMode_INIT != SpeedCtrlMode){
		/* changing the mode according to the received SpeedModeBtn value. */
		status = Rte_Switch_ppSpeedCtrlMode_SpeedCtrlMode(SpeedCtrlMode);
	}
}

