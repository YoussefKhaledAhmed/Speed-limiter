/**
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 * 
 * \brief: Rte header file for SpeedMg SWC
 * Date: 10/3/2023
 */

#ifndef RTE_SWC_SPEEDMG_H
#define RTE_SWC_SPEEDMG_H

#include "Rte_SWC_SpeedMg_Type.h"

/* RTE APIs prototype declaration */
Std_ReturnType Rte_Read_SpeedMg_rpSpeedCtrlBtns_SpeedBtnState(Impl_MultiStateBtnType* SpeedBtnState);
Std_ReturnType Rte_Call_SpeedMg_rpSpeedSensor_GetSpeed(Impl_SensorType* Speed);
Std_ReturnType Rte_Call_SpeedMg_rpVehicleMotor_Limit(Impl_SpeedMotorType Speed);


#define Rte_Read_rpSpeedCtrlBtns_SpeedBtnState    Rte_Read_SpeedMg_rpSpeedCtrlBtns_SpeedBtnState
#define Rte_Call_rpSpeedSensor_GetSpeed           Rte_Call_SpeedMg_rpSpeedSensor_GetSpeed
#define Rte_Call_rpVehicleMotor_Limit             Rte_Call_SpeedMg_rpVehicleMotor_Limit

/* Runnables prototypes declaration */
void RE_SpeedMg_AutoSpeed (void);
void RE_SpeedMg_SetSpeed (void);

#endif