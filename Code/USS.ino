//Coded by MATHEW VARGHESE
//Note that the numbering of arduino pins are different from microcontroller pinout

int d = 10; //Enter depth of your tank here in centimeters

int trig = 2; // Attach Trig of ultrasonic sensor to pin 11
int echo = 3; // Attach Echo of ultrasonic sensor to pin 10
int pin1 = 5;//Highest level
int pin2 = 6;
int pin3 = 7;
int pin4 = 8;
int pin5 = 9;
int pin6 = 10;
int pin7 = 11;
int pin8 = 12;//Lowest evel

void setup() {
  Serial.begin(9600);
pinMode (pin1, OUTPUT);// Set pins to output for controlling I/O
pinMode (pin2, OUTPUT);
pinMode (pin3, OUTPUT);
pinMode (pin4, OUTPUT);
pinMode (pin5, OUTPUT);
pinMode (pin6, OUTPUT);
pinMode (pin7, OUTPUT);
pinMode (pin8, OUTPUT);


digitalWrite(pin1, HIGH);
delay(200);
digitalWrite(pin1, LOW);
delay(200);
digitalWrite(pin1, HIGH);
delay(200);
digitalWrite(pin1, LOW);

}

void loop()
{ 

// Establish variables for duration of the ping,
// and the distance result in inches and centimeters:
long duration, in, cm;       //'in' is inches and 'cm' is centimeter

// The PING is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
pinMode(trig, OUTPUT);
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(5);
digitalWrite(trig, LOW);

// The same pin is used to read the signal from the PING: a HIGH
// pulse whose duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(echo, INPUT);
duration = pulseIn(echo, HIGH);

// Convert the time into a distance
in = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

delay(100);// To save battery,remove if felt inconvenient

digitalWrite(pin1, LOW);//Resetting the LEDs to off state
digitalWrite(pin2, LOW);
digitalWrite(pin3, LOW);
digitalWrite(pin4, LOW);
digitalWrite(pin5, LOW);
digitalWrite(pin6, LOW);
digitalWrite(pin7, LOW);
digitalWrite(pin8, LOW);





if (in < 2)//   Else is included to light only one led at a level and thus save battery charge
digitalWrite(pin1, HIGH);
 if (in <3)
digitalWrite(pin2, HIGH);
 if (in <4)
digitalWrite(pin3, HIGH);
 if (in <5)
digitalWrite(pin4, HIGH);
 if (in <6)
digitalWrite(pin5, HIGH);
 if (in <7)
digitalWrite(pin6, HIGH);
 if (in <8)
digitalWrite(pin7, HIGH);
 if (in <9)
digitalWrite(pin8, HIGH);


Serial.println(in);
}

long microsecondsToInches(long microseconds)
{
// According to Parallax's datasheet for the PING, there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See: http://www.parallax.com/dl/docs/prod/acc/28015-PI...
return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}

