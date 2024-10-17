#include <cstdio>

#include "event-sim.hpp"
#include "BaseBlock.hpp"
#include <utility>
#include <cassert>

class Register : public RegisterBlock {
private:
  // Input
  std::pair<BaseBlock*, uint64_t> m_val;

  // Output
  std::pair<uint64_t, std::vector<BaseBlock*>> m_reg;

public:
  Register(Clock* clock) :
    RegisterBlock(clock),
    m_val(std::pair<BaseBlock*, uint64_t>(nullptr, 0)),
    m_reg(std::pair<uint64_t, std::vector<BaseBlock*>>(0, std::vector<BaseBlock*>())) {}

  void setInput(BaseBlock* block)  { m_val.first = block; }
  void addOutput(BaseBlock* block) { m_reg.second.push_back(block); }

  void updateInput(Agent* src, uint8_t* data, uint64_t size) {
    assert(src == (Agent*)m_val.first);
    m_val.second = *(uint64_t*)data;
  }

  void updateBlock() {
    m_reg.first = m_val.second;
  }

  void updateOutput() {
    uint64_t cur_tick = m_event_queue->tick();
    uint64_t* send_data = new uint64_t;
    *send_data = m_reg.first;
    for (uint64_t i = 0; i < m_reg.second.size(); i++) {
      this->createEvent(Event(cur_tick, (Agent*)this, (Agent*)m_reg.second[i], (uint8_t*)send_data, 8));
    }
  }
};

int main() {

  printf("cpu-sim\n");
  EventQueue event_queue = EventQueue();
  Clock clock = Clock(&event_queue);

  Register r1 = Register(&clock);


  clock.init();

  event_queue.run();
  return 0;
}
