#include  <SoftwareSerial.h>
#include <dht11.h>

String agAdi = "Robotistan";
String agSifresi = "fortinet;"

int rxPin = 10;
int txPin = 11;
int dht11Pin = 2;

String ip = "184.106.153.149";
float sicaklik, nem;
dht11 DHT11;

SoftwareSerial esp(rxPin, txPin);

void setup() {
    Serial.begin(9600);
    esp.begin(115200);
    esp.println("AT");
    while(!esp.find("OK")) {
        esp.println("AT");
        Serial.println("ESP8266 Bulunamadı.");
    }
    esp.println("AT+CWMODE=1");
    while(!esp.find("OK")); 
    Serial.println("Aga Baglaniliyor...");
    esp.println("AT+CWJAP=\"+agAdi+"\",\""+agSifresi+"\"");
    while(!esp.find("OK"));
    Serial.println("Aga Baglanildi");
    delay(1000);
}

void loop() {
    esp.println("AT+CIPSTART=\"TCP\", \""+ip+"\",80");
    if(esp.find("Error")) {
        Serial.println("AT+CIPSTART Error");
    }
    DHT11.read(dht11Pin);
    sicaklik = (float) DHT11.temperature;
    nem = (float) DHT11.humidity;
    String veri = "GET /update?key=11NOMDXGH6DIVEXB&field1=";
    veri += String(sicaklik);
    veri += "&field2=";
    veri += nem;
    veri += "r\n\r\n";
    Serial.println(veri);
    Serial.println("Veri Gonderildi");
    delay(1000);
}

Serial.println("Baglanti Kapatildi");
esp.println("AT+CIPCLOSE");
delay(36000);