//利用監控視窗控制自走車的前後左右
//時間:

#include <Servo.h>
Servo myservoL,myservoR;

const byte ServoR_pin = 12;
const byte ServoL_pin = 13; 


char command = 'S';
char prevCommand = 'A';
unsigned long timer0 = 2000;  
unsigned long timer1 = 0;


void setup() 
{ 
  myservoR.attach(ServoR_pin);
  myservoL.attach(ServoL_pin);
  
  myservoR.write(90);//左右停止
  myservoL.write(90);
  
  Serial.begin(9600);
} 
 
void loop() 
{
 if(Serial.available() > 0){ 
    //timer1 = millis();   
    prevCommand = command;
    command = Serial.read(); 
    if(command!=prevCommand){
      //Serial.println(command);
      switch(command){
      case 'F':  //直行，右順左逆
        myservoR.write(0);
        myservoL.write(180);
        break;
      case 'B':  //後退，左順右逆
        myservoR.write(180);
        myservoL.write(0);
        break;
      case 'L': //左轉，右順左小逆
        myservoR.write(0);
        myservoL.write(99);
        break;
      case 'R'://右轉，右小順左逆
        myservoR.write(96);
        myservoL.write(180); 
        break;
      case 'S':  //左右停止
        myservoR.write(90);
        myservoL.write(90);
        break;
  
      }
      delay(100);
    }
  }
}
