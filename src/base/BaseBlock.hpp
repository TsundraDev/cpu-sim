#ifndef __CPU_SIM__BASE__BASEBLOCK_HPP__
#define __CPU_SIM__BASE__BASEBLOCK_HPP__

#include <event-sim.hpp>

class BaseBlock : public Agent {
public:
  BaseBlock(EventQueue* event_queue);
  ~BaseBlock();

  EventQueue* event_queue() { return m_event_queue; }

  virtual void recvEvent(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateInput(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateBlock();
  virtual void updateOutput();
};



#endif
