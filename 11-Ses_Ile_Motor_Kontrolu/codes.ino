#define sensorPin 3
#define motorPin 5

int  motorDurum = LOW;

void setup() {
    pinMode(sensorPin, INPUT);
    pinMode(motorPin, OUTPUT);
}

void loop() {   
    if(digitalRead(sensorPin)) {
        if(motorDurum == LOW) {
            motorDurum = HIGH;
        } else {
            motorDurum = LOW;
        }
        digitalWrite(motorPin, motorDurum);
    }
    delay(50);
}