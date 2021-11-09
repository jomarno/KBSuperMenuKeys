#include "Keyboard.h"

const int SuperL_Pin = 9;

bool SuperL_OldState = LOW;
bool SuperL_NewState = LOW;
bool SuperL_RisingEdge = LOW;
bool SuperL_FallingEdge = LOW;

void setup() {
  pinMode(SuperL_Pin, INPUT);

  Keyboard.begin();
}

void loop() {
  
  SuperL_NewState = digitalRead(SuperL_Pin);
  if (SuperL_NewState == HIGH && SuperL_OldState == LOW) {
    SuperL_RisingEdge = HIGH;
  } 
  else if (SuperL_NewState == LOW && SuperL_OldState == HIGH) {
    SuperL_FallingEdge = HIGH;
  } 
  else {
    SuperL_RisingEdge = LOW;
    SuperL_FallingEdge = LOW;
  }
  SuperL_OldState = SuperL_NewState;
  if (SuperL_RisingEdge) {Keyboard.press(KEY_LEFT_GUI);}
  if (SuperL_FallingEdge) {Keyboard.release(KEY_LEFT_GUI);}

}
