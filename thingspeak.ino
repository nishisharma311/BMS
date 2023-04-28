#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//------- WI-FI details ----------//
char ssid[] = "OPPO F11"; //SSID here
char pass[] = "nishi311"; // Passowrd here

//----------- Channel details ----------------//
unsigned long Channel_ID = 2124894; // Your Channel ID
const char * myWriteAPIKey = "AOKO0P77GZ8Y4OP7"; //Your write API key

const int Field_Number_1 = 1;
const int Field_Number_2 = 2;
String value = "";
int value_1 = 0, value_2 = 0;
int x, y;
WiFiClient  client;
void internet()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  internet();
}

void loop()
{
  internet();
  if (Serial.available() > 0)
  {
    //Serial.print("hello");
    delay(100);
    while (Serial.available() > 0)
    {
      value = Serial.readString();
      //Serial.println(value);
      if (value[0] == '*')
      {
        if (value[5] == '#')
        {
          value_1 = ((value[1] - 0x30) * 10 + (value[2] - 0x30));
          value_2 = ((value[3] - 0x30) * 10 + (value[4] - 0x30));
        }
        Serial.println(value_1);
      }
    }
      ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
  delay(15000);
  ThingSpeak.writeField(Channel_ID, Field_Number_2, value_2, myWriteAPIKey);
  delay(15000);
  value = "";
  }
}
