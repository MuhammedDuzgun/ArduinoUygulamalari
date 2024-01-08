#define Button 8
#define Led 9

void setup() {

pinMode(Button, INPUT);
pinMode(Led, OUTPUT);

}

void loop() {

bool buttonState = digitalRead(Button);
if(buttonState == 1) {
  digitalWrite(Led , HIGH);
} else {
  digitalWrite(Led , LOW);
}


}
