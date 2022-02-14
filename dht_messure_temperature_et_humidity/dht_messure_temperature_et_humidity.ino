#include <DHT.h>
#include <Adafruit_Sensor.h>
#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

void setup() {
Serial.begin(9600);
Serial.println(F("dht XX test"));
 dht.begin();
}
void loop() {

delay(2000);  
float h = dht.readHumidity();//tempaerature en celsius :par defaut
float t = dht.readTemperature();
float f = dht.readHumidity(true);// temeperature en F
if (isnan(h) || isnan(t) || isnan(f))
{
  Serial.println(F("Failed to send from DHT Sensor"));
  return ;
}
float hif = dht.computeHeatIndex(f,h);
float hic = dht.computeHeatIndex(f,h,false);
Serial.println(F("Humidity : "));
Serial.println(h);
Serial.println(F("Température: "));
Serial.println(t);
Serial.println(F("C"));
Serial.println(f);
Serial.println(F("F Heat index: "));
Serial.println(hic);
Serial.println(F("C"));
Serial.println(hif);
Serial.println(F("F"));

}
