#ifndef __CPU_SIM__BASE__REGISTERBLOCK_HPP__
#define __CPU_SIM__BASE__REGISTERBLOCK_HPP__

#include <cstdint>

#include <event-sim.hpp>
#include <base/BaseBlock.hpp>

class ClockBlock;

class RegisterBlock : public BaseBlock {
private:
  ClockBlock* m_clock;

public:
  RegisterBlock(EventQueue* event_queue, ClockBlock* clock);
  ~RegisterBlock();

  void recvEvent(Agent* src, uint8_t* data, uint64_t size) override;
  virtual void updateInput(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateBlock();
  virtual void updateOutput();
};

#endif
