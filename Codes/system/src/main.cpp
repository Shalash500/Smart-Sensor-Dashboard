#include <Arduino.h>
#include <DHT.h>

// Define DHT11 pin and type
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define Ultrasonic pins
#define trig_pin 9
#define echo_pin 10

// Define LDR pin
#define ldr_pin A0

// sensor data struct
struct SensorData
{
  float humidity {};
  float temperature {};
  float distance {};
  int light {};
};

SensorData read_sensors(){
  SensorData data;

  // Read humidity and temperature
  data.humidity = dht.readHumidity();
  data.temperature = dht.readTemperature();

  // Read distance
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH, 30000);
  data.distance = duration * 0.0343 / 2;

  // Read light denisty
  data.light = analogRead(ldr_pin);

  return data;

}

void send_serial(SensorData data)
{
  Serial.print(data.humidity);
  Serial.print(",");
  Serial.print(data.temperature);
  Serial.print(",");
  Serial.print(data.distance);
  Serial.print(",");
  Serial.println(data.light);
}

void setup(){
  Serial.begin(9600); // Start serial communication

  dht.begin(); // Initialize DHT sensor

  pinMode(trig_pin, OUTPUT); // Trigger pin as output
  pinMode(echo_pin, INPUT); // Echo pin as input

  pinMode(ldr_pin, INPUT); // LDR pin as input

}

void loop() {
  SensorData data = read_sensors();
  send_serial(data);
  delay(200);
}
