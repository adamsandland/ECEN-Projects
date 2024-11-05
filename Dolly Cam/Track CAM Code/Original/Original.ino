// C++ code
//
int maxLeft = 378;
int maxRight = 302;
int range = maxLeft-maxRight;
int midpoint = maxRight+(range/2);

int motorL1 = 5;
int motorL2 = 6;
int motorR1 = 9;
int motorR2 = 10;
//int enL = 13;
//int enR = 12;
int speedMultiplier = 1;
int speed=0;
int deadzone = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
}

void loop()
{
  //Serial.println(analogRead(A0));
  speed = abs(midpoint-analogRead(A0))*speedMultiplier;
  /*if (analogRead(A0) < midpoint-deadzone) {
    //forward
    
    //digitalWrite(enL, HIGH);
    //digitalWrite(enR, HIGH);

    analogWrite(motorL1, speed);
    analogWrite(motorR1, speed);
    analogWrite(motorL2, 0);
    analogWrite(motorR2, 0);
  } else if(analogRead(A0) > midpoint+deadzone) {
    //backwards
    
    //digitalWrite(enL, HIGH);
    //digitalWrite(enR, HIGH);
    
    analogWrite(motorL1, 0);
    analogWrite(motorR1, 0);
    analogWrite(motorL2, speed);
    analogWrite(motorR2, speed);
    
  } else {
    //enable the brakes in the deadzone
    speed=0;
    analogWrite(motorL1, 0);
    analogWrite(motorR1, 0);
    analogWrite(motorL2, 0);
    analogWrite(motorR2, 0);
    
    //digitalWrite(enL, LOW);
    //digitalWrite(enR, LOW);
    
  }*/
  analogWrite(motorL1, 100);
  Serial.println(speed);
  delay(10); // Delay a little bit to improve simulation performance
}