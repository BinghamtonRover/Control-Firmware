#include <Servo.h>
#include "../drive.pb.h"

const int frontSwivelPin = 28;
const int frontTiltPin = 37;
const int backSwivelPin = 24;
const int backTiltPin = 41;

/// A collection of servos that control the rover's camera system.
class Cameras {
  private:
    Servo frontSwivel;
    Servo frontTilt;
    Servo backSwivel;
    Servo backTilt;

  public:
    DriveData data;
    void setup();
    void handleCommand(DriveCommand command);
};
