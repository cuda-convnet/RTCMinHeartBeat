// Sketch outputs Time and Date infos on Serial port every minute

#include <RTCMinHeartBeat.h>

TimeDate td; // time and date infos object

void setup() {
  Serial.begin(9600);
  rtc.configPin(2); // notify which Arduino pin (here pin 2) is connected to D3231 RTC INT pin. Heartbeat is started!
}

void loop() {
  if (rtc.heartBeat()) // true once every minute
  {
    rtc.read(td);  // Get up-to-date Time&Date from the D3231 RTC
    Serial.println(td.dayString()); // print day of week (sunday...saturday) 
    Serial.println(td.dateString()); // print date (DD MM YYYY)
    Serial.println(td.timeString()); // print time (HH:MM:SS)
    Serial.println(td.toString()); // print all info (day of week followed by date fallowed by time)
  }
}
