const int ledPin =  LED_BUILTIN;

// globale variabelen
int ledState = LOW;               // status van de LED
unsigned long millisVorigeVerandering = 0; // bewaard tijd van laatste LED-verandering

// andere constanten
const long interval = 1000;           // interval in milliseconden

void setup() {
  // stel ledpin in als output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // tijd van nu
  unsigned long millisNu = millis();

  // is de verstreken tijd sinds de laatste verandering langer dan de interval?
  if (millisNu - millisVorigeVerandering >= interval) {    
    // bewaar tijdstip van de verandering die we hierna gaan doen
    millisVorigeVerandering = millisNu;

    // zet de status van de LED om
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // geef de pin de waarde van de status
    digitalWrite(ledPin, ledState);
  }
}

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
