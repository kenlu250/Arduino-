//測試自走車馬達是否能夠轉動
//時間:2020/5/1

#include <Servo.h>
Servo myservoL,myservoR;

const byte ServoR_pin = 12;
const byte ServoL_pin = 13;  // 伺服機的控制埠 D11
int sensor;

void setup() 
{ 
  Serial.begin(9600);          // 啟用串列埠
  myservoR.attach(ServoR_pin);
  myservoL.attach(ServoL_pin);
  //myservoR.write(90); 
  // myservoL.write(90);
} 
 
void loop() 
{
  // 判斷串列埠緩衝區有無資料
  if (Serial.available()) {
    sensor=Serial.parseInt();        // 從串列埠緩衝區中讀取下一個有效的整數資料
    Serial.println(sensor);          // 在 Serial Monitor 中顯示訊息
  }
  
  if (sensor==2) { //直行，左逆右順
      myservoR.write(0);
      myservoL.write(180);
      //delay(50);
    }
  else if (sensor==001) { //右轉，左逆右停
      myservoR.write(90);
      myservoL.write(180);
      //delay(50);
    }  
   else if (sensor==100) { //左轉，左停右順
      myservoR.write(0);
      myservoL.write(90);
      //delay(50);
    }
}
