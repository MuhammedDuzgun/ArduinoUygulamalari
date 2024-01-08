#include <virtuabotixRTC.h>

int CLK_PIN = 6;
int DAT_PIN = 7;
int RST_PIN = 8;

virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);

void setup() {
    Serial.begin(9600);
    myRTC.setDS1302Time(10, 10, 14, 4, 13, 9, 2018);
}

void loop() {
    myRTC.updateTime();
    Serial.print("Tarih / Saat : ");
    Serial.print(myRTC.dayofmonth);
    Serial.print("/");
    Serial.print(myRTC.month);
    Serial.print("/");
    Serial.print(myRTC.year);
    Serial.print("/");
    Serial.print(myRTC.hours);
    Serial.print(":");
    Serial.print(myRTC.minutes);
    Serial.print(":");
    Serial.print(myRTC.seconds);
    delay(1000);
}
