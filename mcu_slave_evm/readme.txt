본 Readme.txt 파일은 MCU Slave EVM에 대한 설명을 주 목적으로 작성되었음.

Initial Release : 2024.05.17


1. 디렉토리 설명
uwb_ble_s32k144 : S32k144 Evaluation Board 기반으로 한 Slave Mcu 통합(uwb,ble,can통신) Program   
output : 실행 이미지

2. output 설명
   실행 파일 : uwb_ble_s32k144.elf / uwb_ble_s32k144.hex
   맵  파일 : uwb_ble_s32k144.map

3. 소스 생성자 : stsunlab sw2실 2팀 변승우 책임

4. 소스 관리자 : stsunlab sw2실 2팀 유승재 책임

5. 기타 링크 정보

6. TEST 설명
  - UWB MacRanging START/STOP
    . CAN message (RX) : L_BDC_FD_IAU_02_00ms
	  UWB_Ranging_Cmd_Val
      0 : START
      1 : STOP <- suspend
	  2 : STOP
	. CAN message (TX)
    . Initiator 부재로 거리 값 계산 못 하는 중
	  테스트 후 내용 업데이트 예정
	
  - UWB Reprogramming
    . CAN message (RX) : L_UWB_BLE_MST_FD_14_00ms
	  MST_OTA_CMD
	  4 : UWB Reprogramming
    . Flash 에 Write 한 후 Reprogramming
	. 제약 사항
      :	UWB에 들어 있는 프로그램이 Activate 동작이 되는 프로그램이어야 리프로그래밍 가능
	  : UWB SWUP 시 UWB Firmware(NCJ29D5_Flash_UciSwupComIntf.hex)가 Download 되어 있어야 합니다.
	  : UWB SWUP 시 UWB IC의 Flash memory에 key 값이 들어가 있어야 함 
	. MCU code 수정 후 재 다운로드 시 Flah에 Write되었던 이미지가 지워지는 현상이 있슴
	
  - BLE ADV ON/off
    . CAN message (RX) : L_BDC_FD_IAU_10_200ms
	  OPAdv_On_Cmd
	  0 : STOP
	  1 : StartEnable
	. CAN message (TX) : L_UWB_BLE_SLV_FD_20_200ms
	  SLV_BLE_Passive_ADV_State
	
  - BLE phone connect/disconnect
	. CAN message (TX) : L_UWB_BLE_SLV_FD_20_200ms
	  SLV_BLE_RSSI1
	  SLV_BLE_ConnectedDeviceInfo
	  
  - BLE Reprogramming
	. CAN message (RX) : L_UWB_BLE_MST_FD_14_00ms
	  MST_OTA_CMD
	  7 : BLE Reprogramming
	. 제약 사항
	  : BLE EVM 의 버튼 누른 상태에서 리부팅... (LED 켜질때까지 버튼 누른 상태 유지)
	  : Header file 로 다운로드
        Flash write는 UWB Reprogram에서 검증. BLE에서는 Header 로 만들어 다운로드 테스트
	  
  - Flash Write
    . 설명
	  : PC 프로그램과 UART 통신을 하여 MCU의 Flash에 Write
	  : UWB 만 다운로드 제작 되어 있음
  
7. TIPs
  - BLE와 연결
    . SPI 연결  : NXP          BLE
	            PTB17-CS3 -> DIO11
				PTB14-SCK -> DIO10
				PTB16-SDO -> DIO9
				PTD1-SDI  <- DIO8
				PTA3-RDY  <- DIO24
				PTA2-INT  <- DIO26
    . UART 연결 : NXP          BLE
	            PTA9-TX  ->  DIO2-RX
				PTA8-RX  <-  DIO3-TX

History
#20240517 Jeontaeheon
sorce code 수정 
	1. UWB SWUP 확인 
	2. UWB INIT, Ranging start 확인 
	3. MCU Flash memory write, read 확인 
	
	
* 

* 