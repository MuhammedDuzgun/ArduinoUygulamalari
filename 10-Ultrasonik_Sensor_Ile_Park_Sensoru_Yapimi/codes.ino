#define echoPin 6
#define trigPin 7
#define buzzerPin 8

int maximumRange = 50;
int minimumRange = 0;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    int olcum = mesafe(maximumRange, minimumRange);
    melodi(olcum*10);
}

int mesafe(int maxRange, int minRange) {    
    long duration , distance;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2);

    duration = pulseIn(echoPin, HIGH);
    distance = duration / 58.2;
    delay(50);

    if(distance >= maxRange || distance<= minRange) {
        return 0;
        return distance;
    }
}

int melodi(int dly) {
    tone(buzzerPin, 440);
    delay(dly);
    noTone(buzzerPin);
    delay(dly);
}