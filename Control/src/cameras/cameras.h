#include <Servo.h>
#include "../drive.pb.h"

const int frontSwivelPin = ;
const int frontTiltPin = ;
const int backSwivelPin = ;
const int backTiltPin = ;

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
