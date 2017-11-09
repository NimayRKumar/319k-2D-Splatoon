	 int16_t RedCoord[2]; //[X,Y]
	 int8_t Red_UD;
	 int8_t Red_LR;
	 uint32_t Red_In[2];
	 
	 int16_t BlueCoord[2]; 
	 int8_t Blue_UD;
	 int8_t Blue_LR;
	 uint32_t Blue_In[2];
	 
	 uint16_t PCoord[2];
	 
	 uint8_t SaveX[100];
	 uint8_t SaveY[100];
	 uint8_t SaveIndex;
	 int8_t GameMap[128][160];
	 uint32_t RedScore;
	 uint32_t BlueScore;

	 uint8_t Collision;

		int8_t RedStatus;
		int8_t BlueStatus;
		uint8_t PDir[5];
		uint8_t SongState;
		uint8_t MultiIndex;

