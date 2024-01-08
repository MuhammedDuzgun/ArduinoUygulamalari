int sensorPin = A0;
int esikDegeri = 100;
int buzzerPin = 8;
int veri;

void setup() {
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    veri = analogRead(sensorPin);
    if(veri > esikDegeri) {
        tone(buzzerPin, 440);
        delay(100);
        noTone(buzzerPin);
        delay(100);
    } else {
        noTone(buzzerPin);
    }
}