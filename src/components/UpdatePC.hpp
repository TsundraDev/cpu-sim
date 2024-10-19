#ifndef __CPU_SIM__COMPONENTS__UPDATEPC_HPP__
#define __CPU_SIM__COMPONENTS__UPDATEPC_HPP__

#include <utility>
#include <base/WireBlock.hpp>
#include <base/BlockIO.hpp>

class UpdatePC : public WireBlock {
private:
  // Input
  BlockInput<uint64_t>  m_input;
  BlockOutput<uint64_t> m_output;

public:
  UpdatePC(EventQueue* event_queue);

  ~UpdatePC();

  void setInput(BaseBlock* block);
  void addOutput(BaseBlock* block);

  void updateInput(Agent* src, uint8_t* data, uint64_t size);
  void updateBlock();
  void updateOutput();
  
};

#endif
