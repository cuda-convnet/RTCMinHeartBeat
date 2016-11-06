#include <RTCMinHeartBeat.h>

TimeDate td; // time and date infos variable

void setup() {
  Serial.begin(9600);
  rtc.ConfigPin(2); // notify which Arduino pin (here pin 2) is connected to D3231 RTC INT pin. Minute heartbeat execution is started!
  Serial.println("Pin configured. RTC will provide a heartbeat every min...");

  // Example of RTC time and date SET, TO BE DONE ONLY ONCE !
  // Set to tuesday november 1st, 2016, 13h45 and 33sec
  td.day = tuesday; 
  td.date = 1; td.month = 11; td.year = 2016;
  td.hour = 13; td. min = 45; td.sec = 33;
  rtc.set(td); // update RTC time and date info
  Serial.print("RTC SET command, date and time set to : "); Serial.println(td.toString());
}


void loop() {
  if (rtc.heartBeat()) // true once every minute
  {
    Serial.println("### RTC Hearbeat !! ###");

    // lines below print up-to-date time and data
    rtc.read(td);  // Get up-to-date Time&Date from the D3231 RTC
    Serial.println(td.dayString()); // print day of week (sunday...saturday) 
    Serial.println(td.dateString()); // print date (DD MM YYYY)
    Serial.println(td.timeString()); // print time (HH:MM:SS)
    Serial.println(td.toString()); // print all info (day of week followed by date fallowed by time)
  }
}
