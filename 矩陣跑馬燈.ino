//直行亮 橫列亮 從左到右亮 由下到上亮

#include "LedControl.h"
// Pin 12:Data in, Pin 11: Clock,  Pin 10: CS(Load)
LedControl lc=LedControl(12,11,10,1); 

void setup()
{
  lc.shutdown(0,false);  // address 0(第一個8x8 led Matrix) 關閉省電模式
  lc.setIntensity(0,8);  // 設定亮度為 8 (介於0~15之間)
  lc.clearDisplay(0);    // 清除螢幕
}
void loop()
{
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, B11111111); 
    delay(100);
    lc.setRow(0, i, B00000000); 
  }

  for(int i = 0; i < 8; i++){
    lc.setColumn(0, i, B11111111); 
    delay(100);
    lc.setColumn(0, i, B00000000); 
  }

  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, B11111111); 
    delay(100);
  }

  lc.clearDisplay(0);

  for(int i = 0; i < 8; i++){
    lc.setColumn(0, i, B11111111); 
    delay(100);
  }

  lc.clearDisplay(0);
}
