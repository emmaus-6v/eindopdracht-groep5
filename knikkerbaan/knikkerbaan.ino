// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.


#include <Servo.h>

#define sensorPinLinks 6
#define sensorPinRechts 7

Servo servo_8;  
Servo servo_9;
Servo servo_10;

String sorteerRichting = "linksom"; // kan zijn stilstand, linksom en rechtsom  
int knop1 = 2; //linksom
int knop2 = 3; //rechtsom
int knop3 = 4; //stilstand
int knop4 = 5; //open-dicht

int sensorLinks = 0, lastStateLinks = 0;         // variable for reading the pushbutton status
int sensorRechts = 0, lastStateRechts = 0;

unsigned long startMillisStart; //startmillis voor de servo's die de knikkers tijdelijk tegen houden.
unsigned long currentMillisStart; //currentmillis voor de servo's die de knikkers tijdelijk tegen houden.
unsigned long startMillisSorteer; //startmillis voor het sorteer deel.
unsigned long currentMillisSorteer; //currentmillis voor het sorteer deel.
int periode1000 = 1000;   //periode van 1 sec
int periode2500 = 2500;   //periode van 2,5 sec
int periode3000 = 3000;   //periode van 3 sec

int sorteerMillisStatus = 0;  //zorgt dat blokkade servo's en de sensors goed kunnen werken met millis

void setup()
{
  //servo's
  servo_8.attach(8); //360 sorteer servo
  servo_9.attach(9); //linker blok servo
  servo_9.write(90);
  servo_10.attach(10); //rechter blok servo
  servo_10.write(90);
  //knoppen
  pinMode(knop1, INPUT);
  pinMode(knop2, INPUT);
  pinMode(knop3, INPUT);
  pinMode(knop4, INPUT);
  //onderbrekings sensoren
  pinMode(sensorPinLinks, INPUT);     
  digitalWrite(sensorPinLinks, HIGH); // turn on the pullup
  pinMode(sensorPinRechts, INPUT);     
  digitalWrite(sensorPinRechts, HIGH); // turn on the pullup
}

void loop() 
{
  // millis
  currentMillisStart = millis();
  currentMillisSorteer = millis();
  
  // read the state of the pushbutton value:
  sensorLinks = digitalRead(sensorPinLinks);
  sensorRechts = digitalRead(sensorPinRechts);


  // sorteerRichting regelen
  if (sorteerRichting == "stilstand") {
    servo_8.write(90);
  }

  if (sorteerRichting == "linksom") {
    servo_8.write(110);
  }

  if (sorteerRichting == "rechtsom") {
    servo_8.write(70);
  }


  // met knoppen de richting regelen
  if (digitalRead(knop1) == HIGH) {
    sorteerRichting = "linksom";  
  }

  if (digitalRead(knop2) == HIGH) {
    sorteerRichting = "rechtsom";  
  }

  if (digitalRead(knop3) == HIGH) {
    sorteerRichting = "stilstand";  
  }

  
  // met de onderbrekingssensoren de sorteerRichting regelen.
  // linker sensor
  if (sensorLinks == LOW) {
    sorteerRichting = "rechtsom";
  } 
  // rechter sensor
  if (sensorRechts == LOW) {
    sorteerRichting = "stilstand";
    startMillisStart = currentMillisStart;
    startMillisSorteer = currentMillisSorteer;
    sorteerMillisStatus = 1;
  } 
  // zorgen dat nadat de rechter sensor iets heeft gedetecteerd de blokkade open gaat na 1000 millisec stilstand.
  if ((currentMillisSorteer - startMillisSorteer >= periode1000) && (sorteerMillisStatus == 1)) {
    servo_9.write(0);
    servo_10.write(180);
    startMillisSorteer = currentMillisSorteer;
    sorteerMillisStatus = 2;
  }
  // zorgen dat de sorteer richting na 2500 millisec weer linksom wordt.
  if ((currentMillisSorteer - startMillisSorteer >= periode2500) && (sorteerMillisStatus == 2)) {
    startMillisSorteer = currentMillisSorteer;
    sorteerRichting = "linksom";
    sorteerMillisStatus = 0;
  }

  
  // met een knop de tijdelijke blokkade openen
  if (digitalRead(knop4) == HIGH) {
    servo_9.write(0);
    servo_10.write(180);
    startMillisStart = currentMillisStart;
  }

  // zorgen dat de blokkade altijd na 3000 millisec weer dicht gaat
  if (currentMillisStart - startMillisStart >= periode3000) {
    servo_9.write(90);
    servo_10.write(90);
    startMillisStart = currentMillisStart;  //IMPORTANT to save the start time of the current LED state.
  }  

  // onderbrekings sensor state regelen
  lastStateLinks = sensorLinks;
  lastStateRechts = sensorRechts;
}
