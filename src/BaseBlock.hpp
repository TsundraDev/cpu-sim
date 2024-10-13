#ifndef __CPU_SIM__BASEBLOCK_HPP__
#define __CPU_SIM__BASEBLOCK_HPP__

#include <vector>
#include <cstdint>
#include <event-sim.hpp>

class BaseBlock : public Agent {
protected:
  std::vector<BaseBlock> m_input;
  std::vector<BaseBlock> m_output;

public:
  BaseBlock(EventQueue* event_queue) : Agent(event_queue) {}
  ~BaseBlock() {}

  void addInput(BaseBlock input)   { m_input.push_back(input);   }
  void addOutput(BaseBlock output) { m_output.push_back(output); }
};

class Clock : public BaseBlock {
public:
  Clock(EventQueue* event_queue);
  ~Clock();

  void init();
  void recvEvent(Agent* src, uint8_t* data, uint64_t size);
  void update();
};

class RegisterBlock : public BaseBlock {
private:
public:
  RegisterBlock(Clock clock);
  ~RegisterBlock();
  virtual void recvEvent(Agent* src, uint8_t* data, uint64_t size);
  void update();
};

class WireBlock : public BaseBlock {

};

#endif
