#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

typedef struct
{
	u8 SW_PORT     ;
	u8 SW_PIN      ;
	u8 SW_Type   ;
	u8 SW_PullType ;
}SW_t;

#define SW_u8PRESSED   10
#define SW_u8NPRESSED  20

#define SW_u8PullUP    2
#define SW_u8PullDOWN  4

#define SW_u8PER   5  /*For permanent switch*/
#define SW_u8TEM   6  /*For Temporary switch*/

u8 SW_u8Getstate(SW_t *SW_ptr);
#endif
