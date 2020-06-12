#include <SoftwareSerial.h>
SoftwareSerial BLU(0,1);
String voice;
int First  = 2;  //Connect To Pin #2 
int Second = 3;  //Connect To Pin #3 
int Third  = 4;  //Connect To Pin #4 
int Fourth = 5;  //Connect To Pin #5 
 
void allon()
{    
  digitalWrite(First, HIGH);     
  digitalWrite(Second, HIGH);     
  digitalWrite(Third, HIGH);     
  digitalWrite(Fourth, HIGH);     
}
void alloff()
{
  digitalWrite(First, LOW);     
  digitalWrite(Second, LOW);     
  digitalWrite(Third, LOW);     
  digitalWrite(Fourth, LOW);     
}
void setup() 
{
  Serial.begin(9600);   
  BLU.begin(9600);    
  pinMode(First, OUTPUT);  
  pinMode(Second, OUTPUT);  
  pinMode(Third, OUTPUT);  
  pinMode(Fourth, OUTPUT);
  alloff();  
}
void loop() 
{
  
  while (Serial.available())     //Check if there is an available byte to read
  {   
    delay(10);                   //Delay added to make thing stable   
    char c = Serial.read();      //Conduct a serial read  
    if (c == '#')             //在手機中輸入的結尾會加上'#'
    {
      break;                     //Exit the loop when the # is detected after the word 
    }   
    voice += c; 
  }  
  
  if (voice.length() > 0) 
  {
    if(voice == "芝麻開燈") 
    {
      allon();
    }  
    else if(voice == "芝麻關燈")
    {
      alloff();
    } 
    else if(voice == "第一顆燈打開") 
    {
      digitalWrite(First,HIGH);
    }   
    else if(voice == "第二顆燈打開") 
    {
      digitalWrite(Second,HIGH);
    }  
    else if(voice == "第三顆燈打開") 
    {
      digitalWrite(Third,HIGH);
    }  
    else if(voice == "第四顆燈打開") 
    {
      digitalWrite(Fourth,HIGH);
    }
     else if(voice == "第一顆燈關閉") 
    {
      digitalWrite(First,LOW);
    }  
    else if(voice == "第二顆燈關閉") 
    {
      digitalWrite(Second,LOW);
    }  
    else if(voice == "第三顆燈關閉") 
    {
      digitalWrite(Third,LOW);
    }  
    else if(voice == "第四顆燈關閉") 
    {
      digitalWrite(Fourth,LOW);
    }
    voice="";            //Reset variable
  }
}
