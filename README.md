# RTCMinHeartBeat
Get a minute cadenced heartbeat on your Arduino boards using a D3231 Real Time Clock

## Summary :
It deals with an Arduino library handling D3231 Real Time Clock module (like many already existing ones...).
Its particularity is to implement a minute cadenced heartbeat using D3231 alarm.
Typical usage is for any device triggering an action every minute.
Library provides additionnal functions to get time and date information in string format.

## Hardware Requisite :
- Any Arduino board
- A D3231 Real Time Clock (RTC) module, with a 10k Ohm resistor placed between INT and VCC pins
- D3231 power (vcc/gnd pins) and I2C bus (sda/scl pins) conected to the Arduino
- D3231 INT/SQW pin connected to Arduino pin 2 (or any pin usable for interrupts, check your Arduino board hardware)

![Hardware picture](https://github.com/franckmarini/RTCMinHeartBeat/blob/pictures/Arduino_D3231_pic.jpg)

## API
- set() function : set new time&date in RTC
- read() function : get up-to-date RTC time&date infos
- pinconfig() function : provides the Arduino pin number connected to the RTC Interrupt pin ("INT/SWQ"). Once executed, heartbeat is execution is started.
- heartBeat() function : returns TRUE once per minute. Function to be called cyclically.

## Additional functions
- dayString() : returns day of week (sunday...saturday) in a string
- dateString() : returns date (DD MM YYYY) in a string
- timeString() : returns time (HH:MM:SS) in a string
- toString() : returns day + date + time in a string

## Code Example
```
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
```