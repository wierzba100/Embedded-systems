__irq void UART0_Interrupt (void);
void UART_InitWithInt(unsigned int uiBaudRate);

//Odbiór i dekodowanie...
#define TERMINATOR '\0'
#define RECEIVER_SIZE 4
void Receiver_PutCharacterToBuffer(char cCharacter);
enum eReceiverStatus eReceiver_GetStatus(void);
void Receiver_GetStringCopy(char *ucDestination);
enum eReceiverStatus {EMPTY, READY, OVERFLOW};
struct ReceiverBuffer{
	char cData[RECEIVER_SIZE];
	unsigned char ucCharCtr;
	enum eReceiverStatus eStatus;
};
