

//Enter your blynk auth token

//Get the button value

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6xwsLTxyJ"
#define BLYNK_TEMPLATE_NAME "Smart College"
#define BLYNK_AUTH_TOKEN "OxEFo0fTlGMPlcZKNGaNsIfJ4ZOe5osX"

#include <ESP8266WiFi.h>
#include <Servo.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Tenda_7AD760";  //Enter your WIFI name
char pass[] = "optiplex1745";  //Enter your WIFI password

Servo Door_1;
Servo Door_2;

#define smallLEDsPIN D0
#define RECEPTION_LED D1
#define FAN_PIN_BOTH D2
#define Door_1_Pin D3
#define Door_2_Pin D4


BLYNK_WRITE(V0) {
  int pin = param.asInt();
  if (pin == 0) {
    digitalWrite(smallLEDsPIN, HIGH);
  } else {
    digitalWrite(smallLEDsPIN, LOW);
  }

  Serial.print("smallLEDsPIN ");
  Serial.println(pin);
}

BLYNK_WRITE(V1) {
  int pin = param.asInt();
  digitalWrite(RECEPTION_LED, pin);
  Serial.print("RECEPTION_LED ");
  Serial.println(pin);
}
BLYNK_WRITE(V2) {
  int pin = param.asInt();
  if (pin == 1) {
  digitalWrite(FAN_PIN_BOTH, LOW);
  Serial.print("FAN_PIN_BOTH ");
  Serial.println(pin);
  } else {
  digitalWrite(FAN_PIN_BOTH, HIGH);
  Serial.print("FAN_PIN_BOTH ");
  Serial.println(pin);
  }
}
BLYNK_WRITE(V3) {
  int pin = param.asInt();
  if (pin == 1) {
    Door_1.write(140);
    Serial.print("Door_1_Pin ");
    Serial.println(pin);
  } else {
    Door_1.write(0);
    Serial.print("Door_1_Pin ");
    Serial.println(pin);
  }
}
BLYNK_WRITE(V4) {
  int pin = param.asInt();
  if (pin == 1) {
    Door_2.write(0);
    Serial.print("Door_2_Pin ");
    Serial.println(pin);
  } else {
    Door_2.write(180);
    Serial.print("Door_2_Pin ");
    Serial.println(pin);
  }
}

void setup() {
  //Set the LED pin as an output pin
  Serial.begin(9600);

  pinMode(smallLEDsPIN, OUTPUT);
  pinMode(RECEPTION_LED, OUTPUT);
  pinMode(FAN_PIN_BOTH, OUTPUT);
  pinMode(Door_1_Pin, OUTPUT);
  pinMode(Door_2_Pin, OUTPUT);

  digitalWrite(FAN_PIN_BOTH, LOW);
  digitalWrite(smallLEDsPIN, LOW);
  digitalWrite(RECEPTION_LED, LOW);
  Door_1.attach(Door_1_Pin);
  Door_2.attach(Door_2_Pin);
  Door_2.write(180);
  Door_1.write(0);
  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}