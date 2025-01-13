/*
 * flash_memory_drive.h
 *
 *  Created on: 2024. 4. 15.
 *      Author: C0808
 */

#ifndef FLASH_MEMORY_DRIVE_H_
#define FLASH_MEMORY_DRIVE_H_

#include "flash_driver.h"
#include "interrupt_manager.h"



extern void flash_erase(const flash_ssd_config_t * pSSDConfig, uint32_t address, uint32_t size);
extern void flash_write(const flash_ssd_config_t * pSSDConfig, uint32_t address, uint32_t size, const uint8_t * sourceBuffer);



#endif /* FLASH_MEMORY_DRIVE_H_ */
