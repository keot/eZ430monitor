#include  "cc430x613x.h" 
#include <string.h> 

void main(void)
{ 
	unsigned char * lcdmem; 
	
	// Clear entire display memory 
	LCDBMEMCTL |= LCDCLRBM + LCDCLRM; 
	
	// LCD_FREQ = ACLK/16/8 = 256Hz 
	// Frame frequency = 256Hz/4 = 64Hz, LCD mux 4, LCD on 
	LCDBCTL0 = (LCDDIV0 + LCDDIV1 + LCDDIV2 + LCDDIV3) | (LCDPRE0 + LCDPRE1) | LCD4MUX | LCDON; 
	
	// LCB_BLK_FREQ = ACLK/8/4096 = 1Hz 
	LCDBBLKCTL = LCDBLKPRE0 | LCDBLKPRE1 | LCDBLKDIV0 | LCDBLKDIV1 | LCDBLKDIV2 | LCDBLKMOD0; 
	
	// I/O to COM outputs 
	P5SEL |= (BIT5 | BIT6 | BIT7); P5DIR |= (BIT5 | BIT6 | BIT7); 
	
	// Activate LCD output 
	LCDBPCTL0 = 0xFFFF;  
	
	// Select LCD segments S0-S15 
	LCDBPCTL1 = 0x00FF;  
	
	// Select LCD segments S16-S22 
	// LCD_B Base Address is 0A00H page 30 y in SALS554 document 

	// Show message
	lcdmem  = (unsigned char *)0x0A21; *lcdmem = (unsigned char)(*lcdmem | 0x67); // K
	lcdmem  = (unsigned char *)0x0A22; *lcdmem = (unsigned char)(*lcdmem | 0x97); // E
	lcdmem  = (unsigned char *)0x0A23; *lcdmem = (unsigned char)(*lcdmem | 0xF5); // O
	lcdmem  = (unsigned char *)0x0A25; *lcdmem = (unsigned char)(*lcdmem | 0x70); // T
}
