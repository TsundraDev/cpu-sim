#include "UpdatePC.hpp"

#include <cassert>

UpdatePC::UpdatePC(EventQueue* event_queue) :
  WireBlock(event_queue),
  m_in(std::pair<BaseBlock*, uint64_t>(nullptr, 0)),
  m_out(std::pair<uint64_t, std::vector<BaseBlock*>>(0, std::vector<BaseBlock*>())) {}

UpdatePC::~UpdatePC() {

}

void UpdatePC::setInput(BaseBlock* block)  { m_in.first = block; }
void UpdatePC::addOutput(BaseBlock* block) { m_out.second.push_back(block); }

void UpdatePC::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  // Update output values
  assert(src == (Agent*)m_in.first);
  m_in.second = *(uint64_t*)data;
}

void UpdatePC::updateBlock() {
  m_out.first = m_in.second + 4;
}

void UpdatePC::updateOutput() {
  // Update output blocks
  uint64_t cur_tick = m_event_queue->tick();
  uint64_t* send_data = new uint64_t;
  *send_data = m_out.first;
  for (uint64_t i = 0; i < m_out.second.size(); i++) {
    this->createEvent(Event(cur_tick, (Agent*)this, (Agent*)m_out.second[i], (uint8_t*)send_data, 8));
  }
}
