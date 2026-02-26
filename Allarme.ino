//Allarme v3
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

#define R 0
#define G 1
#define Y 2


#define LED_R 3
#define LED_G 5
#define LED_B 6

#define BUZZER_P 2

#define ECHO 4
#define TRIGGER 7


int t = 100;

int cm = 0, distanceThreshold = 50;

bool alarm_on = false;
bool alarm_trig = false;


long readUltrasonicDistance() {
  //init porta trigger (manda il segnale)
  pinMode(TRIGGER, OUTPUT);

  //emissione impulsi ultrasonici 40kHz
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  //init porta echo
  pinMode(ECHO, INPUT);
  //lettura tempo di percorrenza impulso
  return pulseIn(ECHO, HIGH);
}

void led_setup(int mode) {
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Allarme");
  lcd.setCursor(0,1);

  if(mode == Y) {
    analogWrite(LED_R, 255);
    analogWrite(LED_G, 125);
    analogWrite(LED_B, 0);

    lcd.print("Disattivato");
  } else if(mode == G) {
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 255);
    analogWrite(LED_B, 0);

    lcd.print("Attivato");
  } else {
    analogWrite(LED_R, 255);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, 0);

    lcd.print("Scattato");
  }
}


void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  pinMode(A0, INPUT);

  pinMode(BUZZER_P, OUTPUT);

  led_setup(Y);
  digitalWrite(BUZZER_P, LOW);
}

void loop() {
  
  if(alarm_on) { //allarme attivo
    if(alarm_trig) { //allarme scattato
      tone(BUZZER_P, 4000, 500);
      tone(BUZZER_P, 1000, 500);

      if(digitalRead(A0) == HIGH) { //disattivazione allarme scattato
          while(digitalRead(A0) == HIGH);
          
          led_setup(G);
          t = 100;
          alarm_trig = false;
      }
    } else { //allarme attivo non scattato
      if(digitalRead(A0) == HIGH) { //disattivazione allarme
          while(digitalRead(A0) == HIGH);

          led_setup(Y);
          alarm_on = false;
      }

      //distanza = (tempo distanza * velocità del suono) / 2
      cm = 0.01723 * readUltrasonicDistance();

      Serial.print("Distanza: ");
      Serial.print(cm);
      Serial.print(" / ");
      Serial.println(distanceThreshold);

      if (cm < distanceThreshold) {
        led_setup(R);

        t = 300;
        alarm_trig = true;
      }
    }
  } else { //allarme disattivato
    if(digitalRead(A0) == HIGH) { //attivazione allarme
      while(digitalRead(A0) == HIGH);
      
      led_setup(G);
      alarm_on = true;
    }
  }

  delay(t);
}