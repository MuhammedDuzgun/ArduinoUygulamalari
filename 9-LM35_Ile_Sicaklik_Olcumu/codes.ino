int lm35Pin = AO;
int led = 8;
#define buzzer 9
int zaman = 50;
int okunanDeger = 0;
float sicaklikGerilim = 0;
float sicaklik = 0;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    okunanDeger = analogRead(lm35Pin);
    sicaklikGerilim = (okunanDeger/1023.0) * 5000;
    sicaklik = sicaklikGerilim / 10.0;
    Serial.println(sicaklik);
    
    if(sicaklik > 30) {
        digitalWrite(led, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(zaman);
        digitalWrite(led, LOW);
        digitalWrite(buzzer, LOW);
        delay(zaman);
    } else {
        digitalWrite(led, LOW);
        digitalWrite(buzzer, LOW);
    }
}