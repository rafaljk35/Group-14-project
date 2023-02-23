/* Example code for controlling 2 servos
*Remember servos need common ground with ESP32
*/
#include <ESP32Servo.h> //esp32 specific servo control library

Servo myservo;  
Servo myservo2; // create servo object to control a servo, each servo needs its own object
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33
// Remember GPIO pin numbers are different from regular pin numbers!
int servoPin = 13; //servo 1 pin
int servo2Pin = 14; //servo 2 pin

void setup() {
	// Allow allocation of all timers
  // pretty sure these control the timings for pwm
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  // remember to do settings for each servo!
	myservo.setPeriodHertz(50);
  myservo2.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 1000, 2000); // attaches the servo on pin 13 to the servo object
  myservo2.attach(servo2Pin, 1000, 2000); // attaches the servo on pin 14 to the servo object
	// format is (servo pin, min value, max value)
  // I have no idea what min or max value does but I assume it's something to do with the pwm pulse width
  // using default min/max of 1000us and 2000us
	// different servos may require different min/max settings
	// for an accurate 0 to 180 sweep
}

void loop() {

	for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo 1 to go to position in variable 'pos'
		delay(5);             // waits 5ms for the servo to reach the position
	}
  delay(2000);
	for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
		myservo2.write(pos);    // tell servo 2 to go to position in variable 'pos'
		delay(5);             // waits 5ms for the servo to reach the position
	}
  delay(2000);
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo 1 to go to position in variable 'pos'
		delay(5);             // waits 5ms for the servo to reach the position
	}
  delay(2000);
	for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		myservo2.write(pos);    // tell servo 2 to go to position in variable 'pos'
		delay(5);             // waits 5ms for the servo to reach the position
	}
  delay(2000);
  
}