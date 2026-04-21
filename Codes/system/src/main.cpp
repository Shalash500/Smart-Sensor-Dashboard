#include <Arduino.h>
#include <DHT.h>

// Variables
long duration;
float distanceCm;

// Define DHT11 pin and type
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define Ultrasonic pins
#define trig_pin 9
#define echo_pin 10

// Define LDR pin
#define ldr_pin A0

void setup(){
  Serial.begin(9600); // Start serial communication

  dht.begin(); // Initialize DHT sensor

  pinMode(trig_pin, OUTPUT); // Trigger pin as output
  pinMode(echo_pin, INPUT); // Echo pin as input

  pinMode(ldr_pin, INPUT); // LDR pin as input

}

void loop() {

  // Read humidity and temperature
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();

  // Read distance
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH, 30000);
  distanceCm = duration * 0.0343 / 2;

  // Read light denisty
  int light_density = analogRead(ldr_pin);

  // Sending data to serial (humidity,temperature,distance,light density)
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(temperatureC);
  Serial.print(",");
  Serial.print(distanceCm);
  Serial.print(",");
  Serial.println(light_density);

  delay(200);
}
