//每五毫秒隨機點亮一顆燈
//時間:2020/6/12

#include "LedControl.h"
LedControl lc=LedControl(12,11,10,1); 

void setup()
{
  lc.shutdown(0,false);  // address 0(第一個8x8 led Matrix) 關閉省電模式
  lc.setIntensity(0,8);  // 設定亮度為 8 (介於0~15之間)
  lc.clearDisplay(0);    // 清除螢幕
}
void loop()
{
      int randNumber_col = random(8);
      int randNumber_row = random(8);
      lc.setLed(0,randNumber_col,randNumber_row,1); // 將Led的欄,列設定為亮
      delay(5);
      lc.setLed(0,randNumber_col,randNumber_row,0); // 將Led的欄,列設定為暗
}

