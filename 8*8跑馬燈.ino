//使用8*8矩陣模組輸出橫向的Hello 811085(學號)
//時間:2020/6/19

#include "LedControl.h"
LedControl lc = LedControl(12, 11, 10, 1);

 const byte char_pattern[] =
{
  B00000000, B00000000, B00000000, B00000000, B00000000, //
  B01111111, B00001000, B00001000, B01111111, B00000000, // H
  B00111000, B01010100, B01010100, B00011000, B00000000, // e
  B01000001, B01111111, B01000000, B00000000, B00000000, // l
  B01000001, B01111111, B01000000, B00000000, B00000000, // l
  B00111000, B01000100, B01000100, B00111000, B00000000, // o
  B00000000, B00000000, B00000000, B00000000, B00000000, //  
  B01111110, B01001010, B01001010, B01111110, B00000000, // 8
  B00000000, B01000100, B01111110, B01000000, B00000000, // 1
  B00000000, B01000100, B01111110, B01000000, B00000000, // 1
  B01111110, B01000010, B01000010, B01111110, B00000000, // 0
  B01111110, B01001010, B01001010, B01111110, B00000000, // 8
  B01001110, B01001010, B01001010, B01111010, B00000000, // 5
  B00000000, B00000000, B00000000, B00000000, B00000000, //
  B00000000, B00000000, B00000000, B00000000, B00000000, //
  B00000000, B00000000, B00000000, B00000000, B00000000  //  
};
// 逐字顯示字串 "Hello Arduino " function
void Display1() {
  for (int  i = 0; i < 14; i++) {               //共14個字
    for (int j = 2; j < 7; j++) {               //顯示文字在中間(第2~6行)
      lc.setRow(0, j, char_pattern[i*5 + j-2]); // j-2為從0到5，取到每一個文字的5個Byte
    }
    delay(500);
    lc.clearDisplay(0);
    delay(100);
  }
}

// 由右向左跑馬顯示字串 "Hello Arduino " function
void Display2(int rolling_speed) {
  for (int i = 0; i < (14*5); i++) {
    for (int j = 0; j < 8; j++) {
      lc.setRow( 0 , j, char_pattern[i+j]);
    }
    delay(rolling_speed);
  }
}

// 初始設定
void setup() {

    lc.shutdown(0, false);
    lc.setIntensity(0, 3);
    lc.clearDisplay(0);

}

//
void loop() {
  Display1();
  delay(1000);
  lc.clearDisplay(0);
  Display2(100);
  delay(1000);
  lc.clearDisplay(0);
}
