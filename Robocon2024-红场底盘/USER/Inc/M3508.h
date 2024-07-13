/**
 * @file M3508.h
 * @author 陶子辰 (2405973406@qq.com)
 * @brief 
 * @version 1.0
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#pragma once
#include "main.h"

/*
*********************************************************************************************************
*                                             EXPORTED_TYPES
*********************************************************************************************************
*/

/**
 * @brief M3508电机参数
 * 
 */
typedef struct
{
    int16_t CurSpeed;      // (RPM, RPM, 20/16384 A)
    int16_t ExpSpeed;
    int16_t ActCurrent;
    int16_t OutCurrent;
    int16_t CurPosition;
    int16_t ExpPosition;
    int64_t Temparg;//编码器直接读出的角度
    int32_t Disparg;
    int32_t Exparg;//期望角度 157293.5=360
    int16_t Expvel;//位置环控制中的期望最大速度
    int32_t postemp;
    int16_t posdel;
    int16_t Posflag;
}M3508_MOTOR;


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              函数声明
*********************************************************************************************************
*/

void M3508_Analyze(uint32_t M3508_StdId,uint8_t* MotorData);
void M3508_Motor_Send_Current(void);
void M3508_Motor_Send_Current_h(void);
void M3508_Motor_Speed_Ctrl(void);
void M3508_Motor_Position_Ctrl(void);


/*
*********************************************************************************************************
*                                              变量声明
*********************************************************************************************************
*/


extern M3508_MOTOR M3508[9];


