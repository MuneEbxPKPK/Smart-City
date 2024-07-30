// Define the pin connections for the L298N motor driver
const int in1 = 3;  // Left motor forward pin
const int in2 = 5;  // Left motor backward pin
const int in3 = 6;  // Right motor forward pin
const int in4 = 9;  // Right motor backward pin

// Define the pin connections for the ultrasonic sensors
const int trigPinR = 13;  // Trigger pin for ultrasonic sensor 1
const int echoPinR = 12;  // Echo pin for ultrasonic sensor 1
const int trigPinF = 10;  // Trigger pin for ultrasonic sensor 2
const int echoPinF = 11;  // Echo pin for ultrasonic sensor 2
const int trigPinL = 8;   // Trigger pin for ultrasonic sensor 3
const int echoPinL = 7;   // Echo pin for ultrasonic sensor 3

int motorSpeed = 130;
const int minimumStraightDistance = 60;

// Define the variables for the ultrasonic sensors
int distanceR = 0;
int distanceF = 0;
int distanceL = 0;


void setup() {
  // Initialize the motor pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Initialize the ultrasonic sensor pins as outputs and inputs
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
  pinMode(trigPinF, OUTPUT);
  pinMode(echoPinF, INPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
}

void loop() {

  distanceF = readUltrasonic(trigPinF, echoPinF);
  distanceR = readUltrasonic(trigPinR, echoPinR);
  distanceL = readUltrasonic(trigPinL, echoPinL);

  if (distanceF < 20) {
    // Stop the robot
    stop();
    // Determine the direction to turn
    if (distanceF < 40 && distanceR > 16) {
      // Turn right
      right();
      delay(730);  // Wait for the turn to complete
      forward();   // Move forward after turning
    } else if (distanceL > 16 && distanceF < 40) {
      // Move left
      left();
      delay(700);            
      forward();
    }else if (distanceF < 5 && (distanceL < 10 || distanceR < 10 )){
      backward();
      delay(200);
      right();
      delay(300);
      stop();
    }
  } else {
    // Move forward if there is no obstacle
    forward();
  }
}

void forward() {
  Serial.println("Moving Forward");
  analogWrite(in1, 126);
  digitalWrite(in2, LOW);
  analogWrite(in3, motorSpeed);
  digitalWrite(in4, LOW);
}

void backward() {
  Serial.println("Moving Backward");
  digitalWrite(in1, LOW);
  analogWrite(in2, motorSpeed);
  digitalWrite(in3, LOW);
  analogWrite(in4, motorSpeed);
}

void left() {
  Serial.println("Moving Left");
  digitalWrite(in1, LOW);
  analogWrite(in2, motorSpeed);
  analogWrite(in3, motorSpeed);
  digitalWrite(in4, LOW);
}

void right() {
  analogWrite(in1, motorSpeed);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  analogWrite(in4, motorSpeed);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
}

long readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int d = duration * 0.034 / 2;
  return d;
}


