 void setup() {
    pinMode(9,OUTPUT); //RED
    pinMode(10,OUTPUT); //BLUE
    pinMode(11,OUTPUT);  // GREEN

  }

  void loop() {
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(1000);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(1000);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(1000);
  }
