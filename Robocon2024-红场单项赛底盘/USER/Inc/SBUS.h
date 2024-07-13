/**
 * @file SBUS.h
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
*                                               CONSTANTS
*********************************************************************************************************
*/
#define SBUS_Receive_length 72

#define SBUS_Head  0x48
#define SBUS_Head_  0x44
#define SBUS_Tail  0x4c
#define SBUS_Tail_   0x54
/// SBUS缓存区大小
#define SBUS_BUFFER_SIZE 50
/// SBUS数据包大小
#define SBUS_FRAME_SIZE 25
/// SBUS帧头
#define SBUS_FRAME_HEADER 0x0F
/// SBUS帧尾
#define SBUS_FRAME_FOOTER 0x00


/*
*********************************************************************************************************
*                                             EXPORTED_TYPES
*********************************************************************************************************
*/

/**
 * @brief SBUS状态结构体
 * 
 */
typedef struct 
{
    uint16_t CH1;//通道1数值
	uint16_t CH2;//通道2数值
	uint16_t CH3;//通道3数值
	uint16_t CH4;//通道4数值
	uint16_t CH5;//通道5数值
	uint16_t CH6;//通道6数值
    uint16_t CH7;//通道7数值
    uint16_t CH8;//通道8数值
    uint16_t CH9;//通道9数值
    uint16_t CH10;//通道10数值
    uint16_t CH11;//通道11数值
    uint16_t CH12;//通道12数值
    uint16_t CH13;//通道13数值
    uint16_t CH14;//通道14数值
    uint16_t CH15;//通道15数值
    uint16_t CH16;//通道16数值
	uint8_t ConnectState;//遥控器与接收器连接状态 0=未连接，1-255=正常连接
}SBUS_CH;




/*
*********************************************************************************************************
*                                          变量实现
*********************************************************************************************************
*/

extern SBUS_CH SBUS;
extern uint8_t SBUS_RX_BUF[SBUS_BUFFER_SIZE];
extern uint8_t SBUS_Receive[SBUS_Receive_length];
extern uint8_t SBUS_ch ; // 接受值
extern uint8_t NewControllerData[12];
extern uint8_t NewControllerData_pre[12];

/// @brief SBUS接收标志
extern  uint8_t SBUS_flag ; // 接收标志
/// @brief SBUS接收状态机
extern  uint8_t SBUS_step ; // 状态机
/// @brief SBUS接收计数
extern  uint8_t SBUS_count ; // 计数

extern uint8_t Laser_index;

extern uint8_t pos[10];

extern uint8_t lllflag;

extern int WorkChannel;


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void SBUS_Analyze(void);
void SBUS_Receive_Analyze(void);


int8_t SBUS_Analyse_Switch(int16_t SBUS_CHANNEL_VALUE);
float SBUS_Analyse_Percent(int16_t SBUS_CHANNEL_VALUE);
float Laser_Data_Analyse(float data, float max_available_distance, float min_available_distance);
