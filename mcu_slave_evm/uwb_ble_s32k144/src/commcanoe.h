#ifndef _COMMCANOE_H_
#define _COMMCANOE_H_

#ifdef __cplusplus
extern "C"
{
#endif

extern void initCANOE(void);

extern void commCANOE(unsigned int nEvent);

extern void doBle2Can(unsigned char *pBuffer, int cbData);
extern void doUwb2Can(int nType, unsigned char *pBuffer, int cbData);

#ifdef __cplusplus
}
#endif

#endif
