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
  std::pair<BaseBlock*, uint64_t> m_reg;

public:
  Register(Clock* clock) :
    RegisterBlock(clock),
    m_val(std::pair<BaseBlock*, uint64_t>(nullptr, 0)),
    m_reg(std::pair<BaseBlock*, uint64_t>(nullptr, 0)) {}

  void updateInput(Agent* src, uint8_t* data, uint64_t size) {
    assert(src == (Agent*)m_val.first);
    m_val.second = *(uint64_t*)data;
  }

  void updateBlock() {
    m_reg.second = m_val.second;
  }

  void updateOutput() {
    uint64_t cur_tick = m_event_queue->tick();
    uint64_t* send_data = new uint64_t;
    *send_data = m_reg.second;
    this->createEvent(Event(cur_tick, (Agent*)this, (Agent*)m_reg.first, (uint8_t*)send_data, 8));
  }
};

int main() {

  printf("cpu-sim\n");
  EventQueue event_queue = EventQueue();
  Clock clock = Clock(&event_queue);

  clock.init();

  event_queue.run();
  return 0;
}
