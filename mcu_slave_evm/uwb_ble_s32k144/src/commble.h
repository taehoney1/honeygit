#ifndef _COMMBLE_H_
#define _COMMBLE_H_

#ifdef __cplusplus
extern "C"
{
#endif

extern void initBLE(void);

extern void commBLE(unsigned int nEvent);

extern void doCan2Ble(unsigned char nID, unsigned char *pBuffer, int cbData);


#ifdef __cplusplus
}
#endif

#endif
