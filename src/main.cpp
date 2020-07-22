#include <Arduino.h>
#include <InternetTime.h>

InternetTime iTime;

void setup()
{
  Serial.begin(9600);

  iTime
      .timeZone(0)
      .dst(0)
      .setup([] {
        Serial.println("setupInternetTime is ready!");
      });
}

void loop()
{
  delay(1000);
  Serial.println(iTime.currentTime());
}
