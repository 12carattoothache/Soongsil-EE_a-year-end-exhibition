#define RED 11 // RGB LED Module의 RED 핀
#define GREEN 10 // RGB LED Module의 GREEN 핀
#define BLUE 9 // RGB LED Module의 BLUE 핀
 
void setup(){
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
}
 
void loop() {
    // RED
    digitalWrite(BLUE, LOW);
    delay(1000);
    digitalWrite(RED,LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    delay(1000);
    //GREEN
    
    delay(1000);
    digitalWrite(RED,LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    delay(1000);
    
    }  
