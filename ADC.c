// ADC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Last Modified: 4/14/2016
// Student names: Nimay Kumar
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#include "tm4c123gh6pm.h"


// ADC initialization function 
// Input: none
// Output: none
void ADC0_Init(void){
	volatile uint8_t togle;
	SYSCTL_RCGCADC_R |= 0x01;
	SYSCTL_RCGCGPIO_R |= 0x10;
	togle=SYSCTL_RCGCGPIO_R;
	togle=SYSCTL_RCGCGPIO_R;
	
	GPIO_PORTE_DIR_R &= ~0x0C;
	GPIO_PORTE_AFSEL_R |= 0x0C;
	GPIO_PORTE_DEN_R &= ~0x0C;
		
	GPIO_PORTE_AMSEL_R |= 0x0C;
		
	ADC0_PC_R &= ~0xF;	
	ADC0_PC_R |= 0x01;
	ADC0_SSPRI_R = 0x1023;
	ADC0_ACTSS_R &= ~ 0x08;
	ADC0_EMUX_R &= ~0xF000;
	ADC0_SSMUX3_R = 0x0010;	//adds channel # after clearing
	ADC0_SSCTL3_R =0x06;
	ADC0_IM_R &= ~0x08;
	ADC0_ACTSS_R |= 0x08;
}


void ADC89_Init(void){
	 volatile uint32_t delay;                         
//  SYSCTL_RCGC0_R |= 0x00010000; // 1) activate ADC0 (legacy code)
  SYSCTL_RCGCADC_R |= 0x00000001; // 1) activate ADC0
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4; // 1) activate clock for Port E
  delay = SYSCTL_RCGCGPIO_R;      // 2) allow time for clock to stabilize
  delay = SYSCTL_RCGCGPIO_R;
  GPIO_PORTE_DIR_R &= ~0x30;      // 3) make PE4 PE5 input
  GPIO_PORTE_AFSEL_R |= 0x30;     // 4) enable alternate function on PE4 PE5
  GPIO_PORTE_DEN_R &= ~0x30;      // 5) disable digital I/O on PE4 PE5
                                  // 5a) configure PE4 as ?? (skip this line because PCTL is for digital only)
  GPIO_PORTE_PCTL_R = GPIO_PORTE_PCTL_R&0xFF00FFFF;
  GPIO_PORTE_AMSEL_R |= 0x30;     // 6) enable analog functionality on PE4 PE5
  ADC0_PC_R &= ~0xF;              // 8) clear max sample rate field
  ADC0_PC_R |= 0x1;               //    configure for 125K samples/sec
  ADC0_SSPRI_R = 0x1023;          // 9) Sequencer 3 is lowest priority
  ADC0_ACTSS_R &= ~0x0004;        // 10) disable sample sequencer 2
  ADC0_EMUX_R &= ~0x0F00;         // 11) seq2 is software trigger
  ADC0_SSMUX2_R = 0x0089;         // 12) set channels for SS2
  ADC0_SSCTL2_R = 0x0060;         // 13) no TS0 D0 IE0 END0 TS1 D1, yes IE1 END1
  ADC0_IM_R &= ~0x0004;           // 14) disable SS2 interrupts
  ADC0_ACTSS_R |= 0x0004;
}

//------------ADC_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
void ADC0_In(uint32_t Data1[2]){  //UP down for RED

	ADC0_PSSI_R = 0x08;
	while((ADC0_RIS_R&0x08)==0){}
		
	Data1[1] = (ADC0_SSFIFO3_R&0x0FFF);//Blue_In[PE2, PE3] = Blue_In[UD, LR]
	Data1[0] = (ADC1_SSFIFO3_R&0x0FFF);
		
	ADC0_ISC_R = 0x08; //ack
	 
}

void ADC89_In(uint32_t Data2[2]){	//Left right for RED
	
	ADC0_PSSI_R = 0x0004;
	while((ADC0_RIS_R&0x04)==0){}
		
	Data2[0]=(ADC0_SSFIFO2_R&0x0FFF); //Red_In[PE4,PE5] = Red_In[UD,LR]
	Data2[1]=(ADC0_SSFIFO2_R&0x0FFF);
		
	ADC0_ISC_R = 0x0004;	//ack
	
}


