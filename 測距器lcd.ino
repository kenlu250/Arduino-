const int led=13;  //LED 連接至數位接腳13。
const int echo=8; 
const int trig=9;  

void setup() {
  Serial.begin(9600); //初始化串列埠，設定鮑率9600bps。
  pinMode(led,OUTPUT); //設定數位接腳13 為輸出模式。
  digitalWrite(led,LOW); //關閉led。 
  pinMode(trig,OUTPUT); //設定數位接腳9 為輸出模式。
  pinMode(echo,INPUT); //設定數位接腳8 為接收模式。
  }
  
void loop() {
  unsigned long cm; //距離(單位:公分)。
  cm=ping(trig, echo); //讀取物體距離。
  Serial.print("distance="); //顯示"distance="字元。
  Serial.print(cm); //顯示物體距離。
  Serial.println("cm"); //顯示"cm"字元。
  digitalWrite(led,HIGH); //距離愈近，LED 閃爍速度愈快。
  delay(cm*10); //延遲。
  digitalWrite(led,LOW);
  delay(cm*10); 
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
  if (cm <= 100){
    return cm; //傳回物體距離(單位:公分)
  } 
} 
