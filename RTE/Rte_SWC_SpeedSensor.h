/**
 * \authors Youssef Khaled Ahmed (558)
 *          Mark Ehab Tawfik (201)
 *          Hazem Mohamed Ezzeldin (1297)
 *          Mahmoud Abdrabo Mohamed Abdrabo (267)
 * 
 * \brief: Rte header file for SpeedSensor SWC
 * \date: 10/4/2023
 */


#ifndef RTE_SWC_SPEEDSENSOR_H
#define RTE_SWC_SPEEDSENSOR_H

#include "Rte_SWC_SpeedSensor_Type.h"

/* RTE APIs prototype declaration */
Std_ReturnType Rte_Call_SpeedSensor_rpIoGetSpeed_IoGet(Impl_IoSpeedSensorReadingType* Speed);

#define Rte_Call_rpIoGetSpeed_IoGet     Rte_Call_SpeedSensor_rpIoGetSpeed_IoGet

/* Runnables prototype declaration */
void RE_SpeedSensor_GetPosition (Impl_SensorType* Speed);
void RE_SpeedSensor_GetSpeed (void);

#endif