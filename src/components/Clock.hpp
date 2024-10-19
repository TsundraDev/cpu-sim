#ifndef __CPU_SIM__CLOCK_HPP__
#define __CPU_SIM__CLOCK_HPP__

#include <cstdint>
#include <vector>

#include "event-sim.hpp"
#include "../base/BaseBlock.hpp"

class Clock : public BaseBlock {
private:
  std::vector<BaseBlock*> m_output;

public:
  Clock(EventQueue* event_queue);
  ~Clock();

  void addOutput(BaseBlock* clocked_block) { m_output.push_back(clocked_block); }

  void init();
  void recvEvent(Agent* src, uint8_t* data, uint64_t size);
  void update();
};

#endif
