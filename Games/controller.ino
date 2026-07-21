#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// L298N Pins
#define ENA 33
#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14
#define ENB 32

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Enable Motor Driver
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  stopCar();

  SerialBT.begin("AR083");

  Serial.println("Bluetooth Started");
}

void loop() {

  if (SerialBT.available()) {

    char cmd = toupper(SerialBT.read());

    Serial.print("Received: ");
    Serial.println(cmd);

    switch (cmd) {

      case 'F':
        forward();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;

      case 'S':
        stopCar();
        break;

      default:
        break;
    }
  }
}