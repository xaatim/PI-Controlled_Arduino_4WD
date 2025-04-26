String keys;

int output1 = 2;
int output2 = 3;
int output3 = 12;
int  output4 = 11;

void setup() {

  Serial.begin(115200);
  Serial.setTimeout(1);

  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3,  OUTPUT);
  pinMode(output4, OUTPUT);


  pinMode(9,  OUTPUT); 
  pinMode(10, OUTPUT);

}
void actions (bool con1,bool con2,bool con3,bool con4, int delay_in_ms=3000){
  
  analogWrite(9, 255); //ENA  pin
  analogWrite(10, 255); //ENB pin
  
  digitalWrite(output1, con1);
  digitalWrite(output2, con2);

  digitalWrite(output3, con3);
  digitalWrite(output4, con4);
  // delay(delay_in_ms);

  
}
void  loop() {
  while (!Serial.available());
  keys = Serial.readString();
  if(keys=="f" || keys=="F"){
    actions(true,false,false,true);
  }else if (keys=="b" || keys=="B"){
    actions(false,true,true,false);
  }else if(keys=="r" || keys=="R"){
    actions(true,false,true,false);
  }else if(keys=="l" || keys=="L"){
    actions(false,true,false,true);
  }else if(keys=="q" || keys=="q"){
    actions(false,false,false,false);
  }else{  
    Serial.write("Error : Expected (f,b,r,l or F,B,R,L) ");
  }

}