/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  5/9/2020     *******/
/******* SWC    :  7Segment     *******/
/******* Version:    1.0        *******/
/**************************************/
#ifndef SEG_INTERFACE_H
#define SEG_INTERFACE_H

#define Anode     0
#define Cathode   1

#define EN 1
#define UNEN 0

typedef struct
{
	u8 COM_Type;
	u8 SSD_PORT;
	u8 ENABLEPort;
	u8 ENABLEPin;
	u8 DOTEnable;
}SSD_t;

/*Numbers : [0-9] only */
u8 SSD_u8SetNum(u8 Copy_u8Number ,SSD_t *SSD_ptr);
void SSD_VidEnable(SSD_t *SSD_ptr);
void SSD_vidDisable(SSD_t *SSD_ptr);

#endif
