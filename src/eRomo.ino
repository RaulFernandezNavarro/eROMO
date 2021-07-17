#include "Base64.h"
#include "epd7in5.h"
#include "WiFi.h"
#include <Servo.h>

#define BUTTON_PIN_BITMASK 0x200000000 // 2^33 in hex
#define Threshold 40

Servo myservo;
int pos = 0;

RTC_DATA_ATTR bool state = false;
const char* ssid     = "****";   //your network SSID
const char* password = "****";   //your network password
const char* myDomain = "script.google.com";
String myScript = "/macros/s/XXXXXXXXXXXXXXXXXXXXXX/exec";    //Replace with your own url
String myFolder = "Romke"; //Name of the user's folder

void callback(){
  //placeholder callback function
}

void setup() {
  // put your setup code here, to run once:
  //EPD_initSPI();
  //Drive_setup(ssid, password, myDomain, myScript, myFolder);
//  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
//  digitalWrite(25, HIGH);  
  digitalWrite(26, HIGH);
//  delay(2000);
//  digitalWrite(25, LOW);
//  delay(5000);
//  digitalWrite(25, HIGH); 
//  delay(5000);
//  digitalWrite(25, LOW);
//  delay(5000);
//  digitalWrite(25, HIGH); 
//  WiFi.mode(WIFI_STA);
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    digitalWrite(25, LOW);
//    delay (100);
//    digitalWrite(25, HIGH);
//    }
//  digitalWrite(25, HIGH);

myservo.attach(25);
  for (pos = 170; pos >= 5; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 5; pos <= 170; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
//  esp_sleep_enable_timer_wakeup(30000000); //sleep 30s in us
  touchAttachInterrupt(T3, callback, Threshold);
  esp_sleep_enable_touchpad_wakeup();
//  esp_sleep_pd_config(ESP_PD_DOMAIN_MAX, ESP_PD_OPTION_OFF);
//  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
//  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_OFF);
//  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_FAST_MEM, ESP_PD_OPTION_OFF);
 // esp_sleep_enable_ext1_wakeup(BUTTON_PIN_BITMASK,ESP_EXT1_WAKEUP_ANY_HIGH);
  //esp_sleep_enable_ext0_wakeup(GPIO_NUM_X, level) // x = pin, level = 1/0, whatever triggers

  //Request_image();

   //last of all
   digitalWrite(26, LOW);
  esp_deep_sleep_start();
}

void loop() {
//empty

}
