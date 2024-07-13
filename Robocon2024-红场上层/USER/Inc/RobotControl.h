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

#define WHEELNUM        4
#define	WHEEL_R         0.07636 // radius(m)
#define CONTROL_MANUAL  0
#define CONTROL_WORLD   1
#define CONTROL_AUTO    2
#define ROBOT_SPEED_MAX 2.0 // m/s
#define ROBOT_SPEED_YAW_MAX 0.5 // rad/s

/*
*********************************************************************************************************
*                                             EXPORTED_TYPES
*********************************************************************************************************
*/
/**
 * @brief 位置信息
 * @param x x坐标,m
 * @param y y坐标,m
 * @param yaw 航向角,rad
 */
typedef struct
{
  float x; // m
  float y; // m
  float yaw; // degree(rad)
}Position; // unit: m, rad

/**
 * @brief 速度信息
 * @param Vx x方向速度,m/s
 * @param Vy y方向速度,m/s
 * @param Vw 航向角速度,rad/s
 * 
 */
typedef struct
{
  float Vx;
  float Vy;
  float Vw;
}Velocity; // unit: m/s, rad/s
/**
 * @brief 加速度信息
 * @param Ax x方向加速度,m/s^2
 * @param Ay y方向加速度,m/s^2
 * @param Aw 航向角加速度,rad/s^2
 * 
 */
typedef struct
{
  float Ax;
  float Ay;
  float Aw;
}Acceleration; // unit: m/s^2, rad/s^2
/**
 * @brief 机器人位置信息
 * @param position_now 当前位置信息
 * @param velocity_now 当前速度信息
 * @param position_exp 期望位置信息
 * @param velocity_exp 期望速度信息
 * @param position_last 上一次位置信息
 * @param velocity_last 上一次速度信息
 * @param acceleration_now 当前加速度信息
 * 
 */
typedef struct
{
  Position position_now;
  Velocity velocity_now;
  Position position_exp;
  Velocity velocity_exp;
  Position position_last;
  Velocity velocity_last;
  Acceleration acceleration_now;
}Robot_Pos;

/**
 * @brief 机器人信息
 * @param Robot_in_self 机器人在自身坐标系下的位置信息
 * @param Robot_in_world 机器人在世界坐标系下的位置信息
 * @param Robot_Contorl_Mode 机器人控制模式
 * @param Wheel_Speed 机器人轮子速度
 * 
 */
typedef struct
{
    Robot_Pos Robot_in_self;
    Robot_Pos Robot_in_world;
    uint8_t Robot_Contorl_Mode;
    float Wheel_Speed[WHEELNUM+1];
    float Robot_Speed_max;
}Robot_INFO;

/**
 * @brief 导航点
 * @param Pos_x 导航点X坐标
 * @param Pos_y 导航点Y坐标
 * @param theta 导航点航向角yow
 * @param w 导航点角速度
 * @param v 导航点线速度
 * @param tan_v 导航点速度方向
 * @param Projection 导航点在起始点到终止点连线上的投影
 * 
 */
typedef struct
{
  float Pos_x;
  float Pos_y;
  float v;
  float tan_v;
  float Projection;
}Nav_Point;

/*
*********************************************************************************************************
*                                          变量定义
*********************************************************************************************************
*/
extern Robot_INFO Robot;

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
//调用函数
void Robot_Velocity_To_Wheel_Speed(void);
void Wheel_Speed_To_Motor(void);
void Navigation (int step);
void Robot_Velocity_World_To_Self();

//功能函数
float Get_Projection(float x1, float y1, float x2, float y2);
float Get_Distance(float x1, float y1, float x2, float y2, float k);