
// Hx711.DOUT - pin #A1
// Hx711.SCK - pin #A0

// LCD.RS - pin 12
// LCD.En - pin 11
// LCD.D4 - pin 5
// LCD.D5 - pin 4
// LCD.D6 - pin 3
// LCD.D7 - pin 2


#include "HX711.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7) ;
#define BACKLIGHT 10

int bl=128;



HX711 scale(A2, A1); // lcd is using A0... works for other than A1,A0 ?

void setup() {
  Serial.begin(115200);
  lcd.begin(16,2);
  lcd.clear();
  scale.set_scale();                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();	
  scale.set_scale(-1350.0);  
  
  pinMode(BACKLIGHT,OUTPUT);	
}

void loop() {
  float pounds;
  long duration;
  char key;
  pounds=scale.get_units(1);
  analogWrite(BACKLIGHT,bl);
  Serial.println(pounds);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(pounds);
  key=keyToChar(readKey());
  if(key != 'N'){
    if(key == 'D') bl-=10;
    if(key == 'U') bl+=10;
    bl=bl %255;
  } 
  analogWrite(BACKLIGHT,bl);
}



int readKey() {
  static int NUM_KEYS=5;
  static int adc_key_val[5] ={      
    30, 150, 360, 535, 760         };
  int k, input;
  input=analogRead(0);
  for (k = 0; k < NUM_KEYS; k++)  {
    if (input < adc_key_val[k])    {
      return k;
    }
  }
  if (k >= NUM_KEYS)
    k = -1;     // No valid key pressed
  return k;
}

char keyToChar(int k) {
  switch(k){
  case -1: 
    return 'N';
    break;
  case 0: 
    return 'R';
    break;
  case 1: 
    return 'U';
    break;
  case 2: 
    return 'D';
    break;
  case 3: 
    return 'L';
    break;
  case 4: 
    return 'S';
    break;
  default: 
    return 'w';
  }
}




