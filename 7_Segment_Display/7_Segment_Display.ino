

int input1=6;
int input2=12;
int input3=11;
int input4=7;
int BL=9;
int LE=8;
int LT=10;




void setup()
{
  Serial.begin(9600);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(LE, OUTPUT);
  pinMode(LT, OUTPUT);
  
  digitalWrite(LT, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(LE, LOW);
  /*
  digitalWrite(input1,bool(1));
  digitalWrite(input2,bool(1));
  digitalWrite(input3,bool(1));
  digitalWrite(input4,bool(0));
  */
  
  
  
}

int income=0;
void loop()
{  
  if(Serial.available()>0){
 
      income = int(Serial.read()-'0');
         
      if(income >= 0 && income <=9){
            Serial.println(income);
            Serial.print(income&1);
            Serial.print((income>>1)&1);
            Serial.print((income>>2)&1);
            Serial.println((income>>3)&1);
          digitalWrite(BL, LOW);
            delay(100);
            digitalWrite(BL, HIGH);
            digitalWrite(LE, LOW);
          
            digitalWrite(input1,bool(income&1));
        digitalWrite(input2,bool((income>>1)&1));
        digitalWrite(input3,bool((income>>2)&1));
        digitalWrite(input4,bool((income>>3)&1));
             
      }
  }

}
