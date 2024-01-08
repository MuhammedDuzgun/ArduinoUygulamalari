int sensorPin = 9;
int buzzerPin = 8;
int veri;

void setup() {
    pinMode(sensorPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    veri = digitalRead(sensorPin);
    if(veri == true) {
        tone(buzzerPin, 440);
        delay(100);
        noTone(buzzerPin);
        delay(100);
    } else {
        noTone(buzzerPin);
    }
}