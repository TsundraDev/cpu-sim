#include "Register.hpp"

#include <cassert>
#include <cstdio>

Register::Register(Clock* clock) :
  RegisterBlock(clock),
  m_val(std::pair<BaseBlock*, uint64_t>(nullptr, 0)),
  m_reg(std::pair<uint64_t, std::vector<BaseBlock*>>(0, std::vector<BaseBlock*>())) {}

Register::~Register() {

}


void Register::setInput(BaseBlock* block)  { m_val.first = block; }
void Register::addOutput(BaseBlock* block) { m_reg.second.push_back(block); }

void Register::updateInput(Agent* src, uint8_t* data, uint64_t size) {
  assert(src == (Agent*)m_val.first);
  m_val.second = *(uint64_t*)data;
}

void Register::updateBlock() {
  m_reg.first = m_val.second;
  printf("Reg val : %lx\n", m_reg.first);
}

void Register::updateOutput() {
  uint64_t cur_tick = m_event_queue->tick();
  uint64_t* send_data = new uint64_t;
  *send_data = m_reg.first;
  for (uint64_t i = 0; i < m_reg.second.size(); i++) {
    this->createEvent(Event(cur_tick, (Agent*)this, (Agent*)m_reg.second[i], (uint8_t*)send_data, 8));
  }
}
