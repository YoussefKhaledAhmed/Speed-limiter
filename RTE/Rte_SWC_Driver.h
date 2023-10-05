/**
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 * 
 * \brief: Rte header file for driver SWC
 * \date: 10/4/2023
 */

#ifndef RTE_SWC_DRIVER_H
#define RTE_SWC_DRIVER_H

#include "Rte_SWC_Driver_Type.h"

/* RTE APIs prototype declaration */
Std_ReturnType Rte_Write_Driver_ppSpeedCtrlBtns_SpeedBtnState(Impl_MultiStateBtnType SpeedBtnState);
Std_ReturnType Rte_Read_Driver_rpSpeedCtrlData_Speed(Impl_SpeedType* Speed);
Std_ReturnType Rte_Read_Driver_rpSpeedModeBtn_SpeedModeBtn(Impl_SpeedModeBtnType* SpeedModeBtn);
Std_ReturnType Rte_Switch_Driver_ppSpeedCtrlMode_SpeedCtrlMode(uint8 SpeedCtrlMode);


#define Rte_Write_ppSpeedCtrlBtns_SpeedBtnState     Rte_Write_Driver_ppSpeedCtrlBtns_SpeedBtnState
#define Rte_Read_rpSpeedCtrlData_Speed              Rte_Read_Driver_rpSpeedCtrlData_Speed
#define Rte_Read_rpSpeedModeBtn_SpeedModeBtn        Rte_Read_Driver_rpSpeedModeBtn_SpeedModeBtn
#define Rte_Switch_ppSpeedCtrlMode_SpeedCtrlMode    Rte_Switch_Driver_ppSpeedCtrlMode_SpeedCtrlMode


/* Runnables prototype declaration */
void RE_DriverInput_MainFunction (void);
void RE_DriverInput_SpeedModeChanged (void);

#endif