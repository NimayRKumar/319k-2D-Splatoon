// put implementations for functions, explain how it works
// put your names here, date
#include <stdint.h>
#include "tm4c123gh6pm.h"

const unsigned char Flute[64] = {  	
  6,7,9,9,10,11,12,13,13,14,15,	
  15,15,15,15,14,13,13,12,11,10,9,	
  8,7,7,6,6,5,5,5,5,4,	
  4,4,4,4,4,3,3,3,3,3,	
  2,2,1,1,1,1,0,0,0,0,	
  0,0,1,1,1,2,2,3,3,4,4,5	
}; 

void DAC_Out(uint8_t data){
	GPIO_PORTB_DATA_R = Flute[data];
}
