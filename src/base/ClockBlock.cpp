#include "ClockBlock.hpp"

#include <cassert>
#include <cstdio>
#include <cstdlib>

ClockBlock::ClockBlock(EventQueue* event_queue) :
  BaseBlock(event_queue),
  m_output(BlockOutput<uint8_t>(0)) {}

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
  m_output.send(this, cur_tick);
  
  // Prepare next tick
  uint64_t next_tick = cur_tick + 1;
  this->createEvent(Event(next_tick, this, this));
}
