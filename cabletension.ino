
// Hx711.DOUT - pin #A1
// Hx711.SCK - pin #A0

// LCD.RS - pin 12
// LCD.En - pin 11
// LCD.D4 - pin 5
// LCD.D5 - pin 4
// LCD.D6 - pin 3
// LCD.D7 - pin 2

#include "HX711.h"

Hx711 scale(10,A1, A0);

void setup() {
  Serial.begin(115200);
}

void loop() {
  float grams;
  long start = millis();
  long duration;
  grams=scale.getGram();
  duration = millis() - start;
   
  Serial.print(duration);Serial.print(",");Serial.println(grams);

 // delay(200);
}

