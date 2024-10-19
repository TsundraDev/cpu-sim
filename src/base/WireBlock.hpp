#ifndef __CPU_SIM__BASE__WIREBLOCK_HPP__
#define __CPU_SIM__BASE__WIREBLOCK_HPP__

#include <cstdint>

#include <event-sim.hpp>
#include <base/BaseBlock.hpp>

class WireBlock : public BaseBlock {
public:
  WireBlock(EventQueue* event_queue);
  ~WireBlock();

  void recvEvent(Agent* src, uint8_t* data, uint64_t size) override;
  virtual void updateInput(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateBlock();
  virtual void updateOutput();
};

#endif
