#include <Servo.h>
Servo servoX;
Servo servoY;
int x=90 ;
int y=90 ;
const int led=4;
const int button=3;
int stateb=0;
char input = ' '; 
void setup() {
  Serial.begin(9600);

  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  servoX.attach(10);
  servoY.attach(9);
  servoX.write(x);
  servoY.write(y);
  delay(1000);
}
void loop() {
 stateb=digitalRead(button);
 if(stateb==LOW)
 { 
 digitalWrite(led,LOW); 
 if(Serial.available()){
  input = Serial.read(); 
  if(input == 'D'){
   y -= 1;              
   servoY.write(y);  

  }
  
  else if(input == 'd')
  {
   y -= 2;              
   servoY.write(y);  

  }
  
  else if(input == 'U'){ 
   y += 1;
   servoY.write(y);
  }
  
  else if(input == 'u'){ 
   y += 2;
   servoY.write(y);
  }

  if(input == 'L'){
  x -= 1;  
  servoX.write(x);
  }
  
  else if(input == 'l'){
  x -= 2;  
  servoX.write(x);
  }
  
  else if(input == 'R'){
  x += 1;
  servoX.write(x);
  }
  
  else if(input == 'r'){
  x += 2;
  servoX.write(x);
  }

  input = ' ';       
 }
 }
   else
  {
     digitalWrite(led,HIGH);
     servoX.write(90);
     servoY.write(90);
  }
  
}