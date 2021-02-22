#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;
#include <DHT.h>  // Including library for dht
#define DHTPIN D4          //pin where the dht11 is connected
 
DHT dht(DHTPIN, DHT11);


const char* ssid = "Pratiksha"; //Your Network SSID

const char* password = "Pratu105"; //Your Network Password
 
int bp = A0;
 int val=0;

//const int check1 = 2;     // the number of the pushbutton pin



WiFiClient client;

unsigned long myChannelNumber = 1309795; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "05I9BVZ0ZU6F2SU5"; //Your Write API Key

void setup()

{
// pinMode(check1, INPUT);
Serial.begin(9600);

delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);


ThingSpeak.begin(client);

}

void loop()
{
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 val=analogRead(bp);
 Serial.print(val);      
delay(1000);
h=74;
t=36;
val=125;
ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey); //Update in ThingSpeak
delay(15000);
ThingSpeak.writeField(myChannelNumber, 2,h, myWriteAPIKey); //Update in ThingSpeak
delay(15000);
ThingSpeak.writeField(myChannelNumber, 3,val, myWriteAPIKey); //Update in ThingSpeak
delay(15000);

                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");
}
