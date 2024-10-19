#include "ClockBlock.hpp"

#include <cassert>
#include <cstdio>
#include <cstdlib>

ClockBlock::ClockBlock(EventQueue* event_queue) :
  BaseBlock(event_queue),
  m_output(std::vector<RegisterBlock*>()) {}

ClockBlock::~ClockBlock() {

}

void ClockBlock::recvEvent(Agent* src, uint8_t* data, uint64_t size) {
  assert(src == (Agent*)this);
  this->updateOutput();
}

void ClockBlock::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  fprintf(stderr, "ClockBlock::updateInput should never be called");
  exit(1);
}

void ClockBlock::updateBlock() {
  fprintf(stderr, "ClockBlock::updateBlock should never be called");
  exit(1);
}

void ClockBlock::updateOutput() {
  // Update clocked blocks
  uint64_t cur_tick = m_event_queue->tick();
  for (uint64_t i = 0; i < m_output.size(); i++) {
    this->createEvent(Event(cur_tick, this, m_output[i]));
  }
  
  // Prepare next tick
  uint64_t next_tick = cur_tick + 1;
  this->createEvent(Event(next_tick, this, this));
}
