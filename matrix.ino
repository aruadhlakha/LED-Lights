// This #include statement was automatically added by the Particle IDE.


#include <neopixel.h>
#include "Particle.h"

#define PIXEL_PIN D0
#define PIXEL_COUNT 149
#define PIXEL_TYPE WS2812B
#define wait 1000
#define minBrightness 50
#define maxBrightness 250
#define midBrightness 150




Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup()
{
    EEPROM.clear();
    strip.begin();
    strip.show();
  
    Particle.function("Red",Red);
    Particle.function("Yellow",Yellow);
    Particle.function("SwitchOff",Black);
    Particle.function("White",White);
    Particle.function("Purple",Purple);
    Particle.function("Blue",Blue);
    Particle.function("Cyan",Cyan);
    Particle.function("RedWhite",RedWhite);
    Particle.function("RedWhiteCyan",RedWhiteCyan);
    Particle.function("RedGreen",RedGreen);
    Particle.function("RedBlue",RedBlue);
    Particle.function("Mood",Valentine);
    Particle.function("colorWipe5",colorWipe5);
    Particle.function("Golden", Golden);
    Particle.function("Pink",Pink);
}

void loop() 
{
    Pink("hello");
}
int Pink(String command){
    safety();
        colorWipe(255, 114, 242);
        delay(wait);
}
int Golden(String command){
    safety();
    colorWipe(207, 181, 59);
    delay (wait);
}

int Blue(String command)
{
    safety();
    colorWipe(0, 0, maxBrightness);
    delay(wait);
}

int colorWipe5(String command)
{
    safety();
    colorWipe6(0,0,maxBrightness);
    delay(wait);
}

int Purple(String command)
{
    colorWipe(maxBrightness, 0, maxBrightness);
    delay(wait);
}

int White(String command)
{
    colorWipe(midBrightness, midBrightness, midBrightness);
    delay(wait);
}

int Yellow(String command)
{
    colorWipe(maxBrightness, maxBrightness, 0);
    delay(wait);
}

int Black(String command)
{
    stripSetPixelColor(0, 0, 0);
    delay(wait);
}

int Red(String command)
{
    colorWipe(maxBrightness, 0, 0);
    delay(wait);
}

int Cyan(String command)
{
    colorWipe(0, maxBrightness, maxBrightness);
    delay(wait);
}

int RedWhite(String command)
{
    stripSetPixelColor2(maxBrightness,0,0,maxBrightness,maxBrightness,maxBrightness);
}

int RedGreen(String command)
{
    stripSetPixelColor2(maxBrightness,0,0,0,maxBrightness,0);
}

int RedBlue(String command)
{
    stripSetPixelColor2(maxBrightness,0,0,0,0,maxBrightness);
}

int RedWhiteCyan(String command)
{
    stripSetPixelColor3(maxBrightness,0,0,maxBrightness,maxBrightness,maxBrightness,0,maxBrightness,maxBrightness);
}

int Valentine (String commmand){
    colorWipe2(maxBrightness, 0, 0);
}

void colorWipe2(unsigned char red, unsigned char green, unsigned char blue)
{
    safety();
    uint16_t i;
for (int k=0;k<=50;k++)
{
  int m = i%10;
  if (m == 0)
  {
      safety();
  }
  
  for(int i=0; i <= 149; i+=2) 
  {
      strip.setPixelColor(i, strip.Color(255,50,147));
      strip.show();
      delay(30);
  }
    for(int i=1; i <= 149; i+=2) 
  {
      strip.setPixelColor(i, strip.Color(51,195,255));
      strip.show();
      delay(30);
  }
  for(int i=0; i <= 149; i++) 
  {
      strip.setPixelColor(i, strip.Color(207, 181, 59));
      strip.show();
      delay(30);
  }
}
    safety();
}

void stripSetPixelColor(unsigned char red, unsigned char green, unsigned char blue)
{
    safety();
    uint16_t i;
    for (int i = 0 ; i < strip.numPixels() ; i += 1 )
    {
        strip.setPixelColor(i, strip.Color(red,green,blue));
    }
    strip.show();
    safety();
}

void stripSetPixelColor2(unsigned char red, unsigned char green, unsigned char blue,unsigned char red2, unsigned char green2, unsigned char blue2)
{
    safety();
    uint16_t i;
    for (int i = 0 ; i < strip.numPixels() ; i += 2 )
    {
        strip.setPixelColor(i, strip.Color(red,green,blue));
        strip.setPixelColor(i+1, strip.Color(red2,green2,blue2));
    }
    strip.show();
    safety();
}

void stripSetPixelColor3(unsigned char red, unsigned char green, unsigned char blue,unsigned char red2, unsigned char green2, unsigned char blue2, unsigned char red3, unsigned char green3, unsigned char blue3)
{
    safety();
    uint16_t i;
    for (int i = 0 ; i < strip.numPixels() ; i += 3 )
    {
        strip.setPixelColor(i, strip.Color(red,green,blue));
        delay(30);
        strip.setPixelColor(i+1, strip.Color(red2,green2,blue2));
        delay(30);
        strip.setPixelColor(i+2, strip.Color(red3,green3,blue3));
        delay(30);
    }
    strip.show();
    safety();
}
    
void colorWipe(unsigned char red, unsigned char green, unsigned char blue)
{
    safety();
    uint16_t i;
  for(int i=0; i <= 149; i++) 
  {
      strip.setPixelColor(i, strip.Color(red,green,blue));
      strip.show();
      delay(30);
  }
  safety();
}

void colorWipe6(unsigned char red, unsigned char green, unsigned char blue)
{
    safety();
    int j;
  for(int i=51; i <= 144; i=i+6) 
  {
      j=i;
      for(int k = 0;k<=5;k++)
      {
          strip.setPixelColor(j, strip.Color(red,green,blue));
          j++;
          strip.show();
      }
        
      delay(30);
  }
  safety();
}

void safety()
{
    EEPROM.clear();
    delay(800);
}
