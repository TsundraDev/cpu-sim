#include <cstdio>

#include "event-sim.hpp"
#include "BaseBlock.hpp"
#include "Register.hpp"

class Add4 : public WireBlock {
private:
  // Input
  std::pair<BaseBlock*, uint64_t> m_in;

  // Output
  std::pair<uint64_t, std::vector<BaseBlock*>> m_out;

public:
  Add4(EventQueue* event_queue) :
    WireBlock(event_queue),
    m_in(std::pair<BaseBlock*, uint64_t>(nullptr, 0)),
    m_out(std::pair<uint64_t, std::vector<BaseBlock*>>(0, std::vector<BaseBlock*>())) {}

  ~Add4() {}

  void setInput(BaseBlock* block)  { m_in.first = block; }
  void addOutput(BaseBlock* block) { m_out.second.push_back(block); }

  void update(Agent* src, uint8_t* data, uint64_t size) {
    // Update output values
    m_out.first = *(uint64_t*)data + 4;
    
    // Update output blocks
    uint64_t cur_tick = m_event_queue->tick();
    uint64_t* send_data = new uint64_t;
    *send_data = m_out.first;
    for (uint64_t i = 0; i < m_out.second.size(); i++) {
      this->createEvent(Event(cur_tick, (Agent*)this, (Agent*)m_out.second[i], (uint8_t*)send_data, 8));
    }
  }
  
};

int main() {

  printf("cpu-sim\n");
  EventQueue event_queue = EventQueue();
  Clock clock = Clock(&event_queue);

  Register pc = Register(&clock);
  Add4     update_pc = Add4(&event_queue);

  pc.setInput(&update_pc);
  pc.addOutput(&update_pc);

  update_pc.setInput(&pc);
  update_pc.addOutput(&pc);


  clock.init();

  event_queue.run();
  return 0;
}
