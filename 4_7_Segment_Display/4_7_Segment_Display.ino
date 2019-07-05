

int input1=2;
int input2=3;
int input3=4;
int input4=5;

int LE1=11;
int LE2=10;
int LE3=9;
int LE4=8;





void setup()
{
  Serial.begin(9600);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  pinMode(LE1, OUTPUT);
  pinMode(LE2, OUTPUT);
  pinMode(LE3, OUTPUT);
  pinMode(LE4, OUTPUT);
  

  digitalWrite(LE1,HIGH);
  digitalWrite(LE2,HIGH);
  digitalWrite(LE3,HIGH);
  digitalWrite(LE4,HIGH);

}

int income=0;
String str="";
void loop()
{
  
  while(Serial.available() > 0 ){
     income = Serial.read();
     str += char(income);
     delay(2);
  }

  if(str.length()>0){
    Serial.println(str);
    
    for(int i = 0;i<4;i++){
      
      digitalWrite(LE1,LOW);
     
      digitalWrite(input1,bool(str[i]&1));
      digitalWrite(input2,bool((str[i]>>1)&1));
      digitalWrite(input3,bool((str[i]>>2)&1));
      digitalWrite(input4,bool((str[i]>>3)&1));
      
      digitalWrite(LE1,HIGH);
      
      LE1--;
    }
    LE1 =11;
    str = "";
  }
  /*
  if(Serial.available()>0){
 
      income = int(Serial.read()-'0');
         
      if(income >= 0 && income <=9){
  
            digitalWrite(input1,bool(income&1));
        digitalWrite(input2,bool((income>>1)&1));
        digitalWrite(input3,bool((income>>2)&1));
        digitalWrite(input4,bool((income>>3)&1));
             
      }
  }
*/
}
