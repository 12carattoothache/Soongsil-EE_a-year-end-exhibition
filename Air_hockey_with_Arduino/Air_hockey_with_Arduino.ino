// LCD 화면 출력을 위한 코드
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned long previousMillis1 = 0;
unsigned long interval1 = 1000; // interval in millisecond
unsigned int counter = 0;

int timeRST = 0; // time restart
int hour = 45;
int minute = 5;
int second = 6;

int second_Total = -5; // 초 합계

int reset = 0;

int score1 = 0;
int score2 = 0;

int pin_player1 = 2;
int pin_player2 = 3;
int pin_start = 5;



void setup() {

  lcd.init();

  lcd.backlight();
  digitalWrite(2,INPUT_PULLUP); // player1
  digitalWrite(3,INPUT_PULLUP); // player2
  digitalWrite(5,INPUT_PULLUP); // start button

  lcd.setCursor(0, 0);
  lcd.print("Air Hockey");
  lcd.setCursor(0, 1);
  lcd.print("by.JH,SH,EJ,SY");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("P1= ");
  lcd.setCursor(4, 0);
  lcd.print(score1);
  lcd.setCursor(7, 0);
  lcd.print("/  P2= ");
  lcd.setCursor(14, 0);
  lcd.print(score2);
  lcd.setCursor(0, 1);
  lcd.print("PRESS START");

  // lcd 초기 세팅
  
  

}

void loop() {
  
  int START = digitalRead(pin_start);
  if (START == LOW){
    second_Total = 0;
    score1 = 0;
    score2 = 0;
  }

  while (second_Total > -2){

    // 아래는 게임을 리셋하는 카운트 (약 3초동안 유지)

    int START = digitalRead(pin_start);
    
    if(START == LOW){
      timeRST++;
      delay(10);
    }
    else{
      timeRST = 0;
    }
    
    if (timeRST >= 50) {
      second_Total = -5;
      score1=0;
      score2=0;
      
      lcd.clear();

      lcd.print(" Reset the Game ");
      timeRST = 0;
      delay(1000);
      lcd.clear();
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("P1= ");
      lcd.setCursor(4, 0);
      lcd.print(score1);
      lcd.setCursor(7, 0);
      lcd.print("/  P2= ");
      lcd.setCursor(14, 0);
      lcd.print(score2);
      lcd.setCursor(0, 1);
      lcd.print("PRESS START");
      delay(200);
      break;
    }

    if (millis() - previousMillis1 > interval1) {
      previousMillis1 = millis(); 

      second_Total++;

      hour = ((second_Total / 60) / 60);  // 초를 시간 단위로 환산
      minute = (second_Total / 60) % 60; // 초를 분 단위로 환산
      second = second_Total % 60;       



      lcd.setCursor(0, 1);
      lcd.print("Play Time: "); // 게임 진행 시간

      if (minute < 10) lcd.print("0");
      lcd.print(minute);

      lcd.print(":");
      if (second < 10) lcd.print("0");
      lcd.print(second);

    }
    

    lcd.setCursor(0, 0);
    lcd.print("P1= ");
    lcd.setCursor(4, 0);
    lcd.print(score1);
    lcd.setCursor(7, 0);
    lcd.print("/  P2= ");
    lcd.setCursor(14, 0);
    lcd.print(score2);

    //아래는 1번 플레이어에게 +1점 부여
    
    int countertime1 = digitalRead(pin_player1);
    if (countertime1 == LOW) {
      delay(120);
      score1++;
    }

    //아래는 2번 플레이어에게 +1점 부여
    
    int countertime2 = digitalRead(pin_player2);
    if (countertime2 == LOW) {
      delay(120);
      score2++;

    }

    if (score1 >= 3 && score2 < 3) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(6,1);
      lcd.print("P1 Win");
      delay(5000);
      break;
      
    }
    
    if (score1 < 3 && score2 >= 3) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Congratulations!");
      lcd.setCursor(6,1);
      lcd.print("P2 Win");
      delay(5000);
      break;
 
    }

  }
  
}
