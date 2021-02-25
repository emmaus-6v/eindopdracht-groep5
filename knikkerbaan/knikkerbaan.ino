// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.


#include <Servo.h>

#define sensorPinLinks 10
#define sensorPinRechts 12

Servo servo_8;  

String sorteerRichting = "stilstand"; // kan zijn stilstand, linksom en rechtsom  
int knop1 = 2; //linksom
int knop2 = 3; //rechtsom
int knop3 = 4; //stilstand

int sensorLinks = 0, lastStateLinks = 0;         // variable for reading the pushbutton status
int sensorRechts = 0, lastStateRechts = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  servo_8.attach(8);
  pinMode(knop1, INPUT);
  pinMode(knop2, INPUT);
  // initialize the sensor pin as an input:
  pinMode(sensorPinLinks, INPUT);     
  digitalWrite(sensorPinLinks, HIGH); // turn on the pullup
  pinMode(sensorPinRechts, INPUT);     
  digitalWrite(sensorPinRechts, HIGH); // turn on the pullup
}

void loop() 
{
  // read the state of the pushbutton value:
  sensorLinks = digitalRead(sensorPinLinks);
  sensorRechts = digitalRead(sensorPinRechts);
  
  if (digitalRead(knop1) == HIGH) {
    sorteerRichting = "linksom";  
  }

  if (digitalRead(knop2) == HIGH) {
    sorteerRichting = "rechtsom";  
  }

  if (digitalRead(knop3) == HIGH) {
    sorteerRichting = "stilstand";  
  }
  
  if (sorteerRichting == "stilstand") {
    servo_8.write(90);
  }

  if (sorteerRichting == "linksom") {
    servo_8.write(110);
  }

  if (sorteerRichting == "rechtsom") {
    servo_8.write(70);
  }

  if (sensorLinks == LOW) {
    sorteerRichting = "linksom";
  } 

  if (sensorRechts == LOW) {
    sorteerRichting = "rechtsom";
  } 
  
  lastStateLinks = sensorLinks;
  lastStateRechts = sensorRechts;
}
