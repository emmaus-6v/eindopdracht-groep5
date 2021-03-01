

#include <Servo.h>

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

void setup()
{
  servo1.attach(8);// deze twee zijn van de servo library #include <Servo.h>
  servo1.write(0);
  servo2.attach(9);
  servo2.write(0);
  pinMode(2,INPUT);//blauwe draad
  pinMode(4,INPUT);
  Serial.begin(9600);

}

void loop()
{ 
  int vorigeKnopStatus1 = knopStatus1;
  int vorigeKnopStatus2 = knopStatus2;
  knopStatus1 = digitalRead(2);
  knopStatus2 = digitalRead(4);
  
  if (vorigeKnopStatus1 == LOW && knopStatus1 == HIGH) {
    // blijkbaar is de knop opnieuw ingedrukt
    Serial.println("verander stand van servo");
    
    Serial.println(vorigeMillis1);
    blokkadeStatus1 = ACTIEF;
    Serial.println(knopStatus1);
    
    // Vervolgens passen we de stand van de servo aan:
    if (draaiRichting1 == LINKSOM) {
      servo1.write(90);
      // als dit te snel gaat, kun je bovenstaande regel vervangen door:
      vorigeMillis1 = millis();
      Serial.println(vorigeMillis1);}}
  
    if(millis() >= vorigeMillis1 +1000){
      if(blokkadeStatus1 == ACTIEF){
      Serial.println("delay af");
      draaiRichting1 = RECHTSOM;
      Serial.println("richting veranderd");
      Serial.println(vorigeMillis1);
      }
    }
    
    
  if(blokkadeStatus1 == ACTIEF){  
  if(draaiRichting1 == RECHTSOM){
      Serial.println("begin");
      Serial.println(vorigeMillis1);
      
      Serial.println("delay voorbij");
      servo1.write(0); // ik weet niet precies welke graden je wilt
      // hier kun je ook zo'n vervanging doen, maar dan de andere kant op
      Serial.println("veranderd terug");
    blokkadeStatus1 = INACTIEF;
  }
  }
  
   if (vorigeKnopStatus2 == LOW && knopStatus2 == HIGH) {
    // blijkbaar is de knop opnieuw ingedrukt
    Serial.println("verander stand van servo 2");
    
    Serial.println(vorigeMillis2);
    blokkadeStatus2 = ACTIEF;
    
    // Vervolgens passen we de stand van de servo aan:
    if (draaiRichting2 == LINKSOM) {
      servo2.write(90);
      vorigeMillis2 = millis();
      Serial.println(vorigeMillis2);}}
  
    if(millis() >= vorigeMillis2 +1000){
      if(blokkadeStatus2 == ACTIEF){
      Serial.println("delay 2 af");
      draaiRichting2 = RECHTSOM;
      Serial.println("richting 2 veranderd");
      Serial.println(vorigeMillis2);
      }
    }
    
    
  if(blokkadeStatus2 == ACTIEF){  
  if(draaiRichting2 == RECHTSOM){
      Serial.println("begin 2");
      Serial.println(vorigeMillis2);
      
      Serial.println("delay voorbij");
      servo2.write(0); // ik weet niet precies welke graden je wilt
      // hier kun je ook zo'n vervanging doen, maar dan de andere kant op
      Serial.println("veranderd 2terug");
    blokkadeStatus2 = INACTIEF;
  }
  }
}

// sorteer deel

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
