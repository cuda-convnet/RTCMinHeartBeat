// Sketch changes RTC time by one hour

#include <RTCMinHeartBeat.h>

TimeDate td; // time and date infos object

void setup() {
  Serial.begin(9600);
  rtc.read(td);  // Get up-to-date Time&Date from the D3231 RTC
  td.hour+=1; // add one hour to RTC clock
  rtc.set(td); // update RTC time and date
  Serial.println(td.toString());
}

void loop() {}
