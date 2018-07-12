/*
 * F0cks_LIS3DH.c
 *
 *  Created on: Jul 11, 2018
 *      Author: f0cks
 */

#include "F0cks_LIS3DH.h"

static void F0cks_LIS3DH_SPI_Read(uint8_t reg, uint8_t *pRxData);
static void F0cks_LIS3DH_SPI_Write(uint8_t reg, uint8_t pTxData);

int8_t F0cks_LIS3DH_Init( LIS3DH_HandleTypeDef *handler, LIS3DH_ConfigurationTypeDef config)
{
	int8_t error = 0;
	uint8_t lis3dhData = 0x00;

	F0cks_SPI_CS_State(CS_HIGH);

	/* The boot procedure is complete about 5 milliseconds after device power-up. */
	F0cks_Delay_Us(5000);

	/* Check ID and test SPI read */
	F0cks_LIS3DH_SPI_Read(LIS3DSH_WHO_AM_I_ADDR, &lis3dhData);
	if( lis3dhData != LIS3DSH_WHO_AM_I_DEF  )
	{
		error++;
	}

	/* Check SPI write */
	F0cks_LIS3DH_SPI_Write(LIS3DSH_ACT_DUR_ADDR, 0x42);
	F0cks_LIS3DH_SPI_Read(LIS3DSH_ACT_DUR_ADDR, &lis3dhData);
	if( lis3dhData != 0x42  )
	{
		error++;
	}
	F0cks_LIS3DH_SPI_Write(LIS3DSH_ACT_DUR_ADDR, LIS3DSH_ACT_DUR_DEF);
	F0cks_LIS3DH_SPI_Read(LIS3DSH_ACT_DUR_ADDR, &lis3dhData);
	if( lis3dhData != LIS3DSH_ACT_DUR_DEF  )
	{
		error++;
	}

	return error;
}

void F0cks_LIS3DH_Click_Enable(ClickTypeDef type)
{
	// enable all axes, low power mode 400Hz
	F0cks_LIS3DH_SPI_Write(LIS3DSH_CTRL_REG1_ADDR, 0x7F);

	// BDU enabled
  F0cks_LIS3DH_SPI_Write(LIS3DSH_CTRL_REG4_ADDR, 0x80);

  F0cks_LIS3DH_SPI_Write(LIS3DSH_CTRL_REG3_ADDR, 0x80); // turn on int1 click
  F0cks_LIS3DH_SPI_Write(LIS3DSH_CTRL_REG5_ADDR, 0x08); // latch interrupt on int1

  F0cks_LIS3DH_SPI_Write(LIS3DSH_CLICK_CFG_ADDR, type); // turn on all axes & tap

  F0cks_LIS3DH_SPI_Write(LIS3DSH_CLICK_THS_ADDR, 100); // arbitrary
  F0cks_LIS3DH_SPI_Write(LIS3DSH_TIME_LIMIT_ADDR, 10); // arbitrary
  F0cks_LIS3DH_SPI_Write(LIS3DSH_TIME_LATENCY_ADDR, 20); // arbitrary
  F0cks_LIS3DH_SPI_Write(LIS3DSH_TIME_WINDOW_ADDR, 75); // arbitrary
}

static void F0cks_LIS3DH_SPI_Read(uint8_t reg, uint8_t *pRxData)
{
	uint8_t aTxBuffer[2] = {(reg|0x80)&0xBF, 0x00};
	uint8_t aRxBuffer[2] = {0x00, 0x00};

	// CS Low
	F0cks_SPI_CS_State(CS_LOW);
	F0cks_Delay_Us(1);
	F0cks_SPI_TransmitReceive((uint8_t*)aTxBuffer, (uint8_t *)aRxBuffer, 2);
	// CS High
	F0cks_Delay_Us(1);
	F0cks_SPI_CS_State(CS_HIGH);
	*pRxData = aRxBuffer[1];
}

static void F0cks_LIS3DH_SPI_Write(uint8_t reg, uint8_t pTxData)
{
	uint8_t aTxBuffer[2] = {reg&0x3F, pTxData};
	uint8_t aRxBuffer[2] = {0x00, 0x00};

	// CS Low
	F0cks_SPI_CS_State(CS_LOW);
	F0cks_Delay_Us(1);
	F0cks_SPI_TransmitReceive((uint8_t*)aTxBuffer, (uint8_t *)aRxBuffer, 2);
	// CS High
	F0cks_Delay_Us(1);
	F0cks_SPI_CS_State(CS_HIGH);
}
