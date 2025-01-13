#ifndef _COMMUWB_H_
#define _COMMUWB_H_

#ifdef __cplusplus
extern "C"
{
#endif

extern void initUWB(void);

extern void commUWB(unsigned int nEvent);

extern void doCan2Uwb(unsigned char nID, unsigned char *pBuffer, int cbData);

#ifdef __cplusplus
}
#endif

#endif
