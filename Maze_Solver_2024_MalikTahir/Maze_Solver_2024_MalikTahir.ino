int Trig_F = 2;
int Echo_F = 3;
int Trig_R = 4;
int Echo_R = 5;
int Trig_L = 6;
int Echo_L = 7;

int m1_a = 8;
int m1_b = 9;
int m2_a = 10;
int m2_b = 11;
int enA = 12;
int enB = 13;

int Duration_F = 0, Duration_R = 0, Duration_L = 0;
int Distance_F = 0, Distance_R = 0, Distance_L = 0;

int EN_Speed = 110, En_Turn_Speed = 150, M_Speed = 110, M_Turn_Speed = 150;

void setup() {
  // put your setup code here, to run once:
pinMode(Trig_F, OUTPUT);
pinMode(Echo_F, INPUT);
pinMode(Trig_R, OUTPUT);
pinMode(Echo_R, INPUT);
pinMode(Trig_L, OUTPUT);
pinMode(Echo_L, INPUT);

pinMode(m1_a, OUTPUT);
pinMode(m1_b, OUTPUT);
pinMode(m2_a, OUTPUT);
pinMode(m2_b, OUTPUT);

pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Check_Front() < 5)
{
  if(Check_Right() > Check_Left())
  {
    Right();
  }
  else if(Check_Right() < Check_Left())
  {
    Left();
  }
  else if(Check_Right() == Check_Left())
  {
    Stop();
    delay(500);
    Backward();
  }
}
}

void Check_Front()
{
  digitalWrite(Trig_F, LOW);
  delay(2);
  digitalWrite(Trig_F, HIGH);
  delay(10);
  digitalWrite(Trig_F, LOW);

  Duration_F = pulseIn(Echo_F, HIGH);
  Distance_F = Duration_F * (0.0.34/2);
  return Distance_F;
}

void Check_Right()
{
  digitalWrite(Trig_R, LOW);
  delay(2);
  digitalWrite(Trig_R, HIGH);
  delay(10);
  digitalWrite(Trig_R, LOW);

  Duration_R = pulseIn(Echo_R, HIGH);
  Distance_R = Duration_R * (0.0.34/2);
  return Distance_R;
}

void Check_Left()
{
  digitalWrite(Trig_L, LOW);
  delay(2);
  digitalWrite(Trig_L, HIGH);
  delay(10);
  digitalWrite(Trig_L, LOW);

  Duration_L = pulseIn(Echo_L, HIGH);
  Distance_L = Duration_L * (0.0.34/2);
  return Distance_L;
}

void Forward()
{
  analogWrite(m1_a, M_Speed);
  analogWrite(m1_b, 0);
  analogWrite(m2_a, M_Speed);
  analogWrite(m2_b, 0);

  analogWrite(en_A, En_Speed);
  analogWrite(en_B, En_Speed);
}

void Stop()
{
  analogWrite(m1_a, 0);
  analogWrite(m1_b, 0);
  analogWrite(m2_a, 0);
  analogWrite(m2_b, 0);

  analogWrite(en_A, 0);
  analogWrite(en_B, 0);
}

void Backward()
{
  analogWrite(m1_a, 0);
  analogWrite(m1_b, M_Speed);
  analogWrite(m2_a, 0);
  analogWrite(m2_b, M_Speed);

  analogWrite(en_A, En_Speed);
  analogWrite(en_B, En_Speed);
}

void Right()
{
  analogWrite(m1_a, M_Turn_Speed);
  analogWrite(m1_b, 0);
  analogWrite(m2_a, 0);
  analogWrite(m2_b, M_Turn_Speed);

  analogWrite(en_A, En_Turn_Speed);
  analogWrite(en_B, En_Turn_Speed);
}

void Left()
{
  analogWrite(m1_a, 0);
  analogWrite(m1_b, M_Turn_Speed);
  analogWrite(m2_a, M_Turn_Speed);
  analogWrite(m2_b, 0);

  analogWrite(en_A, En_Turn_Speed);
  analogWrite(en_B, En_Turn_Speed);
}