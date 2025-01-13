/***********************************************************************************************************************
 * This file was generated by the S32 Configuration Tools. Any manual edits made to this file
 * will be overwritten if the respective S32 Configuration Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v7.0
processor: S32K144
package_id: S32K144_LQFP100
mcu_data: s32sdk_s32k1xx_rtm_401
processor_version: 0.0.0
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: a6d43dcb-893a-49cd-9d9d-0bb26ff0f05b
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Included files 
 ******************************************************************************/
#include "peripherals_edma_config_1.h"

/*******************************************************************************
 * edma_config_1 initialization code
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'edma_config_1'
- type: 'edma_config'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'edma'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'EDMA'
- config_sets:
  - edma_driver:
    - settings_edmaUserCfg:
      - userStateStruct: 'dmaController_State'
      - userCfgName: 'dmaController_InitConfig'
      - userCfgType: 'edma_user_config_t'
      - readOnly: 'true'
      - chnArbitration: 'EDMA_ARBITRATION_FIXED_PRIORITY'
      - haltOnError: 'false'
    - settings_array_edmaChCfg:
      - array_chCfgStructs:
        - 0:
          - chStateStructName: 'dmaControllerChn0_State'
          - chConfigName: 'dmaControllerChn0_Config'
          - chType: 'edma_channel_config_t'
          - virtCh: '0'
          - chPrio: 'EDMA_CHN_DEFAULT_PRIORITY'
          - chReq: 'EDMA_REQ_LPSPI0_RX'
          - chCallback: 'NULL'
          - chCallbackParam: 'NULL'
          - enableTrigger: 'false'
        - 1:
          - chStateStructName: 'dmaControllerChn1_State'
          - chConfigName: 'dmaControllerChn1_Config'
          - chType: 'edma_channel_config_t'
          - virtCh: '1'
          - chPrio: 'EDMA_CHN_DEFAULT_PRIORITY'
          - chReq: 'EDMA_REQ_LPSPI0_TX'
          - chCallback: 'NULL'
          - chCallbackParam: 'NULL'
          - enableTrigger: 'false'
        - 2:
          - chStateStructName: 'dmaControllerChn2_State'
          - chConfigName: 'dmaControllerChn2_Config'
          - chType: 'edma_channel_config_t'
          - virtCh: '2'
          - chPrio: 'EDMA_CHN_DEFAULT_PRIORITY'
          - chReq: 'EDMA_REQ_LPSPI1_RX'
          - chCallback: 'NULL'
          - chCallbackParam: 'NULL'
          - enableTrigger: 'false'
        - 3:
          - chStateStructName: 'dmaControllerChn3_State'
          - chConfigName: 'dmaControllerChn3_Config'
          - chType: 'edma_channel_config_t'
          - virtCh: '3'
          - chPrio: 'EDMA_CHN_DEFAULT_PRIORITY'
          - chReq: 'EDMA_REQ_LPSPI1_TX'
          - chCallback: 'NULL'
          - chCallbackParam: 'NULL'
          - enableTrigger: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 *
 */
edma_state_t dmaController_State;

edma_chn_state_t dmaControllerChn0_State;

edma_chn_state_t dmaControllerChn1_State;

edma_chn_state_t dmaControllerChn2_State;

edma_chn_state_t dmaControllerChn3_State;

edma_chn_state_t * const edmaChnStateArray[] = {
    &dmaControllerChn0_State,
    &dmaControllerChn1_State,
    &dmaControllerChn2_State,
    &dmaControllerChn3_State,
};

edma_channel_config_t dmaControllerChn0_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN0_NUMBER,
    .source = EDMA_REQ_LPSPI0_RX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false,
};

edma_channel_config_t dmaControllerChn1_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN1_NUMBER,
    .source = EDMA_REQ_LPSPI0_TX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false,
};

edma_channel_config_t dmaControllerChn2_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN2_NUMBER,
    .source = EDMA_REQ_LPSPI1_RX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false,
};

edma_channel_config_t dmaControllerChn3_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN3_NUMBER,
    .source = EDMA_REQ_LPSPI1_TX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false,
};

const edma_channel_config_t * const edmaChnConfigArray[] = {
    &dmaControllerChn0_Config,
    &dmaControllerChn1_Config,
    &dmaControllerChn2_Config,
    &dmaControllerChn3_Config,
};

const edma_user_config_t dmaController_InitConfig = {
    .chnArbitration = EDMA_ARBITRATION_FIXED_PRIORITY,
    .haltOnError = false
};


