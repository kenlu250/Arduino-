//使用模組偵測空氣中pm2.5含量並顯示在LCD上
//時間:2020/6/20

#include <math.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
char str1[]="dust = ";
char str2[]="ug/m3";
int VoPin = A0; 
int ledPower = 2;  
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
int val = 0;
int temp;
float dustVolts = 0;
float dustDensity = 0;  

void setup(){
  lcd.init();
  lcd.backlight();
  pinMode(ledPower,OUTPUT);
}
  
void loop(){
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);  
  val = analogRead(VoPin);    // read the dust value  
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime); 
  dustVolts = val * (5.0 / 1024.0); 
  dustDensity = 0.17 * dustVolts - 0.1; //mg
  dustDensity=dustDensity*1000; //ug
  lcd.setCursor(0,0);
  printStr(str1);
  temp=dustDensity*10;
  lcd.print(temp/100);
  lcd.print(temp%100/10);
  lcd.print(".");
  lcd.print(temp%10);
  printStr(str2);
  delay(1000);
}
void printStr(char *str)
{
  int i=0;
  while(str[i]!='\0')
  {
    lcd.print(str[i]);  
    i++;
  }  
} 
