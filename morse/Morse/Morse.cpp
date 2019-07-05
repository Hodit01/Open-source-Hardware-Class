#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}
 //控制LED实现‘*’操作
void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}
//控制LED实现‘-’操作
void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

//实现串口输入的字符转换成莫斯编码
String Morse::charToMorse(int ascii)
{
	String m="";
	String alphabet[27]={
		"/",
		"*-",
		"-***",
		"-*-*",
		"-**",
		"*",
		"**-*",
		"--*",
		"****",
		"**",
		"*---",
		"-*-",
		"*-**",
		"--",
		"-*",
		"---",
		"*--*",
		"--*-",
		"*-*",
		"***",
		"-",
		"**-",
		"***-",
		"*--",
		"-**-",
		"-*--",
		"--**"
	};


	if(ascii==32){
		m=alphabet[0];
		return m;
	}
	else{
		m=alphabet[ascii-96];
		return m+" ";
	}
	
	

}


//实现莫斯编码以LED闪灯形式展示
void Morse::MorseStringToLED(String str){
	int n =str.length();
      int i;
      char c;
      for(i=0;i<n;i++){
        c=str[i];
        switch (c){
        case '*':
          dot();
          break;
        case '-':
          dash();
          break;
        case ' ':
          c_space();
          break;
        case '/':
          w_space();
          break;
        }
      }
}

//控制LED实现字母间停顿操作
void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void w_space(); //控制LED实现单词间停顿操作
void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
}
