#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino.h> 

const char* ssid = "NETWORK_NAME";      // Replace with your WiFi SSID
const char* password = "NETWORK_PASSWORD";  // Replace with your WiFi password

// Define GPIO pins for your triggers
const int gpioPin1 = 5;  // GPIO5 corresponds to D1 on ESP8266
const int gpioPin2 = 4;  // GPIO4 corresponds to D2 on ESP8266
const int gpioPin3 = 0;  // GPIO0 corresponds to D3 on ESP8266
const int gpioPin4 = 2;  // GPIO2 corresponds to D4 on ESP8266
const int gpioPin5 = 14; // GPIO14 corresponds to D5 on ESP8266
const int gpioPin6 = 12; // GPIO12 corresponds to D6 on ESP8266

// Define corresponding event keys and names for IFTTT
const char* eventKey1 = "your_event_key_here";  // Event key for trigger 1
const String eventName1 = "your_event_name_here";  // Event name for trigger 1

const char* eventKey2 = "your_event_key_here";  // Event key for trigger 2
const String eventName2 = "your_event_name_here";  // Event name for trigger 2

const char* eventKey3 = "your_event_key_here";  // Event key for trigger 3
const String eventName3 = "your_event_name_here";  // Event name for trigger 3

const char* eventKey4 = "your_event_key_here";  // Event key for trigger 4
const String eventName4 = "your_event_name_here";  // Event name for trigger 4

const char* eventKey5 = "your_event_key_here";  // Event key for trigger 5
const String eventName5 = "your_event_name_here";  // Event name for trigger 5

const char* eventKey6 = "your_event_key_here";  // Event key for trigger 6
const String eventName6 = "your_event_name_here";  // Event name for trigger 6

void setup() {
  pinMode(gpioPin1, INPUT_PULLUP);
  pinMode(gpioPin2, INPUT_PULLUP); 
  pinMode(gpioPin3, INPUT_PULLUP); 
  pinMode(gpioPin4, INPUT_PULLUP); 
  pinMode(gpioPin5, INPUT_PULLUP);
  pinMode(gpioPin6, INPUT_PULLUP); 
  Serial.begin(115200);
  delay(10);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Check if GPIO pin 1 is grounded
  if (digitalRead(gpioPin1) == LOW) {
    Serial.println("GPIO pin 1 grounded. Triggering IFTTT event 1...");
    triggerIFTTT(eventName1, eventKey1);
    delay(5000);  // Delay to prevent multiple triggers from a single touch
  }
  
  // Check if GPIO pin 2 is grounded
  if (digitalRead(gpioPin2) == LOW) {
    Serial.println("GPIO pin 2 grounded. Triggering IFTTT event 2...");
    triggerIFTTT(eventName2, eventKey2);
    delay(5000);  // Delay to prevent multiple triggers from a single touch
  }
  
  // Check if GPIO pin 3 is grounded
  if (digitalRead(gpioPin3) == LOW) {
    Serial.println("GPIO pin 3 grounded. Triggering IFTTT event 3...");
    triggerIFTTT(eventName3, eventKey3);
    delay(5000);  // Delay to prevent multiple triggers from a single touch
  }
  
  // Check if GPIO pin 4 is grounded
  if (digitalRead(gpioPin4) == LOW) {
    Serial.println("GPIO pin 4 grounded. Triggering IFTTT event 4...");
    triggerIFTTT(eventName4, eventKey4);
    delay(5000);  // Delay to prevent multiple triggers from a single touch
  }
  
  // Check if GPIO pin 5 is grounded
  if (digitalRead(gpioPin5) == LOW) {
    Serial.println("GPIO pin 5 grounded. Triggering IFTTT event 5...");
    triggerIFTTT(eventName5, eventKey5);
    delay(5000);  // Delay to prevent multiple triggers from a single touch
  }
  
  // Check if GPIO pin 6 is grounded
  if (digitalRead(gpioPin6) == LOW) {
    Serial.println("GPIO pin 6 grounded. Triggering IFTTT event 6...");
    triggerIFTTT(eventName6, eventKey6);
    delay(5000);  // Delay to prevent multiple triggers from a single touch
  }
  
  delay(100);  // Adjust delay as needed
}

void triggerIFTTT(String eventName, const char* eventKey) {
  WiFiClient client;  // Create WiFiClient object
  HTTPClient http;
  String url = "http://maker.ifttt.com/trigger/" + eventName + "/with/key/" + eventKey;
  http.begin(client, url);  // Use updated begin method with WiFiClient object
  int httpResponseCode = http.POST("");  // Empty POST request
  if (httpResponseCode > 0) {
    Serial.print("IFTTT request sent, response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error sending IFTTT request, error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}
