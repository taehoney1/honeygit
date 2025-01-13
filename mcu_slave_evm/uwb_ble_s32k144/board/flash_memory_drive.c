/*
 * flash_memorry_drive.c
 *
 *  Created on: 2024. 4. 15.
 *      Author: C0808
 */


#include "flash_memory_drive.h"


void flash_erase(const flash_ssd_config_t * pSSDConfig, uint32_t address, uint32_t size)
{
	 status_t ret;
	 ret = FLASH_DRV_EraseSector(&pSSDConfig, address, size);
	 DEV_ASSERT(STATUS_SUCCESS == ret);

	 ret = FLASH_DRV_VerifySection(&pSSDConfig, address, size / FTFx_DPHRASE_SIZE, 1u);
	 DEV_ASSERT(STATUS_SUCCESS == ret);
}


void flash_write(const flash_ssd_config_t * pSSDConfig, uint32_t address, uint32_t size, const uint8_t * sourceBuffer)
{
	 uint32_t failAddr;
	 status_t ret;
	  ret = FLASH_DRV_Program(&pSSDConfig, address, size, sourceBuffer);
	  DEV_ASSERT(STATUS_SUCCESS == ret);

	  /* Verify the program operation at margin level value of 1, user margin */
	  ret = FLASH_DRV_ProgramCheck(&pSSDConfig, address, size, sourceBuffer, &failAddr, 1u);
	  DEV_ASSERT(STATUS_SUCCESS == ret);
}


