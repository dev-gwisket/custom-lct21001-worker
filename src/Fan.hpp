#include <Arduino.h>
#include <stdint.h>

typedef struct {
  uint8_t tach;
  uint8_t pwm;
} FanPins;


class Fan {
  private:
    uint8_t speed;
    uint16_t status;
    FanPins pins;
    void setSpeed(byte);

  public:
    Fan(uint8_t, uint8_t);
    void run();
    uint16_t getStatus();
    void setSpeedByTemperature(byte);
};

