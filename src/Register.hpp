#ifndef __CPU_SIM__REGISTER_HPP__
#define __CPU_SIM__REGISTER_HPP__

#include "Input.hpp"
#include "BaseBlock.hpp"
#include <utility>

class Register : public RegisterBlock {
private:
  // Input
  Input<uint64_t> m_input;
  Output<uint64_t> m_output;

public:
  // Constructor / Destructor
  Register(Clock* clock);
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
