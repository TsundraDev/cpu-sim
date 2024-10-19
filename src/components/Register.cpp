#include "Register.hpp"

#include <cassert>
#include <cstdio>

Register::Register(EventQueue* event_queue, Clock* clock) :
  RegisterBlock(event_queue, clock),
  m_input(BlockInput<uint64_t>(0)),
  m_output(BlockOutput<uint64_t>(0)) {
  assert(event_queue == clock->event_queue());
}

Register::~Register() {

}


void Register::setInput(BaseBlock* block)  { m_input.setSource(block); }
void Register::addOutput(BaseBlock* block) { m_output.addDestination(block); }

void Register::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  assert(src == (Agent*)m_input.getSource());
  uint64_t input = *(uint64_t*)data;
  m_input.set(input);
}

void Register::updateBlock() {
  uint64_t input = m_input.get();
  m_output.set(input);
}

void Register::updateOutput() {
  uint64_t cur_tick = m_event_queue->tick();
  uint64_t* send_data = new uint64_t;
  *send_data = m_output.get();
  for (uint64_t i = 0; i < m_output.getDestination().size(); i++) {
    this->createEvent(Event(cur_tick,
                            (Agent*)this,
                            (Agent*)m_output.getDestination()[i],
                            (uint8_t*)send_data,
                            8)
    );
  }
}
