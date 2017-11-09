#include <stdint.h>
#include "ST7735.h"
#include "Sound.h"

#define C    2389   // 1046.5 Hz
#define B    2531   // 987.8 Hz
#define BF   2681   // 932.3 Hz
#define A    2841   // 880 Hz
#define AF   3010   // 830.6 Hz
#define G    3189   // 784 Hz
#define GF  3378   // 740 Hz
#define F   3579   // 698.5 Hz
#define E   3792   // 659.3 Hz
#define EF  4018   // 622.3 Hz
#define D   4257   // 587.3 Hz
#define DF  4510   // 554.4 Hz
#define C4  4778 
#define B3  5062
#define BF3 5362
#define A3  5682
#define AF3	6020
#define G3	6378
uint8_t MultIndex=0;
	uint8_t SongDela=9;
	
	
typedef const struct Sng{
		uint8_t size;
		uint8_t Repeat;
		uint16_t notes[18];
	}Stype;

Stype Sng ={20, 0, {C4, C4, E, E, G, G, A, A, GF, GF, D, D, E, E, AF, AF, B, B}};

uint32_t CheckOver(uint32_t GameTimer, uint32_t RedScore, uint32_t BlueScore){

	GameTimer--;
	RedScore = RedScore/100 + 4;
		BlueScore = BlueScore/100;
	
	if(GameTimer==0){
		
		
		
		
		ST7735_FillScreen(0);
		ST7735_SetCursor(0,2);
		ST7735_OutString("Red Score:");
		ST7735_OutUDec(RedScore);
		ST7735_SetCursor(0,4);
		ST7735_OutString("Blue Score:");
		ST7735_OutUDec(BlueScore);
		
		ST7735_SetCursor(0,6);
		
		if(RedScore>BlueScore)
			ST7735_OutString("Player Red Wins!");
		
		else if(BlueScore>RedScore)
			ST7735_OutString("Player Blue Wins!");
		
		else
			ST7735_OutString("TIE GAME");
		
		
		
		
		while(1){}
	}
	
	return(GameTimer);
}

