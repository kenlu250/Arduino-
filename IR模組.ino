//使用IR模組偵測距離，若前方有物則LED燈亮起
//時間2020/5/1

const int IR_rec = 2;                // 紅外線接收器
const int LED = 13;                  // 紅外線指示燈

void setup ( ) {                
  pinMode(IR_rec, INPUT);           // 把 irReceiver 接腳設置為 INPUT
  pinMode(LED, OUTPUT);          // 把 ledPin 設置為 OUTPUT
}

void loop() {
  int IR_status = digitalRead(IR_rec); // 讀取 irReceiver 的狀態
  if (IR_status == 0) {
    digitalWrite (LED, HIGH);
  }
  else {
    digitalWrite (LED, LOW);
  }
}
