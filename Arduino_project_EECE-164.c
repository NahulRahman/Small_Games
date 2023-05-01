#include <Servo.h>
Servo myservo;
int pos = 0;
boolean fire = false;
/*-------defining Inputs------*/
#define Forward_S 8 // forward sensor
#define Left_S 9 // left sensor
#define Right_S 10 // right sensor
/*-------defining Outputs------*/
#define LMF 2 // left motor forward
#define LMB 3 // left motor backward
#define RMF 4 // right motor forward
#define RMB 5 // right motor backward
#define pump 6
void setup() {
 /*------defining input and output------*/
 pinMode(Left_S, INPUT);
 pinMode(Right_S, INPUT);
 pinMode(Forward_S, INPUT);
 pinMode(LMF, OUTPUT);
 pinMode(LMB, OUTPUT);
 pinMode(RMF, OUTPUT);
 pinMode(RMB, OUTPUT);
 pinMode(pump, OUTPUT);
 myservo.attach(11);
 myservo.write(90);
}
void put_off_fire() {
 digitalWrite(LMF, HIGH);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, HIGH);
 digitalWrite(RMB, HIGH);
 digitalWrite(pump, LOW); delay(500);
for (pos = 50; pos <= 130; pos += 1)
{
 myservo.write(pos);
 delay(15);
}
for (pos = 130; pos >= 50; pos -= 1)
{
 myservo.write(pos);
 delay(15);
}
 digitalWrite(pump,HIGH);
 myservo.write(90);
 fire=false;
}
void loop() {
 digitalWrite(pump,HIGH);
 myservo.write(90);
 if (digitalRead(Left_S) ==1 && digitalRead(Right_S)==1 &&
digitalRead(Forward_S) ==1)
 //If Fire not detected
 {
 //Do not move the robot
 digitalWrite(LMF, HIGH);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, HIGH);
 digitalWrite(RMB, HIGH);
 }
 else if (digitalRead(Forward_S) ==0)
 //If Fire is straight ahead
 {
 //Move the robot forward
 digitalWrite(LMF, LOW);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, LOW);
 digitalWrite(RMB, HIGH);
 delay (180);

 fire = true;
 }
 else if (digitalRead(Left_S) ==0)
 //If Fire is to the left
 {
 //Move the robot left
 digitalWrite(LMF, LOW);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, HIGH);
 digitalWrite(RMB, HIGH);
 delay (300);

 digitalWrite(LMF, HIGH);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, HIGH);
 digitalWrite(RMB, HIGH);
 delay(50);

 digitalWrite(LMF, LOW);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, LOW);
 digitalWrite(RMB, HIGH);
 delay (0);

 fire = true;
 }
else if (digitalRead(Right_S) ==0)
 //If Fire is to the right
 {
 //Move the robot right
 digitalWrite(LMF, HIGH);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, LOW);
 digitalWrite(RMB, HIGH);
 delay(300);

 digitalWrite(LMF, HIGH);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, HIGH);
 digitalWrite(RMB, HIGH);
 delay(50);

 digitalWrite(LMF, LOW);
 digitalWrite(LMB, HIGH);
 digitalWrite(RMF, LOW);
 digitalWrite(RMB, HIGH);

 delay (0);
 fire = true;
 }
delay(100); //Slow down the speed of robot
 while (fire == true)
 {
 put_off_fire();
 }
}
