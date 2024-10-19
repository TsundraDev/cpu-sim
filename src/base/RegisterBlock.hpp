#ifndef __CPU_SIM__REGISTERBLOCK_HPP__
#define __CPU_SIM__REGISTERBLOCK_HPP__

#include <cstdint>

#include <event-sim.hpp>
#include <base/BaseBlock.hpp>
#include <components/Clock.hpp>

class RegisterBlock : public BaseBlock {
private:
  Clock* m_clock;

public:
  RegisterBlock(EventQueue* event_queue, Clock* clock);
  ~RegisterBlock();

  void recvEvent(Agent* src, uint8_t* data, uint64_t size) override;
  virtual void updateInput(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateBlock();
  virtual void updateOutput();
};

#endif
