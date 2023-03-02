// Omar Faruk Badhon 
// Email: omargarukbadhon@gmail.com 

// Read 4 DS18B20 temp. sensor data with one port of Arduino 

// Library for this project
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h>

StaticJsonDocument<120> doc;

// Data wire is plugged into port 12 on the Arduino
#define ONE_WIRE_BUS 12
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// We'll use this variable to store device address
DeviceAddress tempDeviceAddress1= {0x28, 0xB0, 0xD6, 0x03, 0x00, 0x00, 0x00, 0x53}; 
DeviceAddress tempDeviceAddress2= {0x28, 0xC4, 0xCC, 0x02, 0x00, 0x00, 0x00, 0x59}; 
DeviceAddress tempDeviceAddress3= {0x28, 0x11, 0x58, 0x77, 0x91, 0x14, 0x02, 0x1F};
DeviceAddress tempDeviceAddress4= {0x28, 0x84, 0x42, 0x77, 0x91, 0x0F, 0x02, 0x4B};   


void setup(void) {
  // start serial port
  Serial.begin(9600);
  
  // Start up the library
  sensors.begin();
  
  }

  
void loop(void) { 
    sensors.requestTemperatures(); // Send the command to get temperatures
    float tempC = sensors.getTempC(tempDeviceAddress1);
    doc["T1"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress2);
    doc["T2"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress3);
    doc["T3"] = tempC;
    tempC = sensors.getTempC(tempDeviceAddress4);
    doc["T4"] = tempC;


  // data store in a json file 
  serializeJson(doc, Serial);
  Serial.println();
    
  delay(1000);
}
  
