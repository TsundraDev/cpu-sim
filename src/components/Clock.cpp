#include "Clock.hpp"
#include <cstdio>
#include <cassert>

Clock::Clock(EventQueue* event_queue) :
  ClockBlock(event_queue) {}

Clock::~Clock() {

}

void Clock::init() {
  this->createEvent(Event(0, this, this));
}
