#include <Arduino.h>

#define trigPin 9
#define echoPin 10
long duration;
float distanceCm;

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(trigPin, OUTPUT); // Trigger pin as output
  pinMode(echoPin, INPUT); // Echo pin as input
}

void loop() {
  // Clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance (speed of sound is 0.0343 cm/us)
  distanceCm = duration * 0.0343 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  delay(1000); // Short delay before next measurement
}
