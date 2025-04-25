int output1 = 2;
int output2 = 3;

int output3 = 12;
int  output4 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3,  OUTPUT);
  pinMode(output4, OUTPUT);

  //(Optional)
  pinMode(9,  OUTPUT); 
  pinMode(10, OUTPUT);
  //(Optional)
}

void loop() {


  analogWrite(9, 100); //ENA  pin
  analogWrite(10, 100); //ENB pin

  //forwad movement
  digitalWrite(output1,  true);
  digitalWrite(output2, false);

  digitalWrite(output3, false);
  digitalWrite(output4, true);
  delay(3000);
//backward movement
  digitalWrite(output1,  false);
  digitalWrite(output2, true);

  digitalWrite(output3, true);
  digitalWrite(output4, false);
  delay(10000);



//right  motion
  digitalWrite(output1,  true);
  digitalWrite(output2, false);

  digitalWrite(output3, true);
  digitalWrite(output4, false);
  delay(3000);

}
