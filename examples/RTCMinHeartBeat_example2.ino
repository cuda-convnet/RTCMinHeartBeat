// Sketch sets RTC time and date

#include <RTCMinHeartBeat.h>

TimeDate td; // time and date infos object

void setup() {
  Serial.begin(9600);
  // Set RTC to tuesday november 1st, 2016, 13h45 and 33sec
  td.day = tuesday; 
  td.date = 1; td.month = 11; td.year = 2016;
  td.hour = 13; td. min = 45; td.sec = 33;
  rtc.set(td); // update RTC time and date info
  Serial.print("RTC SET command, date and time set to : "); Serial.println(td.toString());
}

void loop() {}
