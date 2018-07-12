/*
 * F0cks_LIS3DH.h
 *
 *  Created on: Jul 11, 2018
 *      Author: f0cks
 */

#ifndef F0CKS_LIS3DH_H_
#define F0CKS_LIS3DH_H_

#include "stdint.h"

/* Registers */
#define LIS3DSH_STATUS_REG_AUX_ADDR  0x07
#define LIS3DSH_OUT_ADC1_L_ADDR      0x08
#define LIS3DSH_OUT_ADC1_H_ADDR      0x09
#define LIS3DSH_OUT_ADC2_L_ADDR      0x0A
#define LIS3DSH_OUT_ADC2_H_ADDR      0x0B
#define LIS3DSH_OUT_ADC3_L_ADDR      0x0C
#define LIS3DSH_OUT_ADC3_H_ADDR      0x0D
#define LIS3DSH_WHO_AM_I_ADDR        0x0F
#define LIS3DSH_CTRL_REG0_ADDR       0x1E
#define LIS3DSH_TEMP_CFG_REG_ADDR    0x1F
#define LIS3DSH_CTRL_REG1_ADDR       0x20
#define LIS3DSH_CTRL_REG2_ADDR       0x21
#define LIS3DSH_CTRL_REG3_ADDR       0x22
#define LIS3DSH_CTRL_REG4_ADDR       0x23
#define LIS3DSH_CTRL_REG5_ADDR       0x24
#define LIS3DSH_CTRL_REG6_ADDR       0x25
#define LIS3DSH_REFERENCE_ADDR       0x26
#define LIS3DSH_STATUS_REG_ADDR      0x27
#define LIS3DSH_OUT_X_L_ADDR         0x28
#define LIS3DSH_OUT_X_H_ADDR         0x29
#define LIS3DSH_OUT_Y_L_ADDR         0x2A
#define LIS3DSH_OUT_Y_H_ADDR         0x2B
#define LIS3DSH_OUT_Z_L_ADDR         0x2C
#define LIS3DSH_OUT_Z_H_ADDR         0x2D
#define LIS3DSH_FIFO_CTRL_REG_ADDR   0x2E
#define LIS3DSH_FIFO_SRC_REG_ADDR    0x2F
#define LIS3DSH_INT1_CFG_ADDR        0x30
#define LIS3DSH_INT1_SRC_ADDR        0x31
#define LIS3DSH_INT1_THS_ADDR        0x32
#define LIS3DSH_INT1_DURATION_ADDR   0x33
#define LIS3DSH_INT2_CFG_ADDR        0x34
#define LIS3DSH_INT2_SRC_ADDR        0x35
#define LIS3DSH_INT2_THS_ADDR        0x36
#define LIS3DSH_INT2_DURATION_ADDR   0x37
#define LIS3DSH_CLICK_CFG_ADDR       0x38
#define LIS3DSH_CLICK_SRC_ADDR       0x39
#define LIS3DSH_CLICK_THS_ADDR       0x3A
#define LIS3DSH_TIME_LIMIT_ADDR      0x3B
#define LIS3DSH_TIME_LATENCY_ADDR    0x3C
#define LIS3DSH_TIME_WINDOW_ADDR     0x3D
#define LIS3DSH_ACT_THS_ADDR         0x3E
#define LIS3DSH_ACT_DUR_ADDR         0x3F

/* Default register values */
#define LIS3DSH_WHO_AM_I_DEF         0x33
#define LIS3DSH_CTRL_REG0_DEF        0x00
#define LIS3DSH_TEMP_CFG_REG_DEF     0x00
#define LIS3DSH_CTRL_REG1_DEF        0x07
#define LIS3DSH_CTRL_REG2_DEF        0x00
#define LIS3DSH_CTRL_REG3_DEF        0x00
#define LIS3DSH_CTRL_REG4_DEF        0x00
#define LIS3DSH_CTRL_REG5_DEF        0x00
#define LIS3DSH_CTRL_REG6_DEF        0x00
#define LIS3DSH_REFERENCE_DEF        0x00
#define LIS3DSH_FIFO_CTRL_REG_DEF    0x00
#define LIS3DSH_INT1_CFG_DEF         0x00
#define LIS3DSH_INT1_THS_DEF         0x00
#define LIS3DSH_INT1_DURATION_DEF    0x00
#define LIS3DSH_INT2_CFG_DEF         0x00
#define LIS3DSH_INT2_THS_DEF         0x00
#define LIS3DSH_INT2_DURATION_DEF    0x00
#define LIS3DSH_CLICK_CFG_DEF        0x00
#define LIS3DSH_CLICK_THS_DEF        0x00
#define LIS3DSH_TIME_LIMIT_DEF       0x00
#define LIS3DSH_TIME_LATENCY_DEF     0x00
#define LIS3DSH_TIME_WINDOW_DEF      0x00
#define LIS3DSH_ACT_THS_DEF          0x00
#define LIS3DSH_ACT_DUR_DEF          0x00

typedef enum
{
  CS_LOW = 0U,
  CS_HIGH
} CS_PinState;

typedef enum
{
  SINGLE = 0x15,
	DOUBLE = 0x2A,
	BOTH   = 0x3F
} ClickTypeDef;

typedef struct
{

}LIS3DH_ConfigurationTypeDef;

typedef struct
{


}LIS3DH_HandleTypeDef;

int8_t F0cks_LIS3DH_Init( LIS3DH_HandleTypeDef *handler, LIS3DH_ConfigurationTypeDef config);
void F0cks_LIS3DH_Click_Enable(ClickTypeDef type);

/* Functions to implement */
void F0cks_SPI_TransmitReceive(uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);
void F0cks_SPI_CS_State(CS_PinState state);
void F0cks_Delay_Us(uint32_t delay);

#endif /* F0CKS_LIS3DH_H_ */
