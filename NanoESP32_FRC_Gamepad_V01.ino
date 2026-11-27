//Joystick_ESP32S2 allows board with USB compatabilities to appear as a joystick or gamepad
#include <Joystick_ESP32S2.h>

//Creates 5-button HID gamepad with no axes or hats
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD, 
  5, 0,                 //5 buttons, 0 hat switches
  false, false, false,  //No X, Y, Z axes
  false, false, false,  //No Rx, Ry, Rz
  false, false,         //No rudder, throttle
  false, false, false); //No accelerator, brake, steering

const int buttonPins[5] = {D2, D3, D4, D5, D6};

void setup() {
  for (int i = 0; i < 5; i++) {
    //Internal pull=up keeps pin HIGH until button connects it to ground
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  Joystick.begin();
}

void loop() {
  for (int i = 0; i < 5; i++) {
    //Invert reading because LOW means pressed
    int buttonState = !digitalRead(buttonPins[i]);
    Joystick.setButton(i, buttonState);
  }
  delay(10); //10ms debounce
}
