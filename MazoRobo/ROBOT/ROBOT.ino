#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Servo head;
// Servo l_hand;
// Servo r_hand;

// // define sonar sensor's pins
// int trig = 4;
// int echo = 5;

// // received data
// byte val = 0;

// void setup() {
//   // put your setup code here, to run once:
//   head.attach(2);
//   l_hand.attach(3);
//   r_hand.attach(4);

//   Serial.begin(9600); // for communicating via serial port with Python
// }

// void standby() {
//   // all motors to these positions
//   head.write(90);
//   int r_pos = 30;
//   int l_pos = map(r_pos, 0, 180, 180, 0);

//   l_hand.write(l_pos);
//   r_hand.write(r_pos);
// }

// void hi() {
//   // all motors to these positions
//   head.write(90);

//   int i = 0;
//   for (i = 30; i <= 170; i++) {
//     r_hand.write(i);
//     delay(5);
//   }

//   for (i = 170; i >= 100; i--) {
//     r_hand.write(i);
//     delay(5);
//   }

//   for (i = 100; i <= 170; i++) {
//     r_hand.write(i);
//     delay(5);
//   }

//   for (i = 170; i >= 30; i--) {
//     r_hand.write(i);
//     delay(5);
//   }

//   standby();
// }

// void hands_up() {
//   // do this on every command (nothing much just move hands a bit)

//   //head.write(150);
//   //delay(300);
//   //head.write(90);

//   int i = 0;
//   for (i = 30; i <= 170; i++) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(5);
//   }

//   delay(600);

//   for (i = 170; i >= 30; i--) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(5);
//   }

// }

// void weight_lift() {
//   // lift weight using both hands
//   int i = 0;
//   for (i = 30; i <= 170; i++) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(5);
//   }

//   for (int count = 0; count <= 4; count++) {
//     for (i = 170; i >= 60; i--) {
//       int r_pos = i;
//       int l_pos = map(r_pos, 0, 180, 180, 0);

//       l_hand.write(l_pos);
//       r_hand.write(r_pos);
//       delay(5);
//     }

//     for (i = 60; i <= 170; i++) {
//       int r_pos = i;
//       int l_pos = map(r_pos, 0, 180, 180, 0);

//       l_hand.write(l_pos);
//       r_hand.write(r_pos);
//       delay(5);
//     }
//   }

//   for (i = 170; i >= 30; i--) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(5);
//   }
// }

// void excited() {
//   return;
// }

// void look_left() {
//   // rotate hed to left
//   head.write(180);
// }

// void confused() {

//   for (int count = 0; count <= 1; count++) {
//     head.write(30);
//     r_hand.write(170);
//     delay(700);
//     r_hand.write(30);
//     head.write(120);
//     l_hand.write(30);
//     delay(700);
//     l_hand.write(160);
//   }
//   standby();
// }

// void double_punch() {
//   // do a punch
//   int i = 0;
//   for (i = 30; i >= 0; i--) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(5);
//   }
//   delay(2000);

//   int r_pos = 80;
//   int l_pos = map(r_pos, 0, 180, 180, 0);
//   l_hand.write(l_pos);
//   r_hand.write(r_pos);
//   delay(500);
//   standby();
// }

// void r_upper_cut() {
//   // make right upper-cut
//   int i = 0;
//   for (i = 30; i <= 170; i++) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(5);
//   }

//   for (int count = 0; count <= 4; count++) {
//     int i = 0;
//     for (i = 170; i >= 60; i--) {
//       r_hand.write(i);
//       delay(1);
//     }

//     for (i = 60; i <= 170; i++) {
//       r_hand.write(i);
//       delay(1);
//     }
//   }
//   standby();
//   delay(100);
// }

// void smash() {
//   // smash things
//   int i = 0;
//   for (i = 30; i <= 170; i++) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(5);
//   }
//   delay(2000);
//   for (i = 170; i >= 0; i--) {
//     int r_pos = i;
//     int l_pos = map(r_pos, 0, 180, 180, 0);

//     l_hand.write(l_pos);
//     r_hand.write(r_pos);
//     delay(1);
//   }
//   delay(300);
//   int r_pos = 180;
//   int l_pos = map(r_pos, 0, 180, 180, 0);

//   l_hand.write(l_pos);
//   r_hand.write(r_pos);
//   delay(1000);
//   standby();
// }

// void eye_detect() {
//   // do something if eye sensor detect motion
//   return;
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   standby();

//   while (Serial.available() > 0) //look for serial data available or not
//   {
//     val = Serial.read();        //read the serial value

//     if (val == 'h') {
//       // do hi
//       hi();
//     }
//     if (val == 'p') {
//       // do hi
//       double_punch();
//     }
//     if (val == 'u') {
//       hands_up();
//       delay(3000);
//     }
//     if (val == 'l') {
//       standby();
//       look_left();
//       delay(2000);
//     }
//     if (val == 'U') {
//       // uppercut
//       r_upper_cut();
//       delay(2000);
//     }
//     if (val == 's') {
//       smash();
//       delay(2000);
//     }
//   }
// }



// Pins for servo motor

#define head_S_P 1

#define LH_1_S_P 2
#define LH_2_S_P 3
#define LH_3_S_P 4

#define RH_1_S_P 5
#define RH_2_S_P 6
#define RH_3_S_P 7

#define LL_1_S_P 8
#define LL_2_S_P 9
#define LL_3_S_P 10

#define RL_1_S_P 11
#define RL_2_S_P 12
#define RL_3_S_P 13

// Declaring the servos

Servo head_S;

Servo LH_1_S;
Servo LH_2_S;
Servo LH_3_S;

Servo RH_1_S;
Servo RH_2_S;
Servo RH_3_S;

Servo LL_1_S;
Servo LL_2_S;
Servo LL_3_S;

Servo RL_1_S;
Servo RL_2_S;
Servo RL_3_S;

// Head Ultrasonic pins

#define ultraSonic_Trig 11
#define ultraSonic_Echo 11

// PINS and Variables for oled

#define OLED_SDA_PIN A4
#define OLED_SCL_PIN A5
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Attaching the Oled
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Some Important Variables
int OLED_FontSize = 1.5;
int head_Min_Distance = 30;  // Minimum Distance in cm to warn the user



void setup() {

  // Setting up Ultrasonic pins as input and output

  pinMode(ultraSonic_Trig, OUTPUT);
  pinMode(ultraSonic_Echo, INPUT);

  // attaching servos to its pins

  head_S.attach(head_S_P);

  LH_1_S.attach(LH_1_S_P);
  LH_2_S.attach(LH_2_S_P);
  LH_3_S.attach(LH_3_S_P);

  RH_1_S.attach(RH_1_S_P);
  RH_2_S.attach(RH_2_S_P);
  RH_3_S.attach(RH_3_S_P);

  LL_1_S.attach(LL_1_S_P);
  LL_2_S.attach(LL_2_S_P);
  LL_3_S.attach(LL_3_S_P);

  RL_1_S.attach(RL_1_S_P);
  RL_2_S.attach(RL_2_S_P);
  RL_3_S.attach(RL_3_S_P);

  // Confirm that Oled is connected
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ;
  }

  Serial.begin(9600);
}

// Function which returns the distance when called
int returnDistance() {
  digitalWrite(ultraSonic_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultraSonic_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonic_Trig, LOW);
  int duration = pulseIn(ultraSonic_Echo, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

// Function to print text on OLED, Pass the text as parametar
void printTextOLED(String text) {
  oled.clearDisplay(); 
  oled.setTextSize(OLED_FontSize);  
  oled.setCursor(3, 20);
  oled.print(text);
  oled.setTextColor(WHITE); 
  oled.display();
}

// Function To rotate head in East Direction
void rotateHeadEast() {
  head_S.write(180);
}
// Function To rotate head in North-East Direction
void rotateHeadNorthEast() {
  head_S.write(135);
}
// Function To rotate head in North Direction
void rotateHeadNorth() {
  head_S.write(90);
}
// Function To rotate head in North-West Direction
void rotateHeadNorthWest() {
  head_S.write(45);
}
// Function To rotate head in West Direction
void rotateHeadWest() {
  head_S.write(0);
}

// Function will return true if an object is detected with in the minimum distance defined by a variable "head_Min_Distance" in East Direction
bool tellEast() {
  rotateHeadEast();
  int distance = returnDistance();
  if (distance <= head_Min_Distance) {
    return true;
  } else {
    return false;
  }
}
// Function will return true if an object is detected with in the minimum distance defined by a variable "head_Min_Distance" in North-East Direction
bool tellNorthEast() {
  rotateHeadNorthEast();
  int distance = returnDistance();
  if (distance <= head_Min_Distance) {
    return true;
  } else {
    return false;
  }
}
// Function will return true if an object is detected with in the minimum distance defined by a variable "head_Min_Distance" in North Direction
bool tellNorth() {
  rotateHeadNorth();
  int distance = returnDistance();
  if (distance <= head_Min_Distance) {
    return true;
  } else {
    return false;
  }
}
// Function will return true if an object is detected with in the minimum distance defined by a variable "head_Min_Distance" in North-West Direction
bool tellNorthWest() {
  rotateHeadNorthWest();
  int distance = returnDistance();
  if (distance <= head_Min_Distance) {
    return true;
  } else {
    return false;
  }
}
// Function will return true if an object is detected with in the minimum distance defined by a variable "head_Min_Distance" in West Direction
bool tellWest() {
  rotateHeadWest();
  int distance = returnDistance();
  if (distance <= head_Min_Distance) {
    return true;
  } else {
    return false;
  }
}

void loop() {
  printTextOLED("I am your Humanoid Robot");
}

