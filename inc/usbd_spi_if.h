/**
  ******************************************************************************
  * @file    usbd_mem_if_template.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   Header for usbd_mem_if_template.c file.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_IF_MAL_H
#define __SPI_IF_MAL_H

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"

#include "usbd_dfu_mal.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define SPI_START_ADD                 0x00000000 /* Dummy start address */
#define SPI_END_ADD                   (uint32_t)(SPI_START_ADD + (2048 * 1024)) /* Size = 2048KB */

#define SPI_IF_STRING                 "@sst25vf flash /0x00000000/01*002Kg,03*001Kg"

extern DFU_MAL_Prop_TypeDef DFU_Spi_cb;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __SPI_IF_MAL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
