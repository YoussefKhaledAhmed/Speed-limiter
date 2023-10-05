/**
  * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 * 
 * \brief: source file for RTE
 * \date: 4/10/2023
 */

#include "Rte_Types.h"
#include "Rte_Main.h"

#include "Rte_SWC_Driver.h"
#include "Rte_SWC_ECU.h"
#include "Rte_SWC_IoHwAbs.h"
#include "Rte_SWC_SpeedMg.h"
#include "Rte_SWC_SpeedSensor.h"
#include "Rte_SWC_VehicleMotor.h"



/**
 * Mode switch variables
 */

static uint8 SpeedCtrlMode_CurrentMode   =   RTE_MODE_SpeedCtrlMode_INIT;

/* Mode Disbaling Handling */
/* mode 1 for disabling auto mode when the current mode is INIT or MANUAL */
#define IsModeDisablingActive_0  \
(SpeedCtrlMode_CurrentMode == RTE_MODE_SeatCtrlMode_INIT || SpeedCtrlMode_CurrentMode == RTE_MODE_SeatCtrlMode_MANUAL)

/* mode 2 for disabling manual mode when the current mode is INIT or AUTO */
#define IsModeDisablingActive_1  \
(SpeedCtrlMode_CurrentMode == RTE_MODE_SeatCtrlMode_INIT || SpeedCtrlMode_CurrentMode == RTE_MODE_SeatCtrlMode_AUTO)


/**
 * 
 * Sender receriver variables
 *
 */
static Rte_SenderReceiverBuffersType Rte_SenderReceiverBuffers;

/**
 *
 * Sender receiver APIs  -  IntraECU
 *
 */

/* Driver sender receiver APIs */
Std_ReturnType Rte_Write_Driver_ppSpeedCtrlBtns_SpeedBtnState(Impl_MultiStateBtnType SpeedBtnState){
    Rte_SenderReceiverBuffers.SpeedBtnState = SpeedBtnState;
    return RTE_E_OK;
}

Std_ReturnType Rte_Read_Driver_rpSpeedCtrlData_Speed(Impl_SpeedType* Speed){
    *Speed = Rte_SenderReceiverBuffers.Speed;
    return RTE_E_OK;
}

Std_ReturnType Rte_Read_Driver_rpSpeedModeBtn_SpeedModeBtn(Impl_SpeedModeBtnType* SpeedModeBtn){
    *SpeedModeBtn = Rte_SenderReceiverBuffers.SpeedModeBtn;
    return RTE_E_OK;
}

/* Speed manager sender receiver APIs */
Std_ReturnType Rte_Read_SpeedMg_rpSpeedCtrlBtns_SpeedBtnState(Impl_MultiStateBtnType* SpeedBtnState){
    *SpeedBtnState = Rte_SenderReceiverBuffers.SpeedBtnState;
    return RTE_E_OK;
}



/**
 *
 * Client server APIs
 *
 */
/* SpeedMg client server APIs */
Std_ReturnType Rte_Call_SpeedMg_rpSpeedSensor_GetSpeed(Impl_SensorType* Speed){
    RE_SpeedSensor_GetPosition(Speed);
    return RTE_E_OK;
}

Std_ReturnType Rte_Call_SpeedMg_rpVehicleMotor_Limit(Impl_SpeedMotorType Speed){
    RE_VehicleMotor_Limit(Speed);
    return RTE_E_OK;
}

/* SpeedSensor client server APIs */
Std_ReturnType Rte_Call_SpeedSensor_rpIoGetSpeed_IoGet(Impl_IoSpeedSensorReadingType* Speed){
    RE_IoHwAbs_ECUGet_Speed(Speed);
    return RTE_E_OK;
}


/**
 *
 * Mode switch APIs
 *
 */

Std_ReturnType Rte_Switch_Driver_ppSpeedCtrlMode_SpeedCtrlMode(uint8 SpeedCtrlMode){
    SpeedCtrlMode_CurrentMode = SpeedCtrlMode;
    return RTE_E_OK;
}