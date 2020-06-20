//利用手機藍芽功能控制LED燈開關
//時間:2020/4/10

#include <SoftwareSerial.h>
SoftwareSerial BluetoothSerial(3,4); // RX, TX
char code;
byte value;
int led=11;
void setup()
{
  Serial.begin(9600);
  BluetoothSerial.begin(9600); //或38400
  pinMode(led,OUTPUT);
  analogWrite(led,0);
}
void loop() 
{
  if(BluetoothSerial.available())
  {
    delay(50);
    code=BluetoothSerial.read();
    Serial.print("code=");
    Serial.println(code);    
    if(code=='0')
    {
      digitalWrite(led,LOW);
    }
    else if(code=='1')
    {
      digitalWrite(led,HIGH);
    }
    else if(code=='s')
    {
      value=BluetoothSerial.read();
      Serial.print("value=");
      Serial.println(value);
      if(value<20)
        analogWrite(led,0);
      else
        analogWrite(led,value);
    }
  }
}       
