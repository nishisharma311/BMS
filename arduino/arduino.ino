#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

String str;

void setup(){
Serial.begin(115200);
dht.begin();
}

void loop(){
//float h = dht.readHumidity();
// Read temperature as Celsius (the default)
//float t = dht.readTemperature();

//Serial.println(h);
    Serial.print('*'); // Starting char
    Serial.print(dht.readTemperature()); //2 digit data
    Serial.print(dht.readHumidity()); //2 digit data
    Serial.print('#'); // Ending char
    delay(1000);  
}