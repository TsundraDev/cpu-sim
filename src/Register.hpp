#ifndef __CPU_SIM__REGISTER_HPP__
#define __CPU_SIM__REGISTER_HPP__

#include "BaseBlock.hpp"
#include <utility>

class Register : public RegisterBlock {
private:
  // Input
  std::pair<BaseBlock*, uint64_t> m_val;

  // Output
  std::pair<uint64_t, std::vector<BaseBlock*>> m_reg;

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
