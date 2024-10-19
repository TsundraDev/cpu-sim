#ifndef __CPU_SIM__BASE__CLOCKBLOCK_HPP__
#define __CPU_SIM__BASE__CLOCKBLOCK_HPP__

#include <cstdint>
#include <vector>

#include <event-sim.hpp>
#include <base/BaseBlock.hpp>
#include <base/RegisterBlock.hpp>
#include <base/BlockIO.hpp>

class ClockBlock : public BaseBlock {
private:
  BlockOutput<uint8_t> m_output;

public:
  ClockBlock(EventQueue* event_queue);
  ~ClockBlock();

  void addOutput(RegisterBlock* block) { m_output.addDestination(block); }

  void recvEvent(Agent* src, uint8_t* data, uint64_t size) override;
  void updateInput(Agent* src, uint8_t* data, uint64_t size) override;
  void updateBlock() override;
  void updateOutput() override;
};

#endif
