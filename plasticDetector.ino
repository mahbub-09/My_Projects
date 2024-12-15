#include <HX711.h>

// Pins for HX711
#define DT 4   // Data pin
#define SCK 5  // Clock pin

// Initialize HX711
HX711 scale;

// Variables for Ultrasonic Sensor and IR Sensor
long duration;
int distance;
int irSensorPin = 7;    // IR sensor connected to pin 7
const int trigPin = 10; // TRIG pin of ultrasonic sensor
const int echoPin = 11; // ECHO pin of ultrasonic sensor

// Pins for Buzzer and Light
const int buzzerPin = 8;
const int lightPin = 9;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(lightPin, OUTPUT);

  // Initialize HX711
  scale.begin(DT, SCK);
  Serial.println("Initializing scale...");
  scale.set_scale();  // Set the scale calibration factor (adjust this value for accuracy)
  scale.tare();       // Reset the scale to 0

  Serial.println("Scale initialized. Place weight to measure.");
}

void loop() {
  int irStatus = digitalRead(irSensorPin);  // Read IR sensor value

  if (irStatus == LOW) { // Object detected
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;  // Calculate the distance in cm

    if(distance <= 30){
      // Serial and Light/Buzzer Output
      Serial.print("Plastic detected! Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(lightPin, HIGH);
      delay(300); // Buzzer and light on for 2 seconds
      digitalWrite(buzzerPin, LOW);
      digitalWrite(lightPin, LOW);

      // Weight Measurement
      float weight = scale.get_units(); // Get the weight reading
      Serial.print("Measured Weight: ");
      weight = weight/1000;

      Serial.print(weight);
      Serial.println(" grams");

      if(weight <= 10){
        Serial.println("Place heavier plastic object!!");
      }
      else if(weight <= 15){
        Serial.println("You've been credited with 5 coins!!!");
      }
      else if(weight <= 30){
        Serial.println("You've been credited with 10 coins!!!");
      }
      else if(weight <= 45){
        Serial.println("You've been credited with 15 coins!!!");
      }
      else if(weight <= 60){
        Serial.println("You've been credited with 20 coins!!!");
      }
      else if(weight <= 75){
        Serial.println("You've been credited with 25 coins!!!");
      }
      else if(weight <= 100){
        Serial.println("You've been credited with 30 coins!!!");
      }
      else if(weight > 100){
        Serial.println("Object too heavy!!!");
      }

      Serial.println();
      Serial.println();
      Serial.println();
    }

    // Optional: Add a small delay to stabilize the scale reading
    delay(500);
  } else { // No object detected
    Serial.println("No Plastic detected by IR sensor");
    Serial.println();
    Serial.println();
    Serial.println();
  }

  delay(2000); // Wait before next reading
}
