/*
 * Auther: Terry C.
 * Device Usesage: SHT35 Humidy device for USDA cotton
 * Date: 10/16/2022
 * Verson: v4.0
 * Decraption: 
 * This code uses I2C and SPI. the sensors is set as an I2C connention 
 * on address 0x44. The Oled is set as a SPI device using a converter
 * to dispaly the sensor reading. 
 */
#include <Wire.h>
#include "Adafruit_LiquidCrystal.h"
#include "SHTSensor.h"

SHTSensor sht;

Adafruit_LiquidCrystal lcd(3, 2, 4);
/*
 * The circuit:
 * 5V to Arduino 5V pin
 * GND to Arduino GND pin
 * CLK to Digital 2
 * DAT to Digital 3
 * LAT to Digital 4
*/
/*
 * wiring color for sensor
 * RED -- Vcc
 * GREEN -- SDA
 * YELLOW -- SCK
 * BLACK -- GND
 */

void setup() {
   Wire.begin();
   lcd.begin(16, 2);
   sht.init()
   sht.setAccuracy(SHTSensor::SHT_ACCURACY_HIGH);
}

void loop() {
   sht.readSample();
  // GET TEMP AND HUMIDITY THEN CONVIRT TEMPC INTO FARINHIGHT.
   float tempc = sht.getTemperature();
   float h = sht.getHumidity();
   float tempf = tempc*1.8+32;
   
   lcd.setCursor(0,0);
   lcd.print("Temp: "); lcd.print(tempf); lcd.println(" F");
   lcd.setCursor(0,10);
   lcd.print("HUM: "); lcd.print(h);lcd.println(" %RH");
   // ADDS AND CONSTRATINT TO HUMIDITY TO KEEP IN WITH RANG FOR LEDS. 
   // WITH THE IF FUNCHION. 

    delay(5000);
 
 }
