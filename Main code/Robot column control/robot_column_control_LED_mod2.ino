
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
const int servoBase = 2;
const int servoShoulder = 3;
const int servoElbow = 4;
const int servoClaw = 5;
const int servoJoint = 6;
const int servoWrist = 7;
//leds
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int led5 = 12;
const int led6 = 13;
const int led7 = 14;
//sensor
const int sensor = A0;

//variables

//function definition
void claw_open();
void claw_close();
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
  //set servos to standby position. can be violent
  joint.write(90);
  elbow.write(0);
  shoulder.write(24);
  base.write(90);
  claw.write(180);
  //setup leds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Choose 1-7 to choose column to move to");
}

void loop()
{
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state == 1)
    {
      pickup_right(); 
      Serial.println("Command completed arm picked up right token");
      column1();
      Serial.println("Command completed arm move to column 1");
      state = 0;
    }
    else if (state == 2)
    {
      pickup_right();
      Serial.println("Command completed arm picked up right token");
      column2();
      Serial.println("Command completed arm move to column 2");
      state = 0;
    }  
    else if (state == 3)
    {
      pickup_right();
      Serial.println("Command completed arm picked up right token");
      column3();
      Serial.println("Command completed arm move to column 3");
      state = 0;
    }  
    else if (state == 4)
    {
      pickup_right();
      Serial.println("Command completed arm picked up right token");
      column4();
      Serial.println("Command completed arm move to column 4");
      state = 0;
    }  
    else if (state == 5)
    {
      pickup_right();
      Serial.println("Command completed arm picked up right token");
      column5();
      Serial.println("Command completed arm move to column 5");
      state = 0;
    }  
    else if (state == 6)
    {
      pickup_right();
      Serial.println("Command completed arm picked up right token");
      column6();
      Serial.println("Command completed arm move to column 6");
      state = 0;
    }  
    else if (state == 7)
    {
      pickup_right();
      Serial.println("Command completed arm picked up right token");
      column7();
      Serial.println("Command completed arm move to column 7");
      state = 0; 
    }  
    else if (state == 8)
    {
      pickup_left();
      Serial.println("Command completed arm picked up left token");
      column1();
      Serial.println("Command completed arm move to column 1");
      state = 0;
    }
    else if (state == 9)
    {
      pickup_left();
      Serial.println("Command completed arm picked up left token");
      column2();
      Serial.println("Command completed arm move to column 2");
      state = 0;
    }
    else if (state == 10)
    {
      pickup_left();
      Serial.println("Command completed arm picked up left token");
      column3();
      Serial.println("Command completed arm move to column 3");
      state = 0;
    }
    else if (state == 11)
    {
      pickup_left();
      Serial.println("Command completed arm picked up left token");
      column4();
      Serial.println("Command completed arm move to column 4");
      state = 0;
    }
    else if (state == 12)
    {
      pickup_left();
      Serial.println("Command completed arm picked up left token");
      column5();
      Serial.println("Command completed arm move to column 5");
      state = 0;
    }
    else if (state == 13)
    {
      pickup_left();
      Serial.println("Command completed arm picked up left token");
      column6();
      Serial.println("Command completed arm move to column 6");
      state = 0;
    }
    else if (state == 14)
    {
      pickup_left();
      Serial.println("Command completed arm picked up left token");
      column7();
      Serial.println("Command completed arm move to column 7");
      state = 0;
    }
    else
    {
      Serial.println("ERROR: Input not an integer or not a valid input");
      state = 0;
    }
//    For some reason switch case makes the code upset, which is why I used a big ugly if tree
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
void led_sense(int led) //checks sensor, if selected led is on and detected, drop token, else move around a bit
{
  //led on>check sensor>led off
  digitalWrite(led, HIGH);
  int i = 0;
  int senseVal = 0;
  int pos = 90;
  for (i=0;i<=10;i++) //repeats 10 times to ensure a reading can be gotten
  {
    senseVal = digitalRead(sensor);
    Serial.print("IR sensor value:");
    Serial.println(senseVal);
    if(senseVal == LOW) // if something sensed
    {
      claw_open(); //open claw
      break; //break
    }
    else //else wiggle a bit
    {
      if (i<=5)
      {
        pos = pos + i;
        base.write(pos);
        delay(300);
        Serial.println(pos); //testing only
        pos = 90;
      }
      else
      {
        pos = pos + 5 - i;
        base.write(pos);
        delay(300);
        Serial.println(pos); //testing only
        pos = 90;
      }
    }
  }
  if (i>=10)
  {
    Serial.println("ERROR: LED not detected, token not dropped");
  }
  digitalWrite(led, LOW);
}

void claw_close()
{
  int pos = 0;
  for (pos = 180; pos >= 110; pos -= 1) //ADD ANGLES HERE
  { // goes from 180 degrees to 0 degrees
  claw.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(500);
}

void claw_open()
{
  int pos = 0;
  for (pos = 110; pos <= 180; pos += 1) //ADD ANGLES HERE
    { 
    claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
}

void pickup_right() //pickup from tokenholder on the right
{
  int pos = 0;
  for (pos = 90; pos >= 50; pos -= 1) //move base
    { // goes from 180 degrees to 0 degrees
    base.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 90; pos >= 50; pos -= 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 0; pos <= 45; pos += 1) //ADD ANGLES HERE
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 24; pos <= 136; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  claw_close();
  for (pos = 136; pos >= 24; pos -= 1)
    { // goes from 180 degrees to 0 degrees
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 50; pos <= 90; pos += 1) //ADD ANGLES HERE
    { 
    base.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 45; pos >= 0; pos -= 1)
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 50; pos <= 90; pos += 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  
}

void pickup_left()
{
  int pos = 0;
  for (pos = 90; pos <= 132; pos += 1) //move base
    { // goes from 180 degrees to 0 degrees
    base.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 90; pos >= 50; pos -= 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 0; pos <= 45; pos += 1) //ADD ANGLES HERE
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 24; pos <= 136; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  claw_close();
  for (pos = 132; pos >= 24; pos -= 1)
    { // goes from 180 degrees to 0 degrees
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 136; pos >= 90; pos -= 1) //ADD ANGLES HERE
    { 
    base.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 45; pos >= 0; pos -= 1)
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  delay(500);
  for (pos = 50; pos <= 90; pos += 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }

}

void column1()
{
  /* the movement sequence is this;
  standby position > column > standby position
  servo movement sequence;
  joint > elbow > shoulder > claw open > shoulder > elbow > joint
  */
    int  pos = 0;
    delay(500);
    for (pos = 90; pos <= 102; pos += 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 0; pos <= 3; pos += 1) // goes from 0 degrees to 180 degrees
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 24; pos <= 29; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    led_sense(led1);
    Serial.println("Command completed arm at column 1");
    Serial.println("Returning to standby...");
    for (pos = 29; pos >= 24; pos -= 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 3; pos >= 0; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 102; pos >= 90; pos -= 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    claw.write(180); //makes sure claw is open to avoid stress
}

void column2()
{
  /* the movement sequence is this;
  standby position > column > standby position
  servo movement sequence;
  joint > elbow > shoulder > claw open > shoulder > elbow > joint
  */
    int  pos = 0;
    delay(500);
    for (pos = 90; pos <= 96; pos += 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 0; pos <= 14; pos += 1) // goes from 0 degrees to 180 degrees
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 24; pos <= 47; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    led_sense(led2);
    Serial.println("Command completed arm at column 2");
    Serial.println("Returning to standby...");
    for (pos = 47; pos >= 24; pos -= 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 14; pos >= 0; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 96; pos >= 90; pos -= 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    claw.write(180); //makes sure claw is open to avoid stress
}

void column3()
{
  /* the movement sequence is this;
  standby position > column > standby position
  servo movement sequence;
  joint > elbow > shoulder > claw open > shoulder > elbow > joint
  */
    int  pos = 0;
    delay(500);
    for (pos = 90; pos >= 82; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 0; pos <= 25; pos += 1) // goes from 0 degrees to 180 degrees
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 24; pos <= 65; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    led_sense(led3);
    Serial.println("Command completed arm at column 3");
    Serial.println("Returning to standby...");
    for (pos = 65; pos >= 24; pos -= 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 25; pos >= 0; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 82; pos <= 90; pos += 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    claw.write(180); //makes sure claw is open to avoid stress
}

void column4()
{
  /* the movement sequence is this;
  standby position > column > standby position
  servo movement sequence;
  joint > elbow > shoulder > claw open > shoulder > elbow > joint
  */
    int  pos = 0;
    delay(500);
    for (pos = 90; pos >= 70; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 0; pos <= 30; pos += 1) // goes from 0 degrees to 180 degrees
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 24; pos <= 75; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    led_sense(led4);
    Serial.println("Command completed arm at column 4");
    Serial.println("Returning to standby...");
    for (pos = 75; pos >= 24; pos -= 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 30; pos >= 0; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 70; pos <= 90; pos += 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    claw.write(180); //makes sure claw is open to avoid stress
}

void column5()
{
  /* the movement sequence is this;
  standby position > column > standby position
  servo movement sequence;
  joint > elbow > shoulder > claw open > shoulder > elbow > joint
  */
    int  pos = 0;
    delay(500);
    for (pos = 90; pos >= 68; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 0; pos <= 45; pos += 1) // goes from 0 degrees to 180 degrees
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 24; pos <= 93; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    led_sense(led5);
    Serial.println("Command completed arm at column 5");
    Serial.println("Returning to standby...");
    for (pos = 93; pos >= 24; pos -= 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 45; pos >= 0; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 68; pos <= 90; pos += 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    claw.write(180); //makes sure claw is open to avoid stress
}

void column6()
{
  /* the movement sequence is this;
  standby position > column > standby position
  servo movement sequence;
  joint > elbow > shoulder > claw open > shoulder > elbow > joint
  */
    int  pos = 0;
    delay(500);
    for (pos = 90; pos >= 76; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 0; pos <= 66; pos += 1) // goes from 0 degrees to 180 degrees
    { 
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 24; pos <= 109; pos += 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    led_sense(led6);
    Serial.println("Command completed arm at column 6");
    Serial.println("Returning to standby...");
    for (pos = 109; pos >= 24; pos -= 1) //ADD ANGLES HERE
    { 
    shoulder.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 66; pos >= 0; pos -= 1) //ADD ANGLES HERE
    { // goes from 180 degrees to 0 degrees
    elbow.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    delay(500);
    for (pos = 76; pos <= 90; pos += 1) //ADD ANGLES HERE
    { 
    joint.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
    claw.write(180); //makes sure claw is open to avoid stress
}

void column7()
{
    int  pos = 0;
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
    led_sense(led7);
    Serial.println("Command completed arm at column 7");
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
    claw.write(180); //makes sure claw is open to avoid stress
}
