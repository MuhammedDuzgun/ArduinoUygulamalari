#define potPin A0
int value = 0;

void setup()
{
	Serial.begin(9600);
  	Serial.println("Pot Deger Okuma");
  
}

void loop()
{
  value = analogRead(potPin);
  Serial.println(value);
  delay(100);

}