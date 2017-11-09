




void PlayerDelay(uint8_t ToxicEncountered, uint8_t SpeedBoost);
void MovementDelay(void);

int8_t PlayerRedY(uint32_t dataY);
int8_t PlayerRedX(uint32_t dataX);

int8_t PlayerBlueY(uint32_t dataY);
int8_t PlayerBlueX(uint32_t dataX);

uint8_t CheckToxic(int8_t RedStatus, int8_t BlueStatus);

void PlayerRedMove(void);
void PlayerBlueMove(void);

void CollisionReset(void);

void SaveCoord(void);

void UpdateMap(int8_t RedStatus, int8_t BlueStatus);

void CheckCollision(void);
uint8_t CollideDetect(void);
