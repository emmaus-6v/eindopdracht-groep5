/*
  Sweep

  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

String sorteerRichting = "stilstand"; //kan zijn stilstand, linksom en rechtsom 
int pos1 = 90;
int knop1 = 3;
int knop2 = 2;

Servo servo_8;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000;  //the value is a number of milliseconds

void setup() {
  servo_8.attach(8, 500, 2500);
  servo_8.write(pos1);
  pinMode(knop1, INPUT);
  pinMode(knop2, INPUT);
  startMillis = millis();  //initial start time
}

void loop() {
  currentMillis = millis();
  
  if (digitalRead(knop1) == HIGH) {
  	sorteerRichting = "linksom";
  }
  
  if (digitalRead(knop2) == HIGH) {
    sorteerRichting = "rechtsom";
  }
  
  
  if (sorteerRichting == "linksom") {
    servo_8.write(90);
    
    if (currentMillis - startMillis >= period) {
      for (pos1 = 90; pos1 < 180; pos1 += 1) {
        // tell servo to go to position in variable 'pos'
        servo_8.write(pos1);
        // wait 15 ms for servo to reach the position
        delay(15); // Wait for 15 millisecond(s)
      }
      for (pos1 = 180; pos1 > 90; pos1 -=1) {
        // tell servo to go to position in variable 'pos'
        servo_8.write(pos1);
        // wait 15 ms for servo to reach the position
        delay(15); // Wait for 15 millisecond(s)
      }
    }
  }
  
  if (sorteerRichting == "rechtsom") {
    servo_8.write(90);

    if (currentMillis - startMillis >= period) {
      for (pos1 = 90; pos1 > 0; pos1 -= 1) {
        // tell servo to go to position in variable 'pos'
        servo_8.write(pos1);
        // wait 15 ms for servo to reach the position
        delay(15); // Wait for 15 millisecond(s)
      }
      for (pos1 = 0; pos1 < 90; pos1 +=1) {
        // tell servo to go to position in variable 'pos'
        servo_8.write(pos1);
        // wait 15 ms for servo to reach the position
        delay(15); // Wait for 15 millisecond(s)
      }
    }
  } 
}
