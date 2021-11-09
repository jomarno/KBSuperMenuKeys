
#include "Keyboard.h"

const int SuperL_Pin = 9;
const int SuperR_Pin = 8;

bool SuperL_OldState = LOW;
bool SuperL_NewState = LOW;
bool SuperL_RisingEdge = LOW;
bool SuperL_FallingEdge = LOW;

bool SuperR_OldState = LOW;
bool SuperR_NewState = LOW;
bool SuperR_RisingEdge = LOW;
bool SuperR_FallingEdge = LOW;

void setup() {
  pinMode(SuperL_Pin, INPUT);
  pinMode(SuperR_Pin, INPUT);


  Keyboard.begin();
}

void loop() {
  
  // --------------------- LEFT SUPER KEY ---------------------
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


  // --------------------- RIGHT SUPER KEY ---------------------
  SuperR_NewState = digitalRead(SuperR_Pin);
  if (SuperR_NewState == HIGH && SuperR_OldState == LOW) {
    SuperR_RisingEdge = HIGH;
  } 
  else if (SuperR_NewState == LOW && SuperR_OldState == HIGH) {
    SuperR_FallingEdge = HIGH;
  } 
  else {
    SuperR_RisingEdge = LOW;
    SuperR_FallingEdge = LOW;
  }
  SuperR_OldState = SuperR_NewState;
  if (SuperR_RisingEdge) {Keyboard.press(KEY_RIGHT_GUI);}
  if (SuperR_FallingEdge) {Keyboard.release(KEY_RIGHT_GUI);}

}
