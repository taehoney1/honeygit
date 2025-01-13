#ifndef _UTIL_H_
#define _UTIL_H_

#ifdef __cplusplus
}
#endif

#include <stdint.h>

//	main.c	Functions
extern void setEvent(unsigned int nEvent);
extern void toggleLed();

//	utilities
extern void simpleCopy(unsigned char *pDest, unsigned char *pSrc, int cbData);
extern void simpleZero(unsigned char *pDest, int cbData);

extern unsigned int crc32(const char *s, int cbData);

//	queue
extern int queueOpen();
extern int queueClose(int nHandle);

extern int queuePutBuffer(int nHandle, unsigned char *pBuffer, int nCbData);
extern int queueGetBuffer(int nHandle, void *pBuffer, int nCbData, bool bPeek);

extern int queuePutData(int nHandle, unsigned char nChar);
extern int queueGetData(int nHandle, unsigned char *pChar, bool bPeek);

extern int queueGetLength(int nHandle);
extern int queueGetAvailableSpace(int nHandle);

//	block
extern int blockOpen();
extern int blockClose(int nHandle);

extern int blockPutMessage(int nHandle, int nCommand, unsigned char *pMessage, int nCbData);
extern int blockGetMessage(int nHandle, int *pCommand, unsigned char *pMessage, int nCbData);

extern int blockEmpty(int nHandle, int cbData);
extern int blockIsEmpty(int nHandle);

extern int blockGetLength(int nHandle);
extern int blockGetCount(int nHandle);
extern int blockGetAvailableSpace(int nHandle);

#ifdef __cplusplus
}
#endif

#endif
