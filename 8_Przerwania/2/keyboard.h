typedef enum  {RELEASED_, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} KeyboardState;

void KeyboardInit(void);
KeyboardState eKeyboardRead(void);
