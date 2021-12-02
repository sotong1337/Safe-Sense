#define recieve 10 // attach pin D2 Arduino to pin TX of HuskyLens
#define transmit 11 // attach pin D2 Arduino to pin TX of HuskyLens
#define motor 9 // attach pin D9 Arduino to Base of motor

// import libraies needed for HuskyLens
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;
SoftwareSerial mySerial(recieve, transmit);

// defines variables
long pulseOne; // variable for the first duration of sound wave travel
int d1; // variable for the initial distance measurement
long pulseTwo; // variable for the second duration of sound wave travel
int d2; // variable for the second distance measurement
int o_motorspeed = 250; // the original speed of e-scooter
int motorspeed = 250; // variable to store current speed of e-scooter
int echoPin = 2;
int trigPin = 3;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(motor, OUTPUT); // Sets the motor base as an INPUT
  Serial.begin(115200);
  mySerial.begin(9600);
  huskylens.begin(mySerial);
 
  Serial.println("Program started");
}
void loop() {
  delay(50);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  pulseOne = pulseIn(echoPin, HIGH);
    
  // Calculating the distance
  d1 = pulseOne * 0.034 / 2 + 10; // Speed of sound wave divided by 2 (go and back)
  Serial.print("Distance 1: "); 
  Serial.println(d1);

  // if no objects in 1m range
  if (d1 > 30) {
    huskylens.requestBlocks();
    if (huskylens.requestBlocksLearned() > 0) {
      Serial.print(huskylens.countBlocksLearned());
      Serial.println(" People detected by HuskyLens");
      
      if (o_motorspeed < 150) motorspeed = o_motorspeed;
      else if (motorspeed <= 150) motorspeed = motorspeed;
      else motorspeed -= 5;
    }
    else {
      Serial.println("No objects detected by HuskyLens");
      }
  }

  else {
    // Get a second set of distance to tell whether the distance is constant or not
    delay(250);
    //digitalWrite(trigPin, LOW);
    //delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
      
    pulseTwo = pulseIn(echoPin, HIGH);
    d2 = pulseTwo * 0.034 / 2 + 10;
    Serial.print("d2: "); 
    Serial.println(d2);
    
    //compare the two distances , if the current distance is shorter (threshold of 1cm), the e-scooter needs to slow down
    if (d2 < d1 - 0.1) {
      Serial.println("Object getting close");
      if (motorspeed <= 60) motorspeed = motorspeed;
      else motorspeed -= 50;
    }

    else if (d2 == d1) motorspeed = motorspeed;
    
  }
  Serial.print("motorspeed: ");
  Serial.print(float(motorspeed / 10.0));
  Serial.println("km/h");
  analogWrite(9, motorspeed);
}
