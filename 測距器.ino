#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int echo=8; 
const int trig=9;  

void setup() {
  Serial.begin(9600); //初始化串列埠，設定鮑率9600bps。
  pinMode(trig,OUTPUT); //設定數位接腳9 為輸出模式。
  pinMode(echo,INPUT); //設定數位接腳8 為接收模式。

  lcd.begin(16, 2); // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
  lcd.backlight();  //開啟背光

}
  
void loop() {
  unsigned long cm; //距離(單位:公分)。
  cm=ping(trig, echo); //讀取物體距離。

  lcd.print("distance=");//將結果輸出在LCD
  
  if(cm < 100){
    lcd.print(cm);//將結果輸出在LCD
    lcd.print("cm");//將結果輸出在LCD
  }
  else {
    lcd.print("error");//將結果輸出在LCD
  }
  
  delay(700);//延遲
  lcd.clear();//清除
  }
  
int ping(int trig, int echo){
  unsigned long cm; //距離(單位:公分)。
  unsigned long duration; //脈寬(單位:微秒)。
  
  pinMode(trig,OUTPUT); //設定數位接腳 2為輸出模式。
  digitalWrite(trig,LOW); //輸出脈寬 5µs的脈波啟動PING)))。
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  
  digitalWrite(echo,LOW);
  pinMode(echo,INPUT); //設定數位接腳 2為輸入模式。
  duration=pulseIn(echo,HIGH); //讀取與物體距離成正比的脈波HIGH時間。
  cm=duration/29/2; //計算物體距離(單位:公分)。
  return cm; //傳回物體距離(單位:公分)
} 
