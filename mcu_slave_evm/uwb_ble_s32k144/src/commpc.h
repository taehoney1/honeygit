#ifndef _COMMPC_H_
#define _COMMPC_H_

#ifdef __cplusplus
extern "C"
{
#endif

extern void initPC(void);

extern void commPC(unsigned int nEvent);

extern void callbackCCIF(void);

extern void doSendCommand(unsigned char *pBuffer, int cbData);
extern void doSendDebug(unsigned char *pBuffer, int cbData);

#ifdef __cplusplus
}
#endif

#endif
