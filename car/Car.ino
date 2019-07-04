void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);//L LED
  pinMode(2, OUTPUT);//R LED
  Serial.begin(9600);
}

int income=0;
void loop()
{
  if(Serial.available() > 0){
    income = Serial.read();
    switch(char(income)){
      case 'f':
          forward();
          break;
      case 'b':
          backward();
          break;
      case 'l':
          left();
          break;
      case 'r':
          right();
          break;
      case 's':
          stop();
          break;
      default:
          break;
    }
    
  }
}




void forward(){
  digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
}

void backward(){
  digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
}

void left(){
    digitalWrite(2,LOW);
  digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(13,HIGH);
}


void right(){
    digitalWrite(13,LOW);
  digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(2,HIGH);
}

void stop(){
  digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
}
