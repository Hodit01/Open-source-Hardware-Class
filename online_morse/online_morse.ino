void dot();
void dash();
void c_space();
void w_space();
String charToMorse(int ascii);
void MorseStringToLED(String str);

int _pin = 7;
int _dottime = 250; 

void dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}
//控制LED实现‘-’操作
void dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

//实现串口输入的字符转换成莫斯编码
String charToMorse(int ascii)
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
void MorseStringToLED(String str){
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
void c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}


void w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}






int incomingByte = 0; // for incoming serial data
String str ="";
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // reply only when you receive data:
  while(Serial.available() > 0 ){
     incomingByte = Serial.read();
     str += charToMorse(char(incomingByte));
  }

  if(str.length()>0){
    Serial.println(str);
    Serial.println("Next please look at the LED");
    delay(1000);
    MorseStringToLED(str);
    
    str = "";
  }
   
}
