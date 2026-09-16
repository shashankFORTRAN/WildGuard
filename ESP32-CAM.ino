#define TRIGGER_PIN 13

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, INPUT);

  Serial.println("ESP32-CAM Ready");
}

void loop() {

  if (digitalRead(TRIGGER_PIN) == HIGH) {

    Serial.println("Animal Detected - Capture Image");

    delay(3000);
  }
}
