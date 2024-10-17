#include "BaseBlock.hpp"

RegisterBlock::RegisterBlock(Clock* clock) :
  BaseBlock(clock->event_queue()),
  m_clock(clock) {}

RegisterBlock::~RegisterBlock() {

}

void RegisterBlock::recvEvent(Agent* src, uint8_t* data, uint64_t size) {
  if (src == m_clock) {
    this->updateRegister();
    this->updateOutput();
  } else {
    this->update(src, data, size);
  }
}

void RegisterBlock::update(Agent* src, uint8_t* data, uint64_t size) {

}

void RegisterBlock::updateRegister() {

}

void RegisterBlock::updateOutput() {
  // Update output
  uint64_t cur_tick = m_event_queue->tick();
  for (uint64_t i = 0; i < m_output.size(); i++) {
    this->createEvent(Event(cur_tick, this, &(m_output[i])));
  }
}

