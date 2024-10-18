#ifndef __CPU_SIM__BASEBLOCK_HPP__
#define __CPU_SIM__BASEBLOCK_HPP__

#include <vector>
#include <cstdint>
#include <event-sim.hpp>

class BaseBlock : public Agent {
public:
  BaseBlock(EventQueue* event_queue) : Agent(event_queue) {}
  ~BaseBlock() {}

  EventQueue* event_queue() { return m_event_queue; }
};

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

class RegisterBlock : public BaseBlock {
private:
  Clock* m_clock;

public:
  RegisterBlock(Clock* clock);
  ~RegisterBlock();
  virtual void recvEvent(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateInput(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateBlock();
  virtual void updateOutput();
};

class WireBlock : public BaseBlock {
public:
  WireBlock(EventQueue* event_queue);
  ~WireBlock();
  virtual void recvEvent(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateInput(Agent* src, uint8_t* data, uint64_t size);
  virtual void updateBlock();
  virtual void updateOutput();
};

#endif
