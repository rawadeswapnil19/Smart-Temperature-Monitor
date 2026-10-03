// Smart Temperature Monitoring & Alert System
// Arduino UNO + TMP36 + LED + Buzzer

const int tempPin = A0;
const int ledPin = 8;
const int buzzerPin = 9;

const float threshold = 35.0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Read the analog value from TMP36
  int sensorValue = analogRead(tempPin);

  // Convert analog reading to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert TMP36 voltage to temperature in Celsius
  float temperature = (voltage - 0.5) * 100.0;

  // Display temperature in Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Check temperature against threshold
  if (temperature >= threshold) {

    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);

    Serial.println("ALERT: Temperature is HIGH!");

  } else {

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    Serial.println("Status: Normal");
  }

  delay(1000);
}