/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  18/9/2020    *******/
/******* SWC    :    CLCD       *******/
/******* Version:    1.0        *******/
/**************************************/
#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

#define CLCD_CLEAR_DISPLAY      0b00000001
#define CLCD_RETURN_HOME        0b00000010
#define CLCD_DISPLAY_ON         0b00001100
#define CLCD_DISPLAY_OFF        0b00001000
#define CLCD_CURSOR_ENABLE      0b00001010
#define CLCD_CURSOR_DISABLE     0b00001000
#define CLCD_CURSOR_BLINKING    0b00001001
#define CLCD_CURSOR_UNBLINKING  0b00001000

void CLCD_VidSendCommand(u8 Copy_u8command);
void CLCD_VidSendData(u8 Copy_u8Data);
void CLCD_VidInit(void);
void CLCD_VidSendString(const s8*Copy_pcString);
void CLCD_VidWriteSpecialChar(u8* Copy_pu8Pattern,u8 Copy_u8PatternNo,u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_VidWriteNum(s32 Copy_s32Number);
#endif
