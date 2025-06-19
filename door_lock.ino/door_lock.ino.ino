#define HALL_SENSOR_PIN 2   // Hall sensor input pin
#define DOOR_STATUS_LED 8   // Simulated door lock with LED

void setup() {
  pinMode(HALL_SENSOR_PIN, INPUT);
  pinMode(DOOR_STATUS_LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(DOOR_STATUS_LED, LOW);  // Initially door is locked
}

void loop() {
  int magneticField = digitalRead(HALL_SENSOR_PIN);

  if (magneticField == LOW) {  // Magnet detected
    digitalWrite(DOOR_STATUS_LED, HIGH);  // Unlock (LED ON)
    Serial.println("Magnet detected - Door UNLOCKED");
  } else {
    digitalWrite(DOOR_STATUS_LED, LOW);   // Lock (LED OFF)
    Serial.println("No magnet - Door LOCKED");
  }

  delay(300);
}
