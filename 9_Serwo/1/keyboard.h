typedef enum {RELEASED, PRESSED} ButtonState;
typedef enum  {RELEASED_, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} KeyboardState;

void KeyboardInit(void);
ButtonState ReadButton1(void);
KeyboardState eKeyboardRead(void);
