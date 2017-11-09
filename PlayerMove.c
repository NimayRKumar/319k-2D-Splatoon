#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "SpaceInvaders.h"
#include "ST7735.h"

uint32_t Delay=1000;
uint32_t RedDivider=5;
uint32_t BlueDivider=5;
uint8_t BoolRed;
uint8_t BoolBlue;
int8_t PDirection=1;
const unsigned short black[] = {
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843, 0x0843,
};




void PlayerDelay(uint8_t ToxicEncountered, uint8_t SpeedBoost){
	
	if(ToxicEncountered==1)
		RedDivider=9;

	else if (ToxicEncountered==2)
		BlueDivider=9;
	
	else if(ToxicEncountered==3)
		RedDivider=BlueDivider=9;
	
	else 
		RedDivider=BlueDivider=2;
	
	
	if(RedStatus==5)
		RedDivider=2;
	
	if(BlueStatus==5)
		BlueDivider=2;
	
	

}

void MovementDelay(void){
	//delays movement so that sprites move at reasonable pace
	for(int32_t Slow=100000; Slow!=0; Slow--){}
	
}


int8_t PlayerRedY(uint32_t dataY){	//returns 1,0,-1 depending on Red UD movement
	
	if(dataY>=3800)
		return 1;
	
	else if(dataY<=100)
		return -1;
	
	else
		return 0;
}

int8_t PlayerRedX(uint32_t dataX){	//returns 1,0,-1 depending on Red LR movement
	
	if(dataX<=100)
		return -1;
	
	else if(dataX>=3000)
		return 1;
	
	else
		return 0;
}

int8_t PlayerBlueY(uint32_t dataY){
	
	if(dataY>=3800)
		return 1;
	
	else if(dataY<=100)
		return -1;
	
	else
		return 0;
}

int8_t PlayerBlueX(uint32_t dataX){
	
	if(dataX>=3800)
		return -1;
		
	else if(dataX<=100)
		return 1;
	
	else
		return 0;
}

void PlayerRedMove(void){

	if((Delay%RedDivider==0)||(RedStatus==5)){
		
			if((Red_UD==1)&&(RedCoord[1]!=160))
				RedCoord[1]++;
			
			else if((Red_UD==-1)&&(RedCoord[1]!=18))
				RedCoord[1]--;
			
			if((Red_LR==1)&&(RedCoord[0]!=108))
				RedCoord[0]++;
			
			else if((Red_LR==-1)&&(RedCoord[0]!=0))
				RedCoord[0]--;
		}

	}

void PlayerBlueMove(void){
	
	if((Delay%BlueDivider==0)||(BlueStatus==5)){	
	
			if((Blue_UD==1)&&(BlueCoord[1]!=160))
				BlueCoord[1]++;
			
			else if((Blue_UD==-1) && (BlueCoord[1]!=18))
				BlueCoord[1]--;
			
			if((Blue_LR==-1)&&(BlueCoord[0]!=108))
				BlueCoord[0]++;
			
			else if((Blue_LR==1)&&(BlueCoord[0]!=0))
				BlueCoord[0]--;
		}
}

void CollisionReset(void){
	
	
	
	if(Collision==1){
		
		ST7735_DrawBitmap(RedCoord[0],RedCoord[1],black, 20, 20);
		ST7735_DrawBitmap(BlueCoord[0],BlueCoord[1],black, 20, 20);
		
		RedCoord[0]=0;
		RedCoord[1]=19;
		BlueCoord[0]=108;
		BlueCoord[1]=19;	
		RedStatus=1;
		BlueStatus=2;
		
	}
	
	
	if(Collision==2){
		RedStatus=5;
		
	}
	
	 if(Collision==3){
		BlueStatus=5;
		
	 }
	 
	 
	Collision=0;
	}

	







void UpdateMap(int8_t RedStatus, int8_t BlueStatus){
	//update RED
	for(int8_t XI=19; XI!=-1; XI--){
				
			for(int8_t YI=19; YI!=-1; YI--){
				
				

					if((GameMap[RedCoord[0]+XI][RedCoord[1]-YI]!=1)&&(GameMap[RedCoord[0]+XI][RedCoord[1]-YI]!=-1)&&(RedStatus!=-1)&&(GameMap[RedCoord[0]+XI][RedCoord[1]-YI]!=-1))
							RedScore++;
					
					
					if(RedStatus==-1)
						GameMap[RedCoord[0]+XI][RedCoord[1]-YI]=-1;
					else
						GameMap[RedCoord[0]+XI][RedCoord[1]-YI]=1;
					
				}
			}
	
	//update BLUE
  for(int8_t XI=19; XI!=-1; XI--){
		
			for(int8_t YI=19; YI!=-1; YI--){
				
					if((GameMap[BlueCoord[0]+XI][BlueCoord[1]-YI]!=2)&&(GameMap[BlueCoord[0]+XI][BlueCoord[1]-YI]!=-1) &&(BlueStatus!=-1)&&((GameMap[BlueCoord[0]+XI][BlueCoord[1]-YI]!=-1)))
							BlueScore++;
					
					if(BlueStatus==-1)
						GameMap[BlueCoord[0]+XI][BlueCoord[1]-YI]=-1;
					
					else
						GameMap[BlueCoord[0]+XI][BlueCoord[1]-YI]=2;
					

				}
			}
	
	if(PCoord[1]==160){
		if(PCoord[0]==108)
		PDirection=-1;
		
		if(PCoord[0]==0)
		PDirection=1;

		if(PDirection==1)
			PCoord[0]++;
		if(PDirection==-1)
			PCoord[0]--;
	}
	

	
	else
		PCoord[1]++;
	
	
	
		
	
			
	
}

uint8_t CheckToxic(int8_t RedStatus, int8_t BlueStatus){	//0 if no toxic encountered; 1 if RED is in toxic; 2 if BLUE is in toxic

	for(int8_t XI=19; XI!=-1; XI--){
		
		for(int8_t YI=19; YI!=-1; YI--){
			
			BoolRed=(GameMap[RedCoord[0]+XI][RedCoord[1]-YI]==-1)&&(RedStatus!=-1);
			BoolBlue=(GameMap[BlueCoord[0]+XI][BlueCoord[1]-YI]==-1)&&(BlueStatus!=-1);
			
			if(BoolRed&&BoolBlue)
				return 3;
			
			if(BoolRed)
				return 1;	//red in toxic
			
			if(BoolBlue)
				return 2; //blue in toxic
			
		}
	}

		return 0; //none in toxic
}

uint8_t CollideDetect(void){	//0 if no collision, 1 if player collision, 2 if RED powers up, 3 is BLUE powers UP
	
	if(((RedCoord[1])>=(BlueCoord[1]-19))&&
		 ((BlueCoord[0])<=(RedCoord[0])+19)&&
		 (BlueCoord[0]+19>=RedCoord[0]+19) &&
		  ((BlueCoord[1]>=(RedCoord[1]-19))
			)){
				BlueScore /=2;
			RedScore /=2;
				
			return 1;
			}
	
	
	if((RedCoord[0]>=(BlueCoord[0])&&
		(RedCoord[0]<=((BlueCoord[0]+19))) &&
	  (RedCoord[1]>=((BlueCoord[1]-19))) &&
		(BlueCoord[1]>=(RedCoord[1]-19)))){
			BlueScore /=2;
			RedScore /=2;
			
			return 1;
			}
		
		if((RedCoord[0]>=(PCoord[0])&&
		(RedCoord[0]<=((PCoord[0]+19))) &&
	  (RedCoord[1]>=((PCoord[1]-19))) &&
		(PCoord[1]>=(RedCoord[1]-19)))){
			
			ST7735_DrawBitmap(PCoord[0],PCoord[1],black, 20, 20);
			PCoord[0]=200;
			PCoord[1]=200;
			return 2;
			}	
		
		if(((BlueCoord[1])>=(PCoord[1]-19))&&
		 ((PCoord[0])<=(BlueCoord[0])+19)&&
		 (PCoord[0]+19>=BlueCoord[0]+19) &&
		  ((PCoord[1]>=(BlueCoord[1]-19))
			)){
				ST7735_DrawBitmap(PCoord[0],PCoord[1],black, 20, 20);
				PCoord[0]=200;
			PCoord[1]=200;
				
			return 2;
			}	
			
			if((BlueCoord[0]>=(PCoord[0])&&
		(BlueCoord[0]<=((PCoord[0]+19))) &&
	  (BlueCoord[1]>=((PCoord[1]-19))) &&
		(PCoord[1]>=(BlueCoord[1]-19)))){
			ST7735_DrawBitmap(PCoord[0],PCoord[1],black, 20, 20);
			PCoord[0]=200;
			PCoord[1]=200;
			
			return 3;
			}	
		if(((BlueCoord[1])>=(PCoord[1]-19))&&
		 ((PCoord[0])<=(BlueCoord[0])+19)&&
		 (PCoord[0]+19>=BlueCoord[0]+19) &&
		  ((PCoord[1]>=(BlueCoord[1]-19))
			)){
				ST7735_DrawBitmap(PCoord[0],PCoord[1],black, 20, 20);
			PCoord[0]=200;
			PCoord[1]=200;
				
			return 3;
			}
			
			
	return 0;
}














































