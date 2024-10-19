#ifndef __CPU_SIM__CLOCKBLOCK_HPP__
#define __CPU_SIM__CLOCKBLOCK_HPP__

#include <cstdint>
#include <vector>

#include <event-sim.hpp>
#include <base/BaseBlock.hpp>
#include <base/RegisterBlock.hpp>

class ClockBlock : public BaseBlock {
private:
  std::vector<RegisterBlock*> m_output;

public:
  ClockBlock(EventQueue* event_queue);
  ~ClockBlock();

  void addOutput(RegisterBlock* block) { m_output.push_back(block); }

  void recvEvent(Agent* src, uint8_t* data, uint64_t size) override;
  void updateInput(Agent* src, uint8_t* data, uint64_t size) override;
  void updateBlock() override;
  void updateOutput() override;
};

#endif
