


enum DetectirStat eReadDetector(void);
void DetectorInit(void);
void ServoInit(unsigned int);
void ServoGoTo(unsigned int);

enum ServoSate {CALLIB, IDLE, IN_PROGRESS};

struct Servo{
	enum ServoSate eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};
