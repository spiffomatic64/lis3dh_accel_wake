// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 18 //SCL
#define LIS3DH_MOSI 23 //SDA 
#define LIS3DH_MISO 19 //SDO

// Chip Select pins
#define CS_1 25 //CS
#define CS_2 26
#define CS_3 27
#define CS_4 13
#define CS_5 5
#define CS_NUM 5

#define intPin 15
#define sensitivity 16

Adafruit_LIS3DH lis;
uint8_t ref =0;

void setup(void) {
  

  Serial.begin(115200);
  Serial.println("LIS3DH test!");

  lis = Adafruit_LIS3DH(CS_1);

  
  if (!lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
  } else {
    Serial.println("LIS3DH found!");
    lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
    
    ref = lis.getReference();
    Serial.print("Reference: ");
    Serial.println(ref);
    //lis.setReference(ref);
    //ref = lis.getReference();
    //Serial.print("Reference: ");
    //Serial.println(ref);
    lis.setupLowPowerWakeMode(sensitivity,intPin);
  
    Serial.print("Range = "); 
    Serial.print(2 << lis.getRange());  
    Serial.println("G");
  }
}

void loop() {
  int pin;
  uint8_t ret;
  for(int i=0; i<20; i++)
  {
    pin = analogRead(intPin);
    Serial.print("Pin: ");
    Serial.println(pin);
    delay(100);
  }
  ret = lis.clearInterrupt();
  Serial.print("Interrupt ret: ");
  Serial.println(ret);
  //ref = lis.getReference();
  //Serial.print("Reference: ");
  //Serial.println(ref);
}
