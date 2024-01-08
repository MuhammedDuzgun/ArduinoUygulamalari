int esikDegeri = 400;
int buzzerPin = 9;
int deger;

void setup() {
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    deger = analogRead(A0);
    if(deger > esikDegeri) {
        tone(buzzerPin, 440);
        delay(100);
        noTone(buzzerPin);
        delay(100);
    } else {
        noTone(buzzerPin);
    }
}