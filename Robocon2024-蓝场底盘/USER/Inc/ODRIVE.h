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
 * @brief ODRIVEŤ�����ýṹ�� 
 * @param Input_Torque          ����Ť�أ���λ:Nm
 * 
 */
typedef struct
{
    float Input_Torque;
}Set_Input_Torque;

/**
 * @brief ODRIVE�ٶ����ýṹ�� 
 * @param Input_Vel             ����ת�٣���λ:Ȧ/s
 * @param Input_Torque_FF       ǰ��Ť�أ���λ:Nm
 * 
 */
typedef struct
{
    float Input_Vel;
    float Input_Torque_FF;
}Set_Input_Vel;

/**
 * @brief ODRIVEλ�����ýṹ�� 
 * @param Input_Pos             ����λ�ã���λ:Ȧ
 * @param Input_Vel_FF          ǰ��ת�٣���λ:Ȧ/s
 * @param Input_Torque_FF       ǰ��Ť�أ���λ:Nm
 * 
 */
typedef struct
{
    float Input_Pos;
    int Input_Vel_FF;
    int Input_Torque_FF;
}Set_Input_Pos;

/**
 * @brief ODRIVE�޷����ýṹ�� 
 * @param Velocity_Limit        ת���޷�����λ:Ȧ/s
 * @param Current_Limit         �����޷�����λ:A
 * 
 */
typedef struct
{
    float Velocity_Limit;
    float Current_Limit;
}Set_Limits;

/**
 * @brief ODRIVEŤ�����ýṹ�� 
 * @param set_input_pos         λ������
 * @param set_input_vel         ת������
 * @param set_input_torque      Ť������
 * @param set_limits            �޷�����
 * 
 */
typedef struct
{
    Set_Input_Torque set_input_torque;
    Set_Input_Vel    set_input_vel;
    Set_Input_Pos    set_input_pos;
    Set_Limits       set_limits;
}ODRIVE_MOTOR;


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

#define SET_INPUT_TORQUE 0X00e
#define SET_INPUT_VEL    0x00d
#define SET_INPUT_POS    0x00c
#define SET_LIMITS       0x00f


/*
*********************************************************************************************************
*                                              ��������
*********************************************************************************************************
*/

void ODRIVE_Motor_Speed_Ctrl(uint8_t Motor_ID, float ExpSpeed, float ForwardTorque);


/*
*********************************************************************************************************
*                                              ��������
*********************************************************************************************************
*/


extern ODRIVE_MOTOR ODRIVE[5];


