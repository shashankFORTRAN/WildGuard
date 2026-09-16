#include <Servo.h>

const int pirPin = 2;
const int ledPin = 7;
const int buzzerPin = 8;
const int triggerPin = 4;
const int servoPin = 9;

Servo myServo;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);

  digitalWrite(triggerPin, LOW);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.begin(9600);
}

void loop() {

  int motion = digitalRead(pirPin);

  if (motion == HIGH) {

    Serial.println("Animal Detected!");

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    myServo.write(90);

    digitalWrite(triggerPin, HIGH);

    delay(3000);

    digitalWrite(triggerPin, LOW);

    myServo.write(0);

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    delay(10000);
  }
}
