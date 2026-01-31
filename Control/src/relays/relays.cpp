#include "relays.h"

void Relay::setup() {
    pinMode(relayPin, OUTPUT);
}

void Relay::update() {
    if (softwareState) {
        turnOn();
    } else {
        turnOff();
    }
}

void Relay::turnOn() { 
    digitalWrite(relayPin, HIGH);
    relayData = BoolState_ON;
}

void Relay::turnOff() {
    digitalWrite(relayPin, LOW);
    relayData = BoolState_OFF;
}

void Relay::handleCommand(BoolState command) { 
    switch (command) {
        case BoolState_ON:
            softwareState = true;
            break;
        case BoolState_OFF:
            softwareState = false;
            break;
        case BoolState_BOOL_UNDEFINED:
            break;
    }
}

void Relays::setup() {
    delay(250);

    backLeftMotor.setup();
    Serial.println("Back left motor relay initialized");

    backRightMotor.setup();
    Serial.println("Back right motor relay initialized");

    frontLeftMotor.setup();
    Serial.println("Front left motor relay initialized");

    frontRightMotor.setup();
    Serial.println("Front right motor relay initialized");

    arm.setup();
    Serial.println("Arm relay initialized");

    science.setup();
    Serial.println("Science relay initialized");

    lDampRelay.setup();
    Serial.println("Left dampener relay engaged");
    delay(250);

    rDampRelay.setup();
    Serial.println("Right dampener relay engaged");
    delay(250);
    
    delay(250);

    backLeftMotor.turnOn();
    Serial.println("Back left motor relay engaged");
    delay(250);

    backRightMotor.turnOn();
    Serial.println("Back right motor relay engaged");
    delay(250);

    frontLeftMotor.turnOn();
    Serial.println("Front left motor relay engaged");
    delay(250);
    
    frontRightMotor.turnOn();
    Serial.println("Front right motor relay engaged");
    delay(250);

    lDampRelay.turnOn();
    Serial.println("Left dampener relay engaged");
    delay(250);

    rDampRelay.turnOn();
    Serial.println("Right dampener relay engaged");
    delay(250);

    arm.turnOn();
    Serial.println("Arm relay engaged");
    delay(250);
    
    science.turnOn();
    Serial.println("Science relay engaged");
    delay(250);
}

void Relays::update() {
    backLeftMotor.update();
    backRightMotor.update();
    frontLeftMotor.update();
    frontRightMotor.update();
    arm.update();
    science.update();
}

void Relays::handleCommand(RelaysCommand command) {
    backLeftMotor.handleCommand(command.backLeftMotor);
    backRightMotor.handleCommand(command.backRightMotor);
    frontLeftMotor.handleCommand(command.frontLeftMotor);
    frontRightMotor.handleCommand(command.frontRightMotor);
    arm.handleCommand(command.arm);
    science.handleCommand(command.science);
}

// void OverrideSwitch::setup() {
//     pinMode(switchPin, INPUT);
// }