#include <Joystick.h>

#define OFFSET_BUTTON 2
#define OFFSET_DPAD 18

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_GAMEPAD,
  4,1,
  false, false, false, false, false, false,
  false, false, false, false, false);

void setup() {
  pinMode(2, INPUT_PULLUP);  // Button 1
  pinMode(3, INPUT_PULLUP);  // Button 2
  pinMode(4, INPUT_PULLUP);  // Button 3
  pinMode(5, INPUT_PULLUP);  // Button 3
   
  pinMode(18, INPUT_PULLUP); // D-pad Up
  pinMode(19, INPUT_PULLUP); // D-pad Right
  pinMode(20, INPUT_PULLUP); // D-pad Down
  pinMode(21, INPUT_PULLUP); // D-pad Left
  
  Serial.begin(9600); //シリアル通信のデータ転送レートを9600bpsで指定。bpsはビット/秒。

  Joystick.begin();
}

// Last state of the pins
int lastDpadState[2][4] = {{0,0,0,0}, {0,0,0,0}};
int lastButtonState[8] = {0,0,0,0,0,0,0,0};  // Button 1 - 8


void updateDpad(){
  bool valueChanged[2] = {false, false};
  int currentPin = 18;

  // Read pin values
  for (int hatSwitch = 0; hatSwitch < 2; hatSwitch++){
    for (int index = 0; index < 4; index++){
      int currentDpadState = !digitalRead(currentPin++);
      if (currentDpadState != lastDpadState[hatSwitch][index]){
        valueChanged[hatSwitch] = true;
        lastDpadState[hatSwitch][index] = currentDpadState;
      }
    }
  }

  for (int hatSwitch = 0; hatSwitch < 2; hatSwitch++)
  {
    if (valueChanged[hatSwitch]) {
      if ((lastDpadState[hatSwitch][0] == 0)
        && (lastDpadState[hatSwitch][1] == 0)
        && (lastDpadState[hatSwitch][2] == 0)
        && (lastDpadState[hatSwitch][3] == 0)) {
          Joystick.setHatSwitch(hatSwitch, -1);
      }
      if (lastDpadState[hatSwitch][0] == 1) {
        Joystick.setHatSwitch(hatSwitch, 0); // up
      }
      if (lastDpadState[hatSwitch][1] == 1) {
        Joystick.setHatSwitch(hatSwitch, 90); // right
      }
      if (lastDpadState[hatSwitch][2] == 1) {
        Joystick.setHatSwitch(hatSwitch, 180); // down
      }
      if (lastDpadState[hatSwitch][3] == 1) {
        Joystick.setHatSwitch(hatSwitch, 270);
      }
    } // if the value changed
  } // for each hat switch
}

void updateButton() {
  for (int i = 0; i <= 3; i++) {
    int currentButtonState = !digitalRead(i + OFFSET_BUTTON);
    if (currentButtonState != lastButtonState[i]) {
      Joystick.setButton(i, currentButtonState);
      lastButtonState[i] = currentButtonState;
    }
  }
}

void loop() {
  updateDpad();
  updateButton();
  delay(50);
}
