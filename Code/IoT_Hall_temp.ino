#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
#include "ThingSpeak.h"
#include <WiFi.h>

//----------------  Fill in your credentails   ---------------------
char ssid[] = "XXXXXXXXX";             // your network SSID (name) 
char pass[] = "XXXXXXXXX";         // your network password

unsigned long myChannelNumber = 0;  // Replace the 0 with your channel number(ID)
const char * myWriteAPIKey = "XXXXXXXXXXXXXXXX";    // Paste your ThingSpeak Write API Key between the quotes 
//------------------------------------------------------------------

WiFiClient  client;

String myStatus = "";

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client); 
}

void loop() {

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println("place your SSID here");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

float temp = ((temprature_sens_read()-32)/1.8); // reading temperature values
float hall = hallRead(); // reading hall sensor values

  ThingSpeak.setField(1, hall); // for a multivalue upload we need to have fields set according to the order done in the thingspeak account
  ThingSpeak.setField(2, temp);
  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to corresponding fields.
   int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful."); // If upload is successfull you will get this message
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  delay(10000); // Wait 20 seconds before sending a new value (for a free thingspeak account that is the response rate(15 sec here and there) of the servers so chill!)
}
