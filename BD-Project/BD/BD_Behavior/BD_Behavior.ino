// C++ code
//
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN    6
#define LED_COUNT 60
Adafruit_NeoPixel strip(144, 11);

Servo eye;
Servo ear_L;
Servo ear_R;
Servo neck;

std::list<String> modes = {"idle", "alert", "looking around", "scanning", "displaying"};
uint32_t off = strip.Color(0,0,0);
uint32_t red = strip.Color(255,0,0);
uint32_t green = strip.Color(75,255,0);
uint32_t yellow = strip.Color(220,225,0);
uint32_t blue = strip.Color(0,230,255);
uint32_t white = strip.Color(255,255,255);
uint32_t colors = [off,red,green,yellow,blue,white];

void setup()
{
  currentMode = modes(0);
  
  eye.attach(2, 500, 2500);
  ear_L.attach(3, 500, 2500);
  ear_R.attach(4, 500, 2500);
  neck.attach(5, 500, 2500);

  eye.write(90);
  ear_L.write(45);
  ear_R.write(45);
  neck.write(90);

  strip.begin();
  strip.show();
}

void loop()
{
  if(modes == 0) //idle animation, shakes head.
  {
    int time=1000;
    eye_increments = motorControlIncrements(45,eye.read(), time);
    neck_increments = motorControlIncrements(45,neck.read(), time);
    color_inc = fadeColorIncrements(strip.getPixelColor(0), colors(2), time);
    for (int value=0, value<time, value++)
    {
      frameData(color_inc, eye_increments, 0,0,neck_increments);
      sleep(0.001);
    }
    sleep(2);
    eye_increments = motorControlIncrements(135,eye.read(), time);
    neck_increments = motorControlIncrements(135,neck.read(), time);
    for (int value=0, value<time, value++)
    {
      frameData(color_inc, eye_increments, 0,0,neck_increments);
      sleep(0.001);
    }
    sleep(2);
    eye_increments = motorControlIncrements(90,eye.read(), time);
    neck_increments = motorControlIncrements(90,neck.read(), time);
    for (int value=0, value<time, value++)
    {
      frameData(color_inc, eye_increments, 0,0,neck_increments);
      sleep(0.001);
    }
    sleep(5);

  }
  else if(modes ==1)
  {
    frameData();

  }
  else if(modes ==2)
  {
    frameData();

  }
  else if(modes ==3)
  {
    frameData();

  }
  else if(modes==4)
  {
    frameData();

  }

  delay(10); // Delay a little bit to improve simulation performance
}

list<int> color(int r, int g, int b)
{
  std::list<int> colorMatrix = {r,g,b};
  return colorMatrix;
}

int motorControlIncrements(int position, int currentPosition, time_in_s)
{
  int difference_of_positions = position-currentPosition;
  float increments = difference_of_positions/time_in_s;
  int frame_change = (int)increments;
  return frame_change;
}

list<int> fadeColorIncrements(list<int> currentColor, list<int> newColor, time_in_s)
{
  float a = (newColor(0)-currentColor(0))/time_in_s;
  float b = (newColor(1)-currentColor(1))/time_in_s;
  float c = (newColor(2)-currentColor(2))/time_in_s;
  int r = (int)a;
  int g = (int)b;
  int bl = (int)c;
  std::list<int> returnColor = {r,g,bl};
  return returnColor;
}
void frameData(list<int> color_increments, int eye_increments, int ear_L_increments, int ear_R_increments, int neck_increments)
{
  eye.write(eye.read()+eye_increments);
  ear_L.write(ear_L.read()+ear_L_increments);
  ear_R.write(ear_R.read()+ear_R_increments);
  neck.write(neck.read()+neck_increments);
  list<int> most_recent = strip.getPixelColor(0)
  strip.fill(most_recent+color_increments);
  for (int i=1,i<strip.numPixels()-1, i++)
  {
    randomFlare(most_recent, i);
  }
  strip.show();
}

void randomFlare(list<int> currentColor, int pixelNumber){
  if(strip.getPixelColor(pixelNumber)>currentColor || strip.getPixelColor(pixelNumber)<currentColor)
  {
    strip.setPixelColor(pixelNumber, currentColor(0),currentColor(1),currentColor(2));
  }
  else
  {
    int variance = (rand()%10)-(rand()%10);
    strip.setPixelColor(pixelNumber, variance, variance, variance);
  }
}