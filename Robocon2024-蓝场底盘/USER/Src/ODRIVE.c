/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include "ODRIVE.h"

/*
*********************************************************************************************************
*                                            	��������
*********************************************************************************************************
*/

ODRIVE_MOTOR ODRIVE[5];

/**
 * @brief ��odrive�������ָ������ٶ�.
 * 
 * @param[in] Motor_ID ��odrive�����õĵ��ID
 * @param[in] ExpSpeed �������ת�� ��λ��ת/s��
 * 
 * @return none
 * 
 * @note �ú���������odrive�������ָ������ٶȣ��ٶ�ֱ��ģʽ����
 *       can_id=������ID����5λ+0x00d���ٶ����룩
 *       �����ٶ��޷� -6000rpm~6000rpm
 *       Speed_float[0]:��������ٶ�
 *       Speed_float[1]:����ǰ��Ť��
 *       data[0]:�������(floatתuint8_t)�ٶȵ�4λ
 *       data[1]:�������(floatתuint8_t)�ٶȵ�3λ
 *       data[2]:�������(floatתuint8_t)�ٶȵ�2λ
 *       data[3]:�������(floatתuint8_t)�ٶȵ�1λ
 *       data[4]:����ǰ��(floatתuint8_t)Ť�ص�4λ
 *       data[5]:����ǰ��(floatתuint8_t)Ť�ص�3λ
 *       data[6]:����ǰ��(floatתuint8_t)Ť�ص�2λ
 *       data[7]:����ǰ��(floatתuint8_t)Ť�ص�1λ
 * 
 * @example
 *        ODRIVE_Motor_Speed_Ctrl(2, ODRIVE[2].set_input_vel.Input_Vel, ODRIVE[2].set_input_vel.Input_Torque_FF);
 */
void ODRIVE_Motor_Speed_Ctrl(uint8_t Motor_ID, float ExpSpeed, float ForwardTorque)
{
    static union
    {
        uint8_t Speed[8];
        float Speed_float[2];
    }Trans_Speed;
    uint32_t send_mail_box;
    CAN_TxHeaderTypeDef TxHeader;
    TxHeader.StdId = SET_INPUT_VEL + (Motor_ID<<5);
    TxHeader.IDE = CAN_ID_STD;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.DLC = 0x08;
    TxHeader.TransmitGlobalTime = DISABLE;
    uint8_t Txmsg[8] = {0};
    if(ExpSpeed > 100)
      ExpSpeed = 100.0;
    else if(ExpSpeed < -100)
      ExpSpeed = -100.0;
    Trans_Speed.Speed_float[0] = ExpSpeed;
    Trans_Speed.Speed_float[1] = ForwardTorque;
    Txmsg[0] = Trans_Speed.Speed[0];
    Txmsg[1] = Trans_Speed.Speed[1];
    Txmsg[2] = Trans_Speed.Speed[2];
    Txmsg[3] = Trans_Speed.Speed[3];
    Txmsg[4] = Trans_Speed.Speed[7];
    Txmsg[5] = Trans_Speed.Speed[6];
    Txmsg[6] = Trans_Speed.Speed[5];
    Txmsg[7] = Trans_Speed.Speed[4];
    if(HAL_CAN_AddTxMessage(&hcan1, &TxHeader, Txmsg, &send_mail_box)!=HAL_OK)
    {
        Error_Handler();
    }
}