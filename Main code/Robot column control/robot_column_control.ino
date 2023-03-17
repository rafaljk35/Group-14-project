
#include <Servo.h>

//setting up servo objects
Servo base; 
Servo shoulder;
Servo elbow;
Servo claw;
Servo joint;
Servo wrist;

//pin numbers
//====change for esp!!!!====
const int servoBase = 9;
const int servoShoulder = 8;
const int servoElbow = 7;
const int servoClaw = 10;
const int servoJoint = 11;
const int servoWrist = 12;

//variables

//function definition
void column1();
void column7();

void setup() 
{
    //servo attach pin
  base.attach(servoBase);
  shoulder.attach(servoShoulder);
  elbow.attach(servoElbow);
  claw.attach(servoClaw);
  joint.attach(servoJoint);
  wrist.attach(servoWrist);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("CHoose 1-7 to choose column to move to, 0 to pickup position, 8 to open close claw");
}

void loop()
{
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state == 1)
    {
    
      column7();
     Serial.println("Command completed arm move to column 1");
    }
    else if (state == 2)
    {

     Serial.println("Command completed arm at drop position");
    }  
    else if (state == 3)
    {

      Serial.println("Command completed calw open/close");
    }  
    else
    {
      Serial.println("ERROR: Invalid input");
    }
//    switch(state)
//    {
//      case 0:
//        column1();
//      case 1:
//        Serial.println("column 1");
//      case 2:
//        Serial.println("column 2");
//      case 3:
//        Serial.println("column 3");
//      case 4:
//        Serial.println("column 4");
//      case 5:
//        Serial.println("column 5");
//      case 6:
//        Serial.println("column 6");
//      case 7:
//        column7();
//      default:
//        Serial.println("ERROR: Invalid input detected");
//    }
//  }
}
}

//function body
  /* TEMPLATE: Use this if END_ANGLE smaller than START_ANGLE 
    for (pos = START_ANGLE; pos >= END_ANGLE; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    SERVO_NAME.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }

    TEMPLATE: Use this if END_ANGLE larger than START_ANGLE
    for (pos = START_ANGLE; pos <= END_ANGLE; pos += 1) //ADD ANGLES HERE
    { 
    SERVO_NAME.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
   */
void column1()
{
//    for (pos = ; pos >= ; pos -= 1) //ADD ANGLES HERE
//    { // goes from 180 degrees to 0 degrees
//    joint.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//    }
//    delay(500);
//    for (pos = START_ANGLE; pos <= END_ANGLE; pos += 1) { // goes from 0 degrees to 180 degrees
//    elbow.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//    }
//    delay(500);
//    for (pos = ; pos >= ; pos -= 1) //ADD ANGLES HERE
//    { // goes from 180 degrees to 0 degrees
//    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//    }
//    delay(1500);
//    for (pos = ; pos >= ; pos -= 1) //ADD ANGLES HERE
//    { // goes from 180 degrees to 0 degrees
//    claw.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//    }
//    Serial.println("Command completed arm at column 1");
//    Serial.println("Returning to standby...");
//    for (pos = START_ANGLE; pos <= END_ANGLE; pos += 1) //ADD ANGLES HERE
//    { 
//    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//    }
//    for (pos = START_ANGLE; pos >= END_ANGLE; pos -= 1) //ADD ANGLES HERE
//    { // goes from 180 degrees to 0 degrees
//    elbow.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//    }
//    for (pos = START_ANGLE; pos <= END_ANGLE; pos += 1) //ADD ANGLES HERE
//    { 
//    joint.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//    }
Serial.println("Column1");
}
void column7()
{
    int  pos = 0;
    delay(500);
    for (pos = 180; pos >= 110; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 90; pos >= 78; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 0; pos <= 93; pos += 1) // goes from 0 degrees to 180 degrees
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 24; pos <= 126; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 110; pos <= 180; pos += 1) //ADD ANGLES HERE
    { 
    claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    Serial.println("Command completed arm at column 1");
    Serial.println("Returning to standby...");
    for (pos = 126; pos >= 24; pos -= 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 93; pos >= 0; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 78; pos <= 90; pos += 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
}
