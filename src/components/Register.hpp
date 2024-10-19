#ifndef __CPU_SIM__REGISTER_HPP__
#define __CPU_SIM__REGISTER_HPP__

#include "../base/Input.hpp"
#include "../base/RegisterBlock.hpp"
#include <utility>

class Register : public RegisterBlock {
private:
  // Input
  BlockInput<uint64_t> m_input;
  BlockOutput<uint64_t> m_output;

public:
  // Constructor / Destructor
  Register(EventQueue* event_queue, Clock* clock);
  ~Register();

  // Register setup
  void setInput(BaseBlock* block);
  void addOutput(BaseBlock* block);

  // Register update
  void updateInput(Agent* src, uint8_t* data, uint64_t size);
  void updateBlock();
  void updateOutput();
};

#endif
