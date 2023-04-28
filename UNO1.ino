#include <dht.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); //tx and rx
dht DHT;  
#define DHTxxPIN 4
int ack;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(115200);
}
void loop()
{
  ack = 0;
  int chk = DHT.read11(DHTxxPIN);
  switch (chk)
  {
    case DHTLIB_ERROR_CONNECT:
      ack = 1;
      break;
  }
  if (ack == 0)
  {
    Serial.print("Temperature(*C) = ");
    Serial.println(DHT.temperature, 0);
    Serial.print("Humidity(%) = ");
    Serial.println(DHT.humidity, 0);
    Serial.println("-------------------------");
    //------Sending Data to ESP8266--------//
    mySerial.print('*'); // Starting char
    mySerial.print(DHT.temperature, 0); //2 digit data
    mySerial.print(DHT.humidity, 0); //2 digit data
    mySerial.println('#'); // Ending char
    delay(2000);
  }
  if (ack == 1)
  {
    Serial.print("NO DATA");
    Serial.print("\n\n");
    delay(2000);
  }
}
