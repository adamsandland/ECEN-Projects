// C++ code
//

int Speed = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  Speed = 250;
}

void loop()
{
  Serial.println(analogRead(A0));
  delay(10);
}