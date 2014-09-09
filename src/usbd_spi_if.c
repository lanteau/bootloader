/**
  ******************************************************************************
  * @file    usbd_mem_if_template.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   Specific media access Layer for a template memory. This file is 
             provided as template example showing how to implement a new memory
             interface based on pre-defined API.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "usbd_spi_if.h"
#include "usbd_dfu_mal.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
uint16_t SPI_If_Init(void);
uint16_t SPI_If_Erase (uint32_t SectorAddress);
uint16_t SPI_If_Write (uint32_t SectorAddress, uint32_t Len);
uint8_t *SPI_If_Read  (uint32_t SectorAddress, uint32_t Len);
uint16_t SPI_If_DeInit(void);
uint16_t SPI_If_CheckAdd(uint32_t SectorAddress);


/* Private variables ---------------------------------------------------------*/
DFU_MAL_Prop_TypeDef DFU_Spi_cb =
  {
    SPI_IF_STRING,
    SPI_If_Init,
    SPI_If_DeInit,
    SPI_If_Erase,
    SPI_If_Write,
    SPI_If_Read,
    SPI_If_CheckAdd,
    20, /* Erase Time in ms */
    30  /* Programming Time in ms */
  };
  
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  SPI_If_Init
  *         Memory initialization routine.
  * @param  None
  * @retval MAL_OK if operation is successeful, MAL_FAIL else.
  */
uint16_t SPI_If_Init(void)
{
  sFLASH_Init();
  return MAL_OK;
}

/**
  * @brief  SPI_If_DeInit
  *         Memory deinitialization routine.
  * @param  None
  * @retval MAL_OK if operation is successeful, MAL_FAIL else.
  */
uint16_t SPI_If_DeInit(void)
{ 
  return MAL_OK;
}

/**
  * @brief  SPI_If_Erase
  *         Erase sector.
  * @param  Add: Address of sector to be erased.
  * @retval MAL_OK if operation is successeful, MAL_FAIL else.
  */
uint16_t SPI_If_Erase(uint32_t SectorAddress)
{
  sFLASH_EraseSector(SectorAddress);
  return MAL_OK;
}

/**
  * @brief  SPI_If_Write
  *         Memory write routine.
  * @param  SectorAddress: Address to be written to.
  * @param  Len: Number of data to be written (in bytes).
  * @retval MAL_OK if operation is successeful, MAL_FAIL else.
  */
uint16_t SPI_If_Write(uint32_t SectorAddress, uint32_t DataLength)
{
  sFLASH_WriteBuffer(MAL_Buffer, SectorAddress, (uint16_t)DataLength);
  return MAL_OK;
}

/**
  * @brief  SPI_If_Read
  *         Memory read routine.
  * @param  SectorAddress: Address to be read from.
  * @param  Len: Number of data to be read (in bytes).
  * @retval Pointer to the phyisical address where data should be read.
  */
uint8_t *SPI_If_Read (uint32_t SectorAddress, uint32_t DataLength)
{
  /* Return a valid address to avoid HardFault */
  sFLASH_ReadBuffer(MAL_Buffer, SectorAddress, (uint16_t)DataLength);
  return  (uint8_t*)(MAL_Buffer); 
}

uint16_t SPI_If_CheckAdd(uint32_t SectorAddress)
{
  if ((SectorAddress >= SPI_START_ADD) && (SectorAddress < SPI_END_ADD))
  {
    return MAL_OK;
  }
  else
  {
    return MAL_FAIL;
  }
}