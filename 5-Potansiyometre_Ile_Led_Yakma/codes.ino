#define Led 3
#define potPin A0

void setup()
{
 
}

void loop()
{
  int deger = analogRead(potPin);
  deger = map(deger,0,1023,0,255);
  analogWrite(Led, deger);
}