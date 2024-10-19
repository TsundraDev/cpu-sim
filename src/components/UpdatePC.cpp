#include "UpdatePC.hpp"

#include <cassert>

UpdatePC::UpdatePC(EventQueue* event_queue) :
  WireBlock(event_queue),
  m_input(BlockInput<uint64_t>(0)),
  m_output(BlockOutput<uint64_t>(0)) {}

UpdatePC::~UpdatePC() {

}

void UpdatePC::setInput(BaseBlock* block)  { m_input.setSource(block); }
void UpdatePC::addOutput(BaseBlock* block) { m_output.addDestination(block); }

void UpdatePC::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  // Update output values
  assert(src == (Agent*)m_input.getSource());
  uint64_t recv_data = *(uint64_t*)data;
  m_input.set(recv_data);
}

void UpdatePC::updateBlock() {
  m_output.set(m_input.get() + 4);
}

void UpdatePC::updateOutput() {
  // Update output blocks
  uint64_t cur_tick = m_event_queue->tick();
  m_output.send(this, cur_tick);
}
