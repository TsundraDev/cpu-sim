#include "Register.hpp"

#include <cassert>
#include <cstdio>

Register::Register(Clock* clock) :
  RegisterBlock(clock),
  m_input(Input<uint64_t>(nullptr, 0)),
  m_output(Output<uint64_t>(0)) {}

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
  printf("Reg val : %lx\n", input);
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
