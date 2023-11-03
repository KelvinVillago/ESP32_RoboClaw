#include <RoboClaw.h>
// https://resources.basicmicro.com/using-the-roboclaw-arduino-library/

RoboClaw roboclaw(&Serial2, 10000);
#define address 0x80

int increment = 5;
int speed = 0;
bool fwd = true;

void setup() {
  roboclaw.begin(38400);
}

void loop() {

  if(fwd){
    roboclaw.ForwardM1(address,speed); //start Motor1 forward at half speed
  }
  else{
    roboclaw.BackwardM1(address,speed); //start Motor1 forward at half speed
  }
  // roboclaw.BackwardM2(address,64); //start Motor2 backward at half speed
  delay(1500);

  speed = speed + increment;
  if(speed > 125){
    speed = 0;
    fwd = !fwd;
  }
}
