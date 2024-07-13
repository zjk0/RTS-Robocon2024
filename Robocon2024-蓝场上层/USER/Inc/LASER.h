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

#define LASER_BUFFER_SIZE 22
#define LASER_FRAME_SIZE 11


/*
*********************************************************************************************************
*                                             EXPORTED_TYPES
*********************************************************************************************************
*/
extern uint8_t LASER_RX_BUF[4][LASER_BUFFER_SIZE];
extern float LASER_distance[4];
void LASER_Analyze(uint8_t laser_num);