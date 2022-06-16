#include<M5Stack.h>
#include<DHT12.h>
#include<Wire.h>

DHT12 DHT(&Wire);
const int di=2;

void setup() {
  // put your setup code here, to run once:
M5.begin();
Wire.begin();
pinMode(di, INPUT_PULLUP);
dacWrite(25, 0);
M5.Lcd.setCursor(100, 0, 4);
M5.Lcd.print("FARMER");
}
uint16_t d_data;

void loop() {
  // put your main code here, to run repeatedly:
float tmp=DHT.getTemperature();
float hum=DHT.getHumidity();
d_data = digitalRead(di);
M5.Lcd.setCursor(30, 100, 4);
M5.Lcd.printf("Temp:%2.1f Humi:%2.0f%%", tmp, hum);
M5.Lcd.setCursor(30, 120, 4);
M5.Lcd.printf("Sinar:%0d\n", d_data);
delay(200);
}
