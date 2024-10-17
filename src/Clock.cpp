#include "BaseBlock.hpp"
#include <cstdio>
#include <cassert>

Clock::Clock(EventQueue* event_queue) :
  BaseBlock(event_queue),
  m_output(std::vector<BaseBlock*>()) {}

Clock::~Clock() {

}

void Clock::init() {
  this->createEvent(Event(0, this, this));
}

void Clock::recvEvent(Agent* src, uint8_t* data, uint64_t size) {
  assert(src == (Agent*)this);
  this->update();
}

void Clock::update() {
  // Update clocked blocks
  uint64_t cur_tick = m_event_queue->tick();
  for (uint64_t i = 0; i < m_output.size(); i++) {
    this->createEvent(Event(cur_tick, this, m_output[i]));
  }
  
  // Prepare next tick
  uint64_t next_tick = cur_tick + 1;
  this->createEvent(Event(next_tick, this, this));
  printf("clock tick : %ld\n", cur_tick);
}
