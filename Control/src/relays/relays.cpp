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
    softwareState = true;
    relayData = BoolState_ON;
}

void Relay::turnOff() {
    digitalWrite(relayPin, LOW);
    softwareState = false;
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

    leftDampeningMotor.setup();
    Serial.println("Left dampener relay initialized");

    rightDampeningMotor.setup();
    Serial.println("Right dampener relay initialized");

    backLeftMotor.turnOn();
    Serial.println("Back left motor relay engaged");

    delay(100);
    backRightMotor.turnOn();
    Serial.println("Back right motor relay engaged");

    delay(100);
    frontLeftMotor.turnOn();
    Serial.println("Front left motor relay engaged");

    delay(100);
    frontRightMotor.turnOn();
    Serial.println("Front right motor relay engaged");

    delay(100);
    leftDampeningMotor.turnOn();   // temporary fix until dampening motors are implemenented
    Serial.println("Left dampener relay engaged");

    delay(100);
    rightDampeningMotor.turnOn();   // temporary fix until dampening motors are implemenented
    Serial.println("Right dampener relay engaged");

    delay(100);
    arm.turnOn();
    Serial.println("Arm relay engaged");

    delay(100);
    science.turnOn();
    Serial.println("Science relay engaged");
}

void Relays::update() {
    backLeftMotor.update();
    backRightMotor.update();
    frontLeftMotor.update();
    frontRightMotor.update();
    arm.update();
    science.update();
    leftDampeningMotor.update();
    rightDampeningMotor.update();
}

void Relays::handleCommand(RelaysCommand command) {
    backLeftMotor.handleCommand(command.back_left_motor);
    backRightMotor.handleCommand(command.back_right_motor);
    frontLeftMotor.handleCommand(command.front_left_motor);
    frontRightMotor.handleCommand(command.front_right_motor);
    arm.handleCommand(command.arm);
    science.handleCommand(command.science);
    leftDampeningMotor.handleCommand(command.left_dampening_motor);
    rightDampeningMotor.handleCommand(command.right_dampening_motor);
}

// void OverrideSwitch::setup() {
//     pinMode(switchPin, INPUT);
// }