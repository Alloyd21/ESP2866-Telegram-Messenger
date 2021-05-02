#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <stdbool.h>

bool messageSent = false;
bool ledOn = false;

const char* ssid = "WIFI NAME"; // Replace with your wifi name
const char* password = "PASSWORD"; // Replace with your wifi password

#define BOTtoken "TOKEN"   // Replace with your telegram Bot Token
#define CHAT_ID "CHAT_ID" // Replace with your Chat ID

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int buttonPin = 4;     
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
 
  configTime(0, 0, "pool.ntp.org");     
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
}


void loop() {
    // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      if (messageSent == false && ledOn == true) {
        bot.sendMessage(CHAT_ID, "Alert: Adam needs help", "");
        messageSent = true;
      }
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(100);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  // turns on the LED every second button press by checking whether buttonPushCounter can / 2
  if (buttonPushCounter % 2 == 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    ledOn = true;
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    ledOn = false;
    messageSent = false;
  }
}