//讓車子能夠跟著黑線的軌道線走
//時間:2020/5/22

#include <Servo.h>
Servo myservoL,myservoR;

const byte ServoR_pin = 12;
const byte ServoL_pin = 13; 
const byte Sensor_R = 6;
const byte Sensor_M = 7;
const byte Sensor_L = 8;
boolean R,M,L;



void setup() 
{ 
  myservoR.attach(ServoR_pin);
  myservoL.attach(ServoL_pin);
  pinMode(Sensor_R,INPUT);
  pinMode(Sensor_M,INPUT);
  pinMode(Sensor_L,INPUT);
   
} 
 
void loop() 
{
 
    R = digitalRead(Sensor_R);
    M = digitalRead(Sensor_M);
    L = digitalRead(Sensor_L);
  
  
  
    if ((L && R) && M) { //停止
        myservoR.write(90);
        myservoL.write(90);
      }
    else if (L && M) { //左急轉，右順左順
        myservoR.write(0);
        myservoL.write(0);
        delay(500);
      }
    else if (R && M) { //右急轉，右逆左逆
        myservoR.write(180);
        myservoL.write(180);
        delay(500);
      }
    else if (L) { //左轉，右順左微逆
        myservoR.write(0);
        myservoL.write(90);
        delay(100);
      }
    else if (R) { //右轉，右停左逆
        myservoR.write(90);
        myservoL.write(180);
        delay(100);
      }  
    else if (M) { //直行，右順左逆
        myservoR.write(0);
        myservoL.write(180);
        //delay(50);
      }
}
