
#include <Arduino.h>

#include "led_strip.h"

void LedStrip::setup() {
  FastLED.addLeds<LPD8806, dataPin, clockPin, BRG>(ledStrip, stripLength);
  FastLED.setBrightness(255);
  FastLED.setCorrection(TypicalLEDStrip);
  blue();
}

void LedStrip::setColor(ProtoColor color) {
  CRGB toWrite = CRGB::Black;

  switch (color) {
    case ProtoColor::ProtoColor_PROTO_COLOR_UNDEFINED:
    case ProtoColor::ProtoColor_UNLIT:
      break;
    case ProtoColor::ProtoColor_RED:
      toWrite = CRGB::Red;
      break;
    case ProtoColor::ProtoColor_GREEN:
      toWrite = CRGB::Green;
      break;
    case ProtoColor::ProtoColor_BLUE:
      toWrite = CRGB::Blue;
      break;
  }

  if (toWrite == writtenColor) {
    return;
  }
  writtenColor = toWrite;
  fill_solid(ledStrip, stripLength, toWrite);
  noInterrupts();
  FastLED.show();
  interrupts();
}

void LedStrip::red() {
  setColor(ProtoColor::ProtoColor_RED);
  data.color = ProtoColor::ProtoColor_RED;
  oldColor = ProtoColor::ProtoColor_RED;
}

void LedStrip::green() {
  setColor(ProtoColor::ProtoColor_GREEN);
  data.color = ProtoColor::ProtoColor_GREEN;
  oldColor = ProtoColor::ProtoColor_GREEN;
}

void LedStrip::blue() {
  setColor(ProtoColor::ProtoColor_BLUE);
  data.color = ProtoColor::ProtoColor_BLUE;
  oldColor = ProtoColor::ProtoColor_BLUE;
}

void LedStrip::off() {
  setColor(ProtoColor::ProtoColor_UNLIT);
  data.color = ProtoColor::ProtoColor_UNLIT;
}

void LedStrip::update() {
  if (shouldBlink && !isOn) {
    off();
  } else {
    setColor(oldColor);
    data.color = oldColor;
  }
  isOn = !isOn;
}

void LedStrip::handleCommand(DriveCommand command) {
  switch (command.color) {
    case ProtoColor::ProtoColor_PROTO_COLOR_UNDEFINED: break;
    case ProtoColor::ProtoColor_RED: red(); break;
    case ProtoColor::ProtoColor_GREEN: green(); break;
    case ProtoColor::ProtoColor_BLUE: blue(); break;
    case ProtoColor::ProtoColor_UNLIT: off(); break;
  }
  switch (command.blink) {
    case BoolState::BoolState_BOOL_UNDEFINED: break;
    case BoolState::BoolState_ON: shouldBlink = true; break;
    case BoolState::BoolState_OFF: shouldBlink = false; break;
  }
}

