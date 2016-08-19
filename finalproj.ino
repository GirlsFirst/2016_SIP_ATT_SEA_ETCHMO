#include <Servo.h>
Servo servoRight;
Servo servoLeft;
Servo servoPenLift;

void setup() {
 servoLeft.attach(11);
 servoRight.attach(10);
 servoPenLift.attach(13);
 pinMode(2,INPUT);
 pinMode(4,INPUT);
 pinMode(3,INPUT);
 pinMode(5,INPUT);

 servoLeft.writeMicroseconds(1500);
 servoRight.writeMicroseconds(1500);
 delay(1000);
}

boolean up = true;
boolean runProgram=true;
int myposition;
void continueProgram(int p){
  while (digitalRead(p)==HIGH){
    runProgram = false;
  }
  runProgram = true;
}

void loop() {
  if ((digitalRead(2)==HIGH)&&(digitalRead(3)==LOW)&&(digitalRead(4)==LOW)&&(runProgram == true)){ //front one
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(1000);
    //continueProgram(2);
  }
 if ((digitalRead(4)==HIGH)&&(digitalRead(3)==LOW)&&(digitalRead(2)==LOW)&&(runProgram == true)){//left
   servoLeft.writeMicroseconds(1300);
   servoRight.writeMicroseconds(1300);
   delay(1000);
   //continueProgram(4);
 }
  if ((digitalRead(3)==HIGH)&&(digitalRead(4)==LOW)&&(digitalRead(2)==LOW)&&(runProgram == true)){//right
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1700);
    delay(1000);
   // continueProgram(3);
  } 

  
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
    delay(1000);
    
 if ((digitalRead(5)==HIGH)&&(up==true)&&(runProgram==true)){
    for (myposition=0; myposition < 90; myposition+=2){
      servoPenLift.write(myposition);
      delay(15);
    }
    continueProgram(5);
    up=false;
    myposition=90;
    }
   else if ((digitalRead(5)==HIGH)&&(up==false)&&(runProgram==true)){
    for (myposition=90; myposition> 0; myposition-=2){
      servoPenLift.write(myposition);
      delay(15);
      }
      continueProgram(5);
      up=true;
      myposition=0;
      
    }
    servoPenLift.write(myposition);
    delay(15);
  }
  
  

    



