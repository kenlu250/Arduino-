//透過手機app功能遙控車子
//時間:2020/5/8

#include <Servo.h>
Servo myservoL,myservoR;

const byte ServoR_pin = 12;
const byte ServoL_pin = 13; 


char command = 'S';
char prevCommand = 'A';
unsigned long timer0 = 2000;  //Stores the time (in millis since execution started) 
unsigned long timer1 = 0;  //Stores the time when the last command was received from the phone


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
    //Change pin mode only if new command is different from previous.   
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
/*
      default:   //直行，右順左逆
        myservoR.write(0);
        myservoL.write(180);    
        break;
      
/*      case 'I':  //FR右前，右小順左逆  
        myservoR.write(96);
        myservoL.write(180); 
        break; 
      case 'J':  //BR  
        yellowCar.BackRight_4W(velocity);
        break;        
      case 'G':  //FL  
        yellowCar.ForwardLeft_4W(velocity);
        break; 
      case 'H':  //BL
        yellowCar.BackLeft_4W(velocity);
        break;
      case 'W':  //Font ON 
        digitalWrite(pinfrontLights, HIGH);
        break;
      case 'w':  //Font OFF
        digitalWrite(pinfrontLights, LOW);
        break;
      case 'U':  //Back ON 
        digitalWrite(pinbackLights, HIGH);
        break;
      case 'u':  //Back OFF 
        digitalWrite(pinbackLights, LOW);
        break; 
      case 'D':  //Everything OFF 
        digitalWrite(pinfrontLights, LOW);
        digitalWrite(pinbackLights, LOW);
        yellowCar.Stopped_4W();
        break;         

      default:  //Get velocity
        if(command=='q'){
          velocity = 255;  //Full velocity
          yellowCar.SetSpeed_4W(velocity);
        }

        else{ 
          //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
          if((command >= 48) && (command <= 57)){ 
            //Subtracting 48 changes the range from 48-57 to 0-9.
            //Multiplying by 25 changes the range from 0-9 to 0-225.
            velocity = (command - 48)*25;       
            yellowCar.SetSpeed_4W(velocity);
          }
        }
 */       
      }
      delay(100);
    }
  }
 /*
  else{
    timer0 = millis();  //Get the current time (millis since execution started).
    //Check if it has been 500ms since we received last command.
    if((timer0 - timer1)>500){  
      //More tan 500ms have passed since last command received, car is out of range.
      //Therefore stop the car and turn lights off.
       myservoR.write(97); //左右停止
       myservoL.write(98);
    }
  }
*/  
}
