//-----------------------sorteren-----------------------//
#include <Servo.h>

#define sensorPinLinks 6
#define sensorPinRechts 7

Servo servo_2;  //360 servo
Servo servo_3;  //blokkade/tijdelijke stop links
Servo servo_4;  //blokkade/tijdelijke stop rechts

//Bewegingssensor met LED
int led = 13;
int pin = 2;

int value = 0;
int pirState = LOW;

String sorteerRichting = "linksom"; // kan zijn stilstand, linksom en rechtsom  
int knop1 = 14; //linksom
int knop2 = 15; //rechtsom
int knop3 = 16; //stilstand
int knop4 = 17; //open-dicht

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


//-----------------------obstakel-----------------------//
const int RECHTSOM = 0;
const int LINKSOM = 1;
const int ACTIEF = 1;
const int INACTIEF = 0;
Servo servo1;
Servo servo2;
int angle = 0;
long tussenperiode = 1000;
int draaiRichting1= LINKSOM;
int draaiRichting2 = LINKSOM;
long vorigeMillis1 = 0;
long vorigeMillis2 = 0;
int blokkadeStatus1 = INACTIEF;
int blokkadeStatus2 = INACTIEF;
int knopStatus1;
int knopStatus2;
int knopObstakel1 = 18;
int knopObstakel2 = 19;


void setup()
{
  //Bewegingssensor met LED
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
  Serial.begin(9600);
  
  //-----------------------sorteren-----------------------//
  //servo's
  servo_2.attach(2); //360 sorteer servo
  servo_3.attach(3); //linker blok servo
  servo_3.write(90);
  servo_4.attach(4); //rechter blok servo
  servo_4.write(90);
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

  //-----------------------obstakels-----------------------//
  servo1.attach(8);// deze twee zijn van de servo library #include <Servo.h>
  servo1.write(0);
  servo2.attach(9);
  servo2.write(0);
  pinMode(knopObstakel1, INPUT);//blauwe draad
  pinMode(knopObstakel2, INPUT);
  Serial.begin(9600);

}



void loop()
  
  //Bewegingssensor met LED
  
 value = digitalRead(pin);

  if (value == HIGH) {
    digitalWrite(led, HIGH);

    if (pirState == LOW) {
      Serial.println("Motion Detected!");
      pirState = HIGH;
    }
  }else{
    digitalWrite(led, LOW);

    if(pirState == HIGH){
      Serial.println("Motion Ended!");
      pirState = LOW;
      }
    }
{ 
  //-----------------------sorteren-----------------------//
  // millis
  currentMillisStart = millis();
  currentMillisSorteer = millis();
  
  // read the state of the pushbutton value:
  sensorLinks = digitalRead(sensorPinLinks);
  sensorRechts = digitalRead(sensorPinRechts);


  // sorteerRichting regelen
  if (sorteerRichting == "stilstand") {
    servo_2.write(90);
  }

  if (sorteerRichting == "linksom") {
    servo_2.write(110);
  }

  if (sorteerRichting == "rechtsom") {
    servo_2.write(70);
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
    servo_3.write(0);
    servo_4.write(180);
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
    servo_3.write(0);
    servo_4.write(180);
    startMillisStart = currentMillisStart;
  }

  // zorgen dat de blokkade altijd na 3000 millisec weer dicht gaat
  if (currentMillisStart - startMillisStart >= periode3000) {
    servo_3.write(90);
    servo_4.write(90);
    startMillisStart = currentMillisStart;  //IMPORTANT to save the start time of the current LED state.
  }  

  // onderbrekings sensor state regelen
  lastStateLinks = sensorLinks;
  lastStateRechts = sensorRechts;


  //-----------------------obstakels-----------------------//
  int vorigeKnopStatus1 = knopStatus1;
  int vorigeKnopStatus2 = knopStatus2;
  knopStatus1 = digitalRead(2);
  knopStatus2 = digitalRead(4);
  
  if (vorigeKnopStatus1 == LOW && knopStatus1 == HIGH) {
    // knop is ingedrukt
    blokkadeStatus1 = ACTIEF;
    
    //activering obstakel
    if (draaiRichting1 == LINKSOM) {
      servo1.write(90);
      vorigeMillis1 = millis();
    }
  }
    //tussenperiode
    if(millis() >= vorigeMillis1 +1000){
      if(blokkadeStatus1 == ACTIEF){
      draaiRichting1 = RECHTSOM;
      }
    }
    
  //servo naar rust  
  if(blokkadeStatus1 == ACTIEF){  
    if(draaiRichting1 == RECHTSOM){
        servo1.write(0);
      blokkadeStatus1 = INACTIEF;
    }
  }
  
  if (vorigeKnopStatus2 == LOW && knopStatus2 == HIGH) {
    //knop2 ingedrukt
    blokkadeStatus2 = ACTIEF;
    
    //servo2 activatie
    if (draaiRichting2 == LINKSOM) {
      servo2.write(90);
      vorigeMillis2 = millis();
    }
  }
    //rustperiode
    if(millis() >= vorigeMillis2 +1000){
      if(blokkadeStatus2 == ACTIEF){
        draaiRichting2 = RECHTSOM;
      }
    }
    
  //servo2 weer naar ruststand  
  if(blokkadeStatus2 == ACTIEF){  
    if(draaiRichting2 == RECHTSOM){
      servo2.write(0); 
      blokkadeStatus2 = INACTIEF;
    }
  }
}
