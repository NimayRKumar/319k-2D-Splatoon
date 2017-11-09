// Sound.c
// Runs on any computer
// Sound assets based off the original Space Invaders 
// Import these constants into your SpaceInvaders.c for sounds!
// Jonathan Valvano
// November 17, 2014
#include <stdint.h>
#include "Sound.h"
#include "DAC.h"
#include "tm4c123gh6pm.h"

void Sound_Init(void){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF) | 0x40000000;
	NVIC_ST_CTRL_R = 0x07;
}

void Sound_Play(uint32_t period){
	NVIC_ST_RELOAD_R = period - 1;
}


void Game_Start(void){};
	
void Game_End(void){};
	
void Collide(void){};
	
void Toxic(void){};
