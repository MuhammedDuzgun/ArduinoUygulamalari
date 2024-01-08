String agAdi = "Robotistan";
String agSifresi = "fortinet";

int motorPin1 = 3, motorPin2 = 4, motorPin3 = 5, motorPin4 = 6;

void setup() {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    Serial.begin(115200);
    Serial.println("AT");
    while(! Serial.find("OK")) {
        Serial.println("AT");
    }
    delay(1000);
    Serial.println("AT+RST");
    delay(1000);
    while(!Serial.find("ready"));
    delay(1000);
    Serial.println("AT+CWMODE=1");
    while(!Serial.find("OK"));
    Serial.print("AT+CWJAP=\""+agAdi+"\",\""+agSifresi+"\"");
    while(!Serial.find("OK"));
    Serial.print("AT+CIFSR\r\n");
    Serial.print(espOkuma(1000));
    serialTemizle(2000);
    Serial.print("AT+CIPSERVER=1, 80\r\n");
    serialTemizle(2000);
}

void loop() {
    if(Serial.available()) {
        if(Serial.find("+IPD,")) {
            delay(200);
            int connectionId = Serial.read() - 48;
            String komut = espOkuma(1000);
            if(komut.indexOf("step=ileri") != -1) {
                for(int adim = 0; adim<5; adim++) {
                    stepIleri(50);
                }
            } else if(komut.indexOf("step=geri") != -1) {
                for(int adim = 0; adim < 5; i++) {
                        stepGeri(50);
                }
            }
            String sayfa = "<h1>Step Motor Kontrol</h1><br>";
            sayfa += "<br><a href=\"?step=ileri\"><button><h1>Ileri</h1></button>";
            sayfa += "<br><a href=\"?step=geri\"><button><h1>Geri</h1></button>";
            komut = "AT+CIPSEND=";
            komut += connectionId;
            komut += ",";
            komut += sayfa.length();
            komut += "\r\n";
            Serial.print(komut);
            delay(1000);
            Serial.print(sayfa);
            delay(1000);
            komut = "AT+CIPCLOSE=";
            komut += connectionId;
            komut += "\r\n";
            Serial.print(komut);
        }
    }
}

String espOkuma(long int zamanAsimi) {
    long int baslnagic = milis();
    String gelen;
    while(milis() - baslnagic < zamanAsimi) {
        if(Serial.available() > 0) {
            char c = Serial.read();
            gelen += c;
        }
    }
    gelen.replace("AT+", "");
    return gelen;
}

void serialTemizle(long int zamanAsimi) {
    long int baslnagic = milis();
    while(milis() - baslnagic < zamanAsimi) {
        if(Serial.available() > 0) {
            Serial.read();
        }
    }
}

void stepIleri(int beklemeSuresi) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    delay(beklemeSuresi);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    delay(beklemeSuresi);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin1, LOW);
    delay(beklemeSuresi);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, HIGH);
    delay(beklemeSuresi);
}

void stepGeri() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, HIGH);
    delay(beklemeSuresi);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin1, LOW);
    delay(beklemeSuresi);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    delay(beklemeSuresi);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin1, LOW);
    delay(beklemeSuresi);   
}