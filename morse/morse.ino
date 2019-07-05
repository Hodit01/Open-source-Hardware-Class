/*
说明：这是开源硬件实战课程第一次作业
要求：从电脑串口接收一串字符。通过morse电码格式发出
      接收到的字符串，只包含26个小写字母，空格和回车
      作业完成后上交到自己的github
作者：hodit
时间：2019.7.3
代码说明：Morse.h 中声明
    void dot();     //控制LED实现‘*’操作
    void dash();    //控制LED实现‘-’操作
    void c_space(); //控制LED实现字母间停顿操作
    void w_space(); //控制LED实现单词间停顿操作
    String charToMorse(int ascii);//实现串口输入的字符转换成莫斯编码
    void MorseStringToLED(String str);//实现莫斯编码以LED闪灯形式展示
    以上函数在Morse.cpp中实现
*/

#include <Morse.h>
 
Morse morse(13);
 
int incomingByte = 0; // for incoming serial data
String str;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // reply only when you receive data:
  while(Serial.available() > 0 ) {
    
    // read the incoming byte:
    incomingByte = Serial.read();
    if( incomingByte==10){
      Serial.println(str);
      Serial.println("下面请看开发板的灯，以闪灯形式表示摩尔斯编码");
      delay(1000);
      morse.MorseStringToLED(str);
      str="";
      break;
    }
    str += morse.charToMorse(incomingByte);

  }
}
