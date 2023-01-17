#include "Fan.hpp"

Fan::Fan(uint8_t pwmPin, uint8_t tachPin) {
  this->pins.pwm = pwmPin;
  this->pins.tach = tachPin;
}

void Fan::run() {
  analogWrite(this->pins.pwm, this->speed);
}

uint16_t Fan::getStatus() {
  return analogRead(this->pins.tach);
}

void Fan::setSpeed(byte speed) {
  this->speed = speed;
  this->run();
}

void Fan::setSpeedByTemperature(byte temperature) {
  if (temperature > 100) {
    temperature = 100;
  }

  if (temperature < 50) {
    this->setSpeed(0);
  } else {
    this->setSpeed(map(temperature, 50, 100, 0, 255));
  }
}

